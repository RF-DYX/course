/*
* Copyright: (c) 2019
*
* �ļ�����:  singleton.h	
* �ļ���ʶ��
* ժ	Ҫ�� һ�����׵ĵ����࣬��̳�ʹ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/4/15  16:15
*/

#ifndef _SINGLETON_H
#define _SINGLETON_H


template<typename T>
class singleton_basic
{
protected:
	singleton_basic(){}

	typedef singleton_basic<T> base_t;
public:
	static T& instance()
	{
		static T obj;

		return obj;
	}
};

#endif	//_SINGLETON_H