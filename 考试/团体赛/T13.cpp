#include<bits/stdc++.h>
using namespace std;

const int maxn = 500+10;
const int maxm = 500000+10;
struct node
{
	int to,next,dis,value;
}edge[maxm];
int head[maxm],cnt;
bool use[maxn][maxn];
void makeEdge(int from,int to,int dis,int value)
{
	edge[++cnt].next=head[from];
	edge[cnt].dis=dis;
	edge[cnt].to=to;
	edge[cnt].value=value;
	head[from]=cnt;
}
void add(int from,int to,int dis,int value)
{
	makeEdge(from,to,dis,value);
	makeEdge(to,from,dis,value);
}
int happy[maxn];
void dfs(int u,int money)
{
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(money>=edge[i].dis)
		{
			if(!use[u][v] and !use[v][u])
			if(happy[u]+edge[i].value>happy[v])
			{
				happy[v]=happy[u]+edge[i].value;
				use[u][v]=1;
				use[v][u]=1;
				dfs(v,money-edge[i].dis);
				use[u][v]=0;
				use[v][u]=0;
			}
		}
	}
}
int main()
{
	int money,n,m,t;
	cin>>money>>n>>m>>t;
	for(int i=1;i<=m;++i)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		add(a,b,c,d);
	}
	for(int k=1;k<=t;++k)
	{
		memset(happy,0,sizeof(happy));
		int from;
		cin>>from;
		dfs(from,money);
		int MAX=0;
		int flag=0;
		int ans[maxn],cntAns=0;
		for(int i=1;i<=n;++i)
		{
			if(happy[i])
			{
				flag=1;
				ans[++cntAns]=i;
				MAX=max(MAX,happy[i]);
			}
		}
		if(!flag)
		{
			cout<<"T_T"<<endl;	
			continue;
		}
		for(int i=1;i<cntAns;++i)
		{
			cout<<ans[i]<<' ';
		}
		cout<<ans[cntAns]<<endl;
		cntAns=0;
		for(int i=1;i<=n;++i)
		{
			if(happy[i]==MAX)
			ans[++cntAns]=i;
		}
		for(int i=1;i<cntAns;++i)
		{
			cout<<ans[i]<<' ';
		}
		cout<<ans[cntAns]<<endl;
		cntAns=0;
	}
	return 0;
}