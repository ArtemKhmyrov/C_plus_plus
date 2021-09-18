#include<iostream>//библиотека для потока ввода-вывода
#include<ctime>//библиотека для 
#include <stdio.h>
using namespace std;//директива


//а. Быстрая сортировка (Quicksort).

void Quicksort(int* s_arr, int one, int two)//быстрая сортировка
{
    int i = one, j = two, x = s_arr[(one + two) / 2];//первый и второй элемент 

    do 
    {
        while (s_arr[i] < x) i++;//пока массив от первого элемента меньше от (1+2элементов)\2 прибавляем 
        while (s_arr[j] > x) j--;

        if (i <= j)//пока первый меньше второго
        {
            if (s_arr[i] > s_arr[j]) swap(s_arr[i], s_arr[j]);//меняем местами наши элементы
            i++;//первый прибавляем
            j--;//второй убавляем 
        }
    } while (i <= j);//идем пока первый меньше или равно второму

    if (i < two)//если первый меньше второго
        Quicksort(s_arr, i, two);//сортируем 
    if (one < j)//и наоборот с другим элементом 
        Quicksort(s_arr, one, j);
}


//b.Сортировка слиянием(Merge sort).
void Merge(int arr[], int l, int m, int r)
{

    int n1, n2, i, j, k;
    n1 = m - l + 1;
    n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of one subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2;


        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        Merge(arr, l, m, r);
    }
}


void Heapsort(int arr[], int n, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        Heapsort(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapsort(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        // вызываем процедуру на уменьшенной куче
        Heapsort(arr, i, 0);
    }
}

int main()//оператор
{
    setlocale(LC_ALL, "RUS");//использование русской клавиатуры
    srand(unsigned(time(NULL)));//для рандомных чисел
    int N;
    cout << "Введите количество элементов: " << endl;
    cin >> N;
    int* A = new int[N];//выделение памяти
    for (int i = 0; i < N; i++)//заполняем строчку
        A[i] = ((rand() % 9));//рандомная матрица не более 9 чисел


    cout << "Вот Ваша матрица:" << endl << endl;//вывод
    for (int i = 0; i < N; i++)//строчка
    {
        cout << A[i] << " ";//вывод

    }

    cout << endl;//отступ




    int start_time = 0, end_time = 0;


    cout << endl;//отступ

    int R;//переменная

    cout << "Введите номер сортировки: " << endl;//вывод
    cout << "Быстрая сортировка - 1;\nСортировка подсчетом - 2;\nПирамидальная сортировка - 3;\n " << endl;//вывод

    cout << endl;//отступ
    cin >> R;//ввод
    cout << endl;//отступ




    switch (R)//оператор
    {


    case 1://кейс 
    {
        start_time = clock();
        Quicksort(A, 0, N - 1);
        end_time = clock();
        int time = end_time - start_time;
        cout << "Время быстрой сортировки " << time << "в минисекундах"  << endl;
        for (int i = 0; i < N; i++)//строчка
        {
            cout << A[i] << " ";//вывод

        }


    }
    break;//закрытие кейса


    case 2://кейс 2
    {
        start_time = clock();
        mergeSort(A, 0, N - 1);
        end_time = clock();
        int time = end_time - start_time;
        cout << "Время сортировки слиянием " << time << "в минисекундах" << endl;
        for (int i = 0; i < N; i++)//строчка
        {
            cout << A[i] << " ";//вывод

        }
    }
    break;//закрытие кейса


    case 3://кейс 3
    {
        start_time = clock();
        heapSort(A, N);
        end_time = clock();
        int time = end_time - start_time;
        cout << "Время пирамидальной сортировки " << time << "в минисекундах" << endl;
        for (int i = 0; i < N; i++)//строчка
        {
            cout << A[i] << " ";//вывод

        }
    }
    break;//закрытие кейса
    }




    system("pause");//задержка консоли
    return 0;//задержка консоли
}





