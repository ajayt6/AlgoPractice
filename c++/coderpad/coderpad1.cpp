

/*
bool IsSumTree(Node* node) {

}

                            30
            
            7                           8
            
    4               3                           9
    
    */
    
#include<iostream>
using namespace std;

class Node
{   
    public:
    int data;
    Node *left,*right;
    
    Node(int val)
    {
        data = val;
        left =NULL;
        right = NULL;
    }
    
};


// without assumption
bool rec(Node *node, int &s)
{
    if(node  == NULL)
        {   s=0;
            return true;
        }
        
    int suml = 0,sumr=0;
    
    bool left =rec(node->left,s);
    suml = s;
    
    bool right = rec(node->right,s);
    sumr =s;
    
    if (left && right)
    {
        if(suml == 0 && sumr==0)
            {
                s= node->data;
                return true;
            }
        if(suml + sumr == node->data)
            {
                s = 2* (suml+sumr);
                return true;
            }
        else
            return false;
    }
    else
        return false;
    
    
}

bool IsSumTree(Node* node) {
    int sum = 0;
    return rec(node, sum);
       
}


int main()
{
    
    Node *head = new Node(32);
    head->left = new Node(7);
    head->right = new Node(8);
    
    head->left->left = new Node(4);
    head->left->right = new Node(3);
    
    head->right->right = new Node(8);
    
    std::cout<< IsSumTree(head);
}


