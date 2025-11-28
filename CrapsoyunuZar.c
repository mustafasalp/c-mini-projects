#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <windows.h> // try "#include <unistd.h>" , if error encountered.

/* 
ZAR ATMA OYUNU (CRAPS) 2 Oyuncu için!

1)İki zar atılır
2)Gelen zarlar toplanır.
3)İlk atışta sonuç 7 veya 11 ise oyuncu kazanır.
4)İlk atışta 2, 3 veya 12 gelirse oyuncu kaybeder.
5)Bu durumlar oluşmazsa ilk atışta gelen sayı oyuncunun puanı oluyor. Oyuncu bu durumdan sonra kazanmak için ilk attığı zarı atmalıdır.
NOT: İlk zardan sonra 6 defa daha atacak puanını tutturamazsa kaybeder.

*/


int ilkatis_kazanma(int,int);
int ilkatis_kaybetme(int,int);

typedef struct {
	
	int puan;
	int zar1,zar2;
	char isim[50];
	char choose;
	
}Oyuncu;

Oyuncu Oyuncu1,Oyuncu2;



int main (void)
{
	setlocale(LC_ALL,"Turkish");
	srand(time(NULL));		

	printf("Kullanıcıların isimlerini sırasıyla giriniz(Oyuncu1,Oyuncu2):"); 
	fgets(Oyuncu1.isim, sizeof(Oyuncu1.isim), stdin);                         // Önce girileni alır. Sonra girileni 50 karakteri aşmayacak şekilde okur.
	Oyuncu1.isim[strcspn(Oyuncu1.isim, "\n")] = '\0';
	
	fgets(Oyuncu2.isim, sizeof(Oyuncu2.isim), stdin);  
	Oyuncu2.isim[strcspn(Oyuncu2.isim, "\n")] = '\0';
	
	printf("%s zar atsın mı(Evet için: E): ",Oyuncu1.isim);
	scanf("%c",&Oyuncu1.choose);
	
	if(Oyuncu1.choose != 'E')
	{
		printf("%s zar atışı yapmadı.\n",Oyuncu1.isim);
		return -1;
	}	
	
	else
	{
		printf("%s zar atıyor... \n",Oyuncu1.isim); sleep(2);
		
		Oyuncu1.zar1 = rand()%6 + 1;
		Oyuncu1.zar2 = rand()%6 + 1;
		
		printf("%s ZAR1: %d ZAR2: %d\n",Oyuncu1.isim,Oyuncu1.zar1,Oyuncu1.zar2);
		
		Oyuncu1.puan = Oyuncu1.zar2 + Oyuncu1.zar1;
	}
	
	
	printf("%s zar atsın mı(Evet için: E): ",Oyuncu2.isim);
	getchar();
	scanf("%c",&Oyuncu2.choose);
	
	if(Oyuncu2.choose != 'E')
	{
		printf("%s zar atışı yapmadı.\n",Oyuncu2.isim);
		return -1;
	}	
	
	else
	{
		printf("%s zar atıyor... \n",Oyuncu2.isim); sleep(2);
		
		Oyuncu2.zar1 = rand()%6 + 1;
		Oyuncu2.zar2 = rand()%6 + 1;
		
		printf("%s ZAR1: %d ZAR2: %d\n",Oyuncu2.isim,Oyuncu2.zar1,Oyuncu2.zar2);
		
		Oyuncu2.puan = Oyuncu2.zar2 + Oyuncu2.zar1;
	}
	
	int durum = ilkatis_kazanma(Oyuncu1.puan,Oyuncu2.puan);

	if(durum == 0)
		return -1;
	
	durum = ilkatis_kaybetme(Oyuncu1.puan,Oyuncu2.puan);
	
	if(durum == 0)
		return -1;	

	sleep(2);
	
	printf("İlk atışlarda kaybeden veya kazanan olmadı 2.tur başlıyor...\n");
	
	sleep(2);
	
	int hak = 5 ; 
	int o1 = -1, o2 = -1;
	
	while(hak >= 0)
	{
		
		Oyuncu1.zar1 = rand()%6 + 1;
		Oyuncu1.zar2 = rand()%6 + 1;	
		
		int gecici_puan = Oyuncu1.zar1 + Oyuncu1.zar2 ;
		
		if(gecici_puan == Oyuncu1.puan)
			o1 = hak;
		
		Oyuncu2.zar1 = rand()%6 + 1;
		Oyuncu2.zar2 = rand()%6 + 1;	
		
		gecici_puan = Oyuncu2.zar1 + Oyuncu2.zar2 ;
		
		if(gecici_puan == Oyuncu2.puan)
			o2 = hak;
		
		hak--;
	}
	
	if( o2 < o1 )
	{
		printf("%s ilk turda attığı zarı tekrar atarak %d. atışında kazandı\n",Oyuncu2.isim,o2 + 1);
	}
	
	else if( o2 > o1)
	{
		printf("%s ilk turda attığı zarı tekrar atarak %d. atışında kazandı\n",Oyuncu1.isim,o1 + 1);
	}
	
	else if( o2 == o1) 
		printf("İki oyuncu da ilk turda attığı zarları aynı anda attığı için berabere\n");
	
	else
		printf("İki oyuncu da son 6 haklarında ilk attıkları zarı tutturamadılar kazanan yok!\n");
		
	
	return 0;
	
}

int ilkatis_kazanma(int puan1,int puan2)
{
	
	int oyuncu1,oyuncu2;
	
	oyuncu1 = (puan1 == 11 || puan1 == 7) ? 1 : 0;
	oyuncu2 = (puan2 == 11 || puan2 == 7) ? 1 : 0;
	
	
	if(oyuncu1 > oyuncu2)
	{
		printf("%s 11 veya 7 atarak kazandı\n",Oyuncu1.isim);
		return 0;
	}
				
		
	else if(oyuncu2 > oyuncu1)
	{
		printf("%s 11 veya 7 atarak kazandı.\n",Oyuncu2.isim);
		return 0;
	}
			
	
	else if(oyuncu1 == 1 && oyuncu2 == 1)
	{
		printf("Her iki oyuncu da 11 veya 7 atarak kazandı\n");
		return 0;	
	}	
		
	return 1;
}

int ilkatis_kaybetme(int puan1, int puan2)
{
	int oyuncu1,oyuncu2;
	
	oyuncu1 = (puan1 == 2 || puan1 == 3 || puan1 == 12) ? 0 : 1;
	oyuncu2 = (puan2 == 2 || puan2 == 3 || puan2 == 12) ? 0 : 1;
	
	if(oyuncu1 > oyuncu2)
	{
		printf("%s kazandı çünkü %s 2, 3 veya 12 atarak kaybetti\n",Oyuncu1.isim,Oyuncu2.isim);
		return 0;
	}
				
		
	else if(oyuncu2 > oyuncu1)
	{
		printf("%s kazandı çünkü %s 2, 3 veya 12 atarak kaybetti.\n",Oyuncu2.isim,Oyuncu1.isim);
		return 0;
	}
			
	else if(oyuncu1 == 0 && oyuncu2 == 0)
	{
		printf("Her iki oyuncu da 2, 3 veya 12 atarak kaybetti\n");
		return 0;	
	}
	
	return 1;
}
