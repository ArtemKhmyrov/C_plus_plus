#include <iostream> //���������� ��� ������ �����-������ 
#include <cmath> //���������� �������������� ������� 
using namespace std; //��������� 

int main() //�������� 1 
{
	setlocale(LC_ALL, "RUS"); //������������� ������� ���������� 
	double x, y;//�������� ���� ����������
	cout <<"������� � �, ����� ������\n ";//�����
	cin >>x >>y;
	double c = exp(sqrt(log(((x*x) + (y*y)) / ((cos(x)*cos(x) + cos(pow(x, 2)))))));//������� ���������
	cout << "F(x,y) �����:" << c << endl;//�����
	system("pause"); //�������� ������� 
	return 0; //�������� 2 
}