#include <stdio.h>
#include <stdlib.h>

// Using pointers as arrays by dynamic memory management.
// dinamik bellek y�netimi ile pointerlerin diziler gibi kullan�m� 	

int * combine(int *, int *, int, int);

int main (void)
{
	
	int *Ptr1, *Ptr2, *Ptr3;
	int length1, length2;
	int sum = 0;
	
	printf("Enter the length of first and second memory region respectively: ");
	scanf("%d%d",&length1,&length2);	
	
	Ptr1 = (int *) malloc(length1 * sizeof(int));   // Bu k�s�mda Ptr1, ve Ptr2 malloc'un bellekten ay�rd��� yerleri girilen boyuta g�re ba�takini tutuyor.
	Ptr2 = (int *) malloc(length2 * sizeof(int)); 
	  
	int i;
	
	printf("Enter first memory region's  values respectively: \n");
	
	for(i = 0; i < length1 ; i++)
	{
		printf("Prt1[%d]: ",i + 1);
		scanf("%d",Ptr1 + i);
	}
	
	printf("Enter second memory region's  values respectively: \n");
	
	for(i = 0; i < length2 ; i++)
	{
		printf("Prt2[%d]: ",i + 1);
		scanf("%d",Ptr2  + i);
	}
	
	Ptr3 = combine(Ptr1, Ptr2, length1, length2);
	
	for(i = 0; i < length1 + length2 ; i++)
	{
		printf("Ptr3[%d]: %d\n", i + 1, Ptr3[i]);
		sum += Ptr3[i];
	}
	
	printf("\nSum: %d",sum);
	
	return 0;
}


int * combine(int *Ptr1, int *Ptr2, int length1, int length2)
{

	int *Ptr3 =(int * ) malloc((length1 + length2) * (sizeof(int))) ;
	int *Ptr = Ptr3;
	
	int i;
	
	for(i = 0 ; i < length1 ; i++)
	{
		*Ptr3 = *Ptr1;
		Ptr3++ ;
		Ptr1++ ;
	}
	
	// S�ras�yla Ptr1 tuttu�u dizenin de�erlerini Ptr3 e tutturur.
		
	for(i = 0 ; i < length2 ; i++)
	{
		*Ptr3 = *Ptr2;
		Ptr3++ ;
		Ptr2++ ;
	}
	
	// S�ras�yla Ptr1 tuttu�u dizenin de�erlerini Ptr3 e tutturur.

	// *Ptr3 = '\0'; Bu sat�r ile asl�nda yukar�da tahsis etti�im belle�in s�n�r�n� a��yorum ve bir sonraki 4 byte a null yaz�yorum ama Ptr3 bir integer pointer � oldu�undan onu gene asc�� den 0 a �eviriyor. 

	printf("\nCombine step is completed.\n");
	
	return Ptr;
	
}
