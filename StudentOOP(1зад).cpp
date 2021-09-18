
#include <iostream>
#include <string>

using namespace std;

class Student//��������� �������� (��� ������)
{
private://���������� � ��� 
	string name;
	string surname;
	int number;
	int course;
	int group;


public:


	void SetStudent()//��������� ��������
	{
		cout << "������� ��� ��������" << endl;
		cin >> name;
		cout << "������� ������� ��������" << endl;
		cin >> surname;
		cout << "������� ����� ������� ��������" << endl;
		cin >> number;
		cout << "������� ���� ��������" << endl;
		cin >> course;
		cout << "������� ������" << endl;
		cin >> group;
		cout << "\n " << endl;
		if (course >= 5)//�� �� ����� 6 � ����
		{
			cout << "������ ����� �� ����������! \n ��������� ������ � ��������� �������. " << endl;
		}
		else if (number >= 20200000 || number <= 2000000)//����� ������� ������ ������� �� 8 ���� � �� ����� ���������� � �������� ���� � ���� ���� �������� ����
		{
			cout << "����� ������� �� ����������! \n ��������� ������ � ��������� �������." << endl;
		}
		else if (group >= 590 || group <= 110)//��� ����� �� ��������������� ������� ���������
		{
			cout << "����� ������ �� ����������! \n ��������� ������ � ��������� �������. " << endl;
		}

		else
		{
			cout << name << "\n" << surname << "\n" << number << "\n" << course << "\n" << group << "\n";
		}

	}
	
	void vivod()
	{
		cout << "\n��� ��������: " << name << endl;
		cout << "\n������� ��������: " << surname << endl;
		cout << "\n����� ������� ��������: " << number << endl;
		cout << "\n���� ��������: " << course << endl;
		cout << "\n������ ��������: " << group << endl;
		cout << endl;
		cout << endl;

	}

	int getnumber()//����� �������
	{
		return number;
	}

	//��� 
	string  getName()
	{
		cout << name;
	}

	string getname()
	{
		string name = this->name;
		return name;
	}

	//�������
	string  getSurName()
	{
		cout << surname;
	}

	string getsurname()
	{
		return this->surname;
	}



	int Problemy()//�������� 
	{
		cout << "�����������! ������ � �������� ��������� �������� " << endl;
		return 0;
	}

	int UpDownCourse(int m)//�������� �������� ��� �������� �� ������ ����
	{
		this->course = this->course + m;
		return this->course;
	}



	int StidentGoToBoard()//������� ���� � ����� 
	{
		cout << "......oooO.............." << endl;
		cout << ".....(....).......Oooo..." << endl;
		cout << "......).. / .....(....)..." << endl;
		cout << "......(__/ .......).. / ....." << endl;
		cout << ".................(__/ ......" << endl;
		return 0;
	}

	int Prikaz()//���������� 
	{
		cout << "������ �� ����������." << endl;
		cout << "� �������������� �������� �������� ���������, ��� �������� ��������� �������: " << endl;
		return 0;
	}

};

struct node//������ � �����
{
	Student inf;
	node* next;
	node* prev;
};

class list //���������� ������
{
private:

	node* head = NULL;//������ ������
	node* tail = NULL;//������ �����
public:
	void autodel(int N)
	{
		node* r = head;
		int c = 0;
		while (r != NULL)
		{
			if (N == r->inf.getnumber())//��������� � ������� 
			{
				c++;
				if (c == 2)
				{
					if (r == head)
					{
						head = head->next;
						head->prev = NULL;
					}
					else
					{
						if (r == tail)
						{
							tail = tail->prev;
							tail->next = NULL;
						}
						else
						{
							r->next->prev = r->prev;
							r->prev->next = r->next;
						}
					}
					delete r;
					break;
				}

			}
			r = r->next;//��������� � ���������� �������� � ���� � ������
		}
	}

	void del(int N) //������ �������� �������� �� ������ �������
	{
		node* r = head;
		bool fl = false;

		while (r != NULL)
		{
			if (N == r->inf.getnumber())//��������� � ������� 
			{
				fl = true;
				if (r == head)
				{ // �������� ������ ������
					head = head->next;
					head->prev = NULL;
				}
				else
				{
					if (r == tail)
					{ // �������� ������� ������
						tail = tail->prev;
						tail->next = NULL;
					}
					else
					{
						r->next->prev = r->prev;
						r->prev->next = r->next;
					}
				}
				delete r;
				cout << "\n������� � �������� " << N << " ������� ������\n" << endl;
				break;
			}
			r = r->next;
		}
		if (fl == false)
		{
			cout << "\n� ������ ����������� ������� � �������� " << N << endl;
			cout << endl;
		}
	}

	void push(Student x)//�������� �� ������������� ���������� �������
	{
		node* r = new node;
		bool fl = false;
		r->inf = x;
		r->next = NULL;
		if (!head && !tail)
		{
			r->prev = NULL;
			head = r;

		}
		else
		{
			node* j = head;
			while (j != NULL)
			{
				if (j->inf.getnumber() == x.getnumber())
				{
					cout << "\n ������� � ����� �������� ��� ����������! " << x.getnumber() << endl;
					cout << endl;
					fl = true;
					break;
				}
				j = j->next;
			}
			tail->next = r;
			r->prev = tail;
		}
		tail = r;
		if (fl == true)
			autodel(x.getnumber());
	}
	void print()//����� ������� �� �����
	{
		node* r = head;
		while (r != NULL)
		{
			r->inf.getnumber();
			r = r->next;
		}
		cout << endl;
	}
	void printall()//����� ������� �� �����
	{
		node* r = head;
		while (r != NULL)
		{
			r->inf.vivod();
			r = r->next;
		}
		cout << endl;
	}
	void edit(int N)
	{
		node* r = head;
		bool fl = false;
		while (r != NULL)
		{
			if (r->inf.getnumber() == N)
			{
				fl = true;
				r->inf.SetStudent();
				break;
			}
			r = r->next;
		}
		if (fl != true)
			cout << "\n ������� � �������� �" << N << " �� ������ � ������.\n" << endl;
	}


};

int main()
{
	setlocale(LC_ALL, "RUS");
	//��������� � �������������� �������� ���������, � ������ �� ����� � �������
	Student S;
	list arr;
	int c;
	cout << "\n ������ ��������� - 1 \n ��������� ��������� - 2 \n " << endl;
	cin >> c;
	do
	{
		int z, N;
		cout << "\n 1 - �������� �������� \n 2 - �������� ��� �������� �� ��������� \n 3 - ����� �������� �� ������ ������� � ��� �������������� \n 4 - ������� ��������\n 5 - ������� ���� ��������� �� �����\n"  << endl;
		cin >> z;
		cout << endl;
		switch (z)

		{

		case 1:

			S.SetStudent();
			arr.push(S);
			break;


		case 2:

			cout << " " << endl;
			int w;
			cout << "��� �� ������ ������� �� ���������? " << endl;
			cout << "\n 1 - �������� �������� ���������� \n 2 - ������� �������� � ����� \n 3 - ��������� �������� \n 4 - ��������� �������� �� ������ ���� \n " << endl;
			cout << " " << endl;
			cin >> w;

			switch (w)//����� � ����������
			{
			case 1:
				S.Problemy();
				break;
			case 2:
				S.StidentGoToBoard();
				break;
			case 3:
				S.Prikaz();
				break;
			case 4:
				int m;
				cout << "��� �������� �������� �� ������ ����, �������� ����� ����� " << endl;
				cin >> m;
				S.UpDownCourse(m);
				cout << "������� ��������� �� " << m << " ����" << endl;
				break;

			}
		case 3:
			cout << "������� ����� ������� ��������, �������� ����� ���������������: ";
			cin >> N;
			arr.edit(N);


			break;
		case 4:
			cout << "������� ����� ������� ��������, ����� ������� ���: ";
			cin >> N;
			arr.del(N);
			break;

			break;
		case 5:
			arr.printall();
			break;

		}

	} while (c != 2);//����� �� ��������������
	system("pause");
	return 0;
}

