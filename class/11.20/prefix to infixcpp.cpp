#include <stdio.h>
#include <ctype.h>

int calculate(void);

int main(void)
{
    printf("%d\n", calculate());
    return 0;
}

int calculate(void)
{
    char c;		//or int c;
    int ans;
    int op1, op2;

    c = getchar();
    if (isspace(c)) {
        ans = calculate();
    } else if (c=='+') {
        op1 = calculate();
        op2 = calculate();
        ans = op1 + op2;
    } else if (c=='-') {
        op1 = calculate();
        op2 = calculate();
        ans = op1 - op2;
    } else if (c=='*') {
        op1 = calculate();
        op2 = calculate();
        ans = op1 * op2;
    } else if (isdigit(c)) {
        ungetc(c, stdin);
        scanf("%d", &ans);
    }

    return ans;
}
