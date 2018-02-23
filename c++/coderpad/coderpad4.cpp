#include <iostream>
using namespace std;

// [begin, end)

class buf
{
  void **arr;
  int begin;
  int end;
  int limit;
  public:
  buf(int tlimit)
  {
    limit = tlimit;
    arr = new void*[limit];
    begin =0;
    end = 0;
  }
  
  int getSize()
  {
    if(end>=begin)
    return end-begin;
    else
    {
      return limit - begin + (end - 0);
    }
    
    
    
    
  }
  
  bool insert(void *item)
  {
  
    //check if limit is reached or not
    if( (end+1)%limit  == begin )
    {
      return false;
    }
    else
    {
     //insert element
      arr[end] = item;
      end = (end+1)%limit;
      
      
      return true;
    }
    
  }
  
  void *pop()
  {
    if(begin == end)
      return NULL;  //empty buffer
    
    void *temp = arr[begin];
    begin = (begin + 1)%limit;
    return temp;
  }
  
  
};

// To execute C++, please define "int main()"
int main() 
{
  buf mybuf(1000);
  mybuf.insert((char*)"hi");
  printf("%s\n",(char*)mybuf.pop());
  return 0;
}


/* 
Your previous Plain Text content is preserved below:

int buffer.getSize()
bool buffer.insert(item)
item buffer.()
 */