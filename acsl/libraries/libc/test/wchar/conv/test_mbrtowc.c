#include "../../../test_common.h"
#include <wchar.h>
#include <errno.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern mbstate_t* anystate();

void runSuccess() {
    wchar_t s1[4]; s1[0] = L'A'; s1[1] = L'A'; s1[2] = L'A'; s1[3] = L'\0';
    char s2[] = "BBB";
    //@ assert \valid(s1+(0..3));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    mbrtowc(s1, s2, 3, anystate());
    mbrtowc(NULL, s2, 3, anystate());
}

void runSuccess1() {
    mbrtowc(NULL, NULL, anysize(), anystate());
    mbrtowc(NULL, NULL, anysize(), NULL);
}

int f;
void testValues() {
    f = 2;
    size_t result;
    
    wchar_t s1[4]; s1[0] = L'A'; s1[1] = L'A'; s1[2] = L'A'; s1[3] = L'\0';
    char s2[] = "BBB";
    //@ assert \valid(s1+(0..3));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    result = mbrtowc(s1, s2, 3, anystate());
    //@ assert  0 <= result <= 4 || result == (size_t)(-1) || result == (size_t)(-2);
    //@ assert result == (size_t)(-1) ==> errno != 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
