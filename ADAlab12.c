//N-Queens Problem using Backtracking:
#include <stdio.h>
#include <stdlib.h>

int solutionCount = 0;

int isSafe(int board[], int row, int col){
    for (int i = 1; i < row; i++){
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void solveNQueen(int board[], int row, int n){
    for (int col = 1; col <= n; col++){
        if (isSafe(board, row, col)){
            board[row] = col;

            if (row == n){
                solutionCount++;

                printf("Solution %d:\n", solutionCount);
                for (int i = 1; i <= n; i++)
                    printf("Queen %d -> Column %d\n", i, board[i]);

                printf("\n");
            }
            else
            {
                solveNQueen(board, row + 1, n);
            }
        }
    }
}

int main(){
    int n;
    int board[20];

    printf("Enter number of queens: ");
    scanf("%d", &n);

    solveNQueen(board, 1, n);

    if (solutionCount == 0)
        printf("No solutions available for %d queens.\n", n);
    else
        printf("Total number of solutions: %d\n", solutionCount);

    return 0;
}
