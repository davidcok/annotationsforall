#include "../../../test_common.h"
#include <search.h>
#include <string.h>

void runSuccess() {
    char key[5], tab[10][5];
    size_t size = 9;
    
    lfind(key, tab, &size, 5, strcmp);
}

void runFailure1() {
    char key[5], tab[10][5];
    size_t size = 9;
    
    lfind(key, NULL, &size, 5, strcmp);
}

void runFailure2() {
    char key[5], tab[10][5];
    size_t size = 9;
    
    lfind(key, tab, NULL, 5, strcmp);
}

void runFailure3() {
    char key[5], tab[10][5];
    size_t size = 9;
    
    lfind(key, tab, &size, 5, NULL);
}

void runFailure4() {
    char key[5], tab[10][5];
    size_t size = 9;
    
    lfind(key, tab, &size, 50, strcmp);
}

int f;
void testValues() {
    f = 2;
    char* result;
    char key[5], tab[10][5];
    size_t size = 9;
    
    result = lfind(key, tab, &size, 5, strcmp);
    //@ assert result == \null || \valid(result);
    //@ assert size == 9;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}