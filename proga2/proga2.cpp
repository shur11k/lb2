#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void shell(int* items, int count)
{

    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void qs(int* items, long int left, long int right) //вызов функции: qs(items, 0, count-1);
{
    long int i, j;
    long int x, y;

    i = left; j = right;

    /* выбор компаранда */
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}

int compare(const void* x1, const void* x2)
{
    return (*(int*)x1 - *(int*)x2);
}

void osnova(int n) {

    int* arr11 = new int[n];
    int* arr12 = new int[n];
    int* arr13 = new int[n];
    int* arr21 = new int[n];
    int* arr22 = new int[n];
    int* arr23 = new int[n];
    int* arr31 = new int[n];
    int* arr32 = new int[n];
    int* arr33 = new int[n];
    int* arr41 = new int[n];
    int* arr42 = new int[n];
    int* arr43 = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr11[i] = 10 + rand() % 90;
        arr12[i] = 10 + rand() % 90;
        arr13[i] = 10 + rand() % 90;
    }

    for (int i = 0; i < n; i++)
    {
        arr21[i] = i + 1;
        arr22[i] = i + 1;
        arr23[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        arr31[i] = n - i;
        arr32[i] = n - i;
        arr33[i] = n - i;
    }

    for (int i = 0; i < n; i++)
    {
        if (i < n / 2) {
            arr41[i] = i + 1;
            arr42[i] = i + 1;
            arr43[i] = i + 1;
        }
        else {
            arr41[i] = n - i;
            arr42[i] = n - i;
            arr43[i] = n - i;
        }


    }

    cout << "кол-во элмементов: " << n << endl;
    cout << setw(15) << " " << setw(15) << "shell" << setw(15) << "qs" << setw(15) << "qsort";


    ///////////////////////////////////
    double time1 = clock();
    shell(arr11, n);
    double time2 = clock();

    cout << endl << setw(15) << "Рандом" << setw(15) << (time2 - time1) / CLOCKS_PER_SEC;

    time1 = clock();
    qs(arr12, 0, n - 1);
    time2 = clock();

    cout << setw(15) << (time2 - time1) / CLOCKS_PER_SEC;

    time1 = clock();
    qsort(arr13, n, sizeof(int), compare);
    time2 = clock();

    cout << setw(15) << (time2 - time1) / CLOCKS_PER_SEC;
    //////////////////////////////////////
    time1 = clock();
    shell(arr21, n);
    time2 = clock();

    cout << endl << setw(15) << "Возрастание" << setw(15) << (time2 - time1) / CLOCKS_PER_SEC;

    time1 = clock();
    qs(arr22, 0, n - 1);
    time2 = clock();

    cout << setw(15) << (time2 - time1) / CLOCKS_PER_SEC;

    time1 = clock();
    qsort(arr23, n, sizeof(int), compare);
    time2 = clock();

    cout << setw(15) << (time2 - time1) / CLOCKS_PER_SEC;
    ////////////////////////////////////// 
    time1 = clock();
    shell(arr31, n);
    time2 = clock();

    cout << endl << setw(15) << "Убывание" << setw(15) << (time2 - time1) / CLOCKS_PER_SEC;

    time1 = clock();
    qs(arr32, 0, n - 1);
    time2 = clock();

    cout << setw(15) << (time2 - time1) / CLOCKS_PER_SEC;

    time1 = clock();
    qsort(arr33, n, sizeof(int), compare);
    time2 = clock();

    cout << setw(15) << (time2 - time1) / CLOCKS_PER_SEC;
    //////////////////////////////////////
    time1 = clock();
    shell(arr41, n);
    time2 = clock();

    cout << endl << setw(15) << "Возраст/убыва" << setw(15) << (time2 - time1) / CLOCKS_PER_SEC;

    time1 = clock();
    qs(arr42, 0, n - 1);
    time2 = clock();

    cout << setw(15) << (time2 - time1) / CLOCKS_PER_SEC;

    time1 = clock();
    qsort(arr43, n, sizeof(int), compare);
    time2 = clock();

    cout << setw(15) << (time2 - time1) / CLOCKS_PER_SEC;
    ////////////////////////////////////// 
}

int main(void)
{
    setlocale(0, "");

    osnova(1000);
    cout << endl << endl << endl;
    osnova(2000);
    cout << endl << endl << endl;
    osnova(4000);
    cout << endl << endl << endl;
    osnova(5000);
    cout << endl << endl << endl;
    osnova(6000);
    cout << endl << endl << endl;
    osnova(7000);

    cin.get();
    return 0;
}