// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Node 
{
    public:
        char data;
        int frq;
        Node *left;
        Node *right;
        
        Node(int data,char ch)
        {
            this -> data = ch;
            this-> frq = data;
            left = NULL;
            right = NULL;
        }
};

void traverse(Node *root,string temp,char ch,string &n)
{
    
    if(root -> data == ch)
    {
        n = temp;
        return;
    }

    if(root -> left != NULL)
    {
        traverse(root -> left,temp+'0',ch,n);
    }
    
    if(root -> right != NULL)
    {
        traverse(root->right,temp+'1',ch,n);
    }
}

void printTree(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root -> data<<" ";
    printTree(root -> left);
    printTree(root -> right);
}

class cmp{
    public:
        bool operator()(Node * a,Node *b)
        {
            return (a -> frq) > (b -> frq);
        }
};

int main() 
{
    string S = "abcdef";
    int f[6] = {5, 9, 12, 13, 16, 45};
    int n = 6;
    
    priority_queue<Node *,vector<Node*>,cmp> pq;
    
    for(int i=0;i<n;i++)
    {
        pq.push(new Node(f[i],S[i]));
    }
    
    while(pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        

        Node *right = pq.top();
        pq.pop();
  
        
        Node * newNode = new Node(left -> frq + right -> frq,'$');
        newNode -> left = left;
        newNode -> right = right;
        pq.push(newNode);
    }
    

    Node *root = pq.top();
    
    for(int i=0;i<S.size();i++)
    {
        string temp = "";
        string hcode = "";
        traverse(root,temp,S[i],hcode);
        cout<<S[i]<<" - "<<hcode<<endl;
    }
    
}