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
    int studentCount;
    int choice;

    do
    {
        printf("\n1. Add students\n");
        printf("2. List students\n");
        printf("3. Show average\n");
        printf("4. Show highest student\n");
        printf("5. Show lowest student\n");
        printf("6. Exit\n");

        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            //add students
            break;
        case 2:
            // list students
            break;

        case 3:
            // average
            break;

        case 4:
            // highest
            break;

        case 5:
            // lowest
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }

    } while (choice !=6);
    


   

    printf("How many students there will be?\n");
    scanf("%d", &studentCount);

    if (studentCount >= 1 && studentCount <= 10)
    {
        for (int i = 0; i < studentCount; i++)
        {
            printf("Student %d name: ", i + 1);
            scanf("%49s", students[i].name);
            printf("Grade: ");
            scanf("%d", &students[i].grade);

        }
        printf("\nYou entered:\n");

        for (int i = 0; i < studentCount; i++)
        {
            printf("%s - %d\n", students[i].name, students[i].grade);
        }
        
        float average = calculateAverage(students, studentCount);
        printf("Average grade: %.2f\n", average);

        int highest = findHighestGrade(students, studentCount);
        printf("Highest grade is: %d\n", highest);

        int lowest = findLowestGrade(students, studentCount);
        printf("Lowest grade is: %d\n", lowest);

        int highestIndex = findHighestStudentIndex(students, studentCount);
        printf("Highest grade student is: %s and grade is %d\n", students[highestIndex].name, students[highestIndex].grade);

        int lowestIndex = findLowestStudentIndex(students, studentCount);
        printf("Lowest grade student is: %s and grade is %d\n", students[lowestIndex].name, students[lowestIndex].grade);
    }
    else
    {
        printf("Student count must be between 1 and 10.\n");
    }

    
    return 0;

}