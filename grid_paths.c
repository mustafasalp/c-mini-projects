#include <stdio.h>
#include <stdlib.h>

int grid_paths(int, int);

int main (void)
{
	int n,m;
	
	printf("Please enter two numbers respectively for n x m grid: ");
	scanf("%d%d",&n,&m);
	
	printf("Number of ways for a n x m grid is: %d",grid_paths(n,m));
	
	return 0;
}

int grid_paths(int n, int m)
{
	
	if(n == 1 || m == 1)	
		return 1;
	
	else
		return grid_paths(n-1,m) + grid_paths(n,m-1);
	
}
