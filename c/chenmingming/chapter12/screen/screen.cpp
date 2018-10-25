#include"screen.h"
#include<iostream>
#include<string>
using namespace std;

Screen::Screen(index hgth, index wdth, const string &cntnts = " "):
        cursor(0), height(hgth),width(wdth)
{											//���幹�캯�� ���λ��Ϊ0����Ļ�ߴ��ʼ��
    contents.assign(hgth*wdth, ' ');		//����ı���ʼ��Ϊhgth*wdth�� �ո�
    if(!cntnts.empty())
        contents.replace(0,cntnts.size(),cntnts);	//�ӵ�0λ��ʼ����������ַ����滻��
}

char Screen::get(index r, index c) const	//�����Ա���� get(a,b)
{
    if(!contents.empty() && r > 0 && c > 0 && r <= height && c <= width)
    {
        return contents[(r-1) * width + c - 1];					//����(r,c)���д����ַ�
    }
    else
    {
        cout << "������Ļ��Χ������" << endl;
    }
    return '!';
}

Screen::index Screen::get_cursor() const	//�����Ա����get_cursor()
{
    return cursor;							//ע�ⷵ��ֵ����ǰ��������
}

Screen& Screen::move(index r, index c)		//�����Ա���� move(),���cursor�ƶ���ָ��λ��
{
    index row = r * width;
    cursor = row + c;
    return *this;
}

Screen& Screen::set(char c)					//�����Ա���� set(a)
{
    contents[cursor] = c;					//��괦�ַ�=c
    return *this;
}

Screen& Screen::display(ostream &os)		//�����Ա���� display()
{
    string::size_type index = 0;
    while(index != contents.size())			//���ַ���ÿ�п�ȸ����
    {
        os << contents[index];
        if((index+1)%width == 0)
        {
            os << '\n';
        }
        ++index;
    }
    return *this;
}