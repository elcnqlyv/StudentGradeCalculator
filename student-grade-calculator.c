#include <stdio.h>

typedef struct
{
    char name[50];
    int grade;
} Student;

float calculateAverage(Student students[], int studentCount)
{
    float sum = 0;
    for (int i = 0; i < studentCount; i++)
    {
        sum = sum + students[i].grade;
    }
    float average = sum / studentCount;
    return average;
}

int findHighestGrade(Student students[], int studentCount)
{
    int highest = students[0].grade;
    for (int i = 1; i < studentCount; i++)
    {
        if (students[i].grade>highest)
        {
            highest = students[i].grade;
        }

        
    }
    
    return highest;
    
}

int findLowestGrade(Student students[], int studentCount)
{
    int lowest = students[0].grade;
    for (int i = 1; i < studentCount; i++)
    {
        if (students[i].grade<lowest)
        {
            lowest = students[i].grade;
        }

        
    }
    
    return lowest;
    
}

int findHighestStudentIndex(Student students[], int studentCount)
{
    int highestIndex = 0;
    for (int i = 1; i < studentCount; i++)
    {
        if (students[i].grade>students[highestIndex].grade)
        {
            highestIndex = i;
        }
        
    }
    
    return highestIndex;

}


int findLowestStudentIndex(Student students[], int studentCount)
{
    int lowestIndex = 0;
    for (int i = 1; i < studentCount; i++)
    {
        if (students[i].grade<students[lowestIndex].grade)
        {
            lowestIndex = i;
        }
        
    }
    
    return lowestIndex;

}

int main()
{
    Student students[10];
    int studentCount = 0;
    int choice;

    do
    {
        printf("\n1. Add student\n");
        printf("2. List students\n");
        printf("3. Show average\n");
        printf("4. Show highest student\n");
        printf("5. Show lowest student\n");
        printf("6. Exit\n");

        printf("Choose: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Please enter a number between 1 and 6.\n");
        
            int ch = getchar();
        
            while (ch != '\n' && ch != EOF)
            {
                ch = getchar();
            }
        
            continue;
        }

        switch (choice)
        {
        case 1:
            //add students
            {
            if (studentCount>=10)
            {
                printf("Student list is full.\n");
                break;
            }
                                   
            printf("Student name: ");
            scanf("%49s", students[studentCount].name);

            printf("Grade: ");
            if (scanf("%d", &students[studentCount].grade) != 1)
            {
                printf("Grade must be a number.\n");
                int ch = getchar();
                while (ch != '\n' && ch != EOF)
                {
                    ch = getchar();
                }
                break;
            }
        
            if (students[studentCount].grade < 0 || students[studentCount].grade > 100)
            {
                printf("Grade must be between 0 and 100.\n");
                break;
            }
            studentCount++;
            printf("Student added successfully. \n");
            break; 
            }
        case 2:
            // list students
            if (studentCount == 0)
            {
                printf("No students have been added yet.\n");
                break;
            }
            for (int i = 0; i < studentCount; i++)
            {
                printf("Name of student: %s\n", students[i].name);
                printf("Grade of the student: %d\n", students[i].grade);
            }
            break;
        case 3:
            // average
            if (studentCount == 0)
            {
                printf("No students have been added yet.\n");
                break;
            }
            {
            float average = calculateAverage(students, studentCount);
            printf("Average grade is: %.2f\n", average);
            break;
            }
        case 4:
            // highest
            if (studentCount == 0)
            {
                printf("No students have been added yet.\n");
                break;
            }
            {
            int highestGrade = findHighestGrade(students, studentCount);
            int highestIndex = findHighestStudentIndex(students, studentCount);
            printf("Highest grade is: %d\n", highestGrade);
            printf("Highest student is: %s\n", students[highestIndex].name);
            break;
            }
        case 5:
            // lowest
            {
            if (studentCount == 0)
            {
                printf("No students have been added yet.\n");
                break;
            }
            int lowestGrade = findLowestGrade(students, studentCount);
            int lowestIndex = findLowestStudentIndex(students, studentCount);
            printf("Lowest grade is: %d\n", lowestGrade);
            printf("Lowest student is: %s\n", students[lowestIndex].name);
            break;
            }
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }

    } while (choice !=6);
    
}