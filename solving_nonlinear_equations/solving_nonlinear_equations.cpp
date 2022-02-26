#include <iostream>
#include<math.h>
#include<windows.h>
#include<iomanip>
using namespace std;

double f(double x) {
    return (tan(0.5 * x + 0.2) - x * x);
}

//�����������
double f1(double x) {
    return ((0.5) / (cos(0.5 * x + 0.2) * cos(0.5 * x + 0.2)) - 2 * x);
}

//������� ��� �����������
double fx(double x, double xprev) {
    return x - ((f(x) * (x - xprev)) / (f(x) - f(xprev)));
}

//������� ��� ����
double fx2(double x0, double xk) {
    return (xk - ((f(xk)) * (xk - x0) / (f(xk) - f(x0))));
}

//������� ��� ������ ����
double fh(double x, double xprev) {
    return x - ((f(x) * (x - xprev)) / (f(x) - f(xprev)));
}

double roots(double l, double r, double s) {
    int count = 0;
    while (l < r) {
        cout << setw(10) << count << setw(10) << l << setw(10) << f(l) << endl;
        l = l + s;
        count++;
    }
    return 0;
}



int main()
{
    SetConsoleOutputCP(1251);

    double left, right, step;
    cout << "��������� ������\n";
    cout << "������� ����� �������, ������ ������� � ��� ���������\n";
    cin >> left >> right >> step;
    cout << setw(10) << "Step" << setw(10) << "  x    " << setw(10) << "   y   \n";

    roots(left, right, step);
    cout << endl;

    ////////////////////////////////////
    double left2, right2;
    double x;
    int count = 0;

    cout << " ����� ��������� \n\n";
    cout << "������� ����� � ������ �������\n";
    cin >> left2 >> right2;

    cout << setw(10) << "[a, b]" << setw(16) << "x" << setw(16) << "y" << endl;
    x = ((left2 + right2) / 2);

    while (f(x) != 0) {
        x = ((left2 + right2) / 2);

        cout << "[" << left2 << "," << right2 << "]   ";
        cout << setw(16) << x;
        cout << setw(16) << f(x) << endl;
        if (((right2 - left2) / 2) < 0.001) break;
        if (f(x) < 0) left2 = x;
        else right2 = x;
        count++;
    }
    cout << " \n ����������� ������   " << x << " ������� �� " << count << " ��������\n\n";

    ///////////////////////////////////


    cout << " ����� �������\n";
    double x_0, x_1, x_2;
    count = 0;
    cout << "������� �0 � �1\n";
    cin >> x_0 >> x_1;

    while (fabs(x_1 - x_0) > 0.001) {
        x_2 = fx(x_1, x_0);

        x_0 = x_1; x_1 = x_2;
        count++;
    }
    cout << "����������� ������  " << x_1 << " ������� �� " << count << " ��������\n\n";
    /////////////////////////////////////

    cout << "����� �������\n";

    count = 0;
    
    cout << "������� �0\n";
    cin >> x_0;
    do {
        x_0 = x_0 - f(x_0) / f1(x_0);
    } while (fabs(f(x_0)) > 0.001);

    cout << "����������� ������ " << x_0 << " ������� �� " << count << " ��������\n\n";
    //////////////////////////////////////

    cout << "����� ����\n";
    count = 0;
    x_2 = 0;
    cout << "������� �0 � �1\n";
    cin >> x_0 >> x_1;

    while (fabs(x_2 - x_1) > 0.001) {
        x_2 = fh(x_0, x_1);

        cout << x_2 << endl;
        x_1 = x_2;
        count++;
    }
    cout << "����������� ������  " << x_2 << "������� �� " << count << " ��������\n\n";

    system("pause");
    return 0;

}