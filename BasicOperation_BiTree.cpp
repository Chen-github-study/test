#include<iostream>
using namespace std;
#define OK 0
#define ERROR -1
#define MAXSIZE  1000
typedef int Status;
typedef char TElemtype;
typedef struct TNode{
    TElemtype data;
    TNode *lchild;
    TNode *rchild;
}*BiTree;
typedef struct {                   //定义一个存放树节点指针类型的队列
    BiTree *base;
    int front;
    int rear;
}SqQueue;
Status InitQueue(SqQueue &Q)        //初始化队列
{
    Q.base=new BiTree[MAXSIZE];
    Q.front=Q.rear=0;
    return OK;
}
Status EnQueue(SqQueue &Q,BiTree &T)     //入队
{
    if((Q.rear+1)%MAXSIZE==Q.front)
      return ERROR;
    Q.base[Q.rear]=T;
    Q.rear=(Q.rear+1)%MAXSIZE;
    return OK;
}
Status DeQueue(SqQueue &Q,BiTree &T)    //出队
{   
    if(Q.rear==Q.front)
      return ERROR;
    T=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXSIZE;
    return OK;
}
bool IsEmpty(SqQueue Q)    //判断队列是否为空
{
    if(Q.front==Q.rear)
        return 1;
    else
        return 0;
}
Status CreatBiTree (BiTree &T)       //根据序列创建二叉树
{
    
    char c;
    c=getchar();
    if(c=='#')
    {
        T=NULL;
        return OK;
    }
      
    T=new TNode;
    if(!T)
      exit(-1);
    T->data=c;  
    CreatBiTree(T->lchild);
    CreatBiTree(T->rchild);
    return OK;
}

Status PreOrderTraverse(BiTree &T)        //先序遍历二叉树
{
    if(!T)
      return OK;
    cout<<T->data;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    return OK;
}
Status InOrderTraverse(BiTree &T)          //中序遍历二叉树
{
    if(!T)
      return OK;
    InOrderTraverse(T->lchild);
    cout<<T->data;
    InOrderTraverse(T->rchild);
    return OK;
}
Status PostOrderTraverse(BiTree &T)         //后序遍历二叉树
{
    if(!T)
      return OK;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    cout<<T->data;
    return OK;
}
Status LevelOrderTraverse(BiTree &T)         //层序遍历二叉树
{
    SqQueue Q;//构造一个元素类型为节点类型的队列
    BiTree t;
    InitQueue(Q);
    EnQueue(Q,T);
    while(!IsEmpty(Q))
    {
        DeQueue(Q,t);
        cout<<t->data;
        if(t->lchild)
            EnQueue(Q,t->lchild);
        if(t->rchild)
            EnQueue(Q,t->rchild);
    }
    return OK;
}
Status OutputBiTree(BiTree &T,int level)               //输出二叉树
{
    if(!T)
      return OK;
    level++;
    OutputBiTree(T->rchild,level);
    for(int i=1;i<level;i++)
    {
        cout<<"     ";
    }
    cout<<T->data<<endl;
    OutputBiTree(T->lchild,level);
    level--;
    return OK;
}
int main()
{
    BiTree T;
    int level=0;
    CreatBiTree(T);
    PreOrderTraverse(T);
    cout<<endl;
    InOrderTraverse(T);
    cout<<endl;
    PostOrderTraverse(T);
    cout<<endl;
    LevelOrderTraverse(T);
    cout<<endl;
    OutputBiTree(T,level);
    system("pause");
    return 0;
}