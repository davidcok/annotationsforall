#include "../../../test_common.h"
#include <sys/uio.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct iovec * anyiov();

void runSuccess() {
    readv(anyint(), anyiov(), 1);
}

void runFailure() {
    readv(anyint(), NULL, 1);
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    
    result = readv(anyint(), anyiov(), 1);
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
