#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>
using namespace std;

// Функція для обчислення значення залежно від x
double calculateFunction(double x, double R1, double R2) {
    if (x >= -6 * R2 && x < -2 * R2) {
        return -R2; // Пряма лінія
    }
    else if (x >= -2 * R2 && x < -R2) {
        return sqrt(R2 * R2 - (x + R2) * (x + R2)); // Коло з центром (-R2, 0)
    }
    else if (x >= -R2 && x < 0) {
        return x; // Пряма лінія
    }
    else if (x >= 0 && x < R1) {
        return -sqrt(R1 * R1 - x * x); // Коло з центром (0, 0)
    }
    else if (x >= R1 && x <= 2 * R1 + 1) {
        return (x - R1) / 2; // Пряма лінія
    }
    return 0; // Значення поза областю
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double R1, R2, xStart, xEnd, dx;

    // Введення параметрів
    cout << "Введіть значення R1: ";
    cin >> R1;
    cout << "Введіть значення R2: ";
    cin >> R2;
    cout << "Введіть початкове значення x (xпоч): ";
    cin >> xStart;
    cout << "Введіть кінцеве значення x (xкін): ";
    cin >> xEnd;
    cout << "Введіть крок dx: ";
    cin >> dx;

    // Заголовок таблиці
    cout << setw(10) << "x" << setw(20) << "f(x)" << endl;
    cout << "----------------------------" << endl;

    // Цикл для обчислення значень функції
    for (double x = xStart; x <= xEnd; x += dx) {
        double y = calculateFunction(x, R1, R2);
        cout << setw(10) << x << setw(20) << y << endl;
    }

    return 0;
}
