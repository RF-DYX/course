
#include<iostream>
#include<set>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	set<string> sset;
	sset.insert("success");
	ifstream exfile;
	exfile.open("ex10.24.txt");
	if(!exfile)
		cout << "open file fail !" << endl;
	string word;
	while(exfile >> word)
	{
		sset.insert(word);
	}
	exfile.close();
	exfile.clear();
	cout << "����s��β�ĵ��ʣ������ж��Ƿ����ȥ��β��s" << endl;
	while(cin >> word)
	{
		if(!sset.count(word))
		{
			word.resize(word.size()-1);
			cout << "���ʱ���ˣ�" << word << endl;
		}
		else
			cout << word << endl;
	}
	return 0;
}