#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student
{
    char name[50];
    int marks;
    char grade[6];
};

void calculateGrade(int marks, char grade[])
{
    if (marks >= 80)
        strcpy(grade, "A");
    else if (marks >= 60)
        strcpy(grade, "B");
    else if (marks >= 40)
        strcpy(grade, "C");
    else if (marks >= 32)
        strcpy(grade, "D");
    else
        strcpy(grade, "Fail");
}

void displayStudents(struct Student students[], int count)
{
    printf("\nStudent Details:\n");
    printf("---------------------------------------------------\n");
    printf("Name\t\tMarks\t\tGrade\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("%-15s\t%-10d\t%s\n", students[i].name, students[i].marks, students[i].grade);
    }
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int n;

    printf("=========================\n");
    printf("   Created By @Dypixx\n");
    printf("=========================\n");
    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n > MAX_STUDENTS || n <= 0)
    {
        printf("Error: Please enter a valid number of students (1 to %d).\n", MAX_STUDENTS);
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Marks (0-100): ");
        scanf("%d", &students[i].marks);

        if (students[i].marks < 0 || students[i].marks > 100)
        {
            printf("Error: Marks must be between 0 and 100.\n");
            i--;
            continue;
        }
        calculateGrade(students[i].marks, students[i].grade);
    }

    displayStudents(students, n);

    return 0;
}