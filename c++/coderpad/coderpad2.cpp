#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

class Node
{
  public:
  int data;
  Node *left,*right,*next;
  
  Node(int val)
  {
    data= val;
    left = NULL;
    right = NULL;
    next = NULL;
  }
};
  


Node *nodeAt(Node *head, int pos)
{
  Node *temp = head;
  int count =0;
  while(temp && count < pos)
  {
   temp=temp->next;
    count++;
  }
  if(!temp)
    return NULL;
  
  return temp;
}


//reverse linked list via recursion
Node *reverseRecur(Node *child, Node *parent)
{
  
  if (child == NULL)
    return parent;
  
  Node *temp = child->next;
  
  child->next = parent;
  
  return reverseRecur(temp,child);
}

//Print linked list
void printList(Node *head)
{
  Node *temp = head;
  cout<<endl<<"The linked list is: "<<endl;
  while(temp)
  {
    cout<<temp->data<<"  ";
    if(temp->left)
      cout<<"l->"<<temp->left->data<<"  ";
    temp= temp->next;
  }
  cout<<endl;
    
  
}


//Reverse linked list in k groups
Node *reverseK(Node *head, int k)
{
 //iterate till k elements or NULL and then call reverseRecur. take care to link the reversed segments properly
  
  Node *temp = head;
  int count = 0;
  
  Node *iHead=NULL,*iTail=NULL,*pHead=NULL;
  while(temp)
  {
    count = 0;
    iHead = temp;
    while(temp && count<k-1)
    {
      if(temp->next == NULL)
        break;
      temp = temp->next;
      count++;
      
    }
    
    //At this point we have iterated till k elements. reverse this segment
    iTail = temp;
    
    temp = temp->next;
    
    iTail->next = NULL;
    
    if(head == iHead)
    {
      head = reverseRecur(iHead,NULL);
      pHead = iHead; 
    }
    else
    {
      pHead->next = reverseRecur(iHead,NULL);
      pHead = iHead;
    }
    
    
  }
  
  return head;
  
}


/*
Given a singly linked list L: L0→L1→ ... →Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→...

For example, given {1,2,3,4}, reorder it to {1,4,2,3}. You must do this in-place without altering the nodes' values.
*/


void listHelper(Node **first, Node *second)
{
  if(second == NULL)
    return ;
  
  
  listHelper(first,second->next);
  
  //At this point second points to nodes that are in reverse order from end
  if(*first == second)
  {
    (*first)->next = NULL;
    return;
  }
  
  //cout<<endl<<"first is: "<<(*first)->data<<" and second is: "<<second->data;
  Node *temp = (*first)->next;
  (*first)->next = second;
  second->next = temp;
  (*first) = temp;
  
  
  
  
}


Node *reorderList(Node *head)
{
  //Iterate till half of list. then recurse one half and go from beginnig for other half
  Node *fast = head->next, *slow = head;
  if(!fast || !slow)
    return head;
  
  while(fast)
  {
    fast = fast->next;
    if(fast)
    {
      slow = slow->next;
      fast = fast->next;
    }
    
  }
  //cout<<endl<<"head is: "<<(head)->data<<" and slow is: "<<slow->data;
  listHelper(&head,slow);
  if(slow->next)
    slow->next->next = NULL;
  
  return head;
}


/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list
*/
Node *deepCopyList(Node *head)
{
  unordered_map<Node*,Node*> addrMap;
  
  if(!head)
    return NULL;
  
  Node *temp = head;
  
  Node *newHead = new Node(temp->data);
  addrMap.insert(pair<Node*,Node*>(temp,newHead));
  Node *nTemp = newHead;
  
  temp = temp->next;
  
  while(temp)
  {
    nTemp->next = new Node(temp->data);
    addrMap.insert(pair<Node*,Node*>(temp,nTemp->next));
    temp = temp->next;
    nTemp = nTemp->next;
    
  }
  
  nTemp->next = NULL;
  
  //Now copy the random pointers . In this case we use left instead of random pointers
  nTemp = newHead;
  temp = head;
  
  while(temp)
  {
    nTemp->left = addrMap[temp->left];
    temp = temp->next;
    nTemp= nTemp->next;
    
  }
  
  return newHead;
}

void removeDup(Node *head)
{
  Node *temp = head;
  
  
  while(temp)
  {
    Node *t = temp->next;
    while(t && t->data == temp->data)
    {
      Node *del = t;
      t=t->next;
      delete del;
    }
    temp->next = t;
    temp = t;
      
    
  }
  
  
}

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example, given 1->1->1->2->3, return 2->3.
*/

Node *returnDistinct(Node *head)
{
 
  Node *temp = head;
  //cout<<"here";
  int flag=0;
  while(temp)
  {
    flag = 0;
    Node *t = temp->next;
    //cout<<endl<<"t->data is: "<<t->data;
    while(t && ( t->data == temp->data) )
    {
      flag = 1;
      Node *del = t;
      t=t->next;
      //cout<<endl<<"NOde going to be deleted is: "<<del->data;
      delete del;
    }
    if (flag == 1)
    {
      //check if temp is head and then delete  
      if(head == temp)
        head = t;
      delete temp;
    }
    temp = t;
    
  }
  
  return head;
  
}

//Construct linked list form string
Node *constructDigitList(string listStr)
{
  if(listStr.compare("NULL") == 0)
    return NULL;
  
  Node *head = NULL, *temp = NULL;
  for(char ch : listStr)
  {
    //cout<<ch;
    if(ch<'0' || ch>'9')
      continue;
    
    if(!head)
    {
      head = new Node(ch - '0'); 
      temp = head;
    }
    else
    {
      temp->next = new Node(ch - '0');
      temp=temp->next;
    }
  }
  return head; 
  
}

/*

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example, given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.

*/

Node *partitionList(Node *head, int p)
{
  Node *begin = NULL,*sBegin = NULL,*newHead = NULL, *newSHead = NULL;
  Node *temp =head;
  
  
  while(temp)
  {
   if(temp->data < p)
   {
     
     if(!newHead)
     {
       begin = temp;
       newHead = begin;
     }
     else
     {
       begin->next = temp;
       begin = begin->next;
     }
   }
   else
   {
     
     if(!newSHead)
     {
       sBegin = temp;
       newSHead = sBegin;
     }
     else
     {
        sBegin->next = temp;
        sBegin = sBegin->next;
     }
      
   }
    temp = temp->next;
    
  }
  
  //Link both sublists and assign NULL tpo last elelment of second sub list
  begin->next = newSHead; 
  sBegin->next = NULL;
  
  return newHead;
}

string solution(string &S, int K) 
{
  // write your code in C++14 (g++ 6.2.0)
  //cout<<S;
  //First calcluate hoiw many caharacters in first group
  int len = 0;
  for(char ch : S)
  {
      if(ch!='-')
          len++;
  }


  int numFirst = len % K;
  int tk = 0;
  int flag = 0;
  int  i =0;
  
  int length = S.length();
  //Now start iterating thorugh original string. handle numFirst as special case
  
  
  //cout<<endl<<"The originial string is: "<<S;

  int j = 0;
  char ch;
  
  //Move everything to end of string
  j = length -1;
  i=j;
  while(j>=0)
  {
   if(S[j] != '-' )
   {
     S[i] = S[j];
     j--;
     i--;
   }
    else
    {
      j--;
      
      
    }
      
    
    
  }
  
  //cout<<endl<<"The modified string is: "<<S<<endl;
  //cout<<endl<<"the substring of modified is: "<<S.substr(i+1)<<endl;
    
  j=i+1;
  
  i=0;
  
  while(j<length)
  {

    //Assign group length
    if(flag == 0)
    {
         if(numFirst != 0 )
            {
                tk = numFirst;
                numFirst = 0;
            }
            else
            {
              tk = K;
            }

        flag = 1;
    }

    //cout<<endl<<"j is: "<<j<<" and i is: "<<i;
    ch = S[j];

    //cout<<"tk is: "<<tk<<endl;
    if(tk>0)
    {
        
            if (ch >= 'a' && ch <='z')
                ch = ch -'a' + 'A';
            S[i] = ch;
          //cout<<endl<<"S is assigned ch of: "<<ch<<endl;
            tk--;
            i++;

       
    
      j++;
    }
    else
    {
        flag  = 0;

        S[i] = '-';
        i++;


    }




  }
  
    S =S.substr(0,i);
    return S;
}
/*





ompilation successful.

Your test case:  ['2-4A0r7-4k', 4] 
Output:
tk is: 4tk is: 3tk is: 3tk is: 2tk is: 1tk is: 0tk is: 4tk is: 3tk is: 3tk is: 2
Returned value: '24A0-R74K' 

Example test:    ('2-4A0r7-4k', 4) 
Output:
tk is: 4tk is: 3tk is: 3tk is: 2tk is: 1tk is: 0tk is: 4tk is: 3tk is: 3tk is: 2
OK 

Example test:    ('2-4A0r7-4k', 3) 

*/

/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
string longestPrefix(vector<string> strList)
{
  //int len = strList.size();
  string pre = "";
  int flag = 0,bFlag = 0;
  
  for(int i=0;;i++)
  {
    flag = 0;
    for(string str : strList)
    {
      
      if( i<str.length() )
      {
        if(flag == 0)
        {
          flag = 1;
          pre = pre + str[i];
        }
        else
        {
         //Already the character is added to pre. check if it matches with other strings
          if(pre[i] != str[i])
          {  
            pre = pre.substr(0,i);
            bFlag = 1;
            break;
            
          }
        }
        
      }
      else
      {
        
        bFlag =1;
        break;
      }
      
      
      
    }
    if(bFlag == 1)
      break;
  }
  
  return pre;
}
 

/*
Compare two version numbers version1 and version2. If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0
//Assuming only twoi segemnets for versions
*/
int compareVersions(string ver1, string ver2)
{

  int len1 = ver1.length();
  int len2 = ver2.length();
  int i=0,j=0;
  int init1=0,init2=0;
  int num1,num2;
  
  while(i<len1 || j< len2)
  {
   //get  segment for ver1
    init1 = i;
    while(ver1[i] != '.' && i<len1)
      i++;
    
    if(init1 != i)
      num1 = stoi(ver1.substr(init1,i));
    else
    {
      num1=0;
    }
    
    cout<<endl<<"num1 is: "<<num1;
    //get  segment for ver2
    init2 = j;
    while(ver2[j] != '.' && j<len2)
      j++;
    
    if(init2 != j)
      num2 = stoi(ver2.substr(init2,j));
    else
    {
      num2= 0;
    }
    
    
    cout<<endl<<"num2 is: "<<num2<<endl;
    
    i++;
    j++;
    
    //comparison of same segment of versions
    if (num1<num2)
      return -1;
    else if(num1>num2)
      return 1;
    
    
    
    
  }
  
  return 0;
  
}


/*
Given a sorted array of integers, find the starting and ending position of a given target value. Your algorithm's runtime complexity must be in the order of O(log n). If the target is not found in the array, return [-1, -1]. For example, given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].

*/

class rangeClass
{
  public:
    int left,right;
    rangeClass()
    {
       left = -1;
       right =-1; 
    }
  
};

rangeClass rangesearch(int a[],int len,int val)
{
  
  int i=0, j=len-1;
  int mid=-1;
  rangeClass rObj;
  int flag = 0;
  
  while(i<=j)
  {
    mid = i + (j-i)/2;
    
    if(a[mid] == val)
    {
      flag =1;
      break;
    }
    if(a[mid] < val)
      i = mid+1;
    else
      j=mid-1;
    
  }
  
  if(flag ==1)
 {
  //check in both sides
    int tmid = mid;
   while(tmid>=0 && a[tmid] == val)
     tmid--;
   rObj.left = tmid+1;
   
    tmid= mid;
   while(tmid<len && a[tmid] == val)
     tmid++;
   rObj.right = tmid-1;

 }
             
  return rObj;
}



int main() 
{
 
  
  Node *head  = new Node(5);
  Node *temp = NULL;
  head->next= new Node(4);
  temp = head->next;
  
  temp->next = new Node(76);
  temp = temp->next;
  
  temp->next = new Node(236);
  temp = temp->next;
  
  temp->next = new Node(7);
  temp = temp->next;
  
  temp->next = new Node(6);
  temp = temp->next;
  
  temp->next = new Node(776);
  temp = temp->next;
  
  temp->next = new Node(43);
  temp = temp->next;
  
  temp->next = new Node(8);
  temp = temp->next;
  
  temp->next = new Node(61);
  temp = temp->next;
  
  //temp->next = new Node(55);
  //temp = temp->next;
  

  
  
  printList(head);
  
  head = reverseRecur(head,NULL);
  
  printList(head);
  
  head = reverseK(head,3);
  
  printList(head);
  
  reorderList(head);
  
  printList(head);
  

  //assign random (left) pointers
  temp = nodeAt(head,3);
  if (temp)
    temp->left = nodeAt(head,6);
  
  temp = nodeAt(head,1);
  if (temp)
    temp->left = nodeAt(head,8);
  
  printList(head);
  

  
  Node *nHead = deepCopyList(head);

  //Change something in poriginal list to see if it is beign affected
  temp = nodeAt(head,6);
  if(temp)
    temp->data = 555;
  
  cout<<endl<<"original list is: "<<endl;
  printList(head);
  
  cout<<endl<<"Deepcopied list is: "<<endl;
  printList(nHead);
  
  head = constructDigitList("1->1->1->2->3");
  printList(head);
  
  head = returnDistinct(head);
  printList(head);
  
  
  head = constructDigitList("1->1->1->2->3->3");
  printList(head);
  removeDup(head);
  printList(head);
  
  head = constructDigitList("1->4->3->2->5->2");
  printList(head);
  head = partitionList(head,3);
  printList(head);
  
  string S = "2-4A0r7-4k";
  cout<<endl<<"Before string operation: "<<S;
  cout<<endl<<"After string operation: "<<solution(S,4);
  cout<<endl;
  S = "2-4A0r7-4k";
  cout<<endl<<"Before string operation: "<<S;
  cout<<endl<<"After string operation: "<<solution(S,3)<<endl;
  
  vector<string> strList;
  strList.push_back("helilman");
  strList.push_back("heliloo");
  strList.push_back("helilooooo");
  strList.push_back("helil");
  strList.push_back("helicombat");
  strList.push_back("helix");
  cout<<endl<<"Longest common prefix is: "<<longestPrefix(strList)<<endl;
  
  cout<<endl<<"Comaprison value of versions is: "<<compareVersions("1.12", "1.1");
  cout<<endl<<"Comaprison value of versions is: "<<compareVersions("0.1", "1.1");
  cout<<endl<<"Comaprison value of versions is: "<<compareVersions("13.37", "1.1");
  cout<<endl<<"Comaprison value of versions is: "<<compareVersions("0.1", ".1");
  cout<<endl<<"Comaprison value of versions is: "<<compareVersions("1.", "1.0");
  cout<<endl<<"Comaprison value of versions is: "<<compareVersions("1.14", "1.");
  
  cout<<endl;
  
  int a[] = {5, 7, 7, 8, 8, 10};
  
  rangeClass r =  rangesearch(a,sizeof(a)/sizeof(int),156);
  cout<<endl<<"The range is: ["<<r.left<<","<<r.right<<"]"<<endl;
  
  int b[] = {8, 8, 8, 8, 8, 8};
  
   r =  rangesearch(b,sizeof(b)/sizeof(int),8);
  cout<<endl<<"The range is: ["<<r.left<<","<<r.right<<"]"<<endl;
  
  return 0;
}
