#include <stdio.h>

int main()
{
    char rawChar1, rawChar2, pChar1, pChar2;
    printf("Input: ");
    scanf("%c %c", &rawChar1, &rawChar2);

    pChar1 = (rawChar1<='z' && rawChar1>='a')?(rawChar1 - ('a' - 'A')):rawChar1;
    pChar2 = (rawChar2<='z' && rawChar2>='a')?(rawChar2 - ('a' - 'A')):rawChar2;

    printf("Output: ");

    if(pChar1<='Z' && pChar1>='A' && pChar2<='Z' && pChar2>='A')
        printf("%c %c\n", pChar1>pChar2?rawChar2:rawChar1, pChar1<=pChar2?rawChar2:rawChar1);
    else if(pChar1>'Z' || pChar1<'A')
    {
        if(pChar2>'Z' || pChar2<'A')
            printf("%c and %c both are not an English letter.\n", rawChar1, rawChar2);
        else
            printf("%c is not an English letter.\n", rawChar1);
    }
    else
        printf("%c is not an English letter.\n", rawChar2);

    return 0;
}
