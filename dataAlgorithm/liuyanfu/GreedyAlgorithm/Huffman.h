/*
* Copyright: (c) 2019
*
* �ļ�����:  Huffman.h	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/7/9  8:36
*/
#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#define MAXINT 32767

typedef char BYTE;
typedef unsigned int UINT;


typedef struct  
{
	BYTE character;
	UINT weight;
	UINT Parent, lChild, rChild;
}HTNode;

#endif // _HUFFMAN_H