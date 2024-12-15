#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// 屏幕的宽度和高度
#define WIDTH 80
#define HEIGHT 20

// 字符集合
const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_+-=[]{}|;':\",.<>/? ";

// 绘制单个字符
void drawChar(int x, int y, char c) {
    printf("\033[%d;%dH%c", y, x, c);
}

// 主函数
int main() {
    srand((unsigned int)time(NULL));

    while (1) {
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                char c = charset[rand() % (sizeof(charset) - 1)];
                drawChar(x, y, c);
            }
        }
        printf("\033[2J");  // 清屏
        fflush(stdout);  // 立即刷新输出缓冲区
        usleep(100000);  // 暂停 100 毫秒
    }

    return 0;
}
