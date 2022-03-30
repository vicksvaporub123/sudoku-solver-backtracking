#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "sheader.h"
#define SIZE 9

//function to print sudoku
void print_sudoku(int matrix[][9])
{
/*
Function designed to display sudoku board
*/
    for(int i=0;i<9;i++)
    {
        if(i%3==0 && i!=0)
            printf("\t\t--------------------------------\n\t\t");
        else
            printf("\t\t");
        for(int j=0;j<9;j++)
        {
            if(j%3==0 && j!=0)
                printf(" | ");
            if(j!=8)
                printf(" %d ",matrix[i][j]);
            else
                printf(" %d\n",matrix[i][j]);
            
        }
    }
    printf("\n\n");
}

//function to check if all cells are assigned or not
//if there is any unassigned cell
//then this function will change the values of
//row and col accordingly
int number_unassigned(int matrix[][9],int *row, int *col)
{
    int num_unassign = 0;
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            //cell is unassigned
            if(matrix[i][j] == 0)
            {
                //changing the values of row and col
                *row = i;
                *col = j;
                //there is one or more unassigned cells
                num_unassign = 1;
                return num_unassign;
            }
        }
    }
    return num_unassign;
}

//function to check if we can put a
//value in a particular cell or not
int is_safe(int matrix[][9],int n, int r, int c)
{
    int i,j;
    //checking in row
    for(i=0;i<SIZE;i++)
    {
        //there is a cell with same value
        if(matrix[r][i] == n)
            return 0;
    }
    //checking column
    for(i=0;i<SIZE;i++)
    {
        //there is a cell with the value equal to i
        if(matrix[i][c] == n)
            return 0;
    }
    //checking sub matrix
    int row_start = (r/3)*3;
    int col_start = (c/3)*3;
    for(i=row_start;i<row_start+3;i++)
    {
        for(j=col_start;j<col_start+3;j++)
        {
            if(matrix[i][j]==n)
                return 0;
        }
    }
    return 1;
}

//function to check if user entered sudoku is valid or not
int user_safe(int matrix[][9])
{
    int i;
    int j;
    int temp;
    int count=1;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(matrix[i][j]!=0)
            {
                temp=matrix[i][j];
                matrix[i][j]=-1;
                if(!(is_safe(matrix,temp,i,j)))
                {
                    matrix[i][j]=temp;
                    count=0;
                }
                else
                    matrix[i][j]=temp;
            }
        }
    }
    return count;
}

//function to solve sudoku
//using backtracking
int solve_sudoku(int matrix[][9])
{
    int row;
    int col;
    //if all cells are assigned then the sudoku is already solved
    //pass by reference because number_unassigned will change the values of row and col
    if(number_unassigned(matrix,&row, &col) == 0)
        return 1;
    int n,i;
    //number between 1 to 9
    for(i=1;i<=SIZE;i++)
    {
        //if we can assign i to the cell or not
        //the cell is matrix[row][col]
        if(is_safe(matrix,i, row, col))
        {
            matrix[row][col] = i;
            //backtracking
            if(solve_sudoku(matrix))
                return 1;
            //if we can't proceed with this solution
            //reassign the cell
            matrix[row][col]=0;
        }
    }
    return 0;
}

//function to allow user to solve the sudoku themselves
void user_solve(int mat[][9])
{
    int final[9][9];
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            final[i][j]=mat[i][j];
        }
    }
    print_sudoku(final);
    int choice;
    do
    {
        printf("========================================\n");
        printf("1. Change table\n2. Check if sudoku is solved\n0. Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
            system("cls");
            print_sudoku(final);
            int i;int j;int val=0;
            printf("Enter row and column of value to change:\n");
            scanf("%d %d",&i,&j);
            if(i<1||i>9||j<1||j>9)
            {
                printf("Invalid indexing\n");
            }
            else if(final[i-1][j-1]!=0)
            {
                printf("This location already has a value assigned\n");
            }
            if(final[i-1][j-1]==0)
            {
                printf("Enter value to input:\n");
                scanf("%d",&val);
                if(val<1||val>9)
                {
                    printf("Value must be between 1-9\n");
                }
                else
                {
                    final[i-1][j-1]=val;
                    system("cls");
                    print_sudoku(final);
                }
            }
        }
        else if(choice==2)
        {
            int x=0;
            for(int i=0;i<SIZE&&x==0;i++)
            {
                for(int j=0;j<SIZE;j++)
                {
                    if(final[i][j]==0)
                    {
                        printf("The sudoku is incomplete\n");
                        x=1;
                        break;
                    }
                    else if(final[i][j]!=0)
                    {
                        int temp=final[i][j];
                        final[i][j]=-1;
                        if(!(is_safe(final,temp,i,j)))
                        {
                            printf("Repetition error in the sudoku\n");
                            x=1;
                            final[i][j]=temp;
                            choice=0;
                            break;
                        }
                        final[i][j]=temp;
                    }
                }
            }
            if(x==0)
            {
                printf("This solution is correct\nReturning to the main menu\n");
                choice=0;
            }
        }
    }while(choice!=0);
}

//function containing the sudoku of different difficulties
void matrix_diff(int ch)
{
    int measy[9][9]={{4,0,5,2,6,9,7,8,1},
                    {6,8,2,5,7,1,4,9,3},
                    {1,9,7,8,3,4,5,6,2},
                    {8,2,0,1,9,5,3,4,7},
                    {3,7,4,6,8,2,9,1,0},
                    {9,5,1,7,4,3,6,2,8},
                    {0,1,9,3,2,6,8,7,4},
                    {2,4,8,9,5,7,1,3,6},
                    {7,6,3,4,1,8,0,5,9}};
    int mmed[9][9]={{0,4,2,9,0,0,0,0,7},
                    {5,0,0,4,2,0,9,0,0},
                    {0,0,7,0,8,0,0,0,0},
                    {0,0,0,0,0,0,4,0,0},
                    {7,3,0,5,9,0,0,6,0},
                    {2,0,9,0,6,0,0,0,8},
                    {8,5,0,0,4,0,0,0,6},
                    {0,2,0,0,0,1,3,4,0},
                    {0,0,0,2,5,0,0,0,0}};
    int mhard[9][9]={{0,1,3,0,0,0,0,0,0},
                    {0,0,0,5,0,0,0,0,4},
                    {5,0,0,0,2,7,0,0,3},
                    {0,5,0,0,6,0,0,0,0},
                    {7,3,0,0,0,5,0,2,0},
                    {9,0,0,0,0,0,0,0,0},
                    {0,7,0,0,9,0,8,0,2},
                    {2,0,0,0,0,0,1,9,0},
                    {0,0,0,0,1,0,0,0,0}};
    if(ch==1)
        user_solve(measy);
    else if(ch==2)
        user_solve(mmed);
    else if(ch==3)
        user_solve(mhard);
    else
        printf("Invalid choice\n");
}