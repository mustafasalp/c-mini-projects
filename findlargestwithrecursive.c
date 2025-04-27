#include <stdio.h>
#include <stdlib.h>

// Bir dizinin en büyük elemanýný rekürsif(recursive) kullanarak bulma.
// Finding the largest element of an array using recursion(rekürsif).

int SIZE;
int max = -999;
int i = 0;

int largest(int []);

int main (void)
{
	
	printf("Enter the size of the array: "); scanf("%d",&SIZE);
	
	int array[SIZE];
	
	for(i ; i < SIZE ; i++)
	{
		printf("array[%d]: ",i); scanf("%d",&array[i]);
	}
	
	i = 0;
	
	puts("");
	
	printf("%d is the largest value in the array.\n",largest(array)) ;
	
	return 0;
}

int largest(int array[])
{
	if(i < SIZE)
	{	
	
		if(max < array[i])
			max = array[i];
			
		i++;
		
		largest(array);
		
	}
	
	return max;
}
