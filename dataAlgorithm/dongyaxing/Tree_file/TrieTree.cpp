#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

/************************************************************************/
/* Trie���ṹ
* �����ַ���
*/
/************************************************************************/
typedef struct TrieNode
{
	char data;
	TrieNode *children[26];
	bool isEndingChar;
	TrieNode()
	{
		isEndingChar = false;
		for (int i = 0; i < 26; ++i)
		{
			children[i] = NULL;
		}
	}
}TrieNode;

/************************************************************************/
/* Trie��
*/
/************************************************************************/
class Trie
{
private:
	TrieNode *root;		// �����

public:
	//���캯��
	Trie()
	{
		root = NULL;
	}

	// ����
	~Trie()
	{
		delete root;
		root = NULL;
	}

	
	/****************************************************************
	* @brief : 		�����ַ���
	* @author : 	dyx
	* @date : 		2019/7/4 15:34
	* @version : 	ver 1.0
	* @inparam :	����string���͵��ַ���
	* @outparam : 
	*****************************************************************/
	void insert(string text)
	{
		if (!root)
		{
			root = new TrieNode;
		}
		TrieNode *p = root;
		for (int i = 0; i < text.length(); ++i)
		{
			int index = text[i] - 'a';
			if (p->children[index] == NULL)
			{
				p->children[index] = new TrieNode;
				p->children[index]->data = text[i];
			}
			p = p->children[index];
		}
		p->isEndingChar = true;
	}


	/****************************************************************
	* @brief : 		�����Ƿ��д��ַ���
	* @author : 	dyx
	* @date : 		2019/7/4 15:35
	* @version : 	ver 1.0
	* @inparam :	
	* @outparam :	�ɹ�����true
	*****************************************************************/
	bool find(string pattern)
	{
		TrieNode *p = root;
		for (int i = 0; i < pattern.length(); ++i)
		{
			int index = pattern[i] - 'a';
			if (p->children[index] == NULL)
			{
				return false;
			}
			p = p->children[index];
		}
		return p->isEndingChar;
	}


	/****************************************************************
	* @brief : 		��ӡ���е��ֵ�
	* @author : 	dyx
	* @date : 		2019/7/4 15:36
	* @version : 	ver 1.0
	* @inparam : 
	* @outparam : 
	*****************************************************************/
	void print(void)
	{
		// δ�����������
		cout << "uncomple..." << endl;
	}
};



int main()
{
	Trie *trie = new Trie();
	trie->insert("abc");
	trie->insert("hello");
	trie->insert("her");
	trie->insert("his");
	trie->insert("history");
	cout << trie->find("him") << endl;
	cout << trie->find("his") << endl;
	trie->print();
//	system("pause");
	return 0;
}
