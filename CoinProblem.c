/*

Let's say we have coins such as (1,5,10,100)
Find the min required coins for a given money value.

Ex Money value: 131

131 = 100*1 + 10*3 + 1*1 -> So We say 5 here.(Remember this is the min coin value)
*/

#include <stdio.h>

int main(void){

	int moneyValue;
	int coinCount = 0;

	printf("Enter MoneyValue: ");
	scanf("%d", &moneyValue);

	coinCount += moneyValue / 100;
	printf("100 * %d\n", moneyValue / 100);
	moneyValue %= 100;
	coinCount += moneyValue / 10;
	printf("10 * %d\n", moneyValue / 10);
	moneyValue %= 10;
	coinCount += moneyValue / 5;
	printf("5 * %d\n", moneyValue / 5);
	moneyValue %= 5;
	printf("1 * %d\n", moneyValue);
	coinCount += moneyValue;
	
	printf("Min coin count: %d\n", coinCount);
	return 0;
}