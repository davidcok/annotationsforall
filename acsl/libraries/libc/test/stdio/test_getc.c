#include "../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        getc(file);
    }
}

void runFailure() {
    getc(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = getc(file);
        //@ assert result == EOF || (unsigned char)result == result;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
