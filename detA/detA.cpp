
#include <iostream>
#include < windows.h>
#include <iomanip>

using namespace std;



void Initialization(int str, long double** array) {
    cout << " Члены матрицы \n ";
    for (int i = 0; i < str; i++)
    {
        for (int k = 0; k < str; k++)
        {
            cout << " a " << i + 1 << k + 1 << " =====> ";
            cin >> array[i][k];
        }
    }
}


void OutArray(int n, long double** array) {
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (array[i][k] == -0)  array[i][k] = 0;
            cout << setw(10) << array[i][k];

        } cout << endl;
    }
}

void OutArray2(int n, int m,  double** array) {
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            if (array[i][k] == -0)  array[i][k] = 0;
            cout << setw(10) << array[i][k];

        } cout << endl;
    }
}

void U_initialization(int str, long double** array) {
    for (int i = 0; i < str; i++) {
        for (int k = 0; k < str; k++) {
            if (i == k) array[i][k] = 1;
            else if (i > k) array[i][k] = 0;
            else array[i][k] = NULL;

        }
    }
}
void L_initialization(int str, long double** array) {
    for (int i = 0; i < str; i++) {
        for (int k = 0; k < str; k++) {
            array[i][k] = NULL;
        }
    }
}

double sum(int k, int i, long double** array_U, long double** array_L) {
    double sum = 0;
    for (int j = 0; j <= i - 1; j++) {
        sum = sum + array_L[i][j] * array_U[j][k];
    }
    return sum;
}

double sum2(int k, int i, long double** array_U, long double** array_L) {
    double sum2 = 0;
    int j = 0;
    for (int j = 0; j <= k - 1; j++) {
        sum2 = sum2 + array_L[i][j] * array_U[j][k];
    }
    return sum2;
}



void  funct(int st, long double** array_U, long double** array_L, long double** array, int str) {
    for (int j = 0; j < str; j++) {
        int i = j;
        int k = st;
        if (i < k) {
            array_U[i][k] = (array[i][k] - sum(k, i, array_U, array_L)) / array_L[i][i];           
        }
        if (i >= k) {
            array_L[i][k] = (array[i][k] - sum2(k, i, array_U, array_L));
        }
    }
}

double detA(int str, long double** array_L) {
    double det = 1;
    for (int i = 0; i < str; i++)
    {       
            det *= array_L[i][i];        
    }
    return det;
}



void deleteA(long double** array, int str) {
    for (int i = 0; i < str; i++)
    {
        delete[]array[i];
    }
    delete[]array;
}

double sumY(long double** array_L, double** array_Y, int str , int st, int str_L) {
    double sum = 0;   
    for (int k = 0; k < st ; k++) {
        sum = sum + array_L[str_L][k]* array_Y[str][k];
    }      
    return sum;
}

void functY(long double** array_L, double** array_Y, double **array_E, int str, int st) {
    int count_L = 0;
    for (int i = 0; i < st; i++) {
        array_Y[str][i] = (array_E[str][i] - sumY(array_L, array_Y, str, i, count_L))/array_L[i][i];
        cout << array_Y[str][i]<<endl;
        count_L++;
    }    
}

double sumX(long double** array_U, double** array_X, int str, int st, int str_L, int stt) {
    double sum = 0;

    for (int k = stt-1; k > st; k--) {    
        sum = sum + array_U[str_L][k] * array_X[str][k];
    }
    return sum;
}

void functX(long double** array_U, double** array_Y, double** array_X, int str, int st) {
    int count_U = st-1;
    for (int i = st - 1; i >= 0; i--) {
        
         if (i == st - 1) array_X[str][i] = array_Y[str][i];
         else {
             
             array_X[str][i] = (array_Y[str][i] - sumX(array_U, array_X, str, i, count_U, st)) / array_U[i][i];
         }
        count_U--;
    }cout << endl;
}

void FirstStroka(int str_2, int st, double** array, int str) {
    
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
void Raznost(int str_2, int st,  double** array, int str) {

    for (int i = str + 1; i < str_2; i++) {
        double m = array[i][str] / array[str][str];
        for (int k = 0; k < st; k++)
        {
            array[i][k] = m * array[str][k] - array[i][k];
        }
    }OutArray2(str_2, st, array);
    cout << "\n\n----------------------------------------------------------------\n\n";
}

void Raznost2(int str_2, int st,  double** array, int str) {

    for (int i = str - 1; i >= 0; i--) {
        double m = array[i][str] / array[str][str];
        for (int k = 0; k < st; k++)
        {
            array[i][k] = m * array[str][k] - array[i][k];
        }
    }OutArray2(str_2, st, array);
    cout << "\n\n----------------------------------------------------------------\n\n";
}

int main()
{
    SetConsoleOutputCP(1251);
    int str;
    cout << "Количество уравнений =====> ";
    cin >> str;
    int st = str;

    long double** array = new long double* [str];
    for (int i = 0; i < str; i++)
    {
        array[i] = new long double[st];
    }

    long double** array_L = new long double* [str];
    for (int i = 0; i < st; i++)
    {
        array_L[i] = new long double[st];
    }

    long double** array_U = new long double* [str];
    for (int i = 0; i < st; i++)
    {
        array_U[i] = new long double[st];
    }


    cout << "\n\n";
    Initialization(str, array);
    U_initialization(str, array_U);
    L_initialization(str, array_L);
    cout << "\n\n--------- Ваша матрица ---------\n\n";
    OutArray(str, array);
    cout << "\n\n--------------------------------------------\n\n";
    for (int i = 0; i < str; i++) {
        funct(i, array_U, array_L, array, str);
    }
    cout << "--------- L матрица ---------\n\n";
    OutArray(str, array_L);
    cout << "\n\n--------- U матрица ---------\n\n";
    OutArray(str, array_U);

    cout << "\n\n Определитель вашей матрицы =====> " << detA(str, array_L) << "\n\n";
    cout << "\n\n--------------------------------------------\n\n";
    cout << "\n\n-------- Нахождение обратной матрицы -------\n\n";
    double** array_Y = new double* [str];
    for (int i = 0; i < str; i++)
    {
        array_Y[i] = new double[st];
    }
    double** array_X = new double* [str];
    for (int i = 0; i < str; i++)
    {
        array_X[i] = new double[st];
    }
    double** array_E = new double* [str];
    for (int i = 0; i < str; i++)
    {
        array_E[i] = new double[st];
    }
    for (int i = 0; i < str; i++)
    {
        for (int k = 0; k < str; k++)
        {
            if (i == k) { array_E[i][k] = 1; }
            else array_E[i][k] = 0;
        }
    }
    for (int i = 0; i < str; i++)
    {
        cout << "Вектор Y" << i+1 << endl;
        functY(array_L, array_Y, array_E, i, st);            
    }
    for (int i = 0; i <str; i++)
    {       
        functX(array_U, array_Y, array_X, i, st);
    }
    cout << "\n\n--------- Обратная матрица ---------\n\n ";
    for (int i = 0; i < str; i++)
    {
        for (int k = 0; k <str; k++)
        {
            cout << setw(12)<< array_X[i][k] << "   ";
        }cout << endl;
    }
    cout << "\n\n----------------- Метод Жордана-Гаусса ---------------------------\n\n";
    int st_zh = st * 2;
    double** array_ZHG = new double* [str];
    for (int i = 0; i < str; i++)
    {
        array_ZHG[i] = new double[st_zh];
    }
    for (int i = 0; i < str; i++)
    {
        for (int k = 0; k < str; k++)
        {
            array_ZHG[i][k] = array[i][k];
        }
    }
    for (int i = 0; i < str; i++)
    {
        for (int k = str; k < st_zh; k++)
        {
            array_ZHG[i][k] = array_E[i][k-st];
        }
    }
    OutArray2(str, st_zh, array_ZHG);
    cout << "\n\n--------------------------------------------\n\n";
    for (int i = 0; i < str; i++) {
        FirstStroka(str, st_zh, array_ZHG, i);
        Raznost(str, st_zh, array_ZHG, i);
    }
    for (int i = str - 1; i >= 0; i--) {
        FirstStroka(str, st_zh, array_ZHG, i);
        Raznost2(str, st_zh, array_ZHG, i);
    }
    cout << "\n\n--------- Обратная матрица ---------\n\n ";
    for (int i = 0; i < str; i++)
    {
        for (int k = str; k < st_zh; k++)
        {
            cout << setw(12) << array_ZHG[i][k];
        }cout << endl;
    }
    system("pause");
    return 0;
}
