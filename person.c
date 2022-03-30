#include<stdio.h>
#include<string.h>

struct person
{
    char name[20];
    int age;
    int height;
};
int main()
{
    struct person arr[10];
    int ch=1;
    for(int i=0;i<10&&ch==1;i++)
    {
        printf("Enter name, age and height:\n");
        scanf("%s",&arr[i].name);
        scanf("%d",&arr[i].age);
        scanf("%d",&arr[i].height);
        printf("1 to continue:\n");
        scanf("%d",&ch);
    }
}