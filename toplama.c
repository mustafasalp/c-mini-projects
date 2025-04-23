#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Recursive toplama programý.

int toplama(int);
int basamak_toplama(int);


int main (void)
{

	setlocale(LC_ALL,"Turkish");

	unsigned int number1;
	int number2;
	
	printf("0 dan sayýya kadar toplanmasýný istediðiniz sayýyý giriniz:");
	scanf("%u",&number1);
	
	printf("%d",toplama(number1));
	
	puts("");
	
	printf("Basamaklarýnýn toplanmasýný istediðiniz sayýyý giriniz: ");
	scanf("%d",&number2);
	 
	printf("%d",basamak_toplama(number2));
		
		
	return 0;	
}

int toplama(int n1)
{
	
	if(n1 > 0)
		return n1 + toplama(n1 - 1);
	
	return 0;
}

int basamak_toplama(int n2)
{
	
	if(n2 > 0)
		return (n2 % 10) + basamak_toplama(n2 / 10);
	
	return 0;
}

