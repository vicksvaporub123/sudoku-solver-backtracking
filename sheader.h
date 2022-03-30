void print_sudoku(int matrix[][9]);
int number_unassigned(int matrix[][9],int *row, int *col);
int is_safe(int matrix[][9],int n, int r, int c);
int user_safe(int matrix[][9]);
int solve_sudoku(int matrix[][9]);
void user_solve(int mat[][9]);
void matrix_diff(int ch);
