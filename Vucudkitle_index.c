#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

// Vücut kütle indexi hesaplayan program - Program that calculates body-mass index

/*
	Programýn açýklamasý
		
	Bod ve kilo bilgisini alarak vücut kitle indeksini hesaplayan kitleIndeks isimli bir
	fonksiyon yazýnýz.Yazdýðýnýz fonksiyonu main de çaðýrýn.

	indekse göre
	<18 zayýf, <25 normal, <30 kilolu, diðer obez.
	
*/

/*

	setlocale(LC_ALL,"Turkish"); "Benim sayý formatýmý, tarihimi, karakter setimi Türkçeye göre ayarla" demek bundan dolayýda eðer 1.80 gibi yabancýda bir karakter gireceksen 1,80
	girmen gerekir.
	
	setlocale(LC_CTYPE,"Turkish"); ifadesi ise sadece syntax i türkçe yapar dolayýsýyla türkçe karakterleri kullanabilirsin. 
	
	
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
	
	printf("Lütfen kilonuzu(kg) giriniz: ");
	scanf("%u",&kilo);
	
	printf("Lütfen boy(m) giriniz: ");
	scanf("%f", &boy);
	
	float indeks = kitleIndeks(boy,kilo);
	
	if(indeks <= 18)
		printf("Zayýf kategorisindesiniz\n");
	
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
