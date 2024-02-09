#include <stdio.h>

char board[3][3];
char computer, user;

int user_first();
void init_board();
void print_board();
void play_game();
void user_move();
void computer_move();
int symbol_won(char c);
int main() {
    
    init_board();
    print_board();
    if(user_first()) {
        user='X';
        computer='O';
    } else {
        user='O';
        computer='X';
    }
    play_game();

    return 0;
}

void user_move() {
    int x, y;
    do {
        printf("Where would you like to place your letter?\n");
        scanf("%d %d", &x, &y);
    } while (x>=0 && x<=2 && y>=0 && y<=2 && board[x][y]!='-');
    board[x][y] = user;
    // TODO have to check within bounds
    // TODO make sure it's blank
}

void play_game() {

    int turn = 1;
    for ( ; turn <= 9; turn++) {
        if (turn%2==1) {
            if(user=='X'){
                user_move();
            } else {
                computer_move();
            }
        } else {
            if(user=='O'){
                user_move();
            } else {
                computer_move();
            }
        }
        print_board();
        if(symbol_won(user)) {
            printf("You not stupid!\n");
            return;
        } 
        if(symbol_won(computer)){ 
            printf("HAHAHA. That's why we're taking over the world!\n");
            return;
        }
    }

}

int symbol_won(char letter) {
    for(int col=0; col<=2; col++) {
        int a,b,c;
        a=board[0][col];
        b=board[1][col];
        c=board[2][col];
        if(a==b && b==c && a==letter) {
            return 1;
        }
    }
    for(int row=0; row<=2; row++) {
        int a,b,c;
        a=board[row][0];
        b=board[row][1];
        c=board[row][2];
        if(a==b && b==c && a==letter) {
            return 1;
        }
    }

    if (board[0][0]==board[1][1] &&
        board[1][1]==board[2][2] &&
        board[0][0]==letter) {
        return 1;
    }
    if (board[0][2]==board[1][1] &&
        board[1][1]==board[2][0] &&
        board[1][1]==letter) {
        return 1;
    }
    return 0;
}

void computer_move() {

    // win

    // block

    // center
    if(board[1][1]=='-') {
        board[1][1]=computer;
    }

    else if (board[0][0]=='-') { // corner
        board[0][0]=computer;
    } 

    else if (board[0][2]=='-') { // corner
        board[0][2]=computer;
    } 
    
    else if (board[2][0]=='-') { // corner
        board[2][0]=computer;
    } 

    else if (board[2][2]=='-') { // corner
        board[2][2]=computer;
    } 
    // side
    else if (board[0][1]=='-') {
        board[0][1]=computer;
    }
    else if (board[1][0]=='-') {
        board[1][0]=computer;
    }
    else if (board[1][2]=='-') {
        board[1][2]=computer;
    }
    else if (board[2][1]=='-') {
        board[2][1]=computer;
    }


}

void init_board() {
    int row, col;
    for(row=0; row<=2; row++) {
        for(col=0; col<=2; col++) {
            board[row][col] = '-';
        }
    }
}

void print_board() {
    int row, col;
    for(row=0; row<=2; row++) {
        for(col=0; col<=2; col++) {
            printf("%c", board[row][col]);
        }
        printf("\n");
    }
    
}

int user_first() {
    char choice;
    int stupidityCount = 0;
    do {
        if(stupidityCount++ == 0) {
            printf("Would you like to go first? (Y/N)\n");
        } else {
            printf("You stupid x %d. Enter Y/N\n", stupidityCount-1);
        }
        scanf("%c", &choice);
        getchar();
    } while(choice!='Y'&&choice!='N');
    if (choice=='Y') {
        return 1;
    }
    return 0;
}
