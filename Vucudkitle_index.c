#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

// V�cut k�tle indexi hesaplayan program - Program that calculates body-mass index

/*
	Program�n a��klamas�
		
	Bod ve kilo bilgisini alarak v�cut kitle indeksini hesaplayan kitleIndeks isimli bir
	fonksiyon yaz�n�z.Yazd���n�z fonksiyonu main de �a��r�n.

	indekse g�re
	<18 zay�f, <25 normal, <30 kilolu, di�er obez.
	
*/

/*

	setlocale(LC_ALL,"Turkish"); "Benim say� format�m�, tarihimi, karakter setimi T�rk�eye g�re ayarla" demek bundan dolay�da e�er 1.80 gibi yabanc�da bir karakter gireceksen 1,80
	girmen gerekir.
	
	setlocale(LC_CTYPE,"Turkish"); ifadesi ise sadece syntax i t�rk�e yapar dolay�s�yla t�rk�e karakterleri kullanabilirsin. 
	
	
	1	
		LC_ALL
		Sets everything.

	2	
		LC_COLLATE
		Affects strcoll and strxfrm functions.

	3	
		LC_CTYPE
		Affects all character functions.
		
	4	
		LC_MONETARY
		Affects the monetary information provided by localeconv function.

	5	
		LC_NUMERIC
		Affects decimal-point formatting and the information provided by localeconv function.

	6	
		LC_TIME
		Affects the strftime function.

*/


float kitleIndeks(float,unsigned int);

int main (void)
{
	setlocale(LC_CTYPE,"Turkish"); // Affects all character functions.
	
	unsigned int kilo;
	float boy;
	
	printf("L�tfen kilonuzu(kg) giriniz: ");
	scanf("%u",&kilo);
	
	printf("L�tfen boy(m) giriniz: ");
	scanf("%f", &boy);
	
	float indeks = kitleIndeks(boy,kilo);
	
	if(indeks <= 18)
		printf("Zay�f kategorisindesiniz\n");
	
	else if(indeks <= 25)
		printf("Normal kategorisindesiniz\n");
	
	else if(indeks <= 30)
		printf("Kilolu kategorisindesiniz\n");
	
	else
		printf("Obez kategorisindesiniz\n");
	
	return 0;
}

float kitleIndeks(float boy, unsigned int kilo)
{
	
	return kilo / pow(boy,2);	
}
