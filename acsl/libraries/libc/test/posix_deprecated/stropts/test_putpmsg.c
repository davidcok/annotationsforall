#include "../../../test_common.h"
#include <stropts.h>

void runSuccess() {
    putpmsg(anyint(), NULL, NULL, anyint(), anyint());
}

void runSuccess1() {
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    struct strbuf ctlbuf;
    ctlbuf.buf = buf;
    ctlbuf.len = 2;

    putpmsg(anyint(), &ctlbuf, NULL, anyint(), anyint());
}

void runSuccess2() {
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    struct strbuf databuf;
    databuf.buf = buf;
    databuf.len = 2;

    putpmsg(anyint(), NULL, &databuf, anyint(), anyint());
}

void runSuccess3() {
    char buf1[] = "1";

    //@ assert \valid(buf1+(0..\block_length(buf1)-1));
    //@ assert \exists integer x; buf1[x] == '\0';

    char buf2[] = "2";

    //@ assert \valid(buf2+(0..\block_length(buf2)-1));
    //@ assert \exists integer x; buf2[x] == '\0';

    struct strbuf databuf;
    databuf.buf = buf1;
    databuf.len = 2;

    struct strbuf ctlbuf;
    ctlbuf.buf = buf2;
    ctlbuf.len = 2;

    putpmsg(anyint(), &ctlbuf, &databuf, anyint(), anyint());
}

void runFailure() {
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    struct strbuf ctlbuf;
    ctlbuf.buf = buf;
    ctlbuf.len = 9001;

    putpmsg(anyint(), &ctlbuf, NULL, anyint(), anyint());
}

void runFailure1() {
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    struct strbuf databuf;
    databuf.buf = buf;
    databuf.len = 9001;

    putpmsg(anyint(), NULL, &databuf, anyint(), anyint());
}

int f;
void testValues() {
    f = 2;

    char buf1[] = "1";

    //@ assert \valid(buf1+(0..\block_length(buf1)-1));
    //@ assert \exists integer x; buf1[x] == '\0';

    char buf2[] = "2";

    //@ assert \valid(buf2+(0..\block_length(buf2)-1));
    //@ assert \exists integer x; buf2[x] == '\0';

    struct strbuf databuf;
    databuf.buf = buf1;
    databuf.len = 2;

    struct strbuf ctlbuf;
    ctlbuf.buf = buf2;
    ctlbuf.len = 2;

    putpmsg(anyint(), &ctlbuf, &databuf, anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}