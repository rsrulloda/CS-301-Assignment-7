//
//
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#define MAX 100
using namespace std;
const int MAX = 100;
class Queue
{
private:
    int rear;
    int front;
    int *q;
public:
    Queue()
    {
        rear=-1;
        front=-1;
        q = new int[MAX];
    }
    void enqueue(int x)
    {
        rear++;
        q[rear] = x;
    }
    int dequeue()
    {
        if(isEmpty())
        {
            return -999;
        }
        front++;
        return q[front];
    }
    bool isEmpty()
    {
        if(front==rear)
            return true;
        return false;
    }
};
class BST
{
    int data;
    BST *leftChild, *rightChild;
public:
    BST *createNode(int num)
    {
        BST *newNode = new BST;
        newNode -> data = num;
        newNode -> leftChild = newNode -> rightChild = NULL;
        return newNode;
    }
    void assignSortedOrder(BST *root, int arr[], int &position)
    {
        if (root != NULL)
        {
            assignSortedOrder(root -> leftChild, arr, position);
            arr[position++] = root -> data;
            assignSortedOrder(root -> rightChild, arr, position);
        }
    }
    BST* insertNode(BST* root, int num)
    {
        if (root == NULL)
            return createNode(num);
        if (num < root -> data)
            root -> leftChild = insertNode(root -> leftChild, num);
        else if (num > root -> data)
            root -> rightChild = insertNode(root -> rightChild, num);
        return root;
    }
    BST * sortTreeAscending(int arr[], int len)
    {
        BST *root = NULL;
        root = insertNode(root, arr[0]);
        for (int c = 1; c < len; c++)
            insertNode(root, arr[c]);
        int c = 0;
        assignSortedOrder(root, arr, c);
        return root;
    }
    void inOrder(BST* root)
    {
        if (root == NULL)
            return;
        inOrder(root->leftChild);
        cout << root -> data << " ";
        inOrder(root -> rightChild);
    }
};
class BST;
class NODE
{
private:
    NODE *lchild;
    int data;
    NODE *rchild;
    friend class BST;
};
class BST
{
public:
    void tree_insert(NODE **rt,int item)
    {
        if((*rt)==NULL)
        {
            (*rt)=(NODE*)malloc(sizeof(NODE));
            (*rt)->data=item;
            (*rt)->lchild=NULL;
            (*rt)->rchild=NULL;
        }
        else
        {
            if(item<=(*rt)->data)
                tree_insert(&((*rt)->lchild),item);
            else if(item>(*rt)->data)
                tree_insert(&((*rt)->rchild),item);
        }
    }
    void tree_inorder(NODE *rt, Queue &q)
    {
        if((rt)!=NULL)
        {
            tree_inorder(rt->lchild, q);
            q.enqueue(rt->data);
            tree_inorder(rt->rchild, q);
        }
    }
};
int main()
{
    ifstream fin;
    fin.open("input.txt");
    NODE *root = nullptr;
    BST tree;
    Queue q;
    int x;
    cout<<"Input data from file: "<<endl;
    for(int i=0; fin; i++)
    {
        fin>>x;
        if(!fin) break;
        cout<<x<<" ";
        if((i+1)%10==0) cout<<endl;
        tree.tree_insert(&root, x);
    }
    tree.tree_inorder(root, q);
    cout<<"\n\nOutput data from queue: "<<endl;
    for(int i=0; !q.isEmpty(); i++)
    {
        cout<<q.dequeue()<<" ";
        if((i+1)%10==0) cout<<endl;
    }
    fin.close();
    return 0;
}