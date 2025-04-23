#include <stdio.h>
#include <stdlib.h>

/*

Klavyeden ��renci say�s�(en fazla 100) ve ders ge�me notunu alarak bu bilgileri tan�mlanacak "hesapla" fonksiyonuna
g�nderen bir "main" fonksiyonu haz�rlay�n�z. "hesapla" fonksiyonu kendisine gelen ��renci say�s� kadar notu
klavyeden okuyarak 100 elemanl� bir diziye kaydetmeli ve ge�me notuna g�re ka� tane ��rencinin dersten
kald���n� bularak fonksiyondan geri d�nd�r�rken s�n�f ortalamas�n� yazd�rmal�d�r.

*/

int calculate_average(int [], int,int);

int main (void)
{
	int SIZE;
	
	do
	{
		printf("Enter student count(<=100): ");
		scanf("%d",&SIZE);
		
	}while(SIZE > 100);
	
	unsigned int pass_grade;
	
	printf("Enter pass grade: ");
	scanf("%u",&pass_grade);
	
	int student[SIZE];	
	
	int count = calculate_average(student,SIZE,pass_grade);
	
	printf("%d student failed the exam\n",count);
	
	return 0;
}

int calculate_average(int students[],int SIZE,int pass_grade)
{
	
	int i ;
	int count = 0;
	int total = 0;
	
	for(i = 0 ; i < SIZE ; i++)
	{
		printf("%d. student result: ",i+1);
		scanf("%d",&students[i]);
	}
	
	for(i = 0 ; i < SIZE ; i++)
	{
		if(students[i] < pass_grade)
			count++;
			
		total += students[i];
				
	}
	
	printf("Class average: %.2f\n",(float) total / SIZE );
	
	return count;
}
