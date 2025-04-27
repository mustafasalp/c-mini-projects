#include <stdio.h>
#include <stdlib.h>

// Bir dizinin en b�y�k eleman�n� rek�rsif(recursive) kullanarak bulma.
// Finding the largest element of an array using recursion(rek�rsif).

/*

RECURSIVE �N 4 ALTIN KURALI !!!

1. Temel Durum (Base Case)	Fonksiyon ne zaman duracak? Mutlaka bir yerde "Art�k kendimi �a��rm�yorum" demelisin. (Yoksa sonsuza kadar �al���r ve program ��ker!)
2. �lerleme (Progress)	Her recursive ad�mda problem k���lmeli. (Mesela dizinin boyutu azalmal�, say� k���lmeli...) Yoksa sonsuz d�ng� olur.
3. �a�r� (Recursive Call)	Fonksiyon, kendisini daha k���k bir problem �zerinde �a��rmal�.
4. Do�ru ��z�m�n Kurulmas�	Her d�n��te gelen sonucu do�ru bir �ekilde i�lemelisin. (Mesela toplamak, kar��la�t�rmak, eklemek vs.)

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

Dizinin ilk ba�ta son 2 eleman�na gidiyor birini max_rest de tutuyor digerinin indexini elinde tutuyor ve kar��la�t�r�yor b�y�k olan� return ediyor.
daha sonra return edilen b�y��� bir �nceki caller fonksiyonda max_rest e at�yor ve index zaten 1 azalm�� oldu�undan gene kalanlar� kar��la�t�r�p b�y��� 
return ederek devam ediyor.

*/

int largest(int arr[], int size, int index)
{
    // Base case: If we've reached the end of the array(Base case arrayin sonuna eri�mek) 
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
