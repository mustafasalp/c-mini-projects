#include <stdio.h>
#include <stdlib.h>

/*

Klavyeden öðrenci sayýsý(en fazla 100) ve ders geçme notunu alarak bu bilgileri tanýmlanacak "hesapla" fonksiyonuna
gönderen bir "main" fonksiyonu hazýrlayýnýz. "hesapla" fonksiyonu kendisine gelen öðrenci sayýsý kadar notu
klavyeden okuyarak 100 elemanlý bir diziye kaydetmeli ve geçme notuna göre kaç tane öðrencinin dersten
kaldýðýný bularak fonksiyondan geri döndürürken sýnýf ortalamasýný yazdýrmalýdýr.

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
