#include "../../test_common.h"
#include <inttypes.h>

void runSuccess() {
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    char* ptr;

   strtoimax(buf, &ptr, 0);
}

void runSuccess1() {
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    char* ptr;

   strtoimax(buf, &ptr, 10);
}

void runSuccess2() {
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

   strtoimax(buf, NULL, 0);
}

void runFailure() {
    char* ptr;

    strtoimax(NULL, &ptr, 0);
}

void runFailure1() {
    strtoimax(NULL, NULL, 10);
}

int f;
void testValues() {
    f = 2;
    intmax_t result;
    char buf[] = "X";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    char* ptr;
    
    result = strtoimax(buf, &ptr, 0);
    //@ assert \valid(ptr);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}