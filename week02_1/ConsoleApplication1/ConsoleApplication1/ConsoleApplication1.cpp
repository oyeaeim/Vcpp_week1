#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include <windows.h>
#define ESC 27
int main()
{
    char command;
    printf("오예림의 행복한 VC++");
    Sleep(3000);
    system("cls");

    printf("알파벳을 입력해주세요. (q,w,e,r)\n");
    while (1)
    {
        printf("\ncommand>");
        command = _getch();
        if (command == ESC)
        {
            printf("프로그램이 종료되었습니다.");
            break;
        }
        else if (command == 'q')
        {
            printf("qwer 행복해");
        }
        else if (command == 'w')
        {
            printf("과제 너무 좋다");
        }
        else if (command == 'e')
        {
            printf("다음부턴 과제량 3배다");
        }
        else if (command == 'r')
        {
            printf("행복하다요");
        }
        else {
            printf("다시 입력하세요. (q,w,e,r)\n");
        }
    }

}
