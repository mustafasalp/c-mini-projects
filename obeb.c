#include <stdio.h>
#include <stdlib.h>

// Verilen iki sayýnýn EBOB(en büyük ortak bölen) lerini bulma
// Finding the GCD (Greatest Common Divisor) of two given numbers.
// OBEB : iki sayýnýn en büyük ortak bölenidir 2 ve 8 için "2" dir.

int obeb(int,int);

int main (void)
{
	int n1,n2;

	printf("Enter two numbers respectively: ");
	scanf("%d%d",&n1,&n2);

	printf("GCD-OBEB of these values: %d",obeb(n1,n2));
	
	return 0;
}

// Ezberleyebilirsin :*)

int obeb(int n1 ,int n2)
{
	if(n2 != 0)
		obeb(n2, n1%n2);
	
	else
		return n1;	

	return;
}
