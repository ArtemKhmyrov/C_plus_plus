#include <iostream>//���������� ��� ������ ����� ������
#include <cmath>//���������� �������������� �������
using namespace std;//���������

int main()//�������� 1
{
	setlocale(LC_ALL, "RUS");//������������� ������� ����������
	float S = 0, N, x, i, a, b;//��������� ���������� 
	cout << "������� ���� N: ";//����� � 
	cin >> N;//���� �
	cout << "������� �: ";//����� �
	cin >> x;//���� �
	for (float i = 1; i <= N; i++)//���� 1
	{
		a = 1;//���������
		for (b = 1; b <= i; b++)//���� 2
		{
			a *= b;//���������
		}
		S += (pow(-1, i - 1) * pow(x, 2 * i + 2) * a) / (pow(i,2) + i + 1);//�������
	}
	cout << "����� S: " << S << endl;// ����� �
	system("pause");// �������� �������
	return 0;// �������� 2
}
