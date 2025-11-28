#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <stdbool.h>
#define SIZE 50

// MATRÝSLERÝN TOPLANMASI VE SONUCUN GERÝ DÖNDÜRÜLMESÝ.
// MATRÝSLERÝN SIZEZERI AYNI OLMALI, ÇARPMADA FARKLI OLABÝLÝR.

int matrix3[SIZE][SIZE];

bool check(int,int,int,int);

int * matrixaddition(int,int,int,int);

int main (void)
{
	setlocale(LC_ALL,"Turkish");
	
	int satir1,sutun1,satir2,sutun2;
	
	printf("Matrix 1' in satýr ve sütun boyutlarýný sýrasýyla giriniz\n");
	scanf("%d%d",&satir1,&sutun1);
	
	puts("");
	
	printf("Matrix 2' in satýr ve sütun boyutlarýný sýrasýyla giriniz\n");
	scanf("%d%d",&satir2,&sutun2);
	
	int *mPtr = matrixaddition(satir1,sutun1,satir2,sutun2);
	
	if(mPtr == NULL)
	{
		printf("\nERROR - Sizes are not suitable try again\n");	
		return -1;
	} 
	
	printf("\nMatrix 3(matrix1 + matrix2): \n");
	
	int i,j = 0;
	
	for(i = 0 ; i < satir1  ; i++)
	{
		for(j = 0; j < sutun1 ; j++)
		{
			printf("%3d ",*mPtr);
			mPtr++;
		}	
		mPtr += (SIZE - satir1); 	
		puts("");
	}
	
	return 0;
}

bool check(int satir1, int sutun1, int satir2, int sutun2)
{
	if((satir1 == satir2) && (sutun1 == sutun2))
		return true;
	
	return false;
}

int * matrixaddition(int satir1, int sutun1, int satir2, int sutun2)
{

	bool is_suitable = check(satir1, sutun1, satir2, sutun2);
	
	if(!(is_suitable))
		return NULL; 
	
	int matrix1[satir1][sutun1];
	int matrix2[satir2][sutun2];
	
	printf("\nMatrix 1'in bilgilerini giriniz: \n");
	
	int i,j;
	
	for(i = 0 ; i < satir1 ; i++)
	{
		
		for(j = 0 ; j < sutun1 ; j++)
		{
			printf("Matrix 1'in %d.satýr %d.sütun bilgisi: ",i,j);
			scanf("%d",&matrix1[i][j]);
		}
	}	
	
	printf("Matrix 1'in bilgilerin alýndý\n\n");
	
	printf("Matrix 2'in bilgilerini giriniz: \n");
	
	for(i = 0 ; i < satir1 ; i++)
	{
		
		for(j = 0 ; j < sutun1 ; j++)
		{
			printf("Matrix 2'in %d.satýr %d.sütun bilgisi: ",i,j);
			scanf("%d",&matrix2[i][j]);
		}
		
	} 
	
	printf("Matrix 2'in bilgilerin alýndý\n\n");
	
	for(i = 0 ; i < satir1 ; i++)
	{
		
		for(j = 0 ; j < sutun1 ; j++)
		{
			matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
		}
		
	}
	
	return &matrix3[0][0];	
}
