#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>
using namespace std;

// ������� ��� ���������� �������� ������� �� x
double calculateFunction(double x, double R1, double R2) {
    if (x >= -6 * R2 && x < -2 * R2) {
        return -R2; // ����� ���
    }
    else if (x >= -2 * R2 && x < -R2) {
        return sqrt(R2 * R2 - (x + R2) * (x + R2)); // ���� � ������� (-R2, 0)
    }
    else if (x >= -R2 && x < 0) {
        return x; // ����� ���
    }
    else if (x >= 0 && x < R1) {
        return -sqrt(R1 * R1 - x * x); // ���� � ������� (0, 0)
    }
    else if (x >= R1 && x <= 2 * R1 + 1) {
        return (x - R1) / 2; // ����� ���
    }
    return 0; // �������� ���� �������
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double R1, R2, xStart, xEnd, dx;

    // �������� ���������
    cout << "������ �������� R1: ";
    cin >> R1;
    cout << "������ �������� R2: ";
    cin >> R2;
    cout << "������ ��������� �������� x (x���): ";
    cin >> xStart;
    cout << "������ ������ �������� x (x��): ";
    cin >> xEnd;
    cout << "������ ���� dx: ";
    cin >> dx;

    // ��������� �������
    cout << setw(10) << "x" << setw(20) << "f(x)" << endl;
    cout << "----------------------------" << endl;

    // ���� ��� ���������� ������� �������
    for (double x = xStart; x <= xEnd; x += dx) {
        double y = calculateFunction(x, R1, R2);
        cout << setw(10) << x << setw(20) << y << endl;
    }

    return 0;
}
