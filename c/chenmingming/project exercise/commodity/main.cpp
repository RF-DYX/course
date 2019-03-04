#include <iostream>
#include "stdafx.h"
#include "trade.h"
using std::cout;
using std::cin;
using std::endl;
void ToBuy(int &ID, int &count)
{
    cout << "�����빺����Ʒ�ı�ţ�" << endl;
    cin >> ID;
    getchar();
    cout << "�����빺����Ʒ��������" << endl;
    cin >> count;
    getchar();
}
void ToSell(int &ID, int &count)
{
    cout << "������������Ʒ�ı�ţ�" << endl;
    cin >> ID;
    getchar();
    cout << "������������Ʒ��������" << endl;
    cin >> count;
    getchar();
}
void operate()
{
    printf("��ס�����������");
    getchar();
    system("cls");
}
void drawIndex()
{
    system("cls");
    printf("\t----------------------------------------\n");
    printf("\t       *****��ƷĿ¼*****               \n");
    printf("\t----------------------------------------\n");
}
void drawBuyRecord()
{
    system("cls");
    printf("\t----------------------------------------\n");
    printf("\t       *****�ɹ���¼*****               \n");
    printf("\t----------------------------------------\n");
}

void drawSellRecord()
{
    system("cls");
    printf("\t----------------------------------------\n");
    printf("\t       *****���ۼ�¼*****               \n");
    printf("\t----------------------------------------\n");
}

void drawLine()
{
    printf("\t----------------------------------------\n");
}
void drawMainMenu()
{
    printf("\t----------------------------------------\n");
    printf("\t          ��ӭʹ������ϵͳ              \n");
    printf("\t----------------------------------------\n");
    printf("\t          1 ����������Ʒ                \n");
    printf("\t          2 ������Ʒ                    \n");
    printf("\t          3 �����Ʒ                    \n");
    printf("\t          4 �鿴��Ʒ��Ϣ                \n");
    printf("\t          5 �鿴�ɹ���¼                \n");
    printf("\t          6 �鿴���ۼ�¼                \n");
    printf("\t          7 �˳�                        \n");
    printf("\t----------------------------------------\n");
}

int main()
{
    trade myTrade;
    if(!myTrade.init())
    {
        myTrade = trade();
    }
    bool quitFlag = false;
    while(!quitFlag)
    {
        drawMainMenu();
        printf("����������ѡ��:");
        int selection;
        cin >> selection;
        getchar();
        int ID,count;
        switch (selection)
        {
            case 1:
                system("cls");
                drawIndex();
                myTrade.GetIndex();
                drawLine();
                ToBuy(ID,count);
                if(myTrade.Buy(ID,count))
                {
                    system("cls");
                    printf("�����ɹ���");
                }
                else
                {
                    system("cls");
                    printf("������������");
                }
                operate();
                break;
            case 2:
                system("cls");
                drawIndex();
                myTrade.GetIndex();
                drawLine();
                ToSell(ID,count);
                if(myTrade.Sell(count,ID))
                {
                    system("cls");
                    printf("�����ɹ���");
                }
                else
                {
                    system("cls");
                    printf("������������");
                }
                operate();
                break;
            case 3:
                char name[30];
                float value;
                float cost;
                system("cls");
                cout << "��������Ʒ�����ƣ�" << endl;
                cin >> name;
                getchar();
                cout << "�����빺��۸�" << endl;
                cin >> cost;
                getchar();
                cout << "��������ۼ۸�" << endl;
                cin >> value;
                getchar();
                myTrade.AddNew(name,cost,value);
                system("cls");
                printf("�����ɹ���");
                operate();
                break;
            case 4:
                system("cls");
                drawIndex();
                myTrade.GetIndex();
                drawLine();
                cout << "��������Ʒ��ţ�";
                int index;
                cin >> index;
                getchar();
                system("cls");
                if(!myTrade.GetInformation(index))
                {
                    cout << "��Ч����Ʒ��ţ�";
                    operate();
                }
                else
                {
                    operate();
                }
                break;
            case 5:
                system("cls");
                drawBuyRecord();
                myTrade.getBuyRecord();
                break;
            case 6:
                system("cls");
                drawSellRecord();
                myTrade.getSellRecord();
                break;
            case 7:
                quitFlag = true;
                break;
            default:
                system("cls");
                printf("��Ч��ѡ�");
                operate();
        }
    }
    myTrade.save();
    return 0;
}