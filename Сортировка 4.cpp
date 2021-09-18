#include<iostream> //���������� ��� ������ ����� ������
#include<fstream> //���������� ��� �����
#include<string>  //��� �����
#include<vector> //��������� ����������
#include<iomanip> //����������� ����������

using namespace std;//���������


struct Worker//������� ���������
{
	string secondname;//�������
	string position;//�����
	string date;//����
	int experience = 0;
	int salary = 0;
};

vector<Worker> inFile()//������ � �����(������)
{

	ifstream in("input.txt");//��������� � �����
	vector<Worker> x;//������� ������ �
	if (in) //������� ����
	{
		while (in.peek() != EOF)//���� ����
		{
			Worker temp;//
			in >> temp.secondname;//���������
			in >> temp.position;//���������
			in >> temp.date;//���������
			in >> temp.experience;//���������
			in >> temp.salary;//���������
			x.push_back(temp);
		}
		in.close();//��������� ����
	}
	else//������� ����
	{
		cerr << "�� ������� ������� ����" << endl;//�� ������� �������
	}

	return x;//���������
}

void print(vector<Worker> & workers)//������
{

	ofstream out("output.txt");//������ � ����� ����
	if (out)//������� ����
	{
		for (Worker x : workers)//����
		{
			out << x.secondname << " ";
			out << x.position << " ";
			out << x.date << " ";

			out << endl;
		}
		out.close();//���������
	}
	else //������� �����
	{
		cerr << "�� ������� ������� ����" << endl;//������ �������� �����
	}

}


void Puzirek(vector<Worker> & x)//���� ���������� (�������)
{
	for (int i = 0; i < x.size(); i++) //����
	{
		for (int j = x.size() - 1; j > i; j--)//����
		{
			if (x[j - 1].experience > x[j].experience)//������� ����
			{
				Worker a = x[j - 1];//���� ����� �������
				x[j - 1] = x[j];//�����������
				x[j] = a;//�����������
			}
		}
	}
}

void blsort(vector<Worker> & workers)//�������� ����������
{

	int P = 4, m = 0, k = 0;//������ ����������

	vector<Worker> v;//������ 1
	vector<Worker> b;//������ 2
	vector<Worker> n;//������ 3
	vector<Worker> a;//������ 4

	int min = INT_MAX;//����������� ����������(����� �� ������� �� ������)
	int max = INT_MIN;//������������ ����������
	for (int i = 0; i < workers.size(); i++)//����
	{
		if (max < workers[i].experience) //������� ����
		{
			max = workers[i].experience;//���������
		}
		if (min > workers[i].experience) //������� ����
		{
			min = workers[i].experience;//���������
		}
	}

	m = (max - min) / P;//������� ��� ��������� ����������

	for (int i = 0; i < workers.size(); i++)//����
	{

		Worker w = workers[i];

		if (w.experience < (min + (1 * m))) //������� ����
		{
			v.push_back(w);
		}
		else if (w.experience < (min + (2 * m))) //������� ����
		{
			b.push_back(w);
		}
		else if (w.experience < (min + (3 * m))) //������� ����
		{
			n.push_back(w);
		}
		else //������� �����
		{
			a.push_back(workers[i]);
		}
	}

	workers.clear();//�������

	Puzirek(v);//������ 1
	Puzirek(b);//������ 2
	Puzirek(n);//������ 3
	Puzirek(a);//������ 4

	for (Worker w : v)//��� ������� �������
		workers.push_back(w);

	for (Worker w : b)//��� ������� �������
		workers.push_back(w);

	for (Worker w : n)//��� �������� ������
		workers.push_back(w);

	for (Worker w : a)//��� ���������� �������
		workers.push_back(w);

}

int main() //��������
{
	vector<Worker> x;//���������� �
	x = inFile();//����
	blsort(x);
	print(x);//����������
	system("pause");//�������� �������
	return 0;//����������
}