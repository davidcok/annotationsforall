#include "../../../test_common.h"
#include <wctype.h>
#include <wchar.h>

/*@
assigns \result;
*/
extern locale_t locale();

void runSuccess() {
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctype_l(buf, locale());
}

void runFailure() {
    wctype_l(NULL, locale());
}

int f;
void testValues() {
    f = 2;
    wctype_t result;

    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctype_l(buf, locale());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
