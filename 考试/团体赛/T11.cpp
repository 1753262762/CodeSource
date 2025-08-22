#include<bits/stdc++.h>
using namespace std;
int book[86400+10];
int sum[86400+10];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		char ss[100];
		cin>>ss;
		int a,b,c;
		a=(ss[0]-'0')*10+(ss[1]-'0');	
		b=(ss[3]-'0')*10+(ss[4]-'0');
		c=(ss[6]-'0')*10+(ss[7]-'0');
		int t1=a*60*60+b*60+c;
		cin>>ss;
		int e,f,g;
		e=(ss[0]-'0')*10+(ss[1]-'0');	
		f=(ss[3]-'0')*10+(ss[4]-'0');
		g=(ss[6]-'0')*10+(ss[7]-'0');
		int t2=e*60*60+f*60+g;
		sum[t1+1]++;
		sum[t2-1]--;
	}
	for(int i=1;i<86400;++i)
	{
		book[i]=book[i-1]+sum[i];
	}
	int ans=0;
	for(int i=0;i<86400;++i)
	{
		ans=max(ans,book[i]);
	}
	cout<<ans;
	return 0;
	
}