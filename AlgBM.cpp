#include <iostream>//������� ���������� 
#include <algorithm>//���������� ���������� 
#include<vector>//���������� �������� 
#include<string>//���������� ����� 

using namespace std;//��������� 

void BojerMoor(string str, int size, int Elem[256])//������� ������ ���� 
{
    int i;//���������� 
    for (i = 0; i < 256; i++)// ������ �� ����� ��������� 
        Elem[i] = -1;//�������� � - 1 ��� ���� �������� 
    for (i = 0; i < size; i++)// ������� ��� ���������� 
        Elem[(int)str[i]] = i;//��������� �������� �������� �������
}

vector <int> search(string txt, string pat)//������� ��� ������ ��������� � ������ 
{
    int m = pat.size();//���������� ��� ������� ����� ������ 
    int n = txt.size();//���������� ��� ������� ������ ������ 
    vector<int> OUT;//������ 
    int Elem[256];  //��������� �� ����� ��������� 
    BojerMoor(pat, m, Elem);//��������� ������ ���������� ��� ������
    int s = 0; //����� ��� �������� ������ 
    while (s <= (n - m))//���� ���� �� ����� �� ����� 
    {
        int j = m - 1;//������ � ���������� ���������� �������� � ��� �� �����
   
        while (j >= 0 && pat[j] == txt[s + j])     // ���������� ����������� ������ ������� j, ���� ������� ������ � ������� ���������
            j--;//���������
        if (j < 0)//���� ������ ���� �� 
        {
            OUT.push_back(s);//������� ��� ��� ��������� ������ � ������ �������� � ��������� 
            s += (s + m < n) ? m - Elem[txt[s + m]] : 1;//���� ��������� � ����� ������ 
        }
        else    
            s += max(1, j - Elem[txt[s + j]]);// ������������� ����� ��� ����� ������ � ������ ��������� � ���������           
    }
    return OUT;//���������� ��� 
}
int main()//������� ������� 
{
    setlocale(LC_ALL, "RUS");//������� ���������� 
    cout << "������� ������ =>  ";//�����
    string str;//���������� 
    cin >> str;//������ ������ 
    cout << "������� ��������� =>  ";//�����
    string STR;//���������� 
    cin >> STR;//������ ���������
    cout << "��������� =>  ";//����� 
    for (auto upa : search(str, STR))//���� ��� ������ 
    {
        cout  << upa << " -> " << upa + STR.size() - 1  << " ";//������� 
    }
    cout << endl;//������
    system("pause");//�������� ������� 
    return 0;//���������� ���������
}

