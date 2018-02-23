#include <iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;

class LNode
{
  public:
  int data;
  LNode *next;
  LNode(int val)
  {
    data = val;
  }
  
  
};

class Node
{
  public:
  int data;
  Node *left, *right;
  Node(int val)
  {
    data =val;
    left = NULL;
    right = NULL;
    
  }
  
  
};

class pNode
{
  public:
  Node *current;
  pNode *next;
  pNode(Node *temp)
  {
    current = temp;
    next = NULL;
  }
};

class cBuf
{
  public:
  int size;
  void **holder;
  int begin,end;
  
  cBuf(int limit)
  {
    size = limit;
    begin =0;
    end = 1;
    holder = new void*[limit];
  }
  
  int currSize()
  {
    if(end>=begin)
      return end-begin+1;
    else
      return begin -end + size-begin;
  }
  
    
  
  bool eq(void *elem)
  {
    if(begin != (end+1)%size)
    {
      holder[end] = elem;
      end = (end + 1)%size;
      return true;
    }
    else  //begin should be just ahead of end
    {
      //capacity over
      return false;
    }
  }
  
  //returns pointer to element via parameter. if cBuf is empty it returns pointer to NULL
  bool dq(void **elem)
  {
    
    if(currSize() > 0)
    {
      //normal case
      *elem = holder[begin+1];
      begin++;
      return true;
    }
    else
    {
      *elem = NULL;
      return false;
    }
  }

};


class cBufv2
{
  public:
  int limit;
  void **holder;
  int begin,end;
  int size;
  
  cBufv2(int slimit)
  {
    limit = slimit;
    size = 0;
    begin =0;
    end = 0;
    holder = new void*[limit];
  }
  
  int currSize()
  {
    return size;
  }
  
    
  
  bool eq(void *elem)
  {
    if(size == limit)  //its full
    {
      return false;
    }
    else
    {
      holder[end] = elem;
      size++;
      end = (end +1)%limit;
    }
  }
  
  //returns pointer to element via parameter. if cBuf is empty it returns pointer to NULL
  bool dq(void **elem)
  {
    
    if(size == 0)
    {
      *elem = NULL;
      return false;
    }
    else
    {
      *elem = holder[begin];
      begin = (begin+1)%limit;
      size--;
      return true;
    }
  }

};


//assuming both posotive and negative numbers and only one path with the exact sum

//if there are multiple paths then this can be converted to fill in a vector of pNode pointers and this vector can be passed by reference from the first call
pNode *pathSumPath(Node *head,int sum)
{
  
  if(!head)
    return NULL;
  
  int newSum = sum- head->data;
  if(newSum == 0)
  {
    if(!head->left && !head->right)  // it is a leaf node
    {
      pNode *temp = new pNode(head);
      return temp;
    }
  }
  
  pNode *temp1 = pathSumPath(head->left,newSum);
  pNode *temp2 = pathSumPath(head->right,newSum);
  if(!temp1 && !temp2)
    return NULL;
  else if(temp1)
  {
    pNode *current = new pNode(head);
    current->next = temp1;
    return current;
  }
  else if(temp2)
  {
    pNode *current = new pNode(head);
    current->next = temp2;
    return current;
    
  }
  return NULL;
}


int sameTree(Node *aHead, Node *bHead)
{
  if(aHead == NULL && bHead == NULL)
    return 1;
  else if(aHead==NULL || bHead ==NULL)
    return 0;
  else
  {
    if(aHead->data == bHead->data)
      return sameTree(aHead->left,bHead->left) && sameTree(aHead->right,bHead->right);  //return if both are true
    
    else
      return 0;
  }
}


void printAllPaths(Node *head, vector<string> &pathV)
{
  //handle NULL
  if(!head)
    return;
  
  pathV.push_back(to_string(head->data));
  
  if(!head->left && !head->right)
  {
    //print the entire path since this is a leaf node
    cout<<endl;
    for(string nodeVal : pathV)
    {
      cout<<nodeVal<<" -> ";
    }
  }
  else
  {
    printAllPaths(head->left,pathV);

    printAllPaths(head->right,pathV);
  }
  
  //processing in this node is done, so pop the element
  pathV.pop_back();
  
  
}

vector<LNode*> splitListInParts(LNode *head, int k)
{
  //first find the length of the list
  vector<LNode*> partList;
  int len=0;
  
  LNode *temp = head;
  while(temp)
  {
    temp=temp->next;
    len++;
  }
  
  //take modulo
  int remaining = len % k;
  int partLen = len/k + (remaining > 0 ? 1 : 0);
  int parts = k;
  
  
  //process each part
  temp = head;
  for (int i =0; i < parts; i++)
  {
    if(remaining > 0)
    {
      partLen = len/k + 1;
      remaining--;
    }
    
    LNode *tempHead = temp; 
    while(partLen>0)
    {
      
      if(partLen == 1)  //this si the last element of the part
      {
        LNode *ttemp = temp;
        temp=temp->next;
        ttemp->next = NULL;  //end this part
      }
      else
        temp=temp->next;
      
      partLen--;
    }
    partList.push_back(tempHead);
    
  }  
  return partList;
}

void insertLofR(Node *parent, Node* sChild)
{
  // no need to do null check for parent as thsi ficntion is called only if parent is not null
  if(parent->left)
  {
    insertLofR(parent->left,sChild);
  }
  else
    parent->left = sChild;
}

// returns NULL if value os not present in tree
//returns pointer to head of value has been deleted
Node* delNode(Node *head,Node* parent,int val)
{
  
  if(!head)
    return NULL;
  
  if(head->data == val)
  {
    Node* temp= head;
    //delete head
    if(!parent)
    {
      //this node is head. put its left child in its position and right child of ledft child as leftmost child of its right child
      if(head->left)
      {
        head=head->left;
        
        if(head->right)
        {
          if(temp->right)
          {
            insertLofR(temp->right,head->right);
            head->right = temp->right;
          }
          else
            ;  //do nothing here as there was no original right elemnt for head
          
        }
        
      }
      else
        head = head->right;
      
      
    }
    else
    {
      if(head->left)
      {
        parent->left = head->left;
        if(head->right)
        {
         if(head->left->right)
          {
            insertLofR(head->right,head->left->right);
            
          }
          else
            head->left->right = head->right;  
          
        }
        else
          ;  //do nothing
      }
      else
        parent->left = head->right;
      
    }
    delete temp;
      
  }
  else if (val < head->data)
  {
    head->left = delNode(head->left,head,val);
  }
  else
    head->right = delNode(head->right,head,val);
    
  
  return head;
  
  
  
  
}

bool checkS(Node *left, Node *right)
{
  if(!left || !right)
  {
    if(!left && !right)
      return true;
    else 
      return false;
  }
  
  if (left->data != right->data)
    return false;
  
  return checkS(left->left,right->right) && checkS(left->right,right->left);
   
}

int fact(int num, vector<int> &v)
{
  int temp = num;
  while( (size_t) (temp+1)> v.size())  //add element
  {
    v.push_back(0);
    temp--;
  }
  
  if(v[num]!=0)
    return v[num];
  else
  {
    v[num] = num * fact(num-1,v);
    return v[num];
  }
  
  return 0;
  
}
// To execute C++, please define "int main()"
int main() 
{
  vector<int> factNum;
  factNum.push_back(1);  //for 0
  factNum.push_back(1);  //for 1
  int totNum = 0;
  
  string word = "abc";
    
  set<char> lSet;
  for (char c: word)
  {
    lSet.insert(c); 
  }
  
  for(int i=0;i<(int)word.length();i++)
  {
    
    //check how many letters come before the actual first letter alphabetically
    int temp=0;
    for(auto iter = lSet.begin(); *iter!= word[i]; iter++)
      temp++;
    
    totNum = totNum + temp * fact( word.length() - (i+1), factNum ); //temp * fact of remaining number of letters  
    
    //now remove the first letter from the set
    lSet.erase(word[i]);
    
    cout<<"End of round "<<i+1<<endl;
    
    
    
  }


  cout<<"The number fo permutations that will come before the original word is: \n"<<totNum;  
  
  cout<<endl<<"The factorial of 4 is: "<<fact(4,factNum);
  
  Node *head = new Node(4);
  Node * temp = head;
  temp->left = new Node(2);
  temp->right = new Node(2);
  temp->left->left = new Node(45);
  temp->right->right = new Node(45);
  
  
  cout<<endl<<"The result of symmetric check is: "<<checkS(head->left,head->right);
  
  
  int i=3;
  int j=1;
  int sNum = 10;
  int before=0;
  for(;i<sNum; before = i,++j,i=i+3*j)
    ;
  
  int group = sNum - before;
  cout<<endl;
  switch((group-1)/j)
  {
    case 0:
      cout<<"a";
      break;
    case 1:
      cout<<"b";
      break;
    case 2:
      cout<<"c";
  }
  cout<<endl;
  
  return 0;
}


