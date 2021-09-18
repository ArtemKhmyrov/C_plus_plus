
#include <iostream>
#include <string>

using namespace std;

class Student//структура человека (наш объект)
{
private://информация о нем 
	string name;
	string surname;
	int number;
	int course;
	int group;


public:


	void SetStudent()//заполняем студента
	{
		cout << "Введите имя студента" << endl;
		cin >> name;
		cout << "Введите фамилию студента" << endl;
		cin >> surname;
		cout << "Введите номер зачетки студента" << endl;
		cin >> number;
		cout << "Введите курс студента" << endl;
		cin >> course;
		cout << "Введите группу" << endl;
		cin >> group;
		cout << "\n " << endl;
		if (course >= 5)//не мб курса 6 и выше
		{
			cout << "Такого курса не существует! \n Проверьте данные и повторите попытку. " << endl;
		}
		else if (number >= 20200000 || number <= 2000000)//номер зачетки строго состоит из 8 цифр и не может начинаться с прошлого века и быть выше текущего года
		{
			cout << "Таких зачеток не существует! \n Проверьте данные и повторите попытку." << endl;
		}
		else if (group >= 590 || group <= 110)//нет групп не соответствующие данному интервалу
		{
			cout << "Такой группы не существует! \n Проверьте данные и повторите попытку. " << endl;
		}

		else
		{
			cout << name << "\n" << surname << "\n" << number << "\n" << course << "\n" << group << "\n";
		}

	}
	
	void vivod()
	{
		cout << "\nИмя студента: " << name << endl;
		cout << "\nФамилия студента: " << surname << endl;
		cout << "\nНомер зачетки студента: " << number << endl;
		cout << "\nКурс студента: " << course << endl;
		cout << "\nГруппа студента: " << group << endl;
		cout << endl;
		cout << endl;

	}

	int getnumber()//номер зачетки
	{
		return number;
	}

	//имя 
	string  getName()
	{
		cout << name;
	}

	string getname()
	{
		string name = this->name;
		return name;
	}

	//фамилия
	string  getSurName()
	{
		cout << surname;
	}

	string getsurname()
	{
		return this->surname;
	}



	int Problemy()//проблема 
	{
		cout << "Поздравляем! Теперь у студента появились проблемы " << endl;
		return 0;
	}

	int UpDownCourse(int m)//повысить студента или понизить на другой курс
	{
		this->course = this->course + m;
		return this->course;
	}



	int StidentGoToBoard()//студент идет к доске 
	{
		cout << "......oooO.............." << endl;
		cout << ".....(....).......Oooo..." << endl;
		cout << "......).. / .....(....)..." << endl;
		cout << "......(__/ .......).. / ....." << endl;
		cout << ".................(__/ ......" << endl;
		return 0;
	}

	int Prikaz()//отчисление 
	{
		cout << "Приказ об отчислении." << endl;
		cout << "С невозможностью усвоения учебного материала, был отчислен следующий студент: " << endl;
		return 0;
	}

};

struct node//голова и хваст
{
	Student inf;
	node* next;
	node* prev;
};

class list //двусвязный список
{
private:

	node* head = NULL;//пустая голова
	node* tail = NULL;//пустой хвост
public:
	void autodel(int N)
	{
		node* r = head;
		int c = 0;
		while (r != NULL)
		{
			if (N == r->inf.getnumber())//обращение к зачетки 
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
			r = r->next;//переходим к следующему элементу и идем в начало
		}
	}

	void del(int N) //ручное удаления студента по номеру зачетки
	{
		node* r = head;
		bool fl = false;

		while (r != NULL)
		{
			if (N == r->inf.getnumber())//обращение к зачетки 
			{
				fl = true;
				if (r == head)
				{ // Удаление головы списка
					head = head->next;
					head->prev = NULL;
				}
				else
				{
					if (r == tail)
					{ // Удаление хвоства списка
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
				cout << "\nСтудент с зачеткой " << N << " успешно удален\n" << endl;
				break;
			}
			r = r->next;
		}
		if (fl == false)
		{
			cout << "\nВ списке отсутствует студент с зачеткой " << N << endl;
			cout << endl;
		}
	}

	void push(Student x)//проверка на существования одинаковых зачеток
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
					cout << "\n Студент с такой зачеткой уже существует! " << x.getnumber() << endl;
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
	void print()//вывод зачетки на экран
	{
		node* r = head;
		while (r != NULL)
		{
			r->inf.getnumber();
			r = r->next;
		}
		cout << endl;
	}
	void printall()//вывод зачетки на экран
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
			cout << "\n Человек с зачеткой №" << N << " не найден в списке.\n" << endl;
	}


};

int main()
{
	setlocale(LC_ALL, "RUS");
	//обращение и соответственно создание студентов, а точнее их имена и фамилии
	Student S;
	list arr;
	int c;
	cout << "\n Начать программу - 1 \n Закончить программу - 2 \n " << endl;
	cin >> c;
	do
	{
		int z, N;
		cout << "\n 1 - Добавить студента \n 2 - Провести ряд действий со студентом \n 3 - поиск студента по номеру зачетки и его редактирования \n 4 - Удалить студента\n 5 - вывести всех студентов на экран\n"  << endl;
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
			cout << "Что вы хотите сделать со студентом? " << endl;
			cout << "\n 1 - Наделить студента проблемами \n 2 - Вызвать студента к доске \n 3 - Отчислить студента \n 4 - Перевести студента на другой курс \n " << endl;
			cout << " " << endl;
			cin >> w;

			switch (w)//кейсы с действиями
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
				cout << "Для перевода студента на другой курс, выберете номер курса " << endl;
				cin >> m;
				S.UpDownCourse(m);
				cout << "Студент переведен на " << m << " курс" << endl;
				break;

			}
		case 3:
			cout << "Введите номер зачетки студента, которого нужно отредактировать: ";
			cin >> N;
			arr.edit(N);


			break;
		case 4:
			cout << "Введите номер зачетки студента, чтобы удалить его: ";
			cin >> N;
			arr.del(N);
			break;

			break;
		case 5:
			arr.printall();
			break;

		}

	} while (c != 2);//выход из псевдорекурсии
	system("pause");
	return 0;
}

