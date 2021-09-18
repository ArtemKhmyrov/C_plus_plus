#include<iostream>
#include <cstdlib>

using namespace std;//���������

struct rb_node//��������� ����
{
    int red;//�������
    int data;//��� ������
    struct rb_node* link[2];
};

enum status {  INSERT, DELETE, PRINT, EXIT };//������� ��������� �������� 

struct rb_tree//��������� ����
{
    struct rb_node* root; // ��������� �� �������� ����
    int count; // ���������� ����� � ������
};

int is_red(struct rb_node* node)
{
    return node != nullptr && node->red == true;
}

// ������� ��� ������������ �������� ���� 
struct rb_node* rb_single(struct rb_node* root, int dir)
{
    struct rb_node* save = root->link[!dir];

    root->link[!dir] = save->link[dir];
    save->link[dir] = root;

    root->red = true;
    save->red = false;

    return save;//��������� ���� ��������� 
}

// ������� ��� ����������� �������� ���� 
struct rb_node* rb_double(struct rb_node* root, int dir)
{
    root->link[!dir] = rb_single(root->link[!dir], !dir);
    return rb_single(root, dir);
}

struct rb_node* make_node(int data)//�������� ������ ����
{
    struct rb_node* rn = new rb_node;//�������� ������ ��� ���� � ������ 

    if (rn != NULL) //���� ������ �� ������ ��
    {
        rn->data = data;//��������� ������ 
        rn->red = true;  //��������� � ������� ����
        rn->link[0] = NULL;
        rn->link[1] = NULL;
    }
    return rn;
}

int rb_insert(struct rb_tree* tree, int data)
{

    if (tree->root == NULL) //���� �� ������ 
    {
        tree->root = make_node(data);//��������� �������
        if (tree->root == NULL)//���� �� ������ �� 
            return 0;//������
    }
    else //�����
    {
        struct rb_node head = { 0 }; //��������� ������ ������
        struct rb_node* g, * t;      //������� � �������� 
        struct rb_node* p, * q;      // �������� � �������� 
        int dir = 0, last;

        // ��������������� ���������� 
        t = &head;
        g = p = NULL;
        q = t->link[1] = tree->root;

       
        for (; ;)//���� ��� ������� �� ������ 
        {
            if (q == NULL) 
            {
                // ������� ���� 
                p->link[dir] = q = make_node(data);
                tree->count++;//����������� ���������� �����
                if (q == NULL)
                    return 0;
            }
            else if (is_red(q->link[0]) && is_red(q->link[1]))//���� ����� � ������ ������ ������� 
            {
                // ����� ����� 
                q->red = true;
                q->link[0]->red = false;
                q->link[1]->red = false;
            }
 
            if (is_red(q) && is_red(p))//���� ��� ����� ���������
            {
                int dir2 = t->link[1] == g;//������ ������ �������� � ���������� � ���������� 

                if (q == p->link[last])
                    t->link[dir2] = rb_single(g, !last);
                else
                    t->link[dir2] = rb_double(g, !last);
            }

            if (q->data == data)//���� ���� ����� ����
            {
                break;//������� �� �������
            }

            last = dir;
            dir = q->data < data;

            if (g != NULL)
                t = g;
            g = p, p = q;
            q = q->link[dir];
        }

        // �������� ��������� �� ������ ������
        tree->root = head.link[1];
    }
    // ������� ������ ������ ������ 
    tree->root->red = false;

    return 1;
}

int br_remove(struct rb_tree* tree, int data)
{
    if (tree->root != NULL)//���� �� ������ �� ����� ������ 
    {
        struct rb_node head = { 0 }; // ��������� ��������� �� ������ ������ 
        struct rb_node* q, * p, * g; // ��������������� ���������� 
        struct rb_node* f = NULL;  // ����, ���������� �������� 
        int dir = 1;//������ ������ 

        // �������������� ���������� ��� ��������
        q = &head;//���� �������� ������ 
        g = p = NULL;//��� �������� ������ ������ 
        q->link[1] = tree->root;//���� ��������� ������ ��������

        // ����� � �������� 
        while (q->link[dir] != NULL) //���� �� ������ �� ���� ������ 
        {
            int last = dir;

            // ���������� ����� �� ��������� ���������� 
            g = p, p = q;
            q = q->link[dir];
            dir = q->data < data;

           
            if (q->data == data)//���� ���� ����� ��������
                f = q;//��������� ���� ������� �����

            if (!is_red(q) && !is_red(q->link[dir]))
            {
                if (is_red(q->link[!dir]))
                    p = p->link[last] = rb_single(q, dir);//������� 1 ���
                else if (!is_red(q->link[!dir]))
                {
                    struct rb_node* s = p->link[!last];


                    if (s != NULL) {
                        if (!is_red(s->link[!last]) && !is_red(s->link[last])) {//�� ������� ����� � ������ ������,��
                            // ������ ����� ����� ��� ������������ 
                            p->red = false;
                            s->red = true;
                            q->red = true;
                        }
                        else {
                            int dir2 = g->link[1] == p;

                            if (is_red(s->link[last]))
                                g->link[dir2] = rb_double(p, last);//������� ������� ����
                            else if (is_red(s->link[!last]))
                                g->link[dir2] = rb_single(p, last);//��������� ������� ����

                            // ������������� ����� ����� 
                            q->red = g->link[dir2]->red = true;
                            g->link[dir2]->link[0]->red = false;
                            g->link[dir2]->link[1]->red = false;
                        }
                    }
                }
            }
        }

        // �������� ���������� ���� 
        if (f != NULL)//���� ���� �� ������ 
        {
            f->data = q->data;//��������������� ��������
            p->link[p->link[1] == q] =
                q->link[q->link[0] == NULL];//��������������� ������
            free(q);//����������� ������ 
        }

        // �������� ��������� �� ����� ����
        tree->root = head.link[1];//������ ������ ���� � ���� ����� 
        if (tree->root != NULL)//���� ������ �� ������ 
            tree->root->red = false;
    }

    return 1;
}



void Show(rb_node* node, char dir)//������������ ����� ������ �� ������� 
{
    if (!node) return;
    Show(node->link[0], 'l');//������������ � ����� ����� 
    cout << dir << " " << node->data << " " << (node->red ? "red" : "black") << endl;//������� � ������������ ����� ���� �����
    Show(node->link[1], 'r');////������������ � ������ ����� 
}


int main()
{

    setlocale(LC_ALL, "RUS");//����� �������
    rb_tree* tree = new rb_tree();//������� ����� ������ 
    int choice = 0;
 
    status st = INSERT;//�� ������ ���������(����� ���������� ������)
    while (st != EXIT)//���� ��� �������� ������� ��������� 
    {
        cout << "1. �������� ������� � ������ " << endl;//�����
        cout << "2. ������� ������� �� ������ " << endl;//�����
        cout << "3. ����������� ������ " << endl;//�����
        cout << "4. ����� �� ��������� " << endl;//�����
 

        cout << "�������� ����� �� ����  ";
        cin >> choice;//������ ����� �����
        cout << endl;
        switch (choice)//����� 
        {
        case 1:
            cout << "������� ���������� ���������  ";
            int n;
            cout << endl;
          
            cout << "������� �������� " << endl;
            cout << endl;
            cin >> n;

            int W;
            for (int i = 0; i < n; i++)//���� ��� �����-������ ������ 
            {
               
                cin >> W;
              
                rb_insert(tree, W);//���� ��� ������� ���������
                
            }
            break;
        case 2:
            cout << "������� �������, ������� ������ ������� ";//�����
            int to_delete;
            cin >> to_delete;//������ ��������� �������
            br_remove(tree, to_delete); //������� ������� 
            break;
        case 3:
            Show(tree->root, ' ');//���� ��� ������ ������ 
            cout << endl;//������
            break;

        case 4: st = EXIT;//���� ��� ������
            system("cls");//������� ������� 
            break;
        default:
            break;
        }
        cout << endl;//������ 
    }

    system("pause:");//�������� �������
    return 0;//����� ��������� 
}

