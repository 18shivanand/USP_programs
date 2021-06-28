#include<stdio.h>
#include<setjmp.h>

int function1();
int function2();

jmp_buf buf;

int main()
{
	printf("main() function is returned\n");
	int n = setjmp(buf);
	
	printf("\nn = %d\n\n", n);
	
	if(n==10)
	{
		printf("You visited function1\n");
		function2();
	}
	
	if(n==20)
	{
		printf("You visited function2\n");
	}
	
	if(n==0)
	{
		printf("Still in main() function\n");
		function1();
	}
	
	printf("Exiting main() function\n");
}

int function1()
{
	printf("You've entered function 1\n");
	printf("Exiting function1\n");
	longjmp(buf,10);
}

int function2()
{
	printf("You've entered function 2\n");
	printf("exiting function2\n");
	longjmp(buf,20);
}