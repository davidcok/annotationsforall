#include "../../../test_common.h"
#include <netinet/in.h>

/*@
assigns \result;
ensures \valid(\result+(0..size-1));
ensures \block_length(\result) == size;
*/
char* my_malloc(int size);

void runSuccess() {
    int len = 2;
    int room = inet6_option_space(len);
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    uint8_t * buf;
    if (!inet6_option_init(bp, &cmsg, anyint())) {
        inet6_option_find(cmsg, &buf, anyint());
    }
}

void runFailure() {
    int len = 2;
    int room = inet6_option_space(len);
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    uint8_t * buf;
    if (!inet6_option_init(bp, &cmsg, anyint())) {
        inet6_option_find(NULL, &buf, anyint());
    }
}

void runFailure1() {
    int len = 2;
    int room = inet6_option_space(len);
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    uint8_t * buf;
    if (!inet6_option_init(bp, &cmsg, anyint())) {
        inet6_option_find(cmsg, NULL, anyint());
    }
}

int f;
void testValues() {
    f = 2;
    
    int len = 2;
    int room = inet6_option_space(len);
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    uint8_t * buf;
    if (!inet6_option_init(bp, &cmsg, anyint())) {
        int result = inet6_option_find(cmsg, &buf, 42);
        //@ assert result == 0 ==> \valid(buf+(0..1));
        //@ assert result == 0 ==> \valid(buf+(2..1+buf[1]));
        //@ assert result == 0 ==> buf[0] == 42;
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
