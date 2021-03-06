#include "../../../test_common.h"
#include <netinet/in.h>

/*@
assigns \result;
ensures \valid(\result+(0..size-1));
*/
char* my_malloc(int size);

void runSuccess() {
    int room = inet6_option_space(anyint());
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    inet6_option_init(bp, &cmsg, anyint());
}

void runFailure() {
    int room = inet6_option_space(anyint());
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    inet6_option_init(NULL, &cmsg, anyint());
}

void runFailure1() {
    int room = inet6_option_space(anyint());
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    inet6_option_init(bp, NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    int room = inet6_option_space(anyint());
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    int result = inet6_option_init(bp, &cmsg, anyint());
    //@ assert result == 0 ==> \valid(cmsg);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
