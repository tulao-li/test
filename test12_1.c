#include "test12_1.h"

void test()
{
    struct LinkNode*header = Init_LinkNode();

    InsertByValue(header,6,666);
    DeletByValue(header,5);
    forlistnode(header);
}

int main()
{
    test();
    return 0;
}