#include <stdio.h>
#include <windows.h>

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    // 获取初始光标位置
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int startY = csbi.dwCursorPosition.Y + 1;  // 从当前行下一行开始
    
    // 保存原始颜色
    int originalColor = csbi.wAttributes;
    
    setColor(BACKGROUND_INTENSITY | BACKGROUND_BLUE);
    for (int i = 0; i <10; i++) {
        for (int j = 0; j <= i; j++) {
            gotoXY(j * 2, i+1);
            printf("  "); // 用空格表示楼梯，带背景色
        }
        if(i==9){
            printf(" 🚪 🚪 ");
        }
    }
    
    // 2. 笑脸动画（使用高对比度前景色）
    setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    for (int i = 0; i < 10; i++) {
        int x = i * 2.5;
        int y = startY + i;
        
        // 显示笑脸
        gotoXY(x, y);
        printf("😊😀🙂");
        
        // 恢复上一位置
        if (i > 0) {
            gotoXY((i-1)*2.5, startY + i - 1);
            printf("            ");
        }
        Sleep(600);
    }
    
    // 恢复原始颜色
    setColor(originalColor);
    
    // 移动光标到动画区域下方
    gotoXY(0, startY + 11);
    setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("\n动画结束，你下班了!!!!\n");
    
    return 0;
}