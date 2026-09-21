// . Student Result Analysis • Store the roll number, name, and marks in five subjects for N students using structures. • Calculate the total, percentage, and grade of each student. • Display the class topper, students who failed in one or more subjects, and the class average.
#include <stdio.h>
struct Student
{
    int roll;
    char name[30];
    int marks[5];
    int total;
    float percentage;
    char grade;
};
int main()
{
    int n, i, j;
    float classTotal = 0;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student s[n];
    int topper = 0;
    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        s[i].total = 0;
        printf("Enter marks of 5 subjects:\n");
        for(j = 0; j < 5; j++)
        {
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }
        s[i].percentage = s[i].total / 5.0;
        if(s[i].percentage >= 90)
            s[i].grade = 'A';
        else if(s[i].percentage >= 75)
            s[i].grade = 'B';
        else if(s[i].percentage >= 50)
            s[i].grade = 'C';
        else
            s[i].grade = 'F';
        classTotal += s[i].percentage;
        if(s[i].total > s[topper].total)
            topper = i;
    }
    printf("\nClass Topper: %s (%d)\n", s[topper].name, s[topper].total);
    printf("\nFailed Students:\n");
    for(i = 0; i < n; i++)
    {
        int fail = 0;
        for(j = 0; j < 5; j++)
        {
            if(s[i].marks[j] < 40)
                fail = 1;
        }
        if(fail)
            printf("%s\n", s[i].name);
    }
    printf("\nClass Average = %.2f\n", classTotal / n);
    return 0;
}
