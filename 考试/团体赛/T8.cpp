#include<bits/stdc++.h>
using namespace std;
int x[1000+5][1000+5];
const int INF=-2147483646;
int main()
{
	int n,m,t;
	cin>>n>>m>>t;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>x[i][j];
		}
	}
	for(int k=1;k<=t;++k)
	{	
		int MAX=INF,X,Y;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(x[i][j]>MAX)
				{
					X=i,Y=j,MAX=x[i][j];
				}
			}
		}
		for(int i=1;i<=n;++i)
		{
			x[i][Y]=INF;
		}
		for(int j=1;j<=m;++j)
		{
			x[X][j]=INF;
		}
	}
	int cnt2=0;
	for(int i=1;i<=n;++i)
	{
	int cnt=0;
		int flag=0;
		for(int j=1;j<=m;++j)
		{
			if(x[i][j]!=INF)
			{
				cnt++;
				if(cnt==m-t)
				{
					cout<<x[i][j];
				}else 
				cout<<x[i][j]<<' ';
				flag=1;
			}
		}
		if(flag and ++cnt2!=n-t)cout<<endl;
	}
	return 0;
}