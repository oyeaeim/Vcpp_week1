#include <windows.h> // Window API ��� ���� ����, window ���α׷��ֿ� �ʿ��� �Լ��� ������ ���� ��� ����

// ���� ������ �簢���� ��ġ�� ũ�⸦ ����
int blueRectX; // �Ķ��� �簢���� x��ǥ
int blueRectY; // �Ķ��� �簢���� y��ǥ
int blueRectWidth = 50; // �Ķ��� �簢���� �ʺ�
int blueRectHeight = 50; // �Ķ��� �簢���� ����

int textX; // �ؽ�Ʈ�� X ��ǥ
int textY; // �ؽ�Ʈ�� Y ��ǥ
BOOL showText = FALSE; // ù ������ ȭ�鿡�� �ؽ�Ʈ ����: TRUE�� ��� �ؽ�Ʈ ǥ��

// ������ ���ν��� �ݹ��Լ� ����
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CLOSE: // �����찡 ������ �޼��� �߻� �� PostQuitMessage�Լ� ȣ�� �� ���α׷� ���� ��û
        PostQuitMessage(0);
        return 0;
    case WM_PAINT: { // �׸��� �۾�
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // �Ķ��� �簢���� �ܻ��� ���ֱ� ����
        // ȭ���� ������� Ŭ����
        HBRUSH whiteBrush = CreateSolidBrush(RGB(255, 255, 255)); // ��� (���)
        FillRect(hdc, &ps.rcPaint, whiteBrush);
        DeleteObject(whiteBrush);

        // ��ũ �簢�� �׸���
        RECT pinkRect = { 50, 50, 150, 150 };
        HBRUSH pinkBrush = CreateSolidBrush(RGB(117, 198, 211)); // �ϴû�(������ �簢��)
        FillRect(hdc, &pinkRect, pinkBrush);
        DeleteObject(pinkBrush);

        // �Ķ��� �簢�� �׸���
        RECT blueRect = { blueRectX, blueRectY, blueRectX + blueRectWidth, blueRectY + blueRectHeight };
        HBRUSH blueBrush = CreateSolidBrush(RGB(160, 240, 120)); // �ʷϻ�(�����̴� �簢��)
        FillRect(hdc, &blueRect, blueBrush);
        DeleteObject(blueBrush);

        if (showText) { // �ؽ�Ʈ ǥ��
            // �ؽ�Ʈ ����� ȭ�� �߾ӿ� ��ġ
            RECT textRect;
            GetClientRect(hwnd, &textRect); // ������ Ŭ���̾�Ʈ ���� ũ�⸦ ������
            int textWidth = 100; // �ؽ�Ʈ �ʺ�
            int textHeight = 20; // �ؽ�Ʈ ����
            textX = (textRect.right - textRect.left - textWidth) / 2;
            textY = (textRect.bottom - textRect.top - textHeight) / 2;
            SetTextColor(hdc, RGB(255, 0, 0)); // �ؽ�Ʈ ����
            TextOut(hdc, textX, textY, L"�簢���� ���������ϴ� !", 13);
        }

        EndPaint(hwnd, &ps);
        return 0;
    }
    case WM_KEYDOWN: { // Ű���� �Է� ó��
        int stepSize = 10;
        switch (wParam) { // Ű���� �Է¿� ���� �Ķ��� �簢�� ��ġ ����
        case VK_LEFT:
            blueRectX -= stepSize;
            break;
        case VK_RIGHT:
            blueRectX += stepSize;
            break;
        case VK_UP:
            blueRectY -= stepSize;
            break;
        case VK_DOWN:
            blueRectY += stepSize;
            break;
        }

        // �浹 �˻�
        RECT blueRect = { blueRectX, blueRectY, blueRectX + blueRectWidth, blueRectY + blueRectHeight };
        RECT pinkRect = { 50, 50, 150, 150 };
        if (IntersectRect(&blueRect, &blueRect, &pinkRect)) {
            showText = TRUE; // �浹 �� �ؽ�Ʈ ǥ��
        }
        else {
            showText = FALSE; // �浹�� ���� �� �ؽ�Ʈ ����
        }

        // �����츦 �ٽ� �׸����� ��û
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;
    }
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int main() {
    // ������ Ŭ���� ����ü �ʱ�ȭ
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL); // ���� ����� �ڵ��� ���
    wc.lpszClassName = L"SampleWindowClass";

    // ������ Ŭ���� ���
    RegisterClass(&wc);

    // ������ ����
    HWND hwnd = CreateWindow(L"SampleWindowClass", L"202207071������", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, 100, 100, 800, 600, NULL, NULL, GetModuleHandle(NULL), NULL);

    // �Ķ��� �簢���� �ʱ� ��ġ�� ������ �ϴ����� ����
    blueRectX = 700 - blueRectWidth;
    blueRectY = 500 - blueRectHeight;

    // ������ ǥ��
    ShowWindow(hwnd, SW_SHOWDEFAULT); // SW_SHOWDEFAULT ���

    // �޽��� ����
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}