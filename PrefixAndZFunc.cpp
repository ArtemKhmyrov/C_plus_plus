#include <iostream>//������
#include<vector>//�������
#include <algorithm>//��� ������ ��������� � ��������
#include<string>//��� ������

using namespace std;//���������

//���� �� ����� 

//string buildFromZ(z & int[], alphabet char[]) {
//
//
//	string s = ""
//		int prefixLength = 0 // ����� ��������, ������� �� ����������
//		int j // ������� ������� � ������, ������� ����� ����������
//		int newCharacter = 0 // ������ ������ �������
//		for i = 0 to z.size - 1
//			// �� �� ����� �����-�� ������� � �� ����� ������ �����
//			if z[i] = 0 and prefixLength = 0
//				if newCharacter < alphabet.size
//					s += alphabet[newCharacter]
//					newCharacter++
//				else
//					s += alphabet[newCharacter - 1]
//					// ��� ����� ���������, ��� �� ����� ������� 
//					if z[i] > prefixLength
//						prefixLength = z[i]
//						j = 0
//						// ����� �������
//						if (prefixLength > 0)
//						{
//							s += s[j]
//								j++
//								prefixLength--
//						}
//							
//							return s
//}


vector<int> PrefFunc(string s)//������� ������� 
{
	int n = (int)s.size();//���������� ����� ������
	vector<int> pr(n);//����� ������ �� n
	for (int i = 1; i < n; ++i)//���� �� pr �� i
	{
		int j = pr[i - 1];//���������� ��� �������� ������ ��������
		while (j > 0 && s[i] != s[j])//���������� ���� �������� � ������� �� ���� j ���� �� ������ ������������
			j = pr[j - 1]; //��������� ���� j �� 1 � ����� ���� ������� 
		if (s[i] == s[j]) //���� ��������� �� 
			j++;//��������� � ���������� �������� 
		pr[i] = j;//���� ����� �� ����� � ��� ���������� �� 
	}
	return pr;//������������ 
}

vector<int> ZFunc(string s) // �-������� 
{
	int n = (int)s.size();//���������� ����� ������
	vector<int> z(n);//����� ������ �� n
	for (int i = 1, l = 0, r = 0; i < n; ++i) //���� ��� ��������\��������
	{
		if (i <= r)//���� ��� ������� ��������� ������ �� {L & R}
			z[i] = min(r - i + 1, z[i - l]);//����������� �������� ��� {z �� i}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])//����������� {z �� i} �� ������������ ��������
			z[i]++;//���������� 
		if (i + z[i] - 1 > r)//���� �� ������� �� ������ 
			l = i, r = i + z[i] - 1;//�� �������� ���� �������
	}
	return z;//������������ 
}



int main()
{
	setlocale(LC_ALL, "RUS");//������� ����������
	cout << "������� ��������: ";//�����
	string str;//���������� ��� ����� 
	cin >> str;//������ ���� ��������

			cout << "������� -> ";//�����
			for (auto upa : PrefFunc(str))//���� ��� ������ ������� �������
			{
				cout << upa << " ";//�����
			}
			cout << endl;//�����
	
			cout << "Z -------> ";//�����
			for (auto upa : ZFunc(str))//���� ��� ������ z-�������
			{
				cout << upa << " ";//�����
			}
			cout << endl;//������
	


	system("pause");//�������� �������
	return 0;//����� ��������� 
}

