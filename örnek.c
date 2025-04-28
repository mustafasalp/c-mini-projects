#include <stdio.h>
#include <stdlib.h>

//KULLANICIDAN ALINAN SAYI KADAR TABANI OLAN , YILDIZLAR ARACILIÐIYLA ÜÇGEN ÇÝZEN RECURSÝVE PROGRAM.
//A RECURSIVE PROGRAM THAT DRAWS A TRIANGLE MADE OF ASTERISKS, WITH A BASE LENGTH EQUAL TO THE NUMBER ENTERED BY THE USER.

//Hiç bir  yardým almadým, kendim yazdým.
//No support received, Write it on my own.

void triangle(int,int);

int main (void)
{
	int number;
	
	printf("Enter a number to calculate the sum of 1 to n: ");
	scanf("%d",&number);
	
	int temp = number;
	
	triangle(number, temp);
	
	return 0;
}

void triangle(int number,int temp)
{
	int i = 0;
	
	if(number == 0)
		return;
	
	for(i ; i <= temp - number ; i++)
	{
		printf("* ");	
	}	
	
	puts("");
	
	triangle(number - 1, temp);
 }
