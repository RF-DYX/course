#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
int main()
{
	map<string, vector<string> > children;
	string surname, childname;
	do
	{
		cout << "���������ϣ� " << endl;
		cin >> surname;
		if(!cin)
			break;
		vector<string> chd;
		pair<map<string, vector<string> >::iterator, bool> ret =
		children.insert(make_pair(surname, chd));
		if(!ret.second)
		{
			cout << "��������map��" << surname << endl;
			continue;
		}
		cout << "���뺢�ӵ����֣�" << endl;
		while(cin >> childname)
			ret.first->second.push_back(childname);
		cin.clear();
	}
	while(cin);
	char ask;
	do
	{
		cin.clear();
		cout << "�����ս��в��ң�" << endl;
		cin >> surname;
		map<string, vector<string> >::iterator it = children.find(surname);
		if(it == children.end())
			cout << "û�ҵ������ϣ� " << surname << endl;
		else
		{
			cout << "children: " << endl;
			vector<string>::iterator sit = (*it).second.begin();
			while(sit != it->second.end())
			{
				cout << *sit++ << endl;
			}
		}
		
		cout << "continue ?  y/n " << endl;
		cin >> ask;
	}
	while(ask == 'y' || ask == 'Y');
	return 0;
}