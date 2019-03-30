#include "WebBrowse.h"


WebBrowse::WebBrowse(void)
{
}


WebBrowse::~WebBrowse(void)
{
}



/****************************************!
*@brief  �������ǰ������
*@author liuyanfu
*@date   2019��3��28��	22:50
*@param[out] 
*@return     void  
****************************************/
void WebBrowse::forward()
{
	if(!bstk.Empty())
	{
		fstk.Push((bstk.GetTop())->data);
		bstk.Pop();
		displayCurWeb((fstk.GetTop())->data);
	}
	displayCurWeb(NULL);
}


/****************************************!
*@brief  ������ĺ��˹���
*@author liuyanfu
*@date   2019��3��28��	22:51
*@param[out] 
*@return     void  
****************************************/
void WebBrowse::back()
{
	if(!fstk.Empty())
	{
		bstk.Push((fstk.GetTop())->data);
		fstk.Pop();
		displayCurWeb((fstk.GetTop())->data);
	}
	displayCurWeb(NULL);
}


/****************************************!
*@brief  �����������ַ�������ҳ������
*@author liuyanfu
*@date   2019��3��28��	23:27
*@param[out] 
*@param[in]  char * addr  
*@return     void  
****************************************/
void WebBrowse::browseWeb(char *addr)
{
	if(!bstk.Empty())
		bstk.Clear();
	fstk.Push(addr);
	displayCurWeb((fstk.GetTop())->data);
}


/****************************************!
*@brief  ��ʾ��ǰ�����������
*@author liuyanfu
*@date   2019��3��28��	23:27
*@param[out] 
*@param[in]  char * addr  
*@return     void  
****************************************/
void WebBrowse::displayCurWeb(char *addr)
{
	if(addr)
		std::cout << "Current web is : " << addr << std::endl;
	else
		std::cout << "Web error is 404" << std::endl;
}