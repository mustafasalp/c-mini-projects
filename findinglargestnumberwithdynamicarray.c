#include <stdio.h>
#include <stdlib.h>

//Dinamik bellek kullanýmý ile büyük sayý bulma uygulamasý.
//Finding largest number by using dynamic memory.

int main (void)
{
	
	int size;
	int *Ptr; 
	
	printf("How many numbers would you like to input: ");
	scanf("%d",&size);	
	
	Ptr = (int *) calloc(size, sizeof(int)); 
											// Calloc function allocates size * sizeof(int) bytes memory from memory and they will be continuous in RAM. 
											// But the calloc func. returns a void pointer which points the first byte of allocated memory.
											// Then we want to cast the pointer to assign it to another pointer that we have created.
											// "Tipi belli olmayan bir pointer'ý (void*) doðrudan tipli pointer'a atayamazsýn — derleyici ne olduðunu bilemez."
	if(Ptr == NULL)
	{
		printf("Ptr points to NULL!\n");
		return 1;
	}
	
	printf("Memory allocated.\n");
	
	int i = 0;
	
	for(i ; i < size ; i++)
	{
		printf("Enter %d. number of dynamic memory: ",i + 1);
		scanf("%d",Ptr + i);	
	}
	
	int largest = *Ptr ;
	
	for(i = 0 ;  i < size ; i++)
	{
		
		if(largest < *(Ptr + i) )  // *(Ptr + i) and Ptr[i] are works same.
				largest = Ptr[i] ;
	
	}	
	
	printf("Largest number is: %d", largest);
	
	return 0;
}
