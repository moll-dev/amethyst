#include <mathlib.h>
#include "mathlib_private.h"

int add(int a, int b) {
    return private_add(a, b);
}

int private_add(int a, int b) {
    return a + b;
}