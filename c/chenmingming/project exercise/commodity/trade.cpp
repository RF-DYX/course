//
// Created by mingm on 2019/1/28.
//
#include "trade.h"
#include "stdafx.h"
#include <fstream>
#include <time.h>

#define CAP 5
#define TLEN 10
#define ALEN 30
using std::ofstream;
using std::ifstream;
bool trade::Buy(int ID, int count)
{
    for(auto iter = datalist.begin();iter!=datalist.end();++iter)
    {
        if(iter->getID() == ID)
        {
            iter->UpdateStock(count);
            time_t t = time(0);
            char temp[50];
            strftime(temp,sizeof(temp),"%Y ��%d ��%d ��%X%A",localtime(&t));
            buyRecordList.push_back(record(iter->getName(),count,temp));
            return true;
        }
    }
    return false;
}
bool trade::Sell(int n, int ID)
{
    for(auto iter = datalist.begin();iter!=datalist.end();++iter)
    {
        if(iter->getID() == ID && !(iter->getStock()-n<0))
        {
            iter->UpdateStock(-n);
            time_t t = time(0);
            char temp[50];
            strftime(temp,sizeof(temp),"%Y ��%d ��%d ��%X%A",localtime(&t));
            sellRecordList.push_back(record(iter->getName(),n,temp));
            return true;
        }
    }
    return false;
}
void trade::AddNew(char *name, float buyValue, float sellValue)
{
    datalist.push_back(commodity(name,buyValue,sellValue));
}
void trade::GetIndex()
{
    for(auto iter = datalist.begin();iter!=datalist.end();++iter)
    {
        printf("\t ��Ʒ��ţ�%i  ��Ʒ���ƣ�%s\n",iter->getID(),iter->getName());
    }
}
bool trade::GetInformation(int index)
{
    for(auto iter = datalist.begin();iter!=datalist.end();++iter)
    {
        if(iter->getID() == index)
        {
            printf("��Ʒ��ţ�%d\n��Ʒ���ƣ�%s\n����۸�%f\n���ۼ۸�%f\nʣ�ࣺ%d\n",
                    index,iter->getName(),iter->getBuyValue(),iter->getSellValue(),iter->getStock());
            return true;
        }
    }
    return false;
}
void trade::save()
{
    ofstream file;
    file.open("stock.txt");
    if(!file.fail())
    {
        file << "----------------------------------------\n";
        file << "       *****��Ʒ��Ϣ*****               \n";
        file << "----------------------------------------\n";
        for(auto iter = datalist.begin();iter!=datalist.end();++iter)
        {
            file << "ID:" << iter->getID()
                << "\tNAME:" << iter->getName()
                << "\tCOST:" << iter->getBuyValue()
                << "\tVALUE:" << iter->getSellValue()
                << "\tSTOCK:" << iter->getStock() << "\n";
        }
    }
    else
    {
        printf("��¼�ļ�����ʧ�ܣ�");
    }
    file.close();
    file.open("sellRecord.txt");
    if(!file.fail())
    {
        file << "----------------------------------------\n";
        file << "       *****������Ϣ*****               \n";
        file << "----------------------------------------\n";
        for(auto iter = sellRecordList.begin();iter!=sellRecordList.end();++iter)
        {
            file << "NAME:" << iter->name
                 << "\tTIME:" << iter->sTime
                 << "\tCOUNT:" << iter->count
                 << "\n";
        }
    }
    else
    {
        printf("���ۼ�¼�ļ�����ʧ�ܣ�");
    }
    file.close();
    file.open("buyRecord.txt");
    if(!file.fail())
    {
        file << "----------------------------------------\n";
        file << "       *****������Ϣ*****               \n";
        file << "----------------------------------------\n";
        for(auto iter = buyRecordList.begin();iter!=buyRecordList.end();++iter)
        {
            file << "NAME:" << iter->name
                 << "\tTIME:" << iter->sTime
                 << "\tCOUNT:" << iter->count
                 << "\n";
        }
    }
    else
    {
        printf("�����¼�ļ�����ʧ�ܣ�");
    }

}
bool trade::init()
{
    ifstream file("stock.txt");
    if(!file.fail())
    {
        char titles[CAP][TLEN]={"ID:","NAME:","COST:","VALUE:","STOCK:"};
        char saves[CAP][ALEN]={};
        int tIndex = 0;
        char buf[128];
        int kinds = 0;
        for(int i = 0; i<3; ++i)    //  ���Ա���
        {
            file.getline(buf,128);
        }
        while(!file.eof())
        {
            char temp[TLEN]="";
            for(int i=0;i<TLEN && !file.eof(); ++i)
            {
                file.get(temp[i]);
                if(strcmp(temp,titles[tIndex])==0)
                {
                    for(int j=0; j<ALEN && !file.eof(); ++j)
                    {
                        char c;
                        file.get(c);
                        if(c != '\t'&& c != '\n')
                        {
                            saves[tIndex][j] = c;
                        }
                        else if(c != '\n')
                        {
                            if(tIndex > 4)
                            {
                                return false;
                            }
                            tIndex++;
                            break;
                        }
                        else
                        {
                            datalist.push_back(commodity(saves[1],atof(saves[2]),atof(saves[3])));
                            tIndex=0;
                            kinds++;
                            break;
                        }
                        if(j==ALEN-1)
                        {
                            return false;
                        }
                    }
                    break;
                }
                if(i==TLEN-1)
                {
                    return false;
                }
            }
        }
        commodity::kinds = kinds;
        return true;
    }
    return false;
}
void trade::getSellRecord()
{
    for(auto iter = sellRecordList.begin(); iter != sellRecordList.end(); ++iter)
    {
        printf("\t������Ʒ���ƣ�%s\n", iter->name);
        printf("\t�������ڣ�%s\n", iter->sTime);
        printf("\t������Ŀ��%s\n", iter->count);
        printf("\t----------------------------------------\n");
    }
}
void trade::getBuyRecord()
{
    for(auto iter = sellRecordList.begin(); iter != sellRecordList.end(); ++iter)
    {
        printf("\t������Ʒ���ƣ�%s\n", iter->name);
        printf("\t�������ڣ�%s\n", iter->sTime);
        printf("\t������Ŀ��%s\n", iter->count);
        printf("\t----------------------------------------\n");
    }
}