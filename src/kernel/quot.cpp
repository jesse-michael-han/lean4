/*
Copyright (c) 2018 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura

Quotient types.
*/
#include "kernel/quot.h"
#include "kernel/abstract.h"
#include "kernel/type_checker.h"
#include "kernel/inductive/inductive.h"

namespace lean {
name * quot_consts::g_quot = nullptr;
name * quot_consts::g_quot_lift = nullptr;
name * quot_consts::g_quot_ind  = nullptr;
name * quot_consts::g_quot_mk   = nullptr;

static environment add_constant(environment const & env, name const & n, std::initializer_list<name> lvls, expr const & type) {
    auto cd = check(env, mk_constant_assumption(n, level_param_names(lvls), type));
    return env.add(cd);
}

static void check_eq_type(environment const & env) {
    optional<inductive::inductive_decl> decl = inductive::is_inductive_decl(env, "eq");
    if (!decl) throw exception("failed to initialize quot module, environment does not have 'eq' type");
    if (length(decl->m_level_params) != 1)
        throw exception("failed to initialize quot module, unexpected number of universe params at 'eq' type");
    level u = mk_param_univ(head(decl->m_level_params));
    expr alpha = mk_local("α", "α", mk_sort(u), mk_implicit_binder_info());
    expr expected_eq_type = Pi(alpha, mk_arrow(alpha, mk_arrow(alpha, mk_Prop())));
    if (decl->m_type != expected_eq_type)
        throw exception("failed to initialize quot module, 'eq' has an expected type");
    if (length(decl->m_intro_rules) != 1)
        throw exception("failed to initialize quot module, unexpected number of constructors for 'eq' type");
    expr a = mk_local("a", alpha);
    expr expected_eq_refl_type = Pi(alpha, Pi(a, mk_app(mk_constant("eq", {u}), alpha, a, a)));
    if (mlocal_type(head(decl->m_intro_rules)) != expected_eq_refl_type) {
        throw exception("failed to initialize quot module, unexpected type for 'eq' type constructor");
    }
}

environment quot_declare(environment const & env) {
    check_eq_type(env);
    environment new_env = env;
    name u_name("u");
    level u         = mk_param_univ(u_name);
    expr Sort_u     = mk_sort(u);
    expr alpha      = mk_local("α", "α", Sort_u, mk_implicit_binder_info());
    expr r          = mk_local("r", mk_arrow(alpha, mk_arrow(alpha, mk_Prop())));
    /* constant {u} quot {α : Sort u} (r : α → α → Prop) : Sort u */
    new_env = add_constant(new_env, *quot_consts::g_quot, {u_name}, Pi(alpha, Pi(r, Sort_u)));
    expr quot_r     = mk_app(mk_constant(*quot_consts::g_quot, {u}), alpha, r);
    expr a          = mk_local("a", alpha);
    /* constant {u} quot.mk {α : Sort u} (r : α → α → Prop) (a : α) : @quot.{u} α r */
    new_env = add_constant(new_env, *quot_consts::g_quot_mk, {u_name},
                           Pi(alpha, Pi(r, Pi(a, quot_r))));
    /* make r implicit */
    r               = mk_local("r", "r", mk_arrow(alpha, mk_arrow(alpha, mk_Prop())), mk_implicit_binder_info());
    name v_name("v");
    level v         = mk_param_univ(v_name);
    expr Sort_v     = mk_sort(v);
    expr beta       = mk_local("β", "β", Sort_v, mk_implicit_binder_info());
    expr f          = mk_local("f", mk_arrow(alpha, beta));
    expr b          = mk_local("b", alpha);
    expr r_a_b      = mk_app(r, a, b);
    /* f a = f b */
    expr f_a_eq_f_b = mk_app(mk_constant("eq", {v}), beta, mk_app(f, a), mk_app(f, b));
    /* (∀ a b : α, r a b → f a = f b) */
    expr sanity     = Pi(a, Pi(b, mk_arrow(r_a_b, f_a_eq_f_b)));
    /* constant {u v} quot.lift {α : Sort u} {r : α → α → Prop} {β : Sort v} (f : α → β)
                                : (∀ a b : α, r a b → f a = f b) →  @quot.{u} α r → β */
    new_env = add_constant(new_env, *quot_consts::g_quot_lift, {u_name, v_name},
                           Pi(alpha, Pi(r, Pi(beta, Pi(f, mk_arrow(sanity, mk_arrow(quot_r, beta)))))));
    /* {β : @quot.{u} α r → Prop} */
    beta            = mk_local("β", "β", mk_arrow(quot_r, mk_Prop()), mk_implicit_binder_info());
    expr quot_mk_a  = mk_app(mk_constant(*quot_consts::g_quot_mk, {u}), alpha, r, a);
    expr all_quot   = Pi(a, mk_app(beta, quot_mk_a));
    expr q          = mk_local("q", quot_r);
    expr beta_q     = mk_app(beta, q);
    /* constant {u} quot.ind {α : Sort u} {r : α → α → Prop} {β : @quot.{u} α r → Prop}
                   : (∀ a : α, β (@quot.mk.{u} α r a)) → ∀ q : @quot.{u} α r, β q */
    new_env = add_constant(new_env, *quot_consts::g_quot_ind, {u_name},
                           Pi(alpha, Pi(r, Pi(beta, mk_arrow(all_quot, Pi(q, beta_q))))));
    return new_env;
}

void initialize_quot() {
    quot_consts::g_quot      = new name{"quot"};
    quot_consts::g_quot_lift = new name{"quot", "lift"};
    quot_consts::g_quot_ind  = new name{"quot", "ind"};
    quot_consts::g_quot_mk   = new name{"quot", "mk"};
}

void finalize_quot() {
    delete quot_consts::g_quot;
    delete quot_consts::g_quot_lift;
    delete quot_consts::g_quot_ind;
    delete quot_consts::g_quot_mk;
}
}