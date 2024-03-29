//Add Headers
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// To keep track of the number of students
int i = 0;

// A structure to store the student details
struct student_info
{
   char firstName[20];
   char lastName[20];
   int rollNumber;
   float CGPA;
} st[500];


// Function to add student details
void new_student()
{   
   printf("\n\n");
   printf("Add the Student's Details\n\n");
   printf("Enter the first name of the student: ");
   scanf("%s", st[i].firstName);
   printf("Enter the last name of the student: ");
   scanf("%s", st[i].lastName);
   printf("Enter the roll number of the student: ");
   scanf("%d", &st[i].rollNumber);
   printf("Enter the CGPA of the student: ");
   scanf("%f", &st[i].CGPA);
   i = i + 1;
   printf("Student Added!\n");
}

// Function to find the students using roll number
void findByRollNumber()
{
   int temp;
   printf("\nEnter the roll number of the student: ");
   scanf("%d", &temp);
   
   for (int j = 0; j <= i; j++)
   {
      if (temp == st[j].rollNumber)
      {
        printf("The student's details are\n");
        printf("The first name is: %s\n", st[j].firstName);
        printf("The last name is: %s\n", st[j].lastName);
        printf("The CGPA is: %.1f\n", st[j].CGPA);
      }
   }
}
// Function to find the student by the first name
void findByName() {
    char temp[20];
    printf("Enter the First Name of the Student: ");
    scanf("%s", temp);
    int c = 0;

    for (int j = 0; j <= i; j++) {
        if (!strcmp(st[j].firstName, temp)) {
            printf("The student's details are\n");
            printf("The first name is: %s\n", st[j].firstName);
            printf("The last name is: %s\n", st[j].lastName);
            printf("The CGPA is: %.1f\n", st[j].CGPA);
            c++; // Increment the counter
        }
    }

    if (c == 0) {
        printf("Student not found with the given first name.\n");
    }
}


// Function to print the total number of students
void totalCount()
{
   printf("The total number of students currently in the system is %d\n", i);
}
// Function to delete a Student
void deleteStudent()
{
   int temp;
   printf("Enter the roll number of the student: ");
   scanf("%d", &temp);
   for (int j = 1; j <= i; j++)
   {
      if (temp == st[j].rollNumber)
      {
         for (int k = j; k < 499; k++)
         {
            st[k] = st[k + 1];
         }
         i--;
      }
   }
   printf("The entered student's record deleted successfully\n");
}
// Function to update a student's data
void updateStudent()
{
   int temp;
   printf("Enter the roll number of the student: ");
   scanf("%d", &temp);
   for (int j = 0; j < i; j++)
   {
      if (temp == st[j].rollNumber)
      {
        printf("choice which to update!\n");
         printf("1. First Name\n"
                "2. Last Name\n"
                "3. Roll Number\n"
                "4. CGPA\n");
         int c;
         scanf("%d", &c);
         switch(c) {
            case 1:
               printf("Enter the updated first name : ");
               scanf("%s", st[j].firstName);
               break;
            case 2:
               printf("Enter the updated last name : ");
               scanf("%s", st[j].lastName);
               break;
            case 3:
               printf("Enter the updated roll number : ");
               scanf("%d", st[j].rollNumber);
               break;
            case 4:
               printf("Enter the updated CGPA : ");
               scanf("%f", st[j].CGPA);
               break;
         }
         printf("Records updated successfully");
      }
   }
}
int main()
{
   int taskToPerform=0;
   while (1)
   {
      printf("\n\n\n");
      printf("***********MAIN MENU***********");
      printf("\nEnter the task that you want to perform\n");
      printf("1. Add a new Student Detail\n");
      printf("2. Find the details of a Student using Roll Number\n");
      printf("3. Find the details of a Student using the First Name\n");
      printf("4. Find Total number of Students\n");
      printf("5. Delete the details of an Student\n");
      printf("6. Update the details of an Student\n");
      printf("7. Exit\n");
      printf("Enter Your Choice: ");
      scanf("%d", &taskToPerform);

      switch (taskToPerform)
      {
      case 1:
         new_student();
         break;
      case 2:
         findByRollNumber();
         break;
      case 3:
         findByName();
         break;
      case 4:
         totalCount();
         break;
      case 5:
         deleteStudent();
         break;
      case 6:
         updateStudent();
         break;
      case 7:
        printf("exiting now...");
         exit(0);
         break;
      default:
      printf("Enter valid!");
         exit(0);
      }
   }

   return 0;
}
