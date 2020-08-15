#include <stdio.h>
#include <ctype.h>

double calculate(void);

int main()
{
	printf("%.3f\n", calculate());
	return 0;
}

double calculate(void)
{
	char c;
	double ans;
	double op1, op2;
	c = getchar();
	
	if(c == '+'){
		op1 = calculate();
		op2 = calculate();
		ans = op1+op2;
	}
	else if(c == '-'){
		op1 = calculate();
		op2 = calculate();
		ans = op1-op2;
	}
	else if(c == '*'){
		op1 = calculate();
		op2 = calculate();
		ans = op1*op2;
	}
	else if(c == '/'){
		op1 = calculate();
		op2 = calculate();
		ans = op1/op2;
	}
	else if(isdigit(c)){
		ans = c-'0';
	}
	
    return ans;
}
