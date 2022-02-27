#include <windows.h>
#include <iostream>
#include<math.h>

using namespace std;

//������������� �������
double main_function(double x) {
    return((pow(log(x), 3)) / 3);
}

//��������������� �������
double integrand(double x) {
    return ((log(x)*log(x)) / x);
}
  
double f_g(double x, double c) {
    return (c * ((2 * pow(log(3 + 2 * x), 2)) / (3 + 2 * x)));
}

void Right_Rectangle(double h) {
    double x = 1;
    double summa = 0;
    cout << "\n ����� ������ ���������������\n";
    while (x < 5) {
        summa = summa + h*integrand(x);
        x = x + h;
    }
    cout << " �������� ����� =====> " << summa;
}

void Left_Rectangle(double h) {
    double x = 1 + h ;
    double summa = 0;
    cout << "\n\n ����� ����� ���������������\n";
    while (x <= 5) {
        summa = summa + h*integrand(x);
        x = x + h;
    }
    cout << " �������� ����� =====> " << summa;
}

void Central_Rectangle(double h) {
    double x = 1;
    double summa = 0;
    cout << "\n\n ����� ����������� ���������������\n";
    while (x < 5) {
        summa = summa + h * integrand(x + h / 2);
        x = x + h;
    }
    cout << " �������� ����� =====> " << summa;
}

void Trapeze(double h) {
    double x = 1;
    double summa = 0;
    cout << "\n\n ����� ��������\n";
    while (x < 5) {
        summa = summa + (h / 2) * (integrand(x) + integrand(x + h));
        x = x + h;
    }
    cout << " �������� ����� =====> " << summa;
}

void Parabola(double n) {
    double h = 2 / n;
    double x = 1 + h;
    double summa =integrand(x-h);
    cout << "\n\n ����� �������\n";
    while (x < 5) {
        summa = summa + 4  * integrand(x);
        x = x + 2 * h;
    }
    x = 1 + 2 * h;
    while (x < 5) {
        summa = summa + 2 * integrand(x);
        x = x + 2*h;
    }
    summa = (h/ 3)*(summa + integrand(5));
    cout << " �������� ����� =====> " << summa;
}

void Gaus() {
    cout << "\n\n ����� ������\n";
    double g[6] = { 0.93246951 , 0.66120939, 0.23861919,-0.93246951,-0.66120939, -0.23861919 };
    double c[6] = { 0.1713249, 0.36076157, 0.46791393, 0.1713249, 0.36076157, 0.46791393 };
    double summa = 0;
    for (int i = 0; i < 6; i++) {
        summa = summa + f_g(g[i], c[i]);
    }
    cout << " �������� ����� =====> " << summa<<"\n\n";
}





int main() {

    SetConsoleOutputCP(1251);
    
    double n;

    cout << "   ��������� ����������������� \n\n";
    cout << "������� ����� �������� ��������� ======> ";
    cin >> n;

    double h = 4 / n;

    Right_Rectangle(h);
    Left_Rectangle(h);
    Central_Rectangle(h);
    Trapeze(h);
    Parabola(n);
    Gaus();

    system("pause");
    return 0;
}