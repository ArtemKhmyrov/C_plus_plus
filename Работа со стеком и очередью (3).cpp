#include<iostream>//библиотека для потока ввода-вывода
using namespace std;//директива стд

 struct stack //создаем структуру стек
 {
	 int inf;//переменная
	 stack *next;//
	
};

void push(stack *&h, int x) //функция
{
	 stack *r = new stack;//создаем новые ячейки
	 r->inf = x;//вставляем
	 r->next = h;//вставляем
	 h = r;//вставляем
	
}

 int pop(stack *&h)// функция
 { 
	 int i = h->inf;// след
	 stack *r = h;// приравниваем
	 h = h->next;// след
	 delete r;// удаляем
	 return i;// завершение
	
}


 stack *result(stack *&h) //стек
 {
	 bool fl = false;// нет
	 stack *h1 = NULL;//инициализируем
	 while (h)//цикл пока
	 {
		 int y = pop(h);//приравниваем
		 if (y % 2 == 0)//условие если четный элемент
		 {
			 push(h1, 0);//вставляем нулевой элемент
			 push(h1, y);//вставляем другие элементы

			 break;//завершение
		 }
		 else//условие если
			 push(h1, y);//вставляем все элементы
	 }
	 while (h)//цикл пока
		 push(h1, pop(h));//добавление
	
	  return h1;//завершение
 }
 int main() //оператор
 {
	 int n;//переменная
	 cout << " n = ";//вывод
	 cin >> n;//ввод 
	 stack *head = NULL; //инициализация
	 int x;//переменная
	 for (int i = 0; i < n; i++) //цикл фор
	 { 
		 cin >> x;//ввод
		 push(head, x);//добавляем элементы
		
	}
	 
	 stack *res = result(head);// вызов стека
	 while (res)//цикл пока
	cout << pop(res) << " "; //вывод
	
	 cout << endl;//отступ
	 system("pause");//задержка консоли
	 return 0;//завершение
	}