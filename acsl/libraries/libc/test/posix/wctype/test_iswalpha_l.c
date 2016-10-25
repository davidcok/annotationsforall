#include "../../../test_common.h"
#include <wctype.h>
#include <wchar.h>


/*@
assigns \result;
*/
extern wchar_t anychar();
/*@
assigns \result;
ensures (wchar_t)\result != \result && \result != WEOF;
*/
extern wint_t invalid();

/*@
assigns \result;
*/
extern locale_t locale();

void runSuccess() {
    iswalpha_l(WEOF, locale());
    iswalpha_l(anychar(), locale());
}

void runFailure() {
    iswalpha_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = iswalpha_l(anychar(), locale());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


