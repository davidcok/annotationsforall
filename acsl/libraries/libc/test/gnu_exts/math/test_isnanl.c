#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    isnanl(anylongdouble());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;

    int result;
    result = isnanl(0.0L);
    //@ assert result == 0;
    result = isnanl(-5.0L);
    //@ assert result == 0;
    result = isnanl(3e20L);
    //@ assert result == 0;
    result = isnanl(nanl(NULL));
    //@ assert result != 0;
    result = isnanl(HUGE_VALL);
    //@ assert result == 0;
    //result = isnanl(-HUGE_VALL);
    ////@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}