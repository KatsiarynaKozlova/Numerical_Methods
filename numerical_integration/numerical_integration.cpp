#include <windows.h>
#include <iostream>
#include<math.h>

using namespace std;

//Первообразная функция
double main_function(double x) {
    return((pow(log(x), 3)) / 3);
}

//Подынтегральная функция
double integrand(double x) {
    return ((log(x)*log(x)) / x);
}
  
double f_g(double x, double c) {
    return (c * ((2 * pow(log(3 + 2 * x), 2)) / (3 + 2 * x)));
}

void Right_Rectangle(double h) {
    double x = 1;
    double summa = 0;
    cout << "\n Метод правых прямоугольников\n";
    while (x < 5) {
        summa = summa + h*integrand(x);
        x = x + h;
    }
    cout << " Интеграл равен =====> " << summa;
}

void Left_Rectangle(double h) {
    double x = 1 + h ;
    double summa = 0;
    cout << "\n\n Метод левых прямоугольников\n";
    while (x <= 5) {
        summa = summa + h*integrand(x);
        x = x + h;
    }
    cout << " Интеграл равен =====> " << summa;
}

void Central_Rectangle(double h) {
    double x = 1;
    double summa = 0;
    cout << "\n\n Метод центральных прямоугольников\n";
    while (x < 5) {
        summa = summa + h * integrand(x + h / 2);
        x = x + h;
    }
    cout << " Интеграл равен =====> " << summa;
}

void Trapeze(double h) {
    double x = 1;
    double summa = 0;
    cout << "\n\n Метод Трапеций\n";
    while (x < 5) {
        summa = summa + (h / 2) * (integrand(x) + integrand(x + h));
        x = x + h;
    }
    cout << " Интеграл равен =====> " << summa;
}

void Parabola(double n) {
    double h = 2 / n;
    double x = 1 + h;
    double summa =integrand(x-h);
    cout << "\n\n Метод парабол\n";
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
    cout << " Интеграл равен =====> " << summa;
}

void Gaus() {
    cout << "\n\n Метод Гаусса\n";
    double g[6] = { 0.93246951 , 0.66120939, 0.23861919,-0.93246951,-0.66120939, -0.23861919 };
    double c[6] = { 0.1713249, 0.36076157, 0.46791393, 0.1713249, 0.36076157, 0.46791393 };
    double summa = 0;
    for (int i = 0; i < 6; i++) {
        summa = summa + f_g(g[i], c[i]);
    }
    cout << " Интеграл равен =====> " << summa<<"\n\n";
}





int main() {

    SetConsoleOutputCP(1251);
    
    double n;

    cout << "   Численное дифференцирование \n\n";
    cout << "Введите число отрезков разбиения ======> ";
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