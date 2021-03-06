/-
Copyright (c) 2016 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Author: Leonardo de Moura
-/
prelude
import init.data.string.basic init.data.uint init.data.nat.div init.data.repr
open Sum Subtype Nat

universes u v

class HasToString (α : Type u) :=
(toString : α → String)

export HasToString (toString)

-- This instance is needed because `id` is not reducible
instance {α : Type u} [HasToString α] : HasToString (id α) :=
inferInstanceAs (HasToString α)

instance : HasToString String :=
⟨λ s, s⟩

instance : HasToString Substring :=
⟨λ s, s.toString⟩

instance : HasToString String.Iterator :=
⟨λ it, it.remainingToString⟩

instance : HasToString Bool :=
⟨λ b, cond b "true" "false"⟩

instance {p : Prop} : HasToString (Decidable p) :=
-- Remark: type class inference will not consider local instance `b` in the new Elaborator
⟨λ b : Decidable p, @ite p b _ "true" "false"⟩

protected def List.toStringAux {α : Type u} [HasToString α] : Bool → List α → String
| b     []      := ""
| true  (x::xs) := toString x ++ List.toStringAux false xs
| false (x::xs) := ", " ++ toString x ++ List.toStringAux false xs

protected def List.toString {α : Type u} [HasToString α] : List α → String
| []      := "[]"
| (x::xs) := "[" ++ List.toStringAux true (x::xs) ++ "]"

instance {α : Type u} [HasToString α] : HasToString (List α) :=
⟨List.toString⟩

instance : HasToString Unit :=
⟨λ u, "()"⟩

instance : HasToString Nat :=
⟨λ n, repr n⟩

instance : HasToString Char :=
⟨λ c, c.toString⟩

instance (n : Nat) : HasToString (Fin n) :=
⟨λ f, toString (Fin.val f)⟩

instance : HasToString UInt8 :=
⟨λ n, toString n.toNat⟩

instance : HasToString UInt16 :=
⟨λ n, toString n.toNat⟩

instance : HasToString UInt32 :=
⟨λ n, toString n.toNat⟩

instance : HasToString UInt64 :=
⟨λ n, toString n.toNat⟩

instance : HasToString USize :=
⟨λ n, toString n.toNat⟩

instance {α : Type u} [HasToString α] : HasToString (Option α) :=
⟨λ o, match o with | none := "none" | (some a) := "(some " ++ toString a ++ ")"⟩

instance {α : Type u} {β : Type v} [HasToString α] [HasToString β] : HasToString (α ⊕ β) :=
⟨λ s, match s with | (inl a) := "(inl " ++ toString a ++ ")" | (inr b) := "(inr " ++ toString b ++ ")"⟩

instance {α : Type u} {β : Type v} [HasToString α] [HasToString β] : HasToString (α × β) :=
⟨λ ⟨a, b⟩, "(" ++ toString a ++ ", " ++ toString b ++ ")"⟩

instance {α : Type u} {β : α → Type v} [HasToString α] [s : ∀ x, HasToString (β x)] : HasToString (Sigma β) :=
⟨λ ⟨a, b⟩, "⟨"  ++ toString a ++ ", " ++ toString b ++ "⟩"⟩

instance {α : Type u} {p : α → Prop} [HasToString α] : HasToString (Subtype p) :=
⟨λ s, toString (val s)⟩
