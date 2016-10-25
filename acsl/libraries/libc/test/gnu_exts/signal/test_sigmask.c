#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    sigmask(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    sigmask(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
