
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

double sum(int k, int i, long double** array_U, long double** array_L ) {
    double sum = 0;
    for (int j = 0; j <= i - 1; j++) {
        sum = sum + array_L[i][j] * array_U[j][k];
    }
    return sum;
}

double sum2(int k, int i, long double** array_U, long double** array_L) {
    double sum2 = 0; 
    int j = 0;   
    /*do {
        sum2 = sum2 + array_L[i][j] * array_U[j][k];
        j++;
    } while (j < k);*/   
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
            cout << "u" << i << k << " = " << array_U[i][k]<<endl;
        }
        if (i >= k) {
            array_L[i][k] = (array[i][k] - sum2(k, i, array_U, array_L));
            cout << "l" << i << k << " = " << array_L[i][k]<<endl;
        }
    }
}

double sum3(int i, long double **array_L, double *array_Y) {
    double sum = 0;
    for (int k = 0; k <= i - 1; k++) {
        sum = sum + array_L[i][k] * array_Y[k];
    }
    return sum;
}

double sum4(int i, int str, long double ** array_U, double * array_X) {
    double sum = 0;
    for (int k = i + 1; k <= str-1; k++) {
        sum = sum + array_U[i][k] * array_X[k];
    }
    return sum;
}

void functX(int st,  double* array_Y, long double** array, long double** array_U, int str) {
    double* array_X = new double[str];
    //array_X[str - 1] = array_Y[str - 1];
    for (int i = str -1 ; i >= 0; i--) {
        int j = i;
        array_X[i] = array_Y[i] - sum4(j, str, array_U, array_X);
    }
    cout << "------------Вектор-стобец неизвестных --------------\n";
    for (int i = 0; i < str; i++) {
        cout << array_X[i]<<endl;
    }
   
}


void  functY(int st, long double** array_L, long double **array,long double **array_U, int str) {
     double* array_Y = new double[str];
    for (int i = 0; i < str; i++) {
        int j = i;
        array_Y[i] = (array[i][st - 1] - sum3(j, array_L, array_Y)) / array_L[i][i];
    }
    functX(st, array_Y, array, array_U, str);
}



void deleteA(long double** array, int str) {
    for (int i = 0; i < str; i++)
    {
        delete[]array[i];
    }
    delete[]array;
}



int main()
{
    SetConsoleOutputCP(1251);
    int str;
    cout << "Количество уравнений =====> ";
    cin >> str;
    int st = str + 1;
    cout << "Количество неизвестных =====> " << st - 1;

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
    Initialization(str, st, array);
    U_initialization(str, array_U);
    L_initialization(str, array_L);
    cout << "\n\n--------- Ваша расширенная матрица ---------\n\n";
    OutArray(str, st, array);
    cout << "\n\n--------------------------------------------\n\n";
    for (int i = 0; i < str; i++) {
        funct(i, array_U, array_L, array, str);
        cout << "\n\n--------- U матрица ---------\n\n";
        OutArray(str, str, array_U);
        cout << "\n\n--------- L матрица ---------\n\n";
        OutArray(str, str, array_L);
        cout << "\n\n";
    }
    functY(st, array_L,array, array_U,  str);
        
    system("pause");
    return 0;
}
