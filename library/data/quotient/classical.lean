-- Copyright (c) 2014 Floris van Doorn. All rights reserved.
-- Released under Apache 2.0 license as described in the file LICENSE.
-- Author: Floris van Doorn

import struc.relation logic.classes.nonempty data.subtype
import .basic
import logic.axioms.classical logic.axioms.hilbert logic.axioms.funext

namespace quotient

open relation nonempty subtype

-- abstract quotient
-- -----------------

definition prelim_map {A : Type} (R : A → A → Prop) (a : A) :=
-- TODO: it is interesting how the elaborator fails here
-- epsilon (fun b, R a b)
@epsilon _ (nonempty.intro a) (fun b, R a b)

-- TODO: only needed R reflexive (or weaker: R a a)
theorem prelim_map_rel {A : Type} {R : A → A → Prop} (H : is_equivalence R) (a : A)
  : R a (prelim_map R a) :=
have reflR : reflexive R, from is_reflexive.infer R,
epsilon_spec (exists_intro a (reflR a))

-- TODO: only needed: R PER
theorem prelim_map_congr {A : Type} {R : A → A → Prop} (H1 : is_equivalence R) {a b : A}
  (H2 : R a b) : prelim_map R a = prelim_map R b :=
have symmR : symmetric R, from is_symmetric.infer R,
have transR : transitive R, from is_transitive.infer R,
have H3 : ∀c, R a c ↔ R b c, from
  take c,
    iff.intro
      (assume H4 : R a c, transR (symmR H2) H4)
      (assume H4 : R b c, transR H2 H4),
have H4 : (fun c, R a c) = (fun c, R b c), from funext (take c, iff_to_eq (H3 c)),
show @epsilon _ (nonempty.intro a) (λc, R a c) = @epsilon _ (nonempty.intro b) (λc, R b c),
  from congr_arg _ H4

definition quotient {A : Type} (R : A → A → Prop) : Type := image (prelim_map R)

definition quotient_abs {A : Type} (R : A → A → Prop) : A → quotient R :=
fun_image (prelim_map R)

definition quotient_elt_of {A : Type} (R : A → A → Prop) : quotient R → A := elt_of

-- TODO: I had to make is_quotient transparent -- change this?
theorem quotient_is_quotient  {A : Type} (R : A → A → Prop) (H : is_equivalence R)
  : is_quotient R (quotient_abs R) (quotient_elt_of R) :=
representative_map_to_quotient_equiv
  H
  (prelim_map_rel H)
  (@prelim_map_congr _ _ H)

end quotient
