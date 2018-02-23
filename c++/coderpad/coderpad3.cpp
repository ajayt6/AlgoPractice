#include<set>
#include<vector>
#include<string> 
#include<iostream>
using namespace std;

string solution(string &S) 
{
  
  // write your code in C++14 (g++ 6.2.0)
    set<int> numSet;
    int time=0;
    for(char ch : S)
    {
     if (ch!=':')
     {
         time=time *10 + ch-'0';
        numSet.insert(ch-'0');    
     }
    }
  //cout<<"time is: "<<time<<endl;
    
    //store in vector
  vector<int> numV;
    for(auto i = numSet.begin(); i!=numSet.end();i++)
    {
      numV.push_back(*i);
    }
  for(int n: numV)
    ;//cout<<endl<<n<<"  ";
 
  
  string t = "";
  string u="";
  string tu="";
  string v="";
  string x="",ux="",tv="";
  int check;
  int min=2359;
  int temp=0;
  string minTime="";
  
  int ttemp=0;
  int tmin=time;
  string tminTime="";
  
  for(int i =0;i<numV.size();i++)
  {
    t="";
    t= t+to_string(numV[i]);
    for(int j=0;j<numV.size();j++)
    {
      v="";
      v=to_string(numV[j]);
      tv=t+v;
      check = stoi(tv);
      if(check>23)
        continue;
      
      for(int k = 0;k<numV.size();k++)
      {
        u="";
        u=u+to_string(numV[k]);
        for(int l=0;l<numV.size();l++)
        {
          x="";
          x=to_string(numV[l]);
          ux=u+x;
          //cout<<endl<<u<<endl;
          check = stoi(ux);
          //cout<<endl<<check<<endl;
          if(check>59)
            continue;
          
          temp = stoi(tv)*100+stoi(ux);
          ttemp = stoi(tv)*100+stoi(ux);
          //cout<<endl<<temp<<endl;
          if(temp>time )
          {
            //cout<<endl<<temp<<endl;
            if(temp<min)
            {
              min=temp;
              tu = tv+":"+ux;
              minTime = tu;
            }
          }
          if(ttemp<time)
          {
            //cout<<endl<<ttemp<<endl;
           if(ttemp<tmin)
           {
            tmin = ttemp;
             tminTime = tv+":"+ux;
           }
            
          }
          
          //cout<<tu<<endl;
          
          
        }
        
      }
      //u="";
      
    }
    
  }
      
      
if(minTime.compare("") == 0)
{
 // cout<<"special";
  return tminTime;
}
  else
  {
   // cout<<"normal";
 return minTime;   
  }
}

int main()
{
  
  string S="23:58";
  //cout<<stoi("00")<<endl;
  cout<<endl<<solution(S);
  cout<<"end";
  return 0;
}