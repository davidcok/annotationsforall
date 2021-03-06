#include "../../../test_common.h"
#include <termios.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct termios * anytermios();

/*@
assigns \result;
*/
extern speed_t anyspeed();

void runSuccess() {
    cfsetospeed(anytermios(), anyspeed());
}

void runFailure() {
    cfsetospeed(NULL, anyspeed());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = cfsetospeed(anytermios(), anyspeed());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
