// Lean compiler output
// Module: init.data.ordering.basic
// Imports: init.data.repr
#include "runtime/object.h"
#include "runtime/apply.h"
#include "runtime/io.h"
#include "kernel/builtin.h"
typedef lean::object obj;
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#endif
unsigned char l_ordering_or__else(unsigned char, unsigned char);
obj* l_ordering_has__repr___boxed(obj*);
obj* l_ordering_swap___main___boxed(obj*);
unsigned char l_ordering_or__else___main(unsigned char, unsigned char);
unsigned char l_ordering_swap(unsigned char);
unsigned char l_ordering_swap___main(unsigned char);
obj* l_cmp(obj*, obj*);
obj* l_cmp__using(obj*, obj*);
obj* l_ordering_has__repr___closed__3;
obj* l_ordering_or__else___main___boxed(obj*, obj*);
obj* l_cmp__using___rarg___boxed(obj*, obj*, obj*);
unsigned char l_cmp___rarg(obj*, obj*, obj*);
obj* l_ordering_has__repr(unsigned char);
obj* l_ordering_swap___boxed(obj*);
obj* l_ordering_decidable__eq(unsigned char, unsigned char);
obj* l_ordering_or__else___boxed(obj*, obj*);
obj* l_ordering_has__repr___closed__1;
obj* l_ordering_has__repr___closed__2;
unsigned char l_cmp__using___rarg(obj*, obj*, obj*);
obj* l_ordering_decidable__eq___boxed(obj*, obj*);
obj* l_cmp___rarg___boxed(obj*, obj*, obj*);
obj* l_ordering_has__repr(unsigned char x_0) {
_start:
{
switch (x_0) {
case 0:
{
obj* x_1; 
x_1 = l_ordering_has__repr___closed__1;
lean::inc(x_1);
return x_1;
}
case 1:
{
obj* x_3; 
x_3 = l_ordering_has__repr___closed__2;
lean::inc(x_3);
return x_3;
}
default:
{
obj* x_5; 
x_5 = l_ordering_has__repr___closed__3;
lean::inc(x_5);
return x_5;
}
}
}
}
obj* _init_l_ordering_has__repr___closed__1() {
_start:
{
obj* x_0; 
x_0 = lean::mk_string("lt");
return x_0;
}
}
obj* _init_l_ordering_has__repr___closed__2() {
_start:
{
obj* x_0; 
x_0 = lean::mk_string("eq");
return x_0;
}
}
obj* _init_l_ordering_has__repr___closed__3() {
_start:
{
obj* x_0; 
x_0 = lean::mk_string("gt");
return x_0;
}
}
obj* l_ordering_has__repr___boxed(obj* x_0) {
_start:
{
unsigned char x_1; obj* x_2; 
x_1 = lean::unbox(x_0);
x_2 = l_ordering_has__repr(x_1);
return x_2;
}
}
unsigned char l_ordering_swap___main(unsigned char x_0) {
_start:
{
switch (x_0) {
case 0:
{
unsigned char x_1; 
x_1 = 2;
return x_1;
}
case 1:
{
return x_0;
}
default:
{
unsigned char x_2; 
x_2 = 0;
return x_2;
}
}
}
}
obj* l_ordering_swap___main___boxed(obj* x_0) {
_start:
{
unsigned char x_1; unsigned char x_2; obj* x_3; 
x_1 = lean::unbox(x_0);
x_2 = l_ordering_swap___main(x_1);
x_3 = lean::box(x_2);
return x_3;
}
}
unsigned char l_ordering_swap(unsigned char x_0) {
_start:
{
unsigned char x_1; 
x_1 = l_ordering_swap___main(x_0);
return x_1;
}
}
obj* l_ordering_swap___boxed(obj* x_0) {
_start:
{
unsigned char x_1; unsigned char x_2; obj* x_3; 
x_1 = lean::unbox(x_0);
x_2 = l_ordering_swap(x_1);
x_3 = lean::box(x_2);
return x_3;
}
}
unsigned char l_ordering_or__else___main(unsigned char x_0, unsigned char x_1) {
_start:
{
switch (x_0) {
case 0:
{
return x_0;
}
case 1:
{
return x_1;
}
default:
{
return x_0;
}
}
}
}
obj* l_ordering_or__else___main___boxed(obj* x_0, obj* x_1) {
_start:
{
unsigned char x_2; unsigned char x_3; unsigned char x_4; obj* x_5; 
x_2 = lean::unbox(x_0);
x_3 = lean::unbox(x_1);
x_4 = l_ordering_or__else___main(x_2, x_3);
x_5 = lean::box(x_4);
return x_5;
}
}
unsigned char l_ordering_or__else(unsigned char x_0, unsigned char x_1) {
_start:
{
unsigned char x_2; 
x_2 = l_ordering_or__else___main(x_0, x_1);
return x_2;
}
}
obj* l_ordering_or__else___boxed(obj* x_0, obj* x_1) {
_start:
{
unsigned char x_2; unsigned char x_3; unsigned char x_4; obj* x_5; 
x_2 = lean::unbox(x_0);
x_3 = lean::unbox(x_1);
x_4 = l_ordering_or__else(x_2, x_3);
x_5 = lean::box(x_4);
return x_5;
}
}
unsigned char l_cmp__using___rarg(obj* x_0, obj* x_1, obj* x_2) {
_start:
{
obj* x_6; 
lean::inc(x_2);
lean::inc(x_1);
lean::inc(x_0);
x_6 = lean::apply_2(x_0, x_1, x_2);
if (lean::obj_tag(x_6) == 0)
{
obj* x_8; 
lean::dec(x_6);
x_8 = lean::apply_2(x_0, x_2, x_1);
if (lean::obj_tag(x_8) == 0)
{
unsigned char x_10; 
lean::dec(x_8);
x_10 = 1;
return x_10;
}
else
{
unsigned char x_12; 
lean::dec(x_8);
x_12 = 2;
return x_12;
}
}
else
{
unsigned char x_17; 
lean::dec(x_0);
lean::dec(x_1);
lean::dec(x_2);
lean::dec(x_6);
x_17 = 0;
return x_17;
}
}
}
obj* l_cmp__using(obj* x_0, obj* x_1) {
_start:
{
obj* x_4; 
lean::dec(x_1);
lean::dec(x_0);
x_4 = lean::alloc_closure(reinterpret_cast<void*>(l_cmp__using___rarg___boxed), 3, 0);
return x_4;
}
}
obj* l_cmp__using___rarg___boxed(obj* x_0, obj* x_1, obj* x_2) {
_start:
{
unsigned char x_3; obj* x_4; 
x_3 = l_cmp__using___rarg(x_0, x_1, x_2);
x_4 = lean::box(x_3);
return x_4;
}
}
unsigned char l_cmp___rarg(obj* x_0, obj* x_1, obj* x_2) {
_start:
{
obj* x_6; 
lean::inc(x_2);
lean::inc(x_1);
lean::inc(x_0);
x_6 = lean::apply_2(x_0, x_1, x_2);
if (lean::obj_tag(x_6) == 0)
{
obj* x_8; 
lean::dec(x_6);
x_8 = lean::apply_2(x_0, x_2, x_1);
if (lean::obj_tag(x_8) == 0)
{
unsigned char x_10; 
lean::dec(x_8);
x_10 = 1;
return x_10;
}
else
{
unsigned char x_12; 
lean::dec(x_8);
x_12 = 2;
return x_12;
}
}
else
{
unsigned char x_17; 
lean::dec(x_0);
lean::dec(x_1);
lean::dec(x_2);
lean::dec(x_6);
x_17 = 0;
return x_17;
}
}
}
obj* l_cmp(obj* x_0, obj* x_1) {
_start:
{
obj* x_4; 
lean::dec(x_1);
lean::dec(x_0);
x_4 = lean::alloc_closure(reinterpret_cast<void*>(l_cmp___rarg___boxed), 3, 0);
return x_4;
}
}
obj* l_cmp___rarg___boxed(obj* x_0, obj* x_1, obj* x_2) {
_start:
{
unsigned char x_3; obj* x_4; 
x_3 = l_cmp___rarg(x_0, x_1, x_2);
x_4 = lean::box(x_3);
return x_4;
}
}
obj* l_ordering_decidable__eq(unsigned char x_0, unsigned char x_1) {
_start:
{
switch (x_0) {
case 0:
{
switch (x_1) {
case 0:
{
obj* x_2; 
x_2 = lean::alloc_cnstr(1, 0, 0);
;
return x_2;
}
case 1:
{
obj* x_3; 
x_3 = lean::alloc_cnstr(0, 0, 0);
;
return x_3;
}
default:
{
obj* x_4; 
x_4 = lean::alloc_cnstr(0, 0, 0);
;
return x_4;
}
}
}
case 1:
{
switch (x_1) {
case 0:
{
obj* x_5; 
x_5 = lean::alloc_cnstr(0, 0, 0);
;
return x_5;
}
case 1:
{
obj* x_6; 
x_6 = lean::alloc_cnstr(1, 0, 0);
;
return x_6;
}
default:
{
obj* x_7; 
x_7 = lean::alloc_cnstr(0, 0, 0);
;
return x_7;
}
}
}
default:
{
switch (x_1) {
case 0:
{
obj* x_8; 
x_8 = lean::alloc_cnstr(0, 0, 0);
;
return x_8;
}
case 1:
{
obj* x_9; 
x_9 = lean::alloc_cnstr(0, 0, 0);
;
return x_9;
}
default:
{
obj* x_10; 
x_10 = lean::alloc_cnstr(1, 0, 0);
;
return x_10;
}
}
}
}
}
}
obj* l_ordering_decidable__eq___boxed(obj* x_0, obj* x_1) {
_start:
{
unsigned char x_2; unsigned char x_3; obj* x_4; 
x_2 = lean::unbox(x_0);
x_3 = lean::unbox(x_1);
x_4 = l_ordering_decidable__eq(x_2, x_3);
return x_4;
}
}
void initialize_init_data_repr();
static bool _G_initialized = false;
void initialize_init_data_ordering_basic() {
 if (_G_initialized) return;
 _G_initialized = true;
 initialize_init_data_repr();
 l_ordering_has__repr___closed__1 = _init_l_ordering_has__repr___closed__1();
 l_ordering_has__repr___closed__2 = _init_l_ordering_has__repr___closed__2();
 l_ordering_has__repr___closed__3 = _init_l_ordering_has__repr___closed__3();
}