#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

/*

Customer registry application
Saves customers name, surname phone and address info to a file and uses that info.

*/

typedef struct customer{
	
	char name[50];
	char surname[50];
	char phone[15];
	char address[20];

}Customer;

bool search_customer();
bool delete_customer();
bool list_customer();
bool add_customer();
void menu();

int main (void)
{
	int choice;
	menu();
	printf("?: ");
	scanf("%d",&choice);
	getchar();
	
	while(choice != 0)
	{
	
		switch(choice)
		{		
			case 1:
				if(add_customer())
					printf("Successfuly added\n");			
				else
					printf("Failed\n");
				break;
			
			case 2:
				if(delete_customer())
					printf("Successfuly deleted\n");			
				else
					printf("Failed\n");
				break;
			
			case 3:
				if(list_customer())
					printf("Successfuly listed\n");			
				else
					printf("Failed\n");
				break;	
			
			case 4:
				if(search_customer())
					printf("Found\n");			
				else
					printf("Not found\n");
				break;
			
				
		}
	
		sleep(2);
		system("cls");
		menu();
		printf("?: ");
		scanf("%d",&choice);	
		getchar();
	}	
	
	printf("Program is over...");
	return 0;
}

void menu()
{
	printf("0-Exit\n");
	printf("1-Add customer\n");
	printf("2-Delete customer\n");
	printf("3-List all customers\n");
	printf("4-Search customer\n");
	
}

bool add_customer()
{
	Customer add_customer;
	
	printf("Enter customer info: \n");
	
	printf("Name(if name is 2 word, enter without space): ");
	scanf("%s",add_customer.name);
	
	printf("Surname: ");
	scanf("%s",add_customer.surname);
	
	printf("Phone: ");
	scanf("%s",add_customer.phone);
	
	printf("Address: ");
	scanf("%s",add_customer.address);
	
	FILE *file = fopen("clients.txt","a");
	
	if(file == NULL)
	{
		printf("file couldn't be opened\n");
		return false;
	}
	
	fprintf(file, "%s\t%s\t%s\t%s\n", add_customer.name, add_customer.surname, add_customer.phone, add_customer.address);	
	
	fclose(file);
	return true;
}

bool list_customer()
{
	Customer list_customer; 
	
	FILE *file = fopen("clients.txt","r+");
	
	if(file == NULL)
	{
		printf("No info found\n");
		return false;
	}

	printf("%-15s%-15s%-15s%-15s\n","Name", "Surname" ,"Phone", "Address");
	printf("----------------------------------------------------\n");
	
	while(fscanf(file, "%s\t%s\t%s\t%s\n", list_customer.name, list_customer.surname, list_customer.phone, list_customer.address) == 4)
	{
		printf("%-15s%-15s%-15s%-15s\n",list_customer.name, list_customer.surname, list_customer.phone, list_customer.address);	
	}
	
	printf("----------------------------------------------------\n");
	printf("Press any key to continue...\n");
	
	getch();
	
	fclose(file);
	return true;
}

bool delete_customer()
{
	int i = 0;
	
	list_customer();
	
	Customer del_customer;

	char searching_name[50];	
	
	printf("Enter the customer name you want to delete: ");
	scanf("%s", searching_name);
	
	FILE *file = fopen("clients.txt","r+");
	FILE *file2 = fopen("clients2.txt","w+");
	
	if(file == NULL || file2 == NULL)
	{
		printf("files could not be opened\n");
		return false;
	}
	
	while(fscanf(file, "%s\t%s\t%s\t%s\n", del_customer.name, del_customer.surname, del_customer.phone, del_customer.address) == 4)
	{
		if(strcmp(del_customer.name, searching_name) == 0)
		{
			i = 1;
			continue;
		}
				
					
		fprintf(file2, "%s\t%s\t%s\t%s\n", del_customer.name, del_customer.surname, del_customer.phone, del_customer.address);
	
	}	
	
	fclose(file);
	fclose(file2);
	
	remove("clients.txt");
	rename("clients2.txt", "clients.txt");
	
	if(i == 1)
		return true;

	return false;
}

bool search_customer()
{
	list_customer();
	Customer search_customer;
	
	char searching_name[50];
	
	FILE *file = fopen("clients.txt","r");
	
	if(file == NULL)
	{
		printf("file not found\n");
		return false;
	}
	
	printf("Enter the customer name you want to search: ");
	scanf("%s", searching_name);
	
	while(fscanf(file, "%s\t%s\t%s\t%s\n", search_customer.name, search_customer.surname, search_customer.phone, search_customer.address) == 4)
	{
		if(strcmp(search_customer.name, searching_name) == 0)
		{
			printf("----------------------------------------------------\n");	
			printf("%s\t%s\t%s\t%s\n" , search_customer.name, search_customer.surname, search_customer.phone, search_customer.address);	
			printf("----------------------------------------------------\n");
			
			fclose(file);
			return true;
		}	
				
	}
	
	sleep(1);
	
	fclose(file);
	return false;
}
