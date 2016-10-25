#include "../../../test_common.h"
#include <string.h>
#include <wchar.h>

void runSuccess() {
    wchar_t buf[4]; buf[0] = L'A'; buf[1] = L'A'; buf[2] = L'A'; buf[3] = L'\0';
    //@ assert \valid(buf+(0..3));
    //@ assert \exists integer x; buf[x] == L'\0';
    wcschr(buf, L'?');
    wcschr(buf, L'\0');
}

void runFailure() {
    wcschr(NULL, L'H'); 
}

int f;
void testValues() {
    f = 2;
    wchar_t* result;
    
    wchar_t buf[4]; buf[0] = L'A'; buf[1] = L't'; buf[2] = L'A'; buf[3] = L'\0';
    //@ assert \valid(buf+(0..3));
    //@ assert \exists integer x; buf[x] == L'\0';
    
    result = wcschr(buf, L't');
    //@ assert result != \null ==> (\base_addr(result) == \base_addr(buf));
    //@ assert result != \null ==> *result == L't';
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
