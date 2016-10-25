#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    char buf[10];
    mlock2(buf, 10, anyint());
}

void runFailure() {
    mlock2(NULL, 10, anyint());
}

void runFailure1() {
    char buf[10];
    mlock2(buf, 30, anyint());
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    mlock2(buf, 10, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
