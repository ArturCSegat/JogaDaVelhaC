#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void drawGrid(int **grid){ // no aditionals parameters are needed as the grid can be assumed to be 3x3
    for (int i = 0; i < 3; i++){
        printf("\n");
        for (int k = 0; k < 3; k++){
          if(grid[i][k] == 0){
            printf("  %d %d |   ",k ,i);
          }
          else{
              if(grid[i][k] == -1){
                printf("    O |   ");
              }
              if(grid[i][k] == 1){
                printf("    X |   ");
              }

          }
        }
    }
}

void placeInGrid(int **grid, int x, int y, int place){
    if(grid[x][y] == 0){
    grid[x][y] = place;
    }
}

int compareArrays(int a[], int b[], int len){
    int i;
    for(i = 0; i < len; i++) {
        if(a[i] != b[i]){
            return 0;
        }
    }

    return 1;
}

void getMatrixDiagonal1(int **grid, int n, int * ret){
    for (int i = 0; i < n; i++){
       ret[i] = grid[i][i];
    }

}

void getMatrixDiagonal2(int **grid,int n, int * ret){
    int k = n - 1;
    for (int i = 0; i < n; i++){
        ret[i] = grid[i][k];
        k--;
    }
}
int checkForWinner(int **grid){
    int p1[3] = {1, 1, 1};
    int p2[3] = {-1, -1, -1};

    for(int i = 0; i<3; i++){
        if(compareArrays(grid[i], p1, 3) == 1){
            return 1;
        }
        // checks rows

        if(compareArrays(grid[i], p2, 3) == 1){
            return -1;
        }
        int col[3];

        for(int j = 0; j<3; j++){
            col[j] = grid[j][i]; // trasnposes the matrix to get col array
        }

        if(compareArrays(col, p1, 3) == 1){
            return 1;
        }
        // checks cols

        if(compareArrays(col, p2, 3) == 1){
            return -1;
        }

        int diag[3];


        int *a = (int*)malloc(3 * sizeof(int));
        int *b = (int*)malloc(3 * sizeof(int));
                                                // gets diagonals
        getMatrixDiagonal1(grid, 3, a);
        getMatrixDiagonal2(grid, 3, b);

        if(compareArrays(a, p1, 3) == 1){
            return 1;
        }
        // checks rows

        if(compareArrays(a, p2, 3) == 1){
            return -1;
        }

        if(compareArrays(b, p1, 3) == 1){
            return 1;
        }
        // checks rows

        if(compareArrays(b, p2, 3) == 1){
            return -1;
        }
            free(a);
            free(b);
    }

    // now to check for a draw

    int empty_counter = 9;

    for (int i = 0; i < 3; i++){
        for (int k = 0; k < 3; k++){
          if(grid[i][k] != 0){
              empty_counter--;
          }
        }
      }

    if(empty_counter == 0){
      return 2;
    }

    return 0;

}


int main(){
    int **grid = (int**)malloc(3 * sizeof(int*)); // define a primeira dimenção da matriz grid como 3

    for (int i = 0; i<3; i++){
        grid[i] = (int*)malloc(3 * sizeof(int)); // defines a segunda dimeção de grid como 3
    }

    for (int i = 0; i < 3; i++){
        for (int k = 0; k < 3; k++){
            grid[i][k] = 0; // define a grade como uma 3x3 onde todas as casas saõ coupadas por 0 (grade limpa)
        }
    }

    int curr_player = -1;

    int winner = 0;

    while(winner == 0){

    drawGrid(grid);
    printf("vez do jogador %d \n", curr_player);

    int x, y;

    printf("entre com a cordenada da sua jogada: ");

    scanf("%d %d", &y, &x);

    placeInGrid(grid, x, y, curr_player);

    system("cls");
    curr_player *= -1;

    winner = checkForWinner(grid);
    }

    if(winner == 2){
      printf("\nDeu velha =(");
    }
    else{
    printf("\nO vencedor e %d!", winner);
    }

    free(grid);


    getch();

    return 0;
}
