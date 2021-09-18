#include <iostream>//������� ����������
#include <algorithm>//��� ������� ����������
#include<vector>//��� �������� 
#include<string>//��� �����

using namespace std;//���������

vector<int> prefix_function(string s)//������� �������, ���� ����� �����, ��� � � ���������� �������
{
	int n = (int)s.size();//���������� ��� ������
	vector<int> pi(n);//������ n �� p{i}
	for (int i = 1; i < n; ++i) //����� �� pi �� i
	{
		int j = pi[i - 1];//
		while (j > 0 && s[i] != s[j])//���������� ������� ���� �� ����� �� ����� 
			j = pi[j - 1]; //���� ������� ����� �� ��������� j � ��������� ��� ����� ���
		if (s[i] == s[j])  ++j;//���� ��� ��������� 
		pi[i] = j; // �� pi �� i ������ ����� j + 1 � ���� ������
	}
	return pi;//���������� pi ��� ������� ��� ����� �� ����� � �� ����� ���������� 
}


int Find_Substirng(string pattern, string text)//������� 
{
	int end  = -1;//���������� 
	vector<int> pf = prefix_function(pattern);//��������� ��������
	int marker = 0;//������� = 0 

	for (int i = 0; i < text.size(); i++)//���� �� ������
	{
		while (marker > 0 && pattern[marker] != text[i]) { marker = pf[marker - 1]; }//���� �� ����� �� ����� 
		if (pattern[marker] == text[i]) marker++;//���� ������� ��������� � �������� ��������� �� 
		if (marker == pattern.size())//���� � ��������� ���� ����� �� ����� ��������� �� 
		{
			return end  = i - marker + 1;//���������� �������  
		}
	}
	return end ;//���������� ��� 
}


int main()//������� ������� 
{
	setlocale(LC_ALL, "RUS");//������� ����������
	cout << "������� ������ =>  ";//�����
	string str;//���������� ��� ������ 
	cin >> str;//���� ������ 
	cout << "������� ��������� =>  ";//�����
	string STR;//���������� ��� ������
	cin >> STR;//����
	int marker = Find_Substirng(STR, str);//�������� ������� ��� ����� ������ 
	cout << "��������� =>  " << marker << "," << marker + STR.size() - 1  << endl;//����� �� ����� 
	cout << endl;//������
	system("pause");//�������� �������
	return 0;//���������� ��������� 
}

