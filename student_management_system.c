/*
	Group 13
	MEHMET MERYÇ YÜKSEL 230401095
	MUSTAFA EKEN   	    230401046
	MUSTAFA SALYH ALP   230401025
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h> // to use sleep func.
#define MAX_COUNT 100

struct student{ // Struct student has student's info

	int student_no;
	char fullname[50];
	int midterm;
	int final;
	int assignment;
	double GPA;
};

// funct. prototypes.

bool create_file_GPA(struct student [], int);
bool add_new_student(void);
bool is_student_exist(int);
bool is_grades_valid(int, int, int);
bool list_all_students(void);
bool search_edit_delete(void);
bool editing_student(struct student);
bool delete_student(struct student);
bool sorting_students();

int main (void)
{

	FILE *file = fopen("students.txt","rb+"); // if file exists it will open it for "rb+" writing and reading in binary.(should be already exist)

	struct student empty_student = {0, "", 0, 0, 0, 0.0};  // empty_student is created for filling the file by NULLs.

	if(file == NULL) // If file does not exits
	{
		FILE *file = fopen("students.txt","wb+"); // it will open it for "wb+" reading  and writing in binary.(creates it)


		if(file == NULL)
		{
			printf("file could not be opened\n");
			return -1;
		}

		int i;

		for(i = 0 ; i < MAX_COUNT ; i++)
		{
			fwrite(&empty_student, sizeof(struct student), 1, file);  // fills it by NULLs
		}

	}

	fclose(file);

	// Menu is printed.

	int choice;

	do
	{
        puts("");

        printf("1- Add new student\n");
        printf("2- List all students\n");
        printf("3- Search, edit and delete student records\n");
        printf("4- Sort students by GPA\n");
        printf("5- Exit\n");

		printf("(MENU)Enter your choice: ");
		int input_result = scanf("%d",&choice); // scanf returns the number of arguments that were written to. And EOF if error encountered.

		while(getchar() != '\n'); // cleans buffer. if I'd enter "abc" to student number, scanf would read only "a"(and error encountered) and others would drop to buffer and thats dangerous.

		if(input_result != 1) // checks if scanf returned the expected value (1)
		{
			printf("Invalid choice, Try again\n");
			continue; // if not, continue
		}

		switch(choice) // switch-case for choices.
		{

			case 1:
				if(add_new_student())
					printf("Student succesfuly added.\n");

				else
					printf("Student could not be added.\n");

				break;
			case 2:
				if(list_all_students())
					printf("Listing students is succesfly completed.\n");

				else
					printf("Students could not be listed.\n");

				break;
			case 3:
				if(search_edit_delete())
					printf("Search, edit, deleting student is succesfly completed.\n");

				break;
			case 4:
				if(sorting_students())
					printf("Students are sorted well\n");

				else
					printf("Students could not be sorted.\n");

				break;
			case 5:
				printf("Program is over!\n");
				break;

			default:
				printf("Invalid choice, Try again\n");
				break;

		}

	}while(choice != 5); // continues until "choice = 5"

	return 0;
}

bool add_new_student(void)
{
	struct student add_student; // the student that will be added.

	do
	{
		printf("Enter student number to add[1,100]: ");
		int input_result = scanf("%d",&add_student.student_no); // scanf returns the number of arguments that were written to.And EOF if error encountered.

		while(getchar() != '\n'); // cleans buffer. if I'd enter "abc" to student number, scanf would read only "a"(and error encountered) and others would drop to buffer and thats dangerous.

		if(input_result != 1) // checks if scanf returned the expected value (1).
		{
			printf("Invalid input, Try again!\n");
			continue;
		}

		if(add_student.student_no > 100 || add_student.student_no < 1) // checks if its in range.
		{
			printf("Student number must be in range [1,100]!!!\n");
			continue;
		}

		if(is_student_exist(add_student.student_no)) // checks if already student exist
		{
			printf("Student is already exist!\n");
			continue;
		}

		break; // if all requirements are suits then break out the loop.
	}while(1);

	printf("Enter student full name: ");
	fgets(add_student.fullname, 50, stdin);
	add_student.fullname[strcspn(add_student.fullname, "\n")] = '\0'; // when we enter student fullname and scan it by using fgets there will be a "\n" char at the end of the name. So this line clears it.

	do
	{
		printf("Enter midterm, final and assignmet respectively[0,100]: ");
		int input_result = scanf("%d%d%d",&add_student.midterm, &add_student.final, &add_student.assignment); // scanf returns the number of arguments that were written to.And EOF if error encountered.

		while(getchar() != '\n'); // cleans buffer

		if(input_result != 3) // if input_result != 3, input_result has to be 3.
		{
			printf("Invalid input, try again!\n");
			continue; // then continue.
		}

	}while(!is_grades_valid(add_student.midterm, add_student.final , add_student.assignment)); // continues until grades are valid.

	add_student.GPA = add_student.midterm * 0.4 + add_student.final * 0.5 + add_student.assignment * 0.1 ; // calculates GPA.

	FILE *file = fopen("students.txt","rb+"); // opens file for "rb+"

	if(file == NULL)
	{
		printf("File could not be opened.\n");
		return false;
	}

	fseek(file, sizeof(struct student) * (add_student.student_no - 1), SEEK_SET); // sets pointer to related position in the file(to write student info).

	fwrite(&add_student, sizeof(struct student), 1, file); // then writes it.
	printf("Student is adding...\n");
	sleep(2); // Good habit for visual clarity.

	fclose(file); // closes it.

	return true; // returns true to the main funciton, thus it will print "student is added"
}

bool is_grades_valid(int mid, int final, int assign)
{
	if(mid > 100 || mid < 0)
		return false;

	if(final > 100 || final < 0)              // Checks if grades are valid in a good way.
		return  false;

	if(assign > 100 || assign < 0)
		return false;

	return true;
}

bool is_student_exist(int searching_no)
{
	FILE *file = fopen("students.txt","rb+");

	struct student s1;

	if(file == NULL)
	{
		printf("file could not be opened\n");
		return true;
	}

	while(fread(&s1, sizeof(struct student), 1, file) == 1) // reads until end of the file.
	{
		if(s1.student_no == searching_no) // checks if read student's number matches with searching_no.
		{
			fclose(file); // if yes returns true, means student is already exist.
			return true;
		}

	}

	fclose(file);
	return false; // else returns false.
}

bool list_all_students(void)
{
	struct student list_student;
	int i = 0;

	FILE *file = fopen("students.txt","rb+");

	if(file == NULL)
	{
		printf("File could not be opened.\n");
		return false;
	}

	while(fread(&list_student, sizeof(struct student), 1, file) == 1) // reads until end of the file.
	{
		if(list_student.student_no == 0) // passes null students directly.
			continue;

		i++; // counts student count.

		printf("\n");

		printf(" Student no: %d\n",list_student.student_no);
		printf(" Full name: %s\n",list_student.fullname);
		printf(" Final: %d\n assignment: %d\n midterm: %d\n",list_student.final, list_student.assignment, list_student.midterm); // prints all students.
		printf(" GPA: %.2lf\n",list_student.GPA);

	}

	printf("==> %d students are listed <==\n\n",i); // prints student count.

	if(i == 0)
		return false; // if i = 0 returns false that means no student is added yet.

	fclose(file);
	return true;  // returns true, students are listed succesfly
}

bool search_edit_delete(void)
{
	struct student edit_student;
	int input_result;

	puts("");
	list_all_students(); // first lists students, so that the user can see.
	puts("");

	do // same do while in "add_student" function, just one thing is different.
	{
		printf("Enter student number to search[1,100](0 for exit): ");
		int input_result = scanf("%d",&edit_student.student_no);

		while(getchar() != '\n');

		if(input_result != 1)
		{
			printf("Invalid input, Try again\n");
			continue;
		}

		if(edit_student.student_no == 0) // returns to menu if user enters 0.
		{
			printf("Back to menu...\n");
			sleep(2);
			return false;
		}
		if(edit_student.student_no > 100 || edit_student.student_no < 1)
		{
			printf("Student number must be in range [1,100]\n");
			continue;
		}

		if(!is_student_exist(edit_student.student_no))
		{
			printf("Student is not found\n");
			continue;
		}

		break; // if all requirements are suits then break out the loop
	}while(1);

	FILE *file = fopen("students.txt","rb+");

	if(file == NULL)
	{
		printf("file could not be opened.\n");
		return false;
	}

	fseek(file, sizeof(struct student) * (edit_student.student_no - 1), SEEK_SET); // sets pointer to corresponding place.
	fread(&edit_student, sizeof(struct student), 1, file); // reads corresponding place by using student no.

	printf(" Student no: %d\n",edit_student.student_no);
	printf(" Full name: %s\n",edit_student.fullname);
	printf(" Final: %d\n assignment: %d\n midterm: %d\n",edit_student.final, edit_student.assignment, edit_student.midterm); //by given student number from user, program prints studen info.
	printf(" GPA: %.2lf\n",edit_student.GPA);

	puts("");

	int choice;

	printf("1-Edit\n");
	printf("2-Delete\n");            // prints a mini menu for user to choose.
	printf("3-None, back to menu\n");


	printf("Would you like to edit or delete this student: ");
	scanf("%d",&choice); // if user enters any other number from(1,2 or 3) switch will go to default.
						 // And same will happen if user enters "abc" or "a". And other chars.

	while(getchar() != '\n'); // cleans buffer, means clears except the first char user entered. For ex "abc\n" is entered(\n is entered by pressing enter), this line clears "bc" until new line occurs.

	switch(choice)
	{
		case 1:
			if(editing_student(edit_student)) // goes to editin student funct.
				printf("Student succesfuly edited\n");

			else{
					printf("Student could not be edited.\n");
					return false;
			}

			break;

		case 2:
			if(delete_student(edit_student))   // goes to deleting student func.
  				printf("Student succesfuly deleted.\n");

			else{
				printf("Student could not be deleted.\n");
				return false;
			}

			break;

		case 3:
			printf("You're returning to menu...\n"); // Backs to menu
			sleep(2);
			return false;

		default:
			printf("Wrong choice ,returning to menu..\n"); // Again backs to menu with an error warning.
			sleep(2);
			return false;
	}

	return true;
}

bool editing_student(struct student edit_student)
{
	printf("\n");
	printf("Student info: \n");

	printf(" Student no: %d\n",edit_student.student_no);
	printf(" Full name: %s\n",edit_student.fullname);
	printf(" Final: %d\n assignment: %d\n midterm: %d\n",edit_student.final, edit_student.assignment, edit_student.midterm); // First prints student info that will be change by user.
	printf(" GPA: %.2lf\n",edit_student.GPA);

	printf("Enter student full name to edit: "); // And changes it same as add_student func.
	fgets(edit_student.fullname, 50, stdin);
	edit_student.fullname[strcspn(edit_student.fullname, "\n")] = '\0';  // when we enter student fullname and scan it by using fgets there will be a "\n" char at the end of the name. So code clears it.

	do
	{
		printf("Enter midterm, final and assignmet respectively[0,100]: ");
		int input_result = scanf("%d%d%d",&edit_student.midterm, &edit_student.final, &edit_student.assignment); // scanf returns the number of arguments that were written to.And EOF if error encountered.

		while(getchar() != '\n'); // cleans buffer,

		if(input_result != 3) // if input_result != 3
		{
			printf("Invalid input,back to menu...\n");
			sleep(2);
			return false; // then back to menu.
		}


	}while(!is_grades_valid(edit_student.midterm, edit_student.final , edit_student.assignment));  // continues until grades are valid.

	edit_student.GPA = edit_student.midterm * 0.4 + edit_student.final * 0.5 + edit_student.assignment * 0.1 ; // Calculates GPA.

	FILE *file = fopen("students.txt","rb+");

	if(file == NULL)
	{
		printf("File could not be opened.\n");
		return false;
	}

	fseek(file, sizeof(struct student) * (edit_student.student_no - 1), SEEK_SET); // sets pointer to related position in the file(to write student info).

	fwrite(&edit_student, sizeof(struct student), 1, file); // then writes it.
	printf("Student is editing.\n");
	sleep(2); // Good habit for eye clarity.

	fclose(file);

	return true;
}

bool delete_student(struct student del_student)
{
	struct student empty_student = {0, "", 0, 0, 0, 0.0}; // Deleting a student means filling  student info by NULLs.

	printf("\n");
	printf("Student info: \n");

	printf(" Student no: %d\n",del_student.student_no);
	printf(" Full name: %s\n",del_student.fullname);
	printf(" Final: %d\n assignment: %d\n midterm: %d\n",del_student.final, del_student.assignment, del_student.midterm); // First prints student info that will be change by user.
	printf(" GPA: %.2lf\n",del_student.GPA);

	FILE *file = fopen("students.txt","rb+");

	if(file == NULL)
	{
		printf("File could not be opened.\n");
		return false;
	}

	fseek(file, sizeof(struct student) * (del_student.student_no - 1), SEEK_SET); // sets pointer to related position in the file(to write student info).

	fwrite(&empty_student, sizeof(struct student), 1, file); // then f?lls it by NULLs.
	printf("Student has been edited.\n");
	sleep(2);

	fclose(file);

	return true;
}

bool sorting_students()
{
	if(list_all_students() == false) // checks if there is student to sort.
	{
		printf("There is no student to sort\n");
		return false; // returns false if no.
	}

	struct student students[MAX_COUNT]; // creates an array to sort studenst by GPA info.
	struct student temp; // To fill array, by using file.
	int length = 0;
	char ch;

	printf("Students are sorted by GPA..\n\n");

	FILE *file = fopen("students.txt","rb+");

	if(file == NULL)
	{
		printf("file could not be opened.\n");
		return false;
	}

	while(fread(&temp, sizeof(struct student), 1, file) == 1) // reads until EOF.
	{
		if(temp.student_no == 0)
			continue;

		students[length] = temp; // fills the arrays by read ones. In this way students are sorted by number.
 		length++; // counts student count.
	}

	int j,k;

	// Bubble sort.
	for(j = 0 ; j < length - 1 ; j++) // "length - 1" because the last students position will be already fit when others fitted.
	{
		for(k = 0 ; k < length - j - 1; k++) // No need to check all, cause others will be already sorted.(in bubble sort the smallest number will be sink in the last position of the array).So no need to check there
		{
			if(students[k].GPA < students[k + 1].GPA)
			{
				struct student temp2 = students[k];
				students[k] = students[k + 1];             // There is no using point for "struct student temp2" again in the code.
				students[k + 1] = temp2;
			}

		}

	}

	printf("*\n");

	printf("Student no, fullname, GPA\n\n");

	int i;
	for(i = 0 ; i < length ; i++)
	{
		printf("%d, %s, %.2lf\n",students[i].student_no,students[i].fullname, students[i].GPA); // prints array by starting 0 to length.
	}

	printf("*\n");
	printf("Would you like to create a file and write all these to it: ");
	printf("Enter yes or no(Y \\ N): "); // (\\ prints only one "\")
	scanf("%c",&ch);

	while(getchar() != '\n'); // cleans buffer as always

	ch = (char)toupper(ch); // converts user choice to uppercase. toupper returns an integer for the given char.(ASCII)

	while(ch != 'Y' && ch != 'N') // if not matched Y or N, ask again.
	{
		printf("Please enter yes or no(Y \\ N): ");
 		scanf("%c",&ch);
		ch = (char)toupper(ch);

		while(getchar() != '\n');
	}

	if(ch == 'Y')
		create_file_GPA(students, length); // if user choose yes, calls create file for GPA func.

	else
		return false;

	return true;
}

bool create_file_GPA(struct student students[], int length) // length is sent to create_file_GPA func. Because we need student count for a "for" loop.
{
	FILE *file = fopen("sorted_by_GPA.txt","w+"); // No binary mode, cause the user want to read it on his own. Or may share with students.
	int i = 0;

	if(file == NULL)
	{
		printf("File could not be opened.\n");
		return false;
	}

	for(i = 0 ; i < length ; i++)
	{
		fprintf(file, "%s, %.2lf\n", students[i].fullname, students[i].GPA); // fprintf is used, not fwrite(for binary mode).
	}

	fclose(file);

	return true;
}
