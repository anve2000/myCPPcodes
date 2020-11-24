#include<iostream>
using namespace std;

int main()
{
	int n,num,i,count;
	cin>>num;
	n=2;
	while(n<=num)
	{
		count=0;
		i=2;
	while(i<n)
	{
		if(n%i==0)
		{
			i=n;
			count++;
		}
		i=i+1;
	}
      if(count==0)
		{
			cout<<n<<endl;
		}
		n++;
	}
return 0;
}
