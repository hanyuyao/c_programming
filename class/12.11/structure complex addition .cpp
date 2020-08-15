#include <stdio.h>

typedef struct t_complex {
    double r;
    double i;
} Complex;

/*
	complex a, b;
	complex *t;
	
	a的r : a.r 
	a的i : a.i
	
	t(pointer)的r : (*t).r   可寫成t->r 
*/

void add(Complex a, Complex b, Complex *t)
{
    t->r = a.r+b.r;
    t->i = a.i+b.i;
}
void set_complex(Complex *p, double r, double i)
{
    p->r = r;
    p->i = i;
}
void show_complex(Complex t)
{
    printf("%.2f%+.2fi\n", t.r, t.i);
}

int main(void)
{
    Complex x, y, z;
    set_complex(&x, 1, 2);
    set_complex(&y, 2, -3);
    add(x, y, &z);
    show_complex(z);

    return 0;
}
