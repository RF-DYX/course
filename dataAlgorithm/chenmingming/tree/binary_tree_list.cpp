/**
 * @description: 二叉树，链表实现
 * @author: michael ming
 * @date: 2019/5/11 18:03
 * @modified by: 
 */
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
template <class T>
struct node
{
    T data;
    node<T> *left, *right;
    node<T>():left(NULL), right(NULL){}
};
template <class T>
class binary_tree
{
private:
    int nodelen;
    node<T> *root;
public:
    binary_tree():nodelen(0), root(NULL){}
    node<T>* getRoot()const
    {
        return root;
    }
    node<T>* insert(node<T> * nodep, size_t lv, size_t toplv, int data = 1)
    {
        if(lv == 0)
            return NULL;
        else if(nodep == NULL && lv == toplv)
        {
            root = new node<T>();
            nodep = root;
        }
        else
        {
            nodep = new node<T>();
        }
        nodep->data = data;
        nodelen++;
        node<T>* l = insert(nodep->left, lv-1, toplv, 2*data);
        if(l)
            nodep->left = l;    //返回创建好的left节点l，跟父接上
        node<T>* r = insert(nodep->right, lv-1, toplv, 2*data+1);
        if(r)
            nodep->right = r;   //返回创建好的right节点r，跟父接上
        return nodep;
    }
    void preOrderPrint(node<T> * nodep)
    {
        if (nodep == NULL)
            return;
        cout << nodep->data << " ";
        preOrderPrint(nodep->left);
        preOrderPrint(nodep->right);
    }
    void inOrderPrint(node<T> * nodep)
    {
        if (nodep == NULL)
            return;
        inOrderPrint(nodep->left);
        cout << nodep->data << " ";
        inOrderPrint(nodep->right);
    }
    void postOrderPrint(node<T> * nodep)
    {
        if (nodep == NULL)
            return;
        postOrderPrint(nodep->left);
        postOrderPrint(nodep->right);
        cout << nodep->data << " ";
    }
    void levelOrderPrint(node<T> * nodep)    //按层打印
    {
        if (nodep == NULL)
            return;
        queue<node<T>*> nodequeue;
        nodequeue.push(nodep);
        while(!nodequeue.empty())   //建立节点队列，打印父节点，入队左右子节点，出队父节点
        {
            node<T>* p = nodequeue.front();
            cout << p->data << " ";
            if(p->left != NULL)
                nodequeue.push(p->left);
            if(p->right != NULL)
                nodequeue.push(p->right);
            nodequeue.pop();
        }
    }
    //-----------------栈实现的非递归 二叉树遍历-----------------------
    void stackPreOrder()
    {
        stack<node<T>*> nodeStack;
        node<T> * nodep = root;
        if(nodep != NULL)
        {
            nodeStack.push(nodep);
            while(!nodeStack.empty())
            {
                nodep = nodeStack.top();
                nodeStack.pop();
                cout << nodep->data << " ";
                if(nodep->right != NULL)    //注意左右节点入栈顺序！！！
                    nodeStack.push(nodep->right);
                if(nodep->left != NULL)
                    nodeStack.push(nodep->left);
            }
        }
    }
    void stackInOrder()
    {
        stack<node<T>*> nodeStack;
        node<T> *nodep = root;
        while(nodep != NULL)
        {
            while(nodep != NULL)//入栈右、根
            {
                if(nodep->right)
                    nodeStack.push(nodep->right);
                nodeStack.push(nodep);
                nodep = nodep->left;
            }
            nodep = nodeStack.top();//根节点
            nodeStack.pop();
            while(!nodeStack.empty() && nodep->right == NULL)//nodep为叶子节点
            {
                cout << nodep->data << " ";//打印叶子节点
                nodep = nodeStack.top();
                nodeStack.pop();
            }
            cout << nodep->data << " ";//左节点为空，右节点非空or最后一个节点
            if(!nodeStack.empty())
            {
                nodep = nodeStack.top();
                nodeStack.pop();
            }
            else
                nodep = NULL;
        }
    }
    void stackPostOrder()
    {
        stack<node<T>*> nodeStack;
        node<T> *nodep = root, *temp = root;
        while(nodep != NULL)
        {
            for(;nodep->left != NULL; nodep = nodep->left)
                nodeStack.push(nodep);  //入栈一路上的左节点
            while(nodep->right == NULL || nodep->right == temp)
            {
                cout << nodep->data << " ";//打印叶子节点
                temp = nodep;
                if(nodeStack.empty())
                    return;
                nodep = nodeStack.top();//回到父节点
                nodeStack.pop();
            }
            nodeStack.push(nodep);
            nodep = nodep->right;//转到右子树
        }
    }

    void destory_tree(node<T> * nodep)
    {
        if (nodep == NULL)
            return;
        destory_tree(nodep->left);
        destory_tree(nodep->right);
        delete nodep;
    }
    //-----------------求二叉树高度-----------------------
    int get_height(node<T>* nodep)  //递归法, 求左右子树高度，较大的+1
    {
        if(nodep == NULL)
            return 0;
        int leftheight = get_height(nodep->left);
        int rightheight = get_height(nodep->right);
        return max(leftheight, rightheight) + 1;
    }
    int level_get_height(node<T>* nodep)    //按层计算高度
    {
        if (nodep == NULL)
            return 0;
        queue<node<T>*> nodequeue;
        node<T>* p = NULL;
        nodequeue.push(nodep);
        int height = 0;
        while(!nodequeue.empty())   //建立节点队列，入队左右子节点，出队父节点
        {
            height++;
            int n = nodequeue.size();
            for(int i = 0; i < n; ++i)
            {
                p = nodequeue.front();
                if(p->left != NULL)
                    nodequeue.push(p->left);
                if(p->right != NULL)
                    nodequeue.push(p->right);
                nodequeue.pop();
            }
        }
        return height;
    }
    int stack_get_height(node<T>* nodep)    //用栈实现前序（或后序）遍历，最大栈长度即为树的高度
    {
        if (nodep == NULL)
            return 0;
        stack<node<T>*> nodestack;
        node<T> *temp = NULL;
        int height = 0;
        while(nodep != NULL || !nodestack.empty())
        {
            if(nodep != NULL)
            {
                nodestack.push(nodep);
                nodep = nodep->left;//找到最底端左节点
            }
            else
            {
                nodep = nodestack.top();//最底端左节点的父节点nodep
                if(nodep->right != NULL && nodep->right != temp)   //右边有节点，且没有进过栈
                    nodep = nodep->right;   //进入右节点，跳到上个if查其子树
                else    //没有子节点，或者子节点进过栈
                {
                    if(nodestack.size() > height)
                        height = nodestack.size();  //更新最大高度
                    temp = nodep;   //记录弹栈的节点到temp
                    nodestack.pop();
                    nodep = NULL;
                }
            }
        }
        return height;
    }
};

int main()
{
    binary_tree<int> btree;
    btree.insert(btree.getRoot(), 3, 3);
    cout << "recursion preorder：" << endl;
    btree.preOrderPrint(btree.getRoot());
    cout << endl;
    cout << "stack preorder：" << endl;
    btree.stackPreOrder();
    cout << endl;
    cout << "recursion inorder：" << endl;
    btree.inOrderPrint(btree.getRoot());
    cout << endl;
    cout << "stack inorder：" << endl;
    btree.stackInOrder();
    cout << endl;
    cout << "recursion postorder：" << endl;
    btree.postOrderPrint(btree.getRoot());
    cout << endl;
    cout << "stack postorder：" << endl;
    btree.stackPostOrder();
    cout << endl;
    cout << "stack levelorder：" << endl;
    btree.levelOrderPrint(btree.getRoot());
    cout << endl;
    cout << "height of tree: " << btree.get_height(btree.getRoot()) << endl;
    cout << "level height of tree: " << btree.level_get_height(btree.getRoot()) << endl;
    cout << "stack height of tree: " << btree.stack_get_height(btree.getRoot()) << endl;
    btree.destory_tree(btree.getRoot());
    return 0;
}