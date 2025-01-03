#include <stdio.h>

//the fuction is to check Board and return 1 (win) or return 0 (fail)
int check_Board(char board[3][3]) {
    //check row and row whehter and diagonal can link to a line
    int main_diagonal = 1, side_diagonal = 1;
    for(int i = 0; i < 3; i++) {
        //check row
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 'X') {
                break;
            }
            if(j == 2) {
                return 1;
            } 
        }
        //check col
        for(int j = 0; j < 3; j++) {
            if(board[j][i] != 'X') {
                break;
            }
            if(j == 2) {
                return 1;
            }
        }
        //check diagonal and store the result
        for(int j = 0; j < 3; j++) {
            if(main_diagonal && i == j && board[i][i] != 'X') {
                main_diagonal = 0;
            }
            if(side_diagonal && i == 2 - j && board[i][j] != 'X') {
                side_diagonal = 0;
            }
        }

    }

    //check the two diagonal line result
    if(main_diagonal || side_diagonal) {
        return 1;
    }
    return 0;
}

//the fuction is to print the current board
void printBoard(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if(j < 2) {
                printf("|");
            }
        }
        puts("");
        if(i < 2) {
            printf("---|---|---\n");
        }
    }
}
//the fuction is tp update the Board after each throw
void hit_Board_and_print(char board[3][3], int num) {
    int cur_num = 1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == 'X' && cur_num == num) {
                printBoard(board);
                puts("\nSorry, you had hit this position. Try again");
                return;
            }
            if(cur_num == num) {
                board[i][j] = 'X';
            }
            cur_num++;
        }
    }
    printBoard(board);
}

int main() {
    //Board Inationalized
    char Board[3][3];
    int cur_num = 1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            Board[i][j] = cur_num  + '0';
            cur_num++;
        }
    }
    
    puts("Welcome to the Baseball Game!");
    printBoard(Board);
    puts("");
    //player can throw 4 times
    int throw_chances = 4;
    while(throw_chances > 0) {
        int Inum; //Inum is to store the number which player hit
        printf("Enter the number of the grid you hit (1-9). or enter 0 if you missed: ");
        scanf("%d", &Inum);
        //player missed
        if(Inum == 0) {
            printBoard(Board);
            puts("\nMissed! Try again.");
        }
        //player hit 
        else if(Inum >= 1 && Inum <= 9) {
            hit_Board_and_print(Board, Inum);
        }
        //out of range(0 ~ 9)
        else {
            //Invaild value check
            while(Inum < 0 || Inum > 9) {
                puts("Invalid value\nPlease enter the number between 0 to 9");
                scanf("%d", &Inum);
            }
            if(Inum == 0) {
                printBoard(Board);
                puts("\nMissed! Try again.");
            }
            else if(Inum >= 1 && Inum <= 9) {
                hit_Board_and_print(Board, Inum);
            }
        }
        throw_chances--;
    }
    //is_win is to store the player whether win the game (1 = true = win, 0 = false = fail) 
    int is_win;
    is_win = check_Board(Board);
    if(is_win) {
        puts("\nCongratulations, you win!");
    }
    else {
        puts("\nGame over, you didn't complete the line.");
    }
    puts("-----Program ends-----");
    return 0;
}