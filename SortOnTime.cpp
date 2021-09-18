#include<iostream>//���������� ��� ������ �����-������
#include<ctime>//���������� ��� 
#include <stdio.h>
using namespace std;//���������


//�. ������� ���������� (Quicksort).

void Quicksort(int* s_arr, int one, int two)//������� ����������
{
    int i = one, j = two, x = s_arr[(one + two) / 2];//������ � ������ ������� 

    do 
    {
        while (s_arr[i] < x) i++;//���� ������ �� ������� �������� ������ �� (1+2���������)\2 ���������� 
        while (s_arr[j] > x) j--;

        if (i <= j)//���� ������ ������ �������
        {
            if (s_arr[i] > s_arr[j]) swap(s_arr[i], s_arr[j]);//������ ������� ���� ��������
            i++;//������ ����������
            j--;//������ �������� 
        }
    } while (i <= j);//���� ���� ������ ������ ��� ����� �������

    if (i < two)//���� ������ ������ �������
        Quicksort(s_arr, i, two);//��������� 
    if (one < j)//� �������� � ������ ��������� 
        Quicksort(s_arr, one, j);
}


//b.���������� ��������(Merge sort).
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
    // �������������� ���������� ������� ��� ������
    int l = 2 * i + 1; // ����� = 2*i + 1
    int r = 2 * i + 2; // ������ = 2*i + 2

 // ���� ����� �������� ������� ������ �����
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // ���� ����� ������� ������� �� ������
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // ���������� ����������� � �������� ���� ���������� ���������
        Heapsort(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // ���������� ���� (�������������� ������)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapsort(arr, n, i);

    // ���� �� ������ ��������� �������� �� ����
    for (int i = n - 1; i >= 0; i--)
    {
        // ���������� ������� ������ � �����
        swap(arr[0], arr[i]);

        // �������� ��������� �� ����������� ����
        Heapsort(arr, i, 0);
    }
}

int main()//��������
{
    setlocale(LC_ALL, "RUS");//������������� ������� ����������
    srand(unsigned(time(NULL)));//��� ��������� �����
    int N;
    cout << "������� ���������� ���������: " << endl;
    cin >> N;
    int* A = new int[N];//��������� ������
    for (int i = 0; i < N; i++)//��������� �������
        A[i] = ((rand() % 9));//��������� ������� �� ����� 9 �����


    cout << "��� ���� �������:" << endl << endl;//�����
    for (int i = 0; i < N; i++)//�������
    {
        cout << A[i] << " ";//�����

    }

    cout << endl;//������




    int start_time = 0, end_time = 0;


    cout << endl;//������

    int R;//����������

    cout << "������� ����� ����������: " << endl;//�����
    cout << "������� ���������� - 1;\n���������� ��������� - 2;\n������������� ���������� - 3;\n " << endl;//�����

    cout << endl;//������
    cin >> R;//����
    cout << endl;//������




    switch (R)//��������
    {


    case 1://���� 
    {
        start_time = clock();
        Quicksort(A, 0, N - 1);
        end_time = clock();
        int time = end_time - start_time;
        cout << "����� ������� ���������� " << time << "� ������������"  << endl;
        for (int i = 0; i < N; i++)//�������
        {
            cout << A[i] << " ";//�����

        }


    }
    break;//�������� �����


    case 2://���� 2
    {
        start_time = clock();
        mergeSort(A, 0, N - 1);
        end_time = clock();
        int time = end_time - start_time;
        cout << "����� ���������� �������� " << time << "� ������������" << endl;
        for (int i = 0; i < N; i++)//�������
        {
            cout << A[i] << " ";//�����

        }
    }
    break;//�������� �����


    case 3://���� 3
    {
        start_time = clock();
        heapSort(A, N);
        end_time = clock();
        int time = end_time - start_time;
        cout << "����� ������������� ���������� " << time << "� ������������" << endl;
        for (int i = 0; i < N; i++)//�������
        {
            cout << A[i] << " ";//�����

        }
    }
    break;//�������� �����
    }




    system("pause");//�������� �������
    return 0;//�������� �������
}





