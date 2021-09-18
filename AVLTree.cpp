#include<iostream>
#include<algorithm>//для поиска максимума и минима, а так же алгоритмов

using namespace std;

enum status { INSERT, DELETE, PRINT, LOOK, EXIT };//создаем структуру действий 

struct avl //создаем структуру авл дерева
{
    int d;
    struct avl* l;//левая ветка
    struct avl* r;//правая ветка
}*r;//прикрепляем наше дерево к этой структуре


class avl_tree //создаем класс авл дерева 
{
public:
    int height(avl*), difference(avl*);//высота и разница
    avl* rr_rotat(avl*); avl* ll_rotat(avl*);//двойные чередования
    avl* lr_rotat(avl*); avl* rl_rotat(avl*);//чередования в перемешку
    avl* balance(avl*); avl* insert(avl*, int); avl* remove(avl*, int);//балансировка dcnfdrf b elfktyb
    void show(avl*, int), inorder(avl*);//вывод и j,[jl


    avl_tree() //св дерева
    {
        r = NULL;//наше дерево пустое
    }
private:
    avl* removemin(avl* p);//удаление минимального значения 
    avl* findmin(avl* p);//поиск минимального значения
};


int avl_tree::height(avl* t)//высота 
{
    int h = 0;//наша высота пока равна нулю
    if (t != NULL)//и если дерево не пустое 
    {
        int l_height = height(t->l);//считаем высоты левого края
        int r_height = height(t->r);//и правого края 
        int max_height = max(l_height, r_height);//находим максимальную
        h = max_height + 1;//+1 для узла ниже
    }
    return h;//возвращаемся 
}


int avl_tree::difference(avl* t)//находим разницу всех высот 
{
    int l_height = height(t->l);//считаем высоты левого края 
    int r_height = height(t->r);//и правого края 
    int b_factor = l_height - r_height;//переменная в которую кладем нашу разницу
    return b_factor;//возвращаемся 
}


avl* avl_tree::rr_rotat(avl* parent)//двоичное правое чередование
{
    avl* t;//подключаем переменную
    t = parent->r;//вправо
    parent->r = t->l;//вращаем второй раз
    t->l = parent;//передаем указатель на родителя левой ветки
    return t;//возвращаемся по новой
}


avl* avl_tree::ll_rotat(avl* parent)//двоичное левое чередование
{
    avl* t;//подключаем переменную
    t = parent->l;//влево
    parent->l = t->r;//вращаем второй раз
    t->r = parent;//передаем указатель правой ветки на родителя
    return t;//возвращаемся 
}


avl* avl_tree::lr_rotat(avl* parent) //лево правое чередование
{
    avl* t;//подключаем переменную
    t = parent->l;//указываем что родитель левый
    parent->l = rr_rotat(t);//чередуем право
    return ll_rotat(parent);//возвращаемся 
}


avl* avl_tree::rl_rotat(avl* parent) //право левое чередование
{
    avl* t;//подключаем переменную
    t = parent->r;//указываем на правого родителя 
    parent->r = ll_rotat(t);//чередуем лево
    return rr_rotat(parent);//возвращаемся 
}


avl* avl_tree::balance(avl* t)//балансировка дерева
{
    int bal_factor = difference(t);
    if (bal_factor > 1) //если не сбалансированно
    {
        if (difference(t->l) > 0)//если левая 
            t = ll_rotat(t);//влево влево
        else
            t = lr_rotat(t);//влево вправо
    }
    else if (bal_factor < -1)//вращаем в другую сторону
    {
        if (difference(t->r) > 0)//если больше нуля
            t = rl_rotat(t);//вправо влево
        else
            t = rr_rotat(t);//вправо вправо 
    }
    return t;//возвращаемся 
}


avl* avl_tree::insert(avl* r, int v)
{
    if (r == NULL) //если корень пустой
    {//если нет корня, то создаем
        r = new avl;//новый корень создаем
        r->d = v;
        r->l = NULL;//пустой левый
        r->r = NULL;//пустой правый
        return r;//возвращаемся к корню
    }
    else if (v < r->d) {//если меньше
        r->l = insert(r->l, v);//то идем влево
        r = balance(r);//потом балансируем
    }
    else if (v >= r->d) {//если болоьше
        r->r = insert(r->r, v);//то идем вправо 
        r = balance(r);//потом балансируем
    } return r;
}


void avl_tree::show(avl* p, int l)
{
    int i;

    if (p != NULL)//если дерево не пустое
    {

        show(p->r, l + 1);//выводим сначала правую ветку
        cout << " ";//вывод
        if (p == r)//если элемент это кореньь
            cout << endl << "Корень и левая ветка " << endl;//вывод
        for (i = 0; i < l && p != r; i++)//цикл для левой и правой ветки
            cout << " ";//вывод
        cout << p->d;//выводим
        show(p->l, l + 1);//выводим левую ветку
    }
}


void avl_tree::inorder(avl* t)
{
    if (t == NULL)//если дерево пустое 
        return;//возвращаемся
    inorder(t->l);//левая ветка 
    cout << t->d << " ";//вывод
    inorder(t->r);//правая
}


avl* avl_tree::removemin(avl* p) // удаление узла с минимальным ключом из дерева p
{
    if (p->l == 0)//если элемент равен нулю
        return p->r;//возвращаемся 
    p->l = removemin(p->l);//как только находим
    return balance(p);//балансируем
}


avl* avl_tree::findmin(avl* p) // поиск узла с минимальным ключом в дереве p 
{
    return p->l ? findmin(p->l) : p;//возвращаемся до тех пор пока не найдем 
}


avl* avl_tree::remove(avl* p, int k) // удаление ключа k из дерева p
{
    if (!p) return 0;//если дерево не пустое то возвращаемся 
    if (k < p->d)//если значение меньше
        p->l = remove(p->l, k);//идем влево
    else if (k > p->d)//иначе
        p->r = remove(p->r, k);//идем вправо
    else //  если нашли 
    {
        avl* q = p->l;//сохраняем левую
        avl* r = p->r;//и правую ссылки
        delete p;//удаляем p
        if (!r) return q;//если корень не пустой 
        avl* min = findmin(r);//ищем минимальный
        min->r = removemin(r);//удаляем его
        min->l = q;//перекидываем ссылочку
        return balance(min);//балансируем
    }
    return balance(p);//возвращаемся к балансу элементов
}



int main()//мейн
{
    setlocale(LC_ALL, "RUS");//русская клавиатура
    avl_tree* tree = new avl_tree();//создаем копию дерева
    int R = 0;//кейсы


    cout << "1.Добавить элемент " << endl;//вывод
    cout << "2.Удалить элемент " << endl;//вывод
    cout << "3.Симметричный обход " << endl;//вывод
    cout << "4.Показать дерево " << endl;//вывод
    cout << "5.Выход из программы " << endl;//вывод


    status st = INSERT;//от начала программы(старт начинается отсюда)
    while (st != EXIT)//цикл для создания условий программы
    {
        cout << "Введите действие " << endl;//вывод
        cin >> R;//вводим кейс
        switch (R)//кейсы
        {
        case 1:
            cout << "Введите количество элементов " << endl;//вывод 
            int n;//переменная для количества
            cin >> n;//вводим количество
            cout << "Введите элементы " <<endl;//вывод
            int X;//переменная для элементов
            for (int i = 0; i < n; i++)//вывод дерева(его цикл)
            {
                cin >> X;//вводим элементы
                r = tree->insert(r, X);//вызываем функцию ввода
            }
            break;
        case 2:
            cout << "Введите элемент ";//вывод
            int del;//переменная для удаления
            cin >> del;//вводим удаляемое число
            r = tree->remove(r, del);//функция удаления
            break;
        case 3:
            tree->inorder(r); //симметричный обход дерева
            cout << endl;//отступ
            break;
        case 4:
            cout << "Правая ветка ";//вывод
            tree->show(r, 0); //выводим дерево
            cout << endl;//отступ 
            break;
        case 5: st = EXIT;//кейс для выхода
            system("cls");//очистка консоли 
            break;
        default:
            break;
        }
    }
    system("pause");//задержка консоли
    return 0;//конец программы 
}
