#include <iostream>
#include<math.h>
#include<windows.h>
#include<iomanip>
using namespace std;

double f(double x) {
    return (tan(0.5 * x + 0.2) - x * x);
}

//производная
double f1(double x) {
    return ((0.5) / (cos(0.5 * x + 0.2) * cos(0.5 * x + 0.2)) - 2 * x);
}

//формула для касательной
double fx(double x, double xprev) {
    return x - ((f(x) * (x - xprev)) / (f(x) - f(xprev)));
}

//формула для хорд
double fx2(double x0, double xk) {
    return (xk - ((f(xk)) * (xk - x0) / (f(xk) - f(x0))));
}

//формула для метода хорд
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
    cout << "Отделение корней\n";
    cout << "Введите левую границу, правую границу и шаг алгоритма\n";
    cin >> left >> right >> step;
    cout << setw(10) << "Step" << setw(10) << "  x    " << setw(10) << "   y   \n";

    roots(left, right, step);
    cout << endl;

    ////////////////////////////////////
    double left2, right2;
    double x;
    int count = 0;

    cout << " Метод дихотомии \n\n";
    cout << "Введите левую и правую границу\n";
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
    cout << " \n Приближённый корень   " << x << " получен за " << count << " итераций\n\n";

    ///////////////////////////////////


    cout << " Метод секущих\n";
    double x_0, x_1, x_2;
    count = 0;
    cout << "Введите х0 и х1\n";
    cin >> x_0 >> x_1;

    while (fabs(x_1 - x_0) > 0.001) {
        x_2 = fx(x_1, x_0);

        x_0 = x_1; x_1 = x_2;
        count++;
    }
    cout << "Приближённый корень  " << x_1 << " получен за " << count << " итераций\n\n";
    /////////////////////////////////////

    cout << "Метод Ньютона\n";

    count = 0;
    
    cout << "Введите х0\n";
    cin >> x_0;
    do {
        x_0 = x_0 - f(x_0) / f1(x_0);
    } while (fabs(f(x_0)) > 0.001);

    cout << "Приближённый корень " << x_0 << " получен за " << count << " итераций\n\n";
    //////////////////////////////////////

    cout << "Метод хорд\n";
    count = 0;
    x_2 = 0;
    cout << "Введите х0 и х1\n";
    cin >> x_0 >> x_1;

    while (fabs(x_2 - x_1) > 0.001) {
        x_2 = fh(x_0, x_1);

        cout << x_2 << endl;
        x_1 = x_2;
        count++;
    }
    cout << "Приближённый корень  " << x_2 << "получен за " << count << " итераций\n\n";

    system("pause");
    return 0;

}