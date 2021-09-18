#include<iostream>
#include <cstdlib>

using namespace std;//директива

struct rb_node//структура узла
{
    int red;//красное
    int data;//тип данных
    struct rb_node* link[2];
};

enum status {  INSERT, DELETE, PRINT, EXIT };//создаем структуру действий 

struct rb_tree//структура узла
{
    struct rb_node* root; // указатель на корневой узел
    int count; // количество узлов в дереве
};

int is_red(struct rb_node* node)
{
    return node != nullptr && node->red == true;
}

// функция для однократного поворота узла 
struct rb_node* rb_single(struct rb_node* root, int dir)
{
    struct rb_node* save = root->link[!dir];

    root->link[!dir] = save->link[dir];
    save->link[dir] = root;

    root->red = true;
    save->red = false;

    return save;//сохраняем наше положение 
}

// функция для двукратного поворота узла 
struct rb_node* rb_double(struct rb_node* root, int dir)
{
    root->link[!dir] = rb_single(root->link[!dir], !dir);
    return rb_single(root, dir);
}

struct rb_node* make_node(int data)//создание нового узла
{
    struct rb_node* rn = new rb_node;//выделяем память для узла и дерева 

    if (rn != NULL) //если дерево не пустое то
    {
        rn->data = data;//заполняем данные 
        rn->red = true;  //переводим в красный цвет
        rn->link[0] = NULL;
        rn->link[1] = NULL;
    }
    return rn;
}

int rb_insert(struct rb_tree* tree, int data)
{

    if (tree->root == NULL) //если не пустое 
    {
        tree->root = make_node(data);//добавляем элемент
        if (tree->root == NULL)//если он первый то 
            return 0;//ничего
    }
    else //иначе
    {
        struct rb_node head = { 0 }; //временный корень дерева
        struct rb_node* g, * t;      //дедушка и родитель 
        struct rb_node* p, * q;      // родитель и итератор 
        int dir = 0, last;

        // вспомогательные переменные 
        t = &head;
        g = p = NULL;
        q = t->link[1] = tree->root;

       
        for (; ;)//цикл для прохода по дереву 
        {
            if (q == NULL) 
            {
                // вставка узла 
                p->link[dir] = q = make_node(data);
                tree->count++;//увеличиваем количество узлов
                if (q == NULL)
                    return 0;
            }
            else if (is_red(q->link[0]) && is_red(q->link[1]))//если левая и правая ссылки красные 
            {
                // смена цвета 
                q->red = true;
                q->link[0]->red = false;
                q->link[1]->red = false;
            }
 
            if (is_red(q) && is_red(p))//если два цвета совпадают
            {
                int dir2 = t->link[1] == g;//кладем второе значение в переменную и запомниаем 

                if (q == p->link[last])
                    t->link[dir2] = rb_single(g, !last);
                else
                    t->link[dir2] = rb_double(g, !last);
            }

            if (q->data == data)//если узел такой есть
            {
                break;//выходим из функции
            }

            last = dir;
            dir = q->data < data;

            if (g != NULL)
                t = g;
            g = p, p = q;
            q = q->link[dir];
        }

        // обновить указатель на корень дерева
        tree->root = head.link[1];
    }
    // сделать корень дерева черным 
    tree->root->red = false;

    return 1;
}

int br_remove(struct rb_tree* tree, int data)
{
    if (tree->root != NULL)//если не пустой то ходим бродим 
    {
        struct rb_node head = { 0 }; // временный указатель на корень дерева 
        struct rb_node* q, * p, * g; // вспомогательные переменные 
        struct rb_node* f = NULL;  // узел, подлежащий удалению 
        int dir = 1;//правая ссылка 

        // дополнительные переменные для удобства
        q = &head;//сюда передаем голову 
        g = p = NULL;//это значение теперь пустое 
        q->link[1] = tree->root;//сюда сохраняем первое значение

        // поиск и удаление 
        while (q->link[dir] != NULL) //если не пустое то идем вправо 
        {
            int last = dir;

            // сохранение узлов во временные переменные 
            g = p, p = q;
            q = q->link[dir];
            dir = q->data < data;

           
            if (q->data == data)//если есть такое значение
                f = q;//сохраняем узел который нашли

            if (!is_red(q) && !is_red(q->link[dir]))
            {
                if (is_red(q->link[!dir]))
                    p = p->link[last] = rb_single(q, dir);//вращаем 1 раз
                else if (!is_red(q->link[!dir]))
                {
                    struct rb_node* s = p->link[!last];


                    if (s != NULL) {
                        if (!is_red(s->link[!last]) && !is_red(s->link[last])) {//не красные левая и правая ссылки,то
                            // меняем цвета узлов при перестановки 
                            p->red = false;
                            s->red = true;
                            q->red = true;
                        }
                        else {
                            int dir2 = g->link[1] == p;

                            if (is_red(s->link[last]))
                                g->link[dir2] = rb_double(p, last);//двойная поворот узла
                            else if (is_red(s->link[!last]))
                                g->link[dir2] = rb_single(p, last);//одинарный поворот узла

                            // корректировка цвета узлов 
                            q->red = g->link[dir2]->red = true;
                            g->link[dir2]->link[0]->red = false;
                            g->link[dir2]->link[1]->red = false;
                        }
                    }
                }
            }
        }

        // удаление найденного узла 
        if (f != NULL)//если узел не пустой 
        {
            f->data = q->data;//переприсваиваем значения
            p->link[p->link[1] == q] =
                q->link[q->link[0] == NULL];//переприсваиваем ссылки
            free(q);//освобождаем память 
        }

        // передаем указатель на новый узел
        tree->root = head.link[1];//теперь первый узел и есть новый 
        if (tree->root != NULL)//если первый не пустой 
            tree->root->red = false;
    }

    return 1;
}



void Show(rb_node* node, char dir)//симметричный вывод дерева на консоль 
{
    if (!node) return;
    Show(node->link[0], 'l');//направляемся в левую ветку 
    cout << dir << " " << node->data << " " << (node->red ? "red" : "black") << endl;//выводим и присваимваем узлам цвет ветки
    Show(node->link[1], 'r');////направляемся в правую ветку 
}


int main()
{

    setlocale(LC_ALL, "RUS");//рашан кейборд
    rb_tree* tree = new rb_tree();//создаем копию дерева 
    int choice = 0;
 
    status st = INSERT;//от начала программы(старт начинается отсюда)
    while (st != EXIT)//цикл для создания условий программы 
    {
        cout << "1. Вставить элемент в дерево " << endl;//вывод
        cout << "2. Удалить элемент из дерева " << endl;//вывод
        cout << "3. Распечатать дерево " << endl;//вывод
        cout << "4. Выйти из программы " << endl;//вывод
 

        cout << "Выберете пункт из меню  ";
        cin >> choice;//вводим номер кейса
        cout << endl;
        switch (choice)//кейсы 
        {
        case 1:
            cout << "Введите количество элементов  ";
            int n;
            cout << endl;
          
            cout << "Введите элементы " << endl;
            cout << endl;
            cin >> n;

            int W;
            for (int i = 0; i < n; i++)//цикл для ввода-вывода дерева 
            {
               
                cin >> W;
              
                rb_insert(tree, W);//кейс для вставки элементов
                
            }
            break;
        case 2:
            cout << "Введите элемент, который хотите удалить ";//вывод
            int to_delete;
            cin >> to_delete;//вводим удаляемый элемент
            br_remove(tree, to_delete); //удаляем элемент 
            break;
        case 3:
            Show(tree->root, ' ');//кейс для вывода дерева 
            cout << endl;//отступ
            break;

        case 4: st = EXIT;//кейс для выхода
            system("cls");//очистка консоли 
            break;
        default:
            break;
        }
        cout << endl;//отступ 
    }

    system("pause:");//задержка консоли
    return 0;//конец программы 
}

