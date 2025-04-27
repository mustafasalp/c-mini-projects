#include <stdio.h>
#include <stdlib.h>

// Verilen iki say�n�n EBOB(en b�y�k ortak b�len) lerini bulma
// Finding the GCD (Greatest Common Divisor) of two given numbers.
// OBEB : iki say�n�n en b�y�k ortak b�lenidir 2 ve 8 i�in "2" dir.

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
