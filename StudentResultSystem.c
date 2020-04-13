#include<stdio.h>
#include<stdlib.h>
int roll_number, marks[3], total;
char name[15];
float percentage;
FILE *f;
void add_new_student_details()
{
    int ch, c = 0;
    f = fopen("SRS.txt", "a");
    do
    {
        system("cls");
        printf("\nEnter roll number\n");
        scanf("%d", &roll_number);
        printf("\nEnter name\n");
        scanf("%s", name);
        fprintf(f, "%d %s ", roll_number, name);
        int i;
        total = 0;
        for(i = 0; i <= 2; i++)
        {
            printf("\nEnter marks of subject %d\n", i + 1);
            scanf("%d", &marks[i]);
            fprintf(f, "%d ", marks[i]);
            total += marks[i];
        }
        percentage = (float)total / 300 * 100;
        fprintf(f, "%d %f ", total, percentage);
        printf("\nEnter 1 to add another student details\n");
        scanf("%d", &ch);
        c++;
    }while(ch == 1);
    fclose(f);
    c > 1? printf("\n%d students ", c): printf("\n1 student ");
    printf("details are added successfully\n");
}
void view_all_student_details()
{
    system("cls");
    f = fopen("SRS.txt", "r");
    if(f != NULL)
    {
        printf("\nDetails of all students are\n");
        while(fscanf(f, "%d%s", &roll_number, name) != EOF )
        {
            printf("\nRoll Number: %d\nName: %s\n", roll_number, name);
            int i;
            for(i = 0; i <= 2; i++)
            {
                fscanf(f, "%d", &marks[i]);
                printf("Marks of subject %d: %d\n", i + 1, marks[i]);
            }
            fscanf(f,"%d%f", &total, &percentage);
            printf("Total: %d\nPercentage: %.2f\n", total, percentage);
        }
        fclose(f);
    }
    else
    {
        printf("\nNo student details to view\n");
    }
}
void search_student_details()
{
    system("cls");
    f = fopen("SRS.txt", "r");
    if(f != NULL)
    {
        int r, found = 0;
        printf("\nEnter roll number to be searched\n");
        scanf("%d", &r);
        while(fscanf(f, "%d%s", &roll_number, name) != EOF)
        {
            int i;
            for(i = 0; i <= 2; i++)
            {
                fscanf(f, "%d", &marks[i]);
            }
            fscanf(f, "%d%f", &total, &percentage);
            if(roll_number == r)
            {
                found = 1;
                printf("\nDetails of student are\n");
                printf("\nRoll Number: %d\nName: %s\n", roll_number, name);
                for(i = 0; i <= 2; i++)
                {
                    printf("Marks of subject %d: %d\n", i + 1, marks[i]);
                }
                printf("Total: %d\nPercentage: %.2f\n", total, percentage);
                break;
            }
        }
        fclose(f);
        if(!found)
        {
            printf("\nStudent of %d roll number does not exist\n", r);
        }
    }
    else
    {
        printf("\nNo student details to search\n");
    }
}
int main()
{
    int ch;
    do
    {
        system("cls");
        printf("\nEnter 1 to add new student details\n"
        "Enter 2 to view all students details\n"
        "Enter 3 to search student details\n"
        "Enter 4 to exit from application\n"
        "\nEnter your choice\n");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            add_new_student_details();
            break;
        case 2:
            view_all_student_details();
            break;
        case 3:
            search_student_details();
            break;
        case 4:
            exit(0);
        }
        printf("\nEnter 1 to goto main menu\n");
        scanf("%d", &ch);
    }while(ch == 1);
    return 0;
}
