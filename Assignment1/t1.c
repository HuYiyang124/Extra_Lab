#include <stdio.h>

int main(){
    int i = 0, j = 5, k = 4;
    char ch;
    float f;
    scanf("%c", &ch);
    printf("%d is the ASCII code of '%c'\n", ch,  ch);
    printf("the value of i is %d\n", i);
    i = ch;
    printf("the value of i is %d\n", i);
    f = (float)j/k;
    printf("the value of f is %d\n", f);

    return 0;
}
/*
 (1) The first error is the scanf less a &
 The second error is in the forth printf, 
 cann't use %d to print a float variable
 The third error is the last two printf less the ;
*/
/*
 (2) It has two warnning 
 The first warnning is the main function have not a type
 it need add a int and add a return value
 The second warnning is in the second printf 
 i is not initilized, but the function directly output it
*/
