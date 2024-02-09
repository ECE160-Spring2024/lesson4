#include <stdio.h>
#include <globals.h>

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

