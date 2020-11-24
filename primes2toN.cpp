
int main()
{
	int n,num,i,count;
	cin>>num;
	n=2;
	while(n<=num)
        {
                i=2;
	while(i<n && n%i!=0)
	       {
		i=i+1;
	       }
      if(i==n)
		{
			cout<<n<<endl;
		}
		n++;
	}
return 0;
}
