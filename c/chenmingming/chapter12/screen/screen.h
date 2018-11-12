#ifndef SCREEN_H
#define SCREEN_H
#include<string>
#include<iostream>

class Screen
{
public:
	typedef std::string::size_type index;			//������ű���
	Screen(index hgth, index wdth, const std::string &cntnts);	//�������캯��
	char get() const { return contents[cursor];}	//�����Ա���� get() ����λ�ô����ַ�
	char get(index ht, index wd) const;		//������Ա���� get(a,b) get���غ���
	index get_cursor() const;						//������Ա���� get_cursor() ����index
	Screen& move(index r, index c);					//������Ա���� move(a,b) ����screen������
	Screen& set(char);								//������Ա���� set(a) ����screen������
	Screen& display(std::ostream &os);					//������Ա���� display(�����) ����screen������
private:
	std::string contents;	//�����Ա���� �����ַ���
	index cursor;			//�����Ա���� ������
	index height, width;	//�����Ա���� �ߣ���
};

#endif