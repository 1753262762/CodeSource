#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ansi=0,ansk=0;
	cin>>n;
	for(int k=1;k<=100;++k)
	{
		int sum=0;
		for(int i=1;i<=100000;++i)
		{	
			sum+=pow(i,k);
			if(sum>n)break;
			if(sum==n)
			{
				ansi=i;
				ansk=k;
			}
			
		}
	}
	if(ansi==0 and ansk==0)
	{
		cout<<"Impossible for "<<n<<".";
	}
	else 
	{
		for(int i=1;i<ansi;++i)
		{
			cout<<i<<"^"<<ansk<<"+";
		}
		cout<<ansi<<"^"<<ansk;
	}
	return 0;
}