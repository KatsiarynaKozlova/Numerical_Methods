
#include <iostream>
#include < windows.h>
#include <iomanip>

using namespace std;



void Initialization(int str, int st, long double** array) {
    cout << " Коэффициенты при неизвестных\n ";
    for (int i = 0; i < str; i++)
    {
        for (int k = 0; k < st - 1; k++)
        {
            cout << " a " << i + 1 << k + 1 << " =====> ";
            cin >> array[i][k];
        }
    }
    cout << " Свободные члены \n";
    for (int i = 0; i < str; i++)
    {
        cout << " f" << i + 1 << " =====> ";
        cin >> array[i][st - 1];
    }
}


void OutArray(int n, int m, long double** array) {
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            if (array[i][k] == -0)  array[i][k] = 0;
            cout << setw(10) << array[i][k];

        } cout << endl;
    }
}
void Turn(int count, int st, long double** array, int str) {
    for (int i = 0; i < st; i++) {
        double temp = array[str][i];
        array[str][i] = array[count][i];
        array[count][i] = temp;
    }
}
void Gaus2(int i, int st, long double** array) {
    double med = 1;
    for (int k = 0; k < st; k++)
    {
        med = array[i + 1][k + 1] / array[i][k];

    }
}
void FirstStroka(int str_2, int st, long double** array, int str) {

    if (array[str][str] == 0 && str != st - 2) {
        int count_str = 0;
        for (int i = str; i < str_2; i++) {
            if (array[i][str] != 0) {
                count_str = i;
                Turn(count_str, st, array, str);
                break;
            }
        }
    }

    if (array[str][str] != 1) {
        if (array[str][str] == -1) {
            for (int i = 0; i < st; i++) {
                array[str][i] = array[str][i] * (-1);
            }
        }
        else {
            double m = 1 / (array[str][str]);
            for (int i = 0; i < st; i++) {
                array[str][i] = array[str][i] * m;
            }
        }
    }
}
void Raznost(int str_2, int st, long double** array, int str) {

    for (int i = str + 1; i < str_2; i++) {
        double m = array[i][str] / array[str][str];
        for (int k = 0; k < st; k++)
        {
            array[i][k] = m * array[str][k] - array[i][k];
        }
    }OutArray(str_2, st, array);
    cout << "\n\n-------------------------------------\n\n";
}

void Raznost2(int str_2, int st, long double** array, int str) {

    for (int i = str - 1; i >=0; i--) {
        double m = array[i][str] / array[str][str];
        for (int k = 0; k < st; k++)
        {
            array[i][k] = m * array[str][k] - array[i][k];
        }
    }OutArray(str_2, st, array);
    cout << "\n\n-------------------------------------\n\n";
}

void Solution(int str, int st, long double** array) {
    for (int i = 0; i < str; i++) {
        cout << " Неизвестный х" << i + 1 << "=====> " << array[i][st - 1];
        cout << endl;
    }
}
int main()
    {
        SetConsoleOutputCP(1251);
        int str;
        cout << "Количество уравнений =====> ";
        cin >> str;
        int st = str + 1;
        cout << "Количество неизвестных =====> "<< st-1;
        long double** array = new long double* [str];

        for (int i = 0; i < str; i++)
        {
            array[i] = new long double[st];
        }
        cout << "\n\n";
        Initialization(str, st, array);
        cout << "\n\n--------- Ваша расширенная матрица ---------\n\n";
        OutArray(str, st, array);
        cout << "\n\n--------------------------------------------\n\n";
        for (int i = 0; i < str; i++) {
            FirstStroka(str, st, array, i);
            Raznost(str, st, array, i);
        }
        for (int i = str - 1; i >= 0; i--) {
            FirstStroka(str, st, array, i);
            Raznost2(str, st, array, i);
        }
        Solution(str, st, array);
        for (int i = 0; i < str; i++)
        {
            delete []array[i];
        }
        delete []array;
        system("pause");
        return 0;
}
