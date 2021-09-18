#include<iostream>
#include<algorithm>//��� ������ ��������� � ������, � ��� �� ����������

using namespace std;

enum status { INSERT, DELETE, PRINT, LOOK, EXIT };//������� ��������� �������� 

struct avl //������� ��������� ��� ������
{
    int d;
    struct avl* l;//����� �����
    struct avl* r;//������ �����
}*r;//����������� ���� ������ � ���� ���������


class avl_tree //������� ����� ��� ������ 
{
public:
    int height(avl*), difference(avl*);//������ � �������
    avl* rr_rotat(avl*); avl* ll_rotat(avl*);//������� �����������
    avl* lr_rotat(avl*); avl* rl_rotat(avl*);//����������� � ���������
    avl* balance(avl*); avl* insert(avl*, int); avl* remove(avl*, int);//������������ dcnfdrf b elfktyb
    void show(avl*, int), inorder(avl*);//����� � j,[jl


    avl_tree() //�� ������
    {
        r = NULL;//���� ������ ������
    }
private:
    avl* removemin(avl* p);//�������� ������������ �������� 
    avl* findmin(avl* p);//����� ������������ ��������
};


int avl_tree::height(avl* t)//������ 
{
    int h = 0;//���� ������ ���� ����� ����
    if (t != NULL)//� ���� ������ �� ������ 
    {
        int l_height = height(t->l);//������� ������ ������ ����
        int r_height = height(t->r);//� ������� ���� 
        int max_height = max(l_height, r_height);//������� ������������
        h = max_height + 1;//+1 ��� ���� ����
    }
    return h;//������������ 
}


int avl_tree::difference(avl* t)//������� ������� ���� ����� 
{
    int l_height = height(t->l);//������� ������ ������ ���� 
    int r_height = height(t->r);//� ������� ���� 
    int b_factor = l_height - r_height;//���������� � ������� ������ ���� �������
    return b_factor;//������������ 
}


avl* avl_tree::rr_rotat(avl* parent)//�������� ������ �����������
{
    avl* t;//���������� ����������
    t = parent->r;//������
    parent->r = t->l;//������� ������ ���
    t->l = parent;//�������� ��������� �� �������� ����� �����
    return t;//������������ �� �����
}


avl* avl_tree::ll_rotat(avl* parent)//�������� ����� �����������
{
    avl* t;//���������� ����������
    t = parent->l;//�����
    parent->l = t->r;//������� ������ ���
    t->r = parent;//�������� ��������� ������ ����� �� ��������
    return t;//������������ 
}


avl* avl_tree::lr_rotat(avl* parent) //���� ������ �����������
{
    avl* t;//���������� ����������
    t = parent->l;//��������� ��� �������� �����
    parent->l = rr_rotat(t);//�������� �����
    return ll_rotat(parent);//������������ 
}


avl* avl_tree::rl_rotat(avl* parent) //����� ����� �����������
{
    avl* t;//���������� ����������
    t = parent->r;//��������� �� ������� �������� 
    parent->r = ll_rotat(t);//�������� ����
    return rr_rotat(parent);//������������ 
}


avl* avl_tree::balance(avl* t)//������������ ������
{
    int bal_factor = difference(t);
    if (bal_factor > 1) //���� �� ���������������
    {
        if (difference(t->l) > 0)//���� ����� 
            t = ll_rotat(t);//����� �����
        else
            t = lr_rotat(t);//����� ������
    }
    else if (bal_factor < -1)//������� � ������ �������
    {
        if (difference(t->r) > 0)//���� ������ ����
            t = rl_rotat(t);//������ �����
        else
            t = rr_rotat(t);//������ ������ 
    }
    return t;//������������ 
}


avl* avl_tree::insert(avl* r, int v)
{
    if (r == NULL) //���� ������ ������
    {//���� ��� �����, �� �������
        r = new avl;//����� ������ �������
        r->d = v;
        r->l = NULL;//������ �����
        r->r = NULL;//������ ������
        return r;//������������ � �����
    }
    else if (v < r->d) {//���� ������
        r->l = insert(r->l, v);//�� ���� �����
        r = balance(r);//����� �����������
    }
    else if (v >= r->d) {//���� �������
        r->r = insert(r->r, v);//�� ���� ������ 
        r = balance(r);//����� �����������
    } return r;
}


void avl_tree::show(avl* p, int l)
{
    int i;

    if (p != NULL)//���� ������ �� ������
    {

        show(p->r, l + 1);//������� ������� ������ �����
        cout << " ";//�����
        if (p == r)//���� ������� ��� �������
            cout << endl << "������ � ����� ����� " << endl;//�����
        for (i = 0; i < l && p != r; i++)//���� ��� ����� � ������ �����
            cout << " ";//�����
        cout << p->d;//�������
        show(p->l, l + 1);//������� ����� �����
    }
}


void avl_tree::inorder(avl* t)
{
    if (t == NULL)//���� ������ ������ 
        return;//������������
    inorder(t->l);//����� ����� 
    cout << t->d << " ";//�����
    inorder(t->r);//������
}


avl* avl_tree::removemin(avl* p) // �������� ���� � ����������� ������ �� ������ p
{
    if (p->l == 0)//���� ������� ����� ����
        return p->r;//������������ 
    p->l = removemin(p->l);//��� ������ �������
    return balance(p);//�����������
}


avl* avl_tree::findmin(avl* p) // ����� ���� � ����������� ������ � ������ p 
{
    return p->l ? findmin(p->l) : p;//������������ �� ��� ��� ���� �� ������ 
}


avl* avl_tree::remove(avl* p, int k) // �������� ����� k �� ������ p
{
    if (!p) return 0;//���� ������ �� ������ �� ������������ 
    if (k < p->d)//���� �������� ������
        p->l = remove(p->l, k);//���� �����
    else if (k > p->d)//�����
        p->r = remove(p->r, k);//���� ������
    else //  ���� ����� 
    {
        avl* q = p->l;//��������� �����
        avl* r = p->r;//� ������ ������
        delete p;//������� p
        if (!r) return q;//���� ������ �� ������ 
        avl* min = findmin(r);//���� �����������
        min->r = removemin(r);//������� ���
        min->l = q;//������������ ��������
        return balance(min);//�����������
    }
    return balance(p);//������������ � ������� ���������
}



int main()//����
{
    setlocale(LC_ALL, "RUS");//������� ����������
    avl_tree* tree = new avl_tree();//������� ����� ������
    int R = 0;//�����


    cout << "1.�������� ������� " << endl;//�����
    cout << "2.������� ������� " << endl;//�����
    cout << "3.������������ ����� " << endl;//�����
    cout << "4.�������� ������ " << endl;//�����
    cout << "5.����� �� ��������� " << endl;//�����


    status st = INSERT;//�� ������ ���������(����� ���������� ������)
    while (st != EXIT)//���� ��� �������� ������� ���������
    {
        cout << "������� �������� " << endl;//�����
        cin >> R;//������ ����
        switch (R)//�����
        {
        case 1:
            cout << "������� ���������� ��������� " << endl;//����� 
            int n;//���������� ��� ����������
            cin >> n;//������ ����������
            cout << "������� �������� " <<endl;//�����
            int X;//���������� ��� ���������
            for (int i = 0; i < n; i++)//����� ������(��� ����)
            {
                cin >> X;//������ ��������
                r = tree->insert(r, X);//�������� ������� �����
            }
            break;
        case 2:
            cout << "������� ������� ";//�����
            int del;//���������� ��� ��������
            cin >> del;//������ ��������� �����
            r = tree->remove(r, del);//������� ��������
            break;
        case 3:
            tree->inorder(r); //������������ ����� ������
            cout << endl;//������
            break;
        case 4:
            cout << "������ ����� ";//�����
            tree->show(r, 0); //������� ������
            cout << endl;//������ 
            break;
        case 5: st = EXIT;//���� ��� ������
            system("cls");//������� ������� 
            break;
        default:
            break;
        }
    }
    system("pause");//�������� �������
    return 0;//����� ��������� 
}
