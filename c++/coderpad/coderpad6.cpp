#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Node
{
  public:
  int data;
  Node *left,*right;
  Node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

class LNode
{
  public:
  int data;
  LNode *next;
  LNode(int val)
  {
    data = val;
    next = NULL;
  }
};

class NodeList
{
  public:
  Node *current;
  NodeList *next;
  NodeList(Node *temp)
  {
    current = temp;
    next = NULL;
  }
};

LNode *removeDups2(LNode *head)
{
  //dont remove head irrespective of whether its duplicate
  int hFlag = 0;
  if(head && head->next && head->data == head->next->data)
    hFlag = 1;
  
  LNode *temp = head;
  LNode *current = temp->next;
  
  int flag = 0;
  while(current)
  {
    flag = 0;
    
    while(current && current->next && current->data == current->next->data)
    {
      flag = 1;
      LNode *ctemp = current->next;
      current->next = ctemp->next;
      delete ctemp;
      
    }
    
    if(flag)
    {
      //current is also one of the duplicates
      LNode *ctemp = current;
      temp->next = current->next;
      current  = temp->next;
      delete ctemp;
    }
    else
    {
      //current was not a duplicate
      temp->next = current;
      temp=temp->next;
      current = current->next;
    }
  }
  
  if(hFlag)
  {
    //head was part of duplicate
    LNode *ctemp = head;
    head = head->next;
    delete ctemp;
  }
  
  return head;
  
}

//call this only after NULL check for head
pair<NodeList *,int> returnDeepestPath(Node *head, int d=0)
{
  pair<NodeList *,int> lp,rp;
  
  if(!head->left && !head->right)
  {
    NodeList* front = new NodeList(head);
    return pair<NodeList *,int>(front,d);
  }
  
  if(head->left)
    lp = returnDeepestPath(head->left,d+1);
  
  if(head->right)
    rp = returnDeepestPath(head->right,d+1);
  
  if(lp.second>rp.second)
  {
    NodeList* temp = new NodeList(head);
    temp->next = lp.first;
    
    return pair<NodeList *,int>(temp,lp.second);
  }
  else
  {
    NodeList* temp = new NodeList(head);
    temp->next = rp.first;
    
    return pair<NodeList *,int>(temp,rp.second);
  }
  
}

pair<int,int> smallestPair(vector<int> &a,vector<int> &b)
{
  //b is smaller
  //put elements of b into a set
  set<int> dSet;
  
  for(int i : b)
  {
    dSet.insert(i);
  }
  
  int minDiff = INT_MAX;
  pair<int,int> minSol;
  
  for(int i:a)
  {
    dSet.insert(i);
    
    auto iter = dSet.find(i);
    
    auto prevT = prev(iter,1);
    if(prevT!=dSet.end())
    {
      if(*iter - *prevT < minDiff)
      {
        minDiff = *iter - *prevT;
        minSol = pair<int,int>(*prevT,*iter);
      }
    }
    
    auto nextT = next(iter,1);
    if(nextT!=dSet.end())
    {
      if(*nextT - *iter < minDiff)
      {
        minDiff = *nextT - *iter;
        minSol = pair<int,int>(*iter,*nextT);
      }
    }
    
    dSet.erase(i);
  }
  
  return minSol;
}

unordered_map<string,vector<string>> rotList(vector<string> &c)
{
  unordered_map<string,vector<string>> sMap;
  
  for(string s: c)
  {
    
    string temp = s;
    int diff = s[0]-'a';
    temp[0] = s[0]-diff;
    
    for(int i=1;(size_t)i<s.length();i++)
    {
      temp[i] = s[i]-diff;
      
    }
    
    if(sMap.find(temp) != sMap.end())
    {
      sMap[temp].push_back(s);
    }
    else
    {
      vector<string> tempV;
      tempV.push_back(s);
      
      sMap.insert(pair<string,vector<string>> (temp,tempV));
    }
  }
  
  for(auto i: sMap)
  {
    cout<<endl<<"group is: ";
    for(auto j: i.second)
    {
      cout<<j<<"  ";
    }
  }
  
  return sMap;
  
  
}

int minimum(int a,int b, int c)
{
  if(a<=b)
  {
    if(c<=a)
      return c;
    else
      return a;
  }
  else
  {
    if(c<=b)
      return c;
    else
      return b;
  }
}

int editD(string &a,string &b,int i, int j,vector<vector<int>> &m)
{
  if(m[i][j] != -1)
        return m[i][j];
  
  if(i>0 && j>0)
  {
    if(a[i] == b[j])
    {
      m[i][j] =  editD(a,b,i-1,j-1,m);
      return m[i][j];
    }
    else
    {
      //try all three permissible operations in edit distance
      //insert //delete //substitute
      
      m[i][j] = 1 + minimum( editD(a,b,i,j-1,m), editD(a,b,i-1,j-1,m), editD(a,b,i-1,j,m) );
      return m[i][j];
    }
  }
  else
  {
    if(i==0)
      return j;
    else
      return i;
  }
}

int editDWrapper(string &a,string &b)
{
  int l = a.length();
  int n = b.length();
  
  vector<vector<int>> m;
  for(int i=0;i<l;i++)
  {
    vector<int> temp(n);
    fill(temp.begin(),temp.end(),-1);
    m.push_back(temp);
  }
  
  return editD(a,b,l-1,n-1,m);
  
}

int main()
{
  vector<int> A = { 1,3, 15, 11, 2};
  vector<int> B = {23, 127, 235, 19, 8};
  
  Node *head = new Node(10);
  head->left= new Node(5);
  head->right = new Node(15);
  
  head->left->left = new Node(2);
  head->left->left->left = new Node(1);
  head->left->left->right = new Node(3);

  
  head->right->left = new Node(11);
  
  //get deepest path
  if(head)
  {
    pair<NodeList *,int>tempList =  returnDeepestPath(head);
    NodeList *temp = tempList.first;
    
    cout<<endl<<"The deepest path is: "<<endl; 
    while(temp)
    {
      cout<<temp->current->data<<"  ";
      temp=temp->next;
    }
  }
  
  vector<string> v = {"abc","cde","aaa","ddd","efg"};
    //{"bcd","zzz","abc", "cms","fff", "eou","fdf"};
  rotList(v);
  
  pair<int,int> sol;
  if(A.size() > B.size())
    sol = smallestPair(A,B);
  else
    sol = smallestPair(B,A);
  
  cout<<endl<<"THe numbers are: "<<sol.first<<" and "<<sol.second;
  
  string a = "geek";
  string b = "geek";
  cout<<endl<<"The edit distance value is: "<<editDWrapper(a,b);
  return 0;
}