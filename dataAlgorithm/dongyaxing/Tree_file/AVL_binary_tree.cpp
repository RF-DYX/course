#include <iostream>
#include <stdlib.h>
using namespace std;

#define LH +1		// ���
#define EH 0		// �ȸ�
#define RH -1		// �Ҹ�

/*
ƽ������������ݽṹ
*/
typedef struct BalanceBiTNode
{
	int data;
	int bf;				/*����ƽ������*/
	struct BalanceBiTNode *lp, *rp;
}BalanceBiTNode, *BalanceBiTree;


/****************************************************************
* @brief : 		��pΪ�����Ķ�����������(bf��ֵ)
* @author : 	dyx
* @date : 		2019/7/2 10:37
* @version : 	ver 1.0
* @inparam : 
* @outparam :	����֮��pָ���µ�������㣬����ת����֮ǰ���������ĸ����
*****************************************************************/
void R_Rotate(BalanceBiTree *p)
{
	BalanceBiTree L;
	L = (*p)->lp;		// Lָ��p�������������
	(*p)->lp = L->rp;	// L���������ҽ�Ϊp��������
	L->rp = (*p);
	*p = L;				// pָ���µĸ����
}

/****************************************************************
* @brief : 		��pΪ�����Ķ�����������(bf��ֵ)
* @author : 	dyx
* @date : 		2019/7/2 10:37
* @version : 	ver 1.0
* @inparam : 
* @outparam :	����֮��pָ���µ�������㣬����ת����֮ǰ���������ĸ����0
*****************************************************************/
void L_Rotate(BalanceBiTree *p)
{
	BalanceBiTree R;		//Rָ��p�������������
	R = (*p)->rp;			// R����������Ϊp��������
	(*p)->rp = R->lp;		
	R->lp = (*p);
	*p = R;					// pָ���µĸ����
}


/****************************************************************
* @brief : 		����ָ��T��ָ��Ľ��Ϊ���Ķ�������Ϊƽ����ת����
* @author : 	dyx
* @date : 		2019/7/2 10:48
* @version : 	ver 1.0
* @inparam :	
* @outparam :	����ʱ��ָ��Tָ���µĸ����
*****************************************************************/
void LeftBalance(BalanceBiTree *T)
{
	BalanceBiTree L, Lr;
	L = (*T)->lp;				// L ָ��T�������������
	switch(L->bf)
	{							// ���T����������ƽ��ȣ�������Ӧƽ�⴦��
	case LH:					// �½�������T�����ӵ��������ϣ�������������
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:					// �½�������T�����ӵ��������ϣ�Ҫ��˫��ת����
		Lr = L->rp;				// Lrָ��T�����ӵ���������
		switch(Lr->bf)			// �޸�T�������ӵ�ƽ������
		{
		case LH:
			(*T)->bf = RH;
			L->bf = EH;
			break;
		case EH:
			(*T)->bf = L->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			L->bf = LH;
			break;
		}
		Lr->bf = EH;
		L_Rotate(&(*T)->lp);		// ��T��������������ƽ�⴦��
		R_Rotate(T);				// ��T������ƽ�⴦��
		break;
	}
}

/****************************************************************
* @brief : 		����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת����
* @author : 	dyx
* @date : 		2019/7/2 13:35
* @version : 	ver 1.0
* @inparam : 
* @outparam :	�㷨����ʱ��ָ��Tָ���µĸ����
*****************************************************************/
void RightBalance(BalanceBiTree *T)
{
	BalanceBiTree L, Ll;
	L = (*T)->rp;			// Lָ��T�������������
	switch(L->bf)
	{
		/*���T����������ƽ��ȣ�������Ӧƽ�⴦��*/
	case RH:		// �½ڵ������T���Һ��ӵ��������ϣ�Ҫ��������
		(*T)->bf = L->bf = EH;
		L_Rotate(T);
		break;
	case LH:			// �½�������T���Һ��ӵ��������ϣ�Ҫ��˫������
		Ll = L->lp;		// Lrָ��T���Һ��ӵ���������
		switch(Ll->bf)		// �޸�T�����Һ��ӵ�ƽ������
		{
		case LH:
			(*T)->bf = EH;
			L->bf = RH;
			break;
		case EH:
			(*T)->bf = L->bf = EH;
			break;
		case RH:
			(*T)->bf = LH;
			L->bf = EH;
			break;
		}
		Ll->bf = EH;
		R_Rotate(&(*T)->rp);		// ��T��������������ƽ�⴦��
		L_Rotate(T);				// ��T����ƽ�⴦��
		break;
	}
}

/****************************************************************
* @brief : 		����ƽ�����������T�У���e����ͬ�ؼ��ֵĽ�㣬
				�����һ��e,����1�����򣬷���0
				�������Ӱ��ƽ�⣬�������ת����
* @author : 	dyx
* @date : 		2019/7/2 13:40
* @version : 	ver 1.0
* @inparam :	taller:��ʾT�Ƿ񳤸ߡ�true�򳤸ߡ�
* @outparam : 
*****************************************************************/
bool InsertAVL(BalanceBiTree *T, int e, bool *taller)
{
	if (!*T)
	{
		/* �����½�㣬�������ߡ���tallerΪtrue*/
		*T = (BalanceBiTree) malloc(sizeof(BalanceBiTNode));
		(*T)->data = e;
		(*T)->lp = (*T)->rp = NULL;
		(*T)->bf = EH;
		*taller = true;
	}
	else
	{
		if (e == (*T)->data)
		{			/* �����Ѿ����ں�e����ͬ�ؼ��ֵĽ�㣬���ٲ���*/
			*taller = false;
			return false;
		}
		if (e < (*T)->data)
		{
			/* Ӧ������T���������н�������*/
			if (!InsertAVL(&(*T)->lp, e, taller))	// δ����
			{
				return false;
			}
			if (taller)	// �Ѿ����뵽Ttaller�����������ߡ�
			{
				switch((*T)->bf)
				{
				case LH:				// ԭ�����������������ߣ���Ҫ����ƽ�⴦��
					LeftBalance(T);
					*taller = false;
					break;
				case EH:				// ԭ���������ȸߣ����������������߶�������
					(*T)->bf = LH;
					*taller = true;
					break;
				case RH:				// ԭ�����������������ߣ������������ȸ�
					(*T)->bf = EH;
					*taller = false;
					break;
				}
			}
		}
		else
		{
			/*Ӧ������T���������н�������*/
			if (!InsertAVL(&(*T)->rp, e, taller))	// δ����
			{
				return false;
			}
			if (*taller)		// �Ѳ��뵽T���������������������ߡ�
			{
				switch((*T)->bf)	// ���T��ƽ���
				{
				case LH:			// ԭ�����������������ߣ��������ҵȸ�
					(*T)->bf = EH;
					*taller = false;
					break;	
				case EH:			// ԭ�����������ȸߣ��������������ߣ���Ҳ����
					(*T)->bf = RH;
					*taller = true;
					break;
				case RH:			// ԭ�����������������ߣ���Ҫ����ƽ�⴦��
					RightBalance(T);
					*taller = false;
					break;
				}
			}
		}
	}
	return true;
}


/****************************************************************
* @brief : 		�����ӡ���
* @author : 	dyx
* @date : 		2019/7/2 13:59
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void innerPrint(BalanceBiTree T)
{
	if (!T)
	{
		return;
	}
	innerPrint(T->lp);
	cout << T->data << " ";
	innerPrint(T->rp);
}
int main()
{
	int i;
	int a[10] = {3,2,1,4,5,6,7,10,9,8};
	BalanceBiTree T = NULL;
	bool taller;
	for (i = 0; i < 10; ++i)
	{
		InsertAVL(&T, a[i], &taller);
	}
	innerPrint(T);
	//system("pause");
	return 0;
}
