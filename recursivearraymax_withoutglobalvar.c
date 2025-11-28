#include <stdio.h>
#include <stdlib.h>

// Bir dizinin en büyük elemanýný rekürsif(recursive) kullanarak bulma.
// Finding the largest element of an array using recursion(rekürsif).

/*

RECURSIVE ÝN 4 ALTIN KURALI !!!

1. Temel Durum (Base Case)	Fonksiyon ne zaman duracak? Mutlaka bir yerde "Artýk kendimi çaðýrmýyorum" demelisin. (Yoksa sonsuza kadar çalýþýr ve program çöker!)
2. Ýlerleme (Progress)	Her recursive adýmda problem küçülmeli. (Mesela dizinin boyutu azalmalý, sayý küçülmeli...) Yoksa sonsuz döngü olur.
3. Çaðrý (Recursive Call)	Fonksiyon, kendisini daha küçük bir problem üzerinde çaðýrmalý.
4. Doðru Çözümün Kurulmasý	Her dönüþte gelen sonucu doðru bir þekilde iþlemelisin. (Mesela toplamak, karþýlaþtýrmak, eklemek vs.)

*/


int largest(int arr[], int size, int index);

int main(void)
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int i, array[size];
    
    // Input array elements
    for(i = 0; i < size; i++)
    {
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }
    
    puts("");
    
    // Call recursive function starting from index 0
    printf("%d is the largest value in the array.\n", largest(array, size, 0));
    
    return 0;
}

// Recursive function that finds the largest element
// Parameters: array, size of array, current index

/*

Dizinin ilk baþta son 2 elemanýna gidiyor birini max_rest de tutuyor digerinin indexini elinde tutuyor ve karþýlaþtýrýyor büyük olaný return ediyor.
daha sonra return edilen büyüðü bir önceki caller fonksiyonda max_rest e atýyor ve index zaten 1 azalmýþ olduðundan gene kalanlarý karþýlaþtýrýp büyüðü 
return ederek devam ediyor.

*/

int largest(int arr[], int size, int index)
{
    // Base case: If we've reached the end of the array(Base case arrayin sonuna eriþmek) 
    if(index == size - 1)
        return arr[index];
    
    // Recursive case: Find max of current element and max of remaining elements
    int max_rest = largest(arr, size, index + 1);
    
    // Return the larger value
    if(arr[index] > max_rest)
        return arr[index];
    else
        return max_rest;
}
