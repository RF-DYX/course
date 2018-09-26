#include<iostream>
#include<cstring>
using namespace std;
int sum=0;
void merge(int *arr,size_t left,size_t mid,size_t right)
{
    int len = right - left + 1;
    int *temp = new int [len];  //数组较长时请用new，不然栈空间容易溢出
    size_t index = 0;
    size_t i = left, j = mid + 1;
    while(i <= mid && j <= right)
    {
        if(arr[i]<=arr[j])
        {
            temp[index++] = arr[i++];
        }
        else
        {
            temp[index++] = arr[j++];
            sum += mid - i + 1;
        }
        temp[index++] = arr[i]<= arr[j]? arr[i++]: arr[j++]; //对两边的数组从小到大放入临时空间
    }
    while(i <= mid)     //比较完后，左半边有没放进去的，直接写入
    {
        temp[index++]= arr[i++];
    }
    while(j <= right)   //比较完后，右半边有没有放进去的，直接写入
    {
        temp[index++]= arr[j++];
    }
    for(int k = 0;k< len;++k)
    {
        arr[left++ ]= temp[k];  //把有序的临时数组写入原来数组的起始位置
    }
    delete [] temp;  //释放空间
    temp = NULL;  //指针置空
}
void divide(int *arr,size_t left,size_t right)
{
    if(left == right)
    {   
        return;
    }
    size_t mid = (left+right)/2;  //找出区间中部的数，将数组分段
    divide(arr,left,mid);  //递归调用，对左边继续分段；
    divide(arr,mid+1,right);  //递归调用，对右边继续分段；
    merge(arr,left,mid,right); //对左右两半进行排序合并成一小段有序的数组
}
void mergesort(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    size_t left = 0, right = dsize-1;
    divide(arr,left,right);
}

int main()
{
    const int N = 1001;
    int cyctime,len,len1;
    int arr[N];
    int i=0,j=0,temp;
    memset(arr,0,sizeof(int)*N);
    cin >> cyctime;
    for(i = 0; i < cyctime; ++i)
    {
        //cin.clear();
        cin >> len;
        len1=len;
        j=0;
        while(len1--)	//先输入数组
        {
            cin >> temp;
            arr[j++] = temp;
        }
        mergesort(len,arr);
        cout << "Scenario #" << i+1 << ":" << endl;
        cout << sum << endl << endl;
        sum = 0;
    }
    return 0;
}