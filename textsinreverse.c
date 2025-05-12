#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


// Kelimelerin harflerini tersten yazdýrma.
// Printing words' letters in reverse.

// Cümle içindeki kelimeleri tersden yazdýrma.
// Printing sentences' words in reverse.


void print_word_inreverse(char *);
void print_sentence_inreverse(char *);

int main (void)
{
	setlocale(LC_CTYPE,"Turkish");
	
	char text[200];
	
	printf("Enter text: ");
	gets(text);
	
	printf("Kelimelerin harflerini tersten yazdýrma.\n");
	print_sentence_inreverse(text);
	
	puts("");
	
	printf("Cümle içindeki kelimeleri tersden yazdýrma.\n");
	print_word_inreverse(text);
	
	return 0;
}

void print_sentence_inreverse(char *text_Ptr)
{
	int length = strlen(text_Ptr);
	int i = length - 1;
	
	while(i >= 0)
	{
		printf("%c",text_Ptr[i]);
		i--;
	}
	
	printf("\n");
}


void print_word_inreverse(char *text_Ptr)
{
	int length = strlen(text_Ptr);
	int i = length - 1; 
	int j = 0;
	
	char *word_Ptr = (char * ) malloc(length * sizeof(char));
	
	while( i >= -1)
	{
		
		word_Ptr[j] = text_Ptr[i];
		
		if(word_Ptr[j] == ' ' || i == -1)
		{
			word_Ptr[j] = '\0';
			strrev(word_Ptr);       // Reverses the given text.
			printf("%s ",word_Ptr);
			j = -1;
			
		}
		i--;
		j++;
	
	}
	
}
