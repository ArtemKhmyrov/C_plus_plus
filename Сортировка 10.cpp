#include <iostream>//���������� ��� ������ �����-������
#include <string>//���������� �����
#include <fstream>//���������� �����
#include <vector>//���������� ��� ��������

using namespace std;//���������

struct worker//������� ���������
{
	string SURNAME; // �������
	string POSITION; // ���������
	string DATE; //���� ��������
	string EXPERIENCE; // ���� 
	int s; // ���� �����
	string SALARY; // �������� ������
};

bool operator <=(worker a, worker b) //�������� ���������
{
	if (a.POSITION < b.POSITION) return true;//������� ����
	if (a.POSITION == b.POSITION && a.s < b.s) return true;//������� ����
	return false;//����������
}

int main()//��������
{
	setlocale(LC_ALL, "RUS");//������������� ������� ����������
	int surname = 0; // ����� ������� �������
	int position = 0; // ����� ������� ���������
	int experience = 0; // ����� ������� ����
	int salary = 0; // ����� ������� ��������
	string inp = "";
	vector<worker> vec;//������

	ifstream in("input.txt");//��� ������
	ofstream out("output.txt");//��� ������
	

	while (in.peek() != EOF)//���� ����
	{
		string inp;//������
		worker w;//����������

		getline(in, inp);//���������

		w.SURNAME = inp.substr(0, inp.find(' ', 0)); //�������
		inp.erase(0, inp.find(' ', 0) + 1);
		if (w.SURNAME.length() > surname) surname = w.SURNAME.length();//������� ����

		w.POSITION = inp.substr(0, inp.find(' ', 0)); //���������
		inp.erase(0, inp.find(' ', 0) + 1);
		if (w.POSITION.length() > position)position = w.POSITION.length();//������� ����

		w.DATE = inp.substr(0, inp.find(' ', 0)); //��������
		inp.erase(0, inp.find(' ', 0) + 1);

		const char *sd;//������ ����������
		w.EXPERIENCE = inp.substr(0, inp.find(' ', 0)); // ����
		if (w.EXPERIENCE.length() > experience) experience = w.EXPERIENCE.length();
		inp.erase(0, inp.find(' ', 0) + 1);
		sd = w.EXPERIENCE.c_str();
		w.s = atoi(sd);

		w.SALARY = inp; // ��������
		inp.erase();
		vec.push_back(w);
	}

	vector<worker>::iterator i = vec.begin();//��������
	while (i < vec.end())//���� ����
	{
		if (i == vec.begin())//������� ����
		{
			i++;//����������
		}
		else if ((*(i - 1)) <= *i) //������� ����
		{
			i++;//����������
		}
		else //������� �����
		{
			swap(*(i - 1), *i);//�������
			i--;//��������
		}
	}

	for (vector<worker>::iterator i = vec.begin(); i < vec.end(); i++)//����
	{ // ����� ������ � ��������������� �����
		if ((*i).SURNAME.length() < surname)//������� ����
			for (int j = (*i).SURNAME.length(); j < surname; j++) (*i).SURNAME += " ";//����
		if ((*i).POSITION.length() < position)//������� ����
			for (int j = (*i).POSITION.length(); j < position; j++) (*i).POSITION += " ";//����
		if ((*i).EXPERIENCE.length() < experience)//������� ����
			for (int j = (*i).EXPERIENCE.length(); j < experience; j++) (*i).EXPERIENCE = " " + (*i).EXPERIENCE;//����
		if ((*i).SALARY.length() < salary)//������� ����
			for (int j = (*i).SALARY.length(); j < salary; j++) (*i).SALARY = " " + (*i).SALARY;//����

		out << (*i).SURNAME << " " << (*i).POSITION << " " << (*i).DATE << " " << (*i).EXPERIENCE << " " << (*i).SALARY << endl;//������� �����
	}

	in .close();//���������
	out.close();//���������
	system("pause");//�������� �������
	return 0;//����������
}