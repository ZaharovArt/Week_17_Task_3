// Week_17_Task_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дана матрица порядка M×N (M строк, N столбцов). Необходимо заполнить ее значениями и написать
//функцию, осуществляющую циклический сдвиг строк
//и / или столбцов массива указанное количество раз и в указанную сторону

#include <iostream>

using namespace std;

void cols_rt(int** array, int rows, int cols);
void cols_lt(int** array, int rows, int cols);
void rows_up(int** array, int rows, int cols);
void rows_dn(int** array, int rows, int cols);

void dialog(int cols, int rows, char& answer, int& p);
int** init_array(int rows, int cols);
void complate_array(int** Array, int rows, int cols);
void print_array(int** Array, int rows, int cols);

void main() {
    setlocale(LC_ALL, "russian");
    int rows, cols;

    cout << " Введите количество строк: ";
    cin >> rows;
    cout << " Введите количество сотбцов: ";
    cin >> cols;

    int** array = init_array(rows, cols);
   
    complate_array(array, rows, cols);

    print_array(array, rows, cols);
    
    char action;
    int pos;

    dialog(rows, cols, action, pos);

    switch (action)
    {
    case'r':
        for (int i = 0; i < pos; i++) {
            cols_rt(array, rows, cols);
        }
        break;
    case'l':
        for (int i = 0; i < pos; i++) {
            cols_lt(array, rows, cols);
        }
        break;
    case'u':
        for (int i = 0; i < pos; i++) {
            rows_up(array, rows, cols);
        }
        break;
    case'd':
        for (int i = 0; i < pos; i++) {
            rows_dn(array, rows, cols);
        };
        break;
    }

    print_array(array, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }

    delete[] array;
}


void print_array(int** arr, int rows, int cols) {
    
    for (int i = 0; i < rows; i++) {
        cout << endl;

        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "\t";
    }
    cout << "\n\n";
}

void rows_up(int** array, int rows, int cols) {

    int* tmp = new int[cols];

    for (int j = 0; j < cols; j++)
        tmp[j] = array[0][j];

    for (int i = 0; i < rows - 1; i++)
        for (int j = 0; j < cols; j++)
            array[i][j] = array[i + 1][j];

    for (int j = 0; j < cols; j++)
        array[rows - 1][j] = tmp[j];

    delete[] tmp;
}


void rows_dn(int** array, int rows, int cols) {

    int* tmp = new int[cols];

    for (int j = 0; j < cols; j++)
        tmp[j] = array[rows - 1][j];

    for (int i = rows - 1; i > 0; i--)
        for (int j = 0; j < cols; j++)
            array[i][j] = array[i - 1][j];

    for (int j = 0; j < cols; j++)
        array[0][j] = tmp[j];

    delete[] tmp;
}

void cols_lt(int** array, int rows, int cols) {

    int* tmp = new int[rows];

    for (int i = 0; i < rows; i++)
        tmp[i] = array[i][0];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols - 1; j++)
            array[i][j] = array[i][j + 1];

    for (int i = 0; i < rows; i++)
        array[i][cols - 1] = tmp[i];

    delete[] tmp;
}

void cols_rt(int** array, int rows, int cols) {

    int* tmp = new int[rows];

    for (int i = 0; i < rows; i++)
        tmp[i] = array[i][cols-1];

    for (int i = 0; i < rows; i++)
        for (int j = cols - 1; j > 0; j--)
            array[i][j] = array[i][j - 1];

    for (int i = 0; i < rows; i++)
        array[i][0] = tmp[i];

    delete[] tmp;
}

void dialog(int rows, int cols, char& answer, int& p) {

    do {
        cout << " Двигаем в право  r   Двигаем в лево  l   Вверх  u   Вниз  d   : ";
        cin >> answer;
    } while (answer != 'r' && answer != 'l' && answer != 'u' && answer != 'd');

    if (answer == 'u' || answer == 'd') {

        do {
            cout << "\n двигаем от  1 до " << rows <<" позиции: ";
            cin >> p;
        } while (p < 1 || p > rows);

    }
    else {

        do {
            cout << "\n двигаем от  1 до " << cols << " позиции: ";
            cin >> p;
        } while (p < 1 || p > cols);

    }
}

int** init_array(int rows, int cols) {
    int** pparr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        pparr[i] = new int[cols];
    };
    return pparr;
}

void complate_array(int** Array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Array[i][j] = rand() % 10;
        }
    }
}