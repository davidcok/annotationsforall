#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    char buf[] = "net";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    getprotobyname(buf);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct protoent * result;
    
    char buf[] = "net";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = getprotobyname(buf);
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
