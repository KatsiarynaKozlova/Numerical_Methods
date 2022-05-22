

#include <iostream>
#include < windows.h>
#include <iomanip>

using namespace std;



void Initialization(int str, int st, long double** array) {
    cout << " Коэффициенты при неизвестных\n ";
    for (int i = 0; i < str; i++)
    {
        for (int k = 0; k < st; k++)
        {

            if (k == st - 1) {
                cout << " f" << i + 1 << " =====> ";
                cin >> array[i][st - 1];
            }
            else {
                cout << " a " << i + 1 << k + 1 << " =====> ";
                cin >> array[i][k];
            }
        }
    }
}


void OutArray(int n, int m, long double** array) {
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            if (array[i][k] == -0)  array[i][k] = 0;
            cout << setw(12) << array[i][k];
        } cout << endl;
    }
}


void Gaus2(int i, int st, long double** array) {
    double med = 1;
    for (int k = 0; k < st; k++)
    {
        med = array[i + 1][k + 1] / array[i][k];
    }
}

void Turn(int count, int st, long double** array, int str) {
    for (int i = 0; i < st; i++) {
        double temp = array[str][i];
        array[str][i] = array[count][i];
        array[count][i] = temp;
    }
}
bool CheckZero(int str_2, int st, long double** array, int str) {
   
    bool is_z = false;
    double sum = 0;
    for (int i = 0; i < st - 1; i++) {
        sum = array[str][i] + sum;
    }
    if (sum == 0 && array[str][st - 1] != 0) { is_z = true; }
    return is_z;
}

bool CheckZero2(int str_2, int st, long double** array, int str) {

    bool is_z = false;
    double sum = 0;
    for (int i = 0; i < st - 1; i++) {
        sum = array[str][i] + sum;
    }
    if (sum == 0 && array[str][st - 1] == 0) { is_z = true; }
    return is_z;
}


bool CheckSol(long double** array, int str, int st) {
    bool is_sol = false;
    int count = 0;   
    for (int k = 0; k < str; k++) {
        double sum = 0;
        for (int i = 0; i < st - 1; i++) {
            sum = array[k][i] + sum;
        }
        if (sum == 0) count++;
    }
    if (count < st - 1 && count>0) {
        is_sol = true;
    }
    return is_sol;
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
        if (array[str][str] != 1 && array[str][str] != 0) {
            double m = 1 / (array[str][str]);
            for (int i = 0; i < st; i++) {
                array[str][i] = array[str][i] * m;
            }

            OutArray(str_2, st, array);
            cout << "\n\n-------------------------------------\n\n";
        }
    }


void Raznost(int str_2, int st, long double** array, int str) {
    int st2 = str;
    if (array[str][st2] == 0) {
        for (int i = st2; i < st; i++)
        {
            if (array[str][i] != 0) {
                st2 = i; break;
            }
        }
    }
    if (array[str][st2] != 0) {
        for (int i = str + 1; i < str_2; i++) {
            double m = array[i][st2] / array[str][st2];
            for (int k = 0; k < st; k++)
            {
                array[i][k] = m * array[str][k] - array[i][k];
            }
        }
        OutArray(str_2, st, array);
        cout << "\n\n-------------------------------------\n\n";
    }
}

double sumx(double *arx,long double** ar, int i, int st) {
    double sum = 0;
    for (int j = i + 1; j <= st-2; j++) {
        sum = sum + arx[j] * ar[i][j];
    }
    return sum;
}

void Roots(long double** array, int str, int st) {
    double *array_x = new double[str];
    for (int i = str-1; i>=0 ; i--)
    {
            array_x[i] = array[i][st - 1] - sumx(array_x, array, i, st);
    }
    for (int i = 0; i < str; i++)
    {
        cout << array_x[i] << endl;
    }
}

int re(long double** array, int str, int st) {
    int count = 0;
    int k = 100;
    int d = str - 1;
    for (int i = 0; i < str; i++)
    {
        if (CheckZero2(str, st, array, i)) {
            k = i;
            for (int j = 0; j < st;j++)
            {
                array[k][j] = array[d][j];
            }
            d--;
            count++;
        }
    }
    return count;
}



int main()
{
    SetConsoleOutputCP(1251);
    int str, st;
    cout << "Количество уравнений =====> ";
    cin >> str;
    cout << "Количество неизвестных =====> ";
    cin >> st;
    st = st + 1;
    long double** array = new long double* [str];
    double* infa = new double[st - 1];
    for (int i = 0; i < str; i++)
    {
        array[i] = new long double[st];
    }
    cout << "Elemets\n";
    Initialization(str, st, array);
    cout << "\n\n-------------------------------------\n\n";
    OutArray(str, st, array);
    cout << "\n\n-------------------------------------\n\n";
    for (int i = 0; i < str; i++) {
       if(CheckZero(str, st, array, i)) goto beck;
        FirstStroka(str, st, array, i);
        Raznost(str, st, array, i);
        str=str-re(array, str, st);
    }
    OutArray(str, st, array);
    cout << "\n\n-------------------------------------\n\n";
    if (str< st-1) goto infinity;
    Roots(array, str, st);
    goto end;
beck:
    cout << "Система не имеет решений\n\n";
    goto end;
infinity:
    cout << "Система имеет бесконечное число решений\n\n";

end:
    system("pause");
    return 0;
}

