#include <iostream>//���������� �=��� ������ �����-������
#include <math.h>//���������� �������������� �������
using namespace std;//���������
int main() //�������� 1
{
	setlocale(LC_ALL, "RUS");//������������� ������� ����������
	int N = 100;//���������� ����������
	double eps;//����������
	cout << "eps="; cin >> eps;//�����
	double a, S = 0; //��������� �������
	int n = 0;//����������
	do//����
	{
		n++;
		a = -1 / (2 * n + 1 * (2 * n + 1));//�������
		S += a;
	} while (abs(a) > eps && n <= N);//����
	cout << "����� S:" << S << endl;//�����
	cout << "����� n:" << n << endl;//�����
	system("pause");//�������� �������
	return 0;//�������� 2
}