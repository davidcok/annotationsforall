#include "../../../test_common.h"
#include <sys/stat.h>

void runSuccess() {
    struct stat buf;
    char path[] = "f";
    //@ assert \valid(path+(0..\block_length(path)-1));
    //@ assert \exists integer x; path[x] == '\0';
    
    stat(path, &buf);
}

void runFailure() {
    stat(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    struct stat buf;
    char path[] = "f";
    //@ assert \valid(path+(0..\block_length(path)-1));
    //@ assert \exists integer x; path[x] == '\0';
    
    result = stat(path, &buf);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
