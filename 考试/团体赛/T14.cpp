#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[10000][10000];
long long f(int X,int Y)
{
	long long res=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			res+=max(abs(X-i),abs(Y-j))*x[X][Y];
		}
	}
	return res;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>x[i][j];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<m;++j)
		{
			cout<<f(i,j)<<' ';
		}
		cout<<f(i,m);
		cout<<endl;
	}
	return 0;
}