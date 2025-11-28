#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



// m'ye kadar olan parçalarý kullanarak n nesneyi bölme yollarýnýn sayýsýný hesaplayan bir fonksiyon yazýn (m >= 0 olduðu varsayýlmaktadýr).

// count_partitions(n,m) is 1 if n = 0 .
// count_partitions(n,m) is 0 if m = 0 .


int count_partitions(int n,int m);

int main (void)
{
	setlocale(LC_CTYPE,"Turkish"); // ifadesi ise sadece syntax i türkçe yapar dolayýsýyla türkçe karakterleri kullanabilirsin.
	
	int n,m;	
	
	printf("n ve m yi sýrasýyla giriniz(n and m are >= 0): ");
	scanf("%d%d",&n,&m);
	
	
	printf("Answer: %d",count_partitions(n,m));
	
	return 0;
}

int count_partitions(int n,int m)
{
	
	if(n == 0)
		return 1;
	
	else if(m == 0 || n < 0)
		return 0;
	
	else
		return count_partitions(n-m,m) + count_partitions(n,m-1);
	
}
