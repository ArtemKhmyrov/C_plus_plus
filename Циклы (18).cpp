#include<iostream>//���������� �����-������
using namespace std;//���������

int main() //�������� 1
{
	const int N = 5; //���������� ������
	for (int i = 1; i <= N; i++) {//�����
		for (int j = 1; j <= i; j++) //�������� ������
			cout << j << "   ";//����� ����� 
		cout << endl;//��������� ������� � ������ 
		for (int j = 1; j <= i; j++) //������ ������
			cout << 9 - 2 * (j - 1) << "   ";//����� ����� 
		cout << endl;//��������� ������� � ������ 
	}

	system("pause");//�������� ������� 
	return 0;// �������� 2
}