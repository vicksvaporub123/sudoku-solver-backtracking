#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "sheader.h"
#define SIZE 9

//main function to receive options
int main()
{
    int matrix[9][9]={{0}};
    int ch1;
    do
    {
        printf("========================================\n");
        printf("\t\tMain Menu\n");
        printf("1. Solve the sudoku yourself\n2. Computer solves an unsolved sudoku using backtracking\n0. Exit the program\n");
        printf("Enter choice:");
        scanf("%d",&ch1);
        if(ch1==1)
        {
            int chs;
            printf("Enter easy(1), medium(2) or hard(3) option:");
            scanf("%d",&chs);
            if(chs==1||chs==2||chs==3)
            {
                matrix_diff(chs);
            }
            else
                printf("Invalid choice\n");
                fflush(stdin);
            
        }
        else if(ch1==2)
        {
            print_sudoku(matrix);
            int choice;
            do
            {
                printf("1. Change table\n2. Solve and exit\n");
                printf("Enter choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                    {
                        system("cls");
                        print_sudoku(matrix);
                        int i;int j;int val;
                        printf("Enter row and column of value to change:\n");
                        scanf("%d %d",&i,&j);
                        if(i<1||i>9||j<1||j>9)
                        {
                           printf("Invalid indexing\n");
                           break;
                        }
                        printf("Enter value to input:\n");
                        scanf("%d",&val);
                        if(val<1||val>9)
                        {
                            printf("Value must be between 1-9\n");
                            break;
                        }
                        matrix[i-1][j-1]=val;
                        system("cls");
                        print_sudoku(matrix);
                        break;
                    }
                    case 2:
                    {
                        if(user_safe(matrix))
                        {
                            if (solve_sudoku(matrix))
                            {   
                                print_sudoku(matrix);
                            }
                            else
                                printf("No solution\n");
                        }
                        else
                            printf("Unsolvable sudoku entered\n");
                        break;
                    }
                    default:
                    {
                        printf("Invalid input\n");
                        break;
                    }
                }
            }while(choice!=2);
        }
        else if(ch1==0)
            printf("Exiting program...\n");
        else
            printf("Invalid option\n");
    }while(ch1!=0);
    return 0;
}