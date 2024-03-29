﻿#include<iostream>//библиотека для потока ввода-вывода
#include<ctime>//библиотека для 
#include <stdio.h>
#include <vector>
using namespace std;//директива



vector<int> CountingSort(vector <int> A)//сортировка подсчетом
{
	vector <int> j;//вектора
	int ma = A[0];//

	for (int i = 1; i < A.size(); i++)//делаем копию 
		if (ma < A[i])//ищим макс элемент
			ma = A[i];//окей это максимальный элемент

	for (int i = 0; i < ma + 1; i++)//создаем массив размерностью максимального элемента 
		j.push_back(0);//заполняем 

	for (int i = 0; i < A.size(); i++)//ходим бродим 
		j[A[i]]++;//прибавляем + 1 

	A.clear();//очищаем 
	for (int i = 0; i < j.size(); i++)//создаем второй массив двумерный так скажем ибо то был одномерный а это вот такой
		if (j[i] != 0)//если он не = 0 то 
			for (int a = 0; a < j[i]; a++)//заполняем 
				A.push_back(i);//заносим элементы в наш массив 
	return A;//возвращаем 
}


vector<int> RadixSort(vector <int> A)//поразрядная сортировка
{
	vector <vector<int>> sup;//вектор
	int c = 1, m = 10;//

	for (int i = 0; i < 10; i++)//делаем копию массива
		sup.push_back(vector<int>());//заносим в массив 

	for (int i = 0; i < 2; i++)//тут ходим по разрядам ( 1 и 2 разряд) тк у нас рандом до 100 то есть 1-99 то смотрим первый и второй разряд
	{
		for (int j = 0; j < A.size(); j++)
			sup[(A[j] % m) / c].push_back(A[j]);//заносим 

		A.clear();//очищаем


		for (int a = 0; a < 10; a++)
			for (int j = 0; j < sup[a].size(); j++)
				A.push_back(sup[a][j]);

		for (int i = 0; i < sup.size(); i++)
			sup[i].clear();

		m *= 10;
		c *= 10;
	}
	return A;//возвращаемся
}





int main()//оператор
{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры
	srand(unsigned(time(NULL)));//для рандомных чисел
	int N = 7;//матрица 7 
	vector<int> A, Ra, Co;//выделение памяти
	for (int i = 0; i < N; i++)//строчка
		A.push_back(rand() % 100);//рандомная матрица не более 9 чисел

	cout << "Вот Ваша матрица:" << endl << endl;//вывод
	for (int i = 0; i < N; i++)//строчка
		cout << A[i] << " ";//вывод

	cout << endl;//отступ

	int R, e;//переменная
	cout << "Поразрядная сортировка - 1;\nСортировка подсчетом - 2;\n " << endl;//вывод
	cout << "Введите номер сортировки: " << endl;//вывод
	cout << endl;//отступ
	cin >> R;//ввод
	cout << endl;//отступ


	do//оператор
	{
		switch (R)//оператор
		{
		case 1://кейс 
			Ra = RadixSort(A);//вызываем сортировку
			cout << "Новый массив, отсортированный поразрядной сортировкой " << endl;//вывод
			for (int i = 0; i < Ra.size(); i++)//Цикл для вывода
				cout << Ra[i] << " ";//вывод
		break;//закрытие кейса


		case 2://кейс 2
			Co = CountingSort(A);//вызываем сортировку
			cout << "Новый массив, отсортированный подсчетной сортировкой " << endl;//вывод
			for (int i = 0; i < Co.size(); i++)//цикл для вывода сортировки
				cout << Co[i] << " ";//вывод
		break;//закрытие кейса
		}

		cout << endl;//отступ
		cout << "Вы хотите перезапустить программу?" << endl;//вывод
		cout << "Да - Введите номер сортировки: / Нет, нажмите - 3" << endl;//вывод
		cout << "Ваш ответ: ";//вывод
		cin >> e; // ввод
	} while (e != 3); // проверка условия на перезапуск
	cout << endl;//отступ 


	system("pause");//задержка консоли
	return 0;//задержка консоли
}





