#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <conio.h>

int main() {
    std::vector<char> inputBuffer;

    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            inputBuffer.push_back(ch);

            if (ch == 27) { // 27�� 'esc' Ű�� ASCII �ڵ��Դϴ�.
                std::cout << "���α׷� ����!" << std::endl;
                break; // ���� ����
            }
        }

        if (inputBuffer.size() >= 3) {
            // �Է��� �׿���, ������ Ȯ��
            if (inputBuffer[0] == '2' &&
                inputBuffer[1] == '6' && inputBuffer[2] == 'a') {
                std::cout << "�Ƶ���! =o" << std::endl;
                inputBuffer.clear(); // �Է� ���� ����
            }
            else if (inputBuffer[0] == '8' && inputBuffer[1] == '2' &&
                inputBuffer[2] == 'a') {
                std::cout << "�ѽ�! =o" << std::endl;
                inputBuffer.clear(); // �Է� ���� ����
            }
            else if (inputBuffer[0] == '8' && inputBuffer[1] == '2' &&
                inputBuffer[2] == 'a') {
                std::cout << "�ϴð� �� ������ �ð��� ! =o" << std::endl;
                inputBuffer.clear(); // �Է� ���� ����
            }
            else if (inputBuffer[0] == '6' && inputBuffer[1] == '6' &&
                inputBuffer[2] == 'a') {
                std::cout << "���� �޸��� ==3" << std::endl;
                inputBuffer.clear(); // �Է� ���� ����
            }
            else {
                std::cout << "�߸��� �Է�" << std::endl;
                inputBuffer.clear(); // �߸��� �Է��� ó���ϰ� ���� ����
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(300)); // 0.3��(300ms) ���
    }

    return 0;
}