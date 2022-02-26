

#include <iostream>
#include<windows.h>
#include<iomanip>
using namespace std;

double fx(double x) {
    return(x * exp(x) + x);
}

double fx_right(double x, double step) {
    return ((fx(x + step) - fx(x)) / step);
}

double fx_left(double x, double step) {
    return ((fx(x) - fx(x - step)) / step);
}

double fx_central(double x, double step) {
    return ((fx(x + step) - fx(x - step)) / 2 * step);
}

double fx_tochnoe(double x) {
    return (exp(x) + x * exp(x) + 1);
}

double fx_fx(double x, double step) {
    return ((fx(x + step) - 2 * fx(x) + fx(x - step)) / (step * step));
}

double ffx_tochnoe(double x) {
    return (exp(x) * (2 + x));
}

void table(double left, double right, double step) {
    cout << "Значение x(i)";
    while (right >= left) {
        cout << setw(11) << left;
        left = left + step;
    }
}

void f_right(double x, double step, double right) {
    double x_right = x;
    cout << "\n\nПравая произв.";
    while (x_right + step <= right) {
        cout << setw(11) << fx_right(x_right, step);
        x_right = x_right + step;
    }
    cout << setw(11) << "-";
}

void f_left(double x, double step, double right) {
    double x_left = x + step;
    cout << "\n\n Левая произв." << setw(11) << "-";
    while (x_left <= right) {
        cout << setw(11) << fx_left(x_left, step);
        x_left = x_left + step;
    }
}

void f_central(double x, double step, double right) {
    double x_central = x + step;
    cout << "\n\n Центр.произв." << setw(11) << "-";
    while (x_central <= right - step) {
        cout << setw(11) << fx_central(x_central, step);
        x_central = x_central + step;
    }
    cout << setw(11) << "-";
}

void f_tochnoe(double x, double step, double right) {
    double x_tochnoe = x;
    cout << "\n\n Точная произв";
    while (x_tochnoe <= right) {
        cout << setw(11) << fx_tochnoe(x_tochnoe);
        x_tochnoe = x_tochnoe + step;
    }
}

void f_fx(double x, double step, double right) {
    double x_x = x + step;
    cout << "\n\n Вторая произв" << setw(11) << '-';
    while (x_x <= right - step) {
        cout << setw(11) << fx_fx(x_x, step);
        x_x = x_x + step;
    }
    cout << setw(11) << "-";
}

void f_fx_tochnoe(double x, double step, double right) {
    cout << "\n\n Точная вторая";
    while (x <= right) {
        cout << setw(11) << ffx_tochnoe(x);
        x = x + step;
    }
    cout << endl;
}


int main()
{
    SetConsoleOutputCP(1251);
    double step;
    double x = -1;
    double left = -1;
    double right = 0;

    cout << "Шаг =========> ";
    cin >> step;

    cout << "\n ЧИСЛЕННОЕ ДИФФЕРЕНЦИРОВАНИЕ \n\n ";

    table(left, right, step);
    f_right(x, step, right);
    f_left(x, step, right);
    f_central(x, step, right);
    f_tochnoe(x, step, right);
    f_fx(x, step, right);
    f_fx_tochnoe(x, step, right);

    system("pause");
    return 0;

}

