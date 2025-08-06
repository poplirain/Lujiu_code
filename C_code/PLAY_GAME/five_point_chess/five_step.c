#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define SIZE 15  // 棋盘大小
#define EMPTY ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

// 初始化棋盘
void init_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

// 打印棋盘
void print_board(char board[SIZE][SIZE]) {
    // 打印列号
    printf("  ");
    for (int i = 0; i < SIZE; i++) {
        printf(" %2d ", i);
    }
    printf("\n");
    
    // 打印棋盘行
    for (int i = 0; i < SIZE; i++) {
        printf(" %2d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// 检查是否获胜
int check_win(char board[SIZE][SIZE], int row, int col, char player) {
    // 检查方向: 水平、垂直、两条对角线
    int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    
    for (int d = 0; d < 4; d++) {
        int count = 1;  // 当前位置已经有一个棋子
        
        // 正向检查
        int r = row + directions[d][0];
        int c = col + directions[d][1];
        while (r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == player) {
            count++;
            r += directions[d][0];
            c += directions[d][1];
        }
        
        // 反向检查
        r = row - directions[d][0];
        c = col - directions[d][1];
        while (r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == player) {
            count++;
            r -= directions[d][0];
            c -= directions[d][1];
        }
        
        if (count >= 5) {
            return 1;  // 获胜
        }
    }
    return 0;
}

// 检查棋盘是否已满
int is_board_full(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    SetConsoleOutputCP(65001); // 设置控制台编码为 UTF-8
    char board[SIZE][SIZE];
    int currentPlayer = 1;  // 玩家1先行
    int row, col;
    int moves = 0;
    
    init_board(board);
    
    printf("欢迎来到五子棋游戏！\n");
    printf("玩家1: %c, 玩家2: %c\n", PLAYER1, PLAYER2);
    printf("输入行号和列号进行落子（例如：7 7）\n");
    
    while (1) {
        print_board(board);
        printf("\n玩家 %d 的回合: ", currentPlayer);
        
        // 获取玩家输入
        if (scanf("%d %d", &row, &col) != 2) {
            printf("输入无效！请重新输入两个整数。\n");
            while (getchar() != '\n'); // 清除输入缓冲区
            continue;
        }
        
        // 检查坐标是否有效
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("坐标超出范围！请重新输入（0-%d）。\n", SIZE-1);
            continue;
        }
        
        // 检查位置是否为空
        if (board[row][col] != EMPTY) {
            printf("该位置已有棋子！请重新选择。\n");
            continue;
        }
        
        // 放置棋子
        char piece = (currentPlayer == 1) ? PLAYER1 : PLAYER2;
        board[row][col] = piece;
        moves++;
        
        // 检查获胜
        if (check_win(board, row, col, piece)) {
            print_board(board);
            printf("\n恭喜！玩家 %d 获胜！\n", currentPlayer);
            break;
        }
        
        // 检查平局
        if (is_board_full(board)) {
            print_board(board);
            printf("\n平局！棋盘已满。\n");
            break;
        }
        
        // 切换玩家
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    
    return 0;
}