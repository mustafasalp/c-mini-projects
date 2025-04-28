#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Usage of pointer array.

int main (void)
{
	setlocale(LC_CTYPE,"Turkish");
	
	
	char *Ptr_ilkbahar[] = {"mart","nisan", "mayýs"};
	char *Ptr_yaz[] = {"haziran","temmuz", "aðustos"};                            //BUNLAR HER BÝRÝ KARAKTER TUTAN POÝNTER ARRAYÝ
	char *Ptr_kis[] = {"aralýk", "ocak", "þubat"};	
	char *Ptr_sonbahar[] = {"eylül", "ekim", "kasým"};
	
	char* *PtrMevsimler[4]; //BU DÝZÝ POÝNTERLARI POÝNTER TUTARLAR(POINTERLARIN TUTTUKLARI POINTERLAR DA KARAKTER TUTARLAR).
	
	PtrMevsimler[0] = Ptr_ilkbahar; // ilk pointer mart ayýný tutan pointerý tutsun
	PtrMevsimler[1] = Ptr_yaz; 		// ikinci pointer haziran ayýný tutan pointerý tutsun
	PtrMevsimler[2] = Ptr_sonbahar; 		// üçüncü pointer aralýk ayýný tutan pointerý tutsun
	PtrMevsimler[3] = Ptr_kis; // dördüncü pointer eylül ayýný tutan pointerý tutsun

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
