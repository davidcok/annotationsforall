#include "../../../test_common.h"
#include <string.h>
#include <wchar.h>

wchar_t* buf;

void runSuccess() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L's'; s2[1] = L'2'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \valid(s2+(0..2));
    
    wmemmove(s1, s2, 2);
}

void runSuccess1() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L's'; s2[1] = L'2'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \valid(s2+(0..2));
    
    wmemmove(s1, s2, 1);
}

void runSuccess2() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    
    wmemmove(s1, s1, 2);
}

void runFailure() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    wmemmove(s1, NULL, 2);
}

void runFailure1() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    wmemmove(NULL, s1, 1);
}

void runFailure2() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L's'; s2[1] = L'2'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \valid(s2+(0..2));
    
    wmemmove(s1, s2, 20);
}

int f;
void testValues() {
    f = 2;
    wchar_t* result;
    
    wchar_t s1[3]; s1[0] = L'A'; s1[1] = L'A'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L'V'; s2[1] = L'\0'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \valid(s2+(0..2));
    
    result = wmemmove(s1, s2, 1);
    //@ assert result == s1;

    int cmp = wmemcmp(s1, s2, 1);
    //@ assert cmp == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
