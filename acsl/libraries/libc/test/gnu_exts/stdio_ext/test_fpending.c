#include "../../../stdio_common.h"
#include <stdio_ext.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        __fpending(file);
    }
}

void runFailure() {
    __fpending(NULL);
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        __fpending(file);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}