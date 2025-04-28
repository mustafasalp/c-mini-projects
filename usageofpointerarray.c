#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Usage of pointer array.

int main (void)
{
	setlocale(LC_CTYPE,"Turkish");
	
	
	char *Ptr_ilkbahar[] = {"mart","nisan", "may�s"};
	char *Ptr_yaz[] = {"haziran","temmuz", "a�ustos"};                            //BUNLAR HER B�R� KARAKTER TUTAN PO�NTER ARRAY�
	char *Ptr_kis[] = {"aral�k", "ocak", "�ubat"};	
	char *Ptr_sonbahar[] = {"eyl�l", "ekim", "kas�m"};
	
	char* *PtrMevsimler[4]; //BU D�Z� PO�NTERLARI PO�NTER TUTARLAR(POINTERLARIN TUTTUKLARI POINTERLAR DA KARAKTER TUTARLAR).
	
	PtrMevsimler[0] = Ptr_ilkbahar; // ilk pointer mart ay�n� tutan pointer� tutsun
	PtrMevsimler[1] = Ptr_yaz; 		// ikinci pointer haziran ay�n� tutan pointer� tutsun
	PtrMevsimler[2] = Ptr_sonbahar; 		// ���nc� pointer aral�k ay�n� tutan pointer� tutsun
	PtrMevsimler[3] = Ptr_kis; // d�rd�nc� pointer eyl�l ay�n� tutan pointer� tutsun

	int i,j;
	
	int i_size = sizeof(Ptr_ilkbahar) / sizeof(Ptr_ilkbahar[0]);
	int j_size = sizeof(PtrMevsimler) / sizeof(*Ptr_ilkbahar);	
	
	
	for(i = 0 ; i < j_size  ; i++)
	{

		for(j = 0 ; j < i_size ; j++)
		{ 
			printf("%s\t",PtrMevsimler[i][j]);
		}
	
		puts("");		
	}


	return 0;
}
