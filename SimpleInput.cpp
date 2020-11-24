
#include<iostream>
using namespace std;

int main()
{
    int n=1,sum=0,count=0;
    while(cin>>n)
{
  
    if(n)
    {
    sum=sum+n;
      if(sum>=0 && count==0)
      {
        cout<<n<<endl;
      }
      else if(sum<0)
        count++;
    }
}
return 0;
}
