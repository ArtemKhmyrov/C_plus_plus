//���� �����������. ������� ��� �����, � ������� ����������� ��� ����� ��������� �����.

#include <iostream> //���������� ��� ������ �����-������
#include <string> //���������� ��� ������ �� ��������
using namespace std; //���������

int main()//�������� 1
{
	int c;
	do
	{
		setlocale(LC_ALL, "RUS"); //������������� ������� ����������
		string str, slovo, nxtwrd, punct = "!?,.:;- "; //����������
		int count = 0, r = 0; //���������� ��������� 
		cout << "������� �����������\n"; //�����
		getline(cin, str); //����
		cout << "������� �����\n"; //�����
		getline(cin, slovo); //����
		str += '.';//��� + � ������
		string::size_type pos = 0, k;
		string::size_type max = 0;
		k = str.find_first_of(punct); //������� ����� ������� �����
		while (k != string::npos) //���� ���������� ����
		{
			nxtwrd = str.substr(pos, k - pos); //�������� ������ �����
			for (int i = 0; i < nxtwrd.length(); i++) //��������� ����� � �����
				if (slovo.find_first_of(nxtwrd[i]) != string::npos)//���� ����� �����
					r++;//+1
			if (r == nxtwrd.length())//������� ����
				str.erase(pos, k - pos);//��������
			r = 0;//�������� 
			if (pos < str.length() - 1)//������� ����
			{
				if (ispunct(str[k]) && isspace(str[k + 1])) pos = k + 2;  //���� ����� ����� ���������� ���� ������
				else pos = k + 1;//�����
				k = str.find_first_of(punct, pos); //���� ����� ���������� �����
			}
			else k = string::npos;//�����
		}
	
		cout << "����� �����������\n" << str << endl; //�����
		cout << "������ ������������� ���������? " << endl;
		cout << "���� ��, ������� 1" << endl;
		cout << "���� ���, ������� 2 " << endl;
		cin >> c;
		system("pause"); //�������� �������
		return 0;//�������� 2
	} while (c != 2);
}