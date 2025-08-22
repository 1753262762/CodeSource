#include<bits/stdc++.h>
using namespace std;
int n;
double d;
double ans; 
int a[1000],CNT;
void Sovle(double x)
{
    int cnt = 0;
    while(1)
    {
        if(x != int(x))
        {
            x*=10;
            cnt++;
        }
        else break;
    }
    int cnt2=1,tmpx=int(x);
    int ans = 0;
    while (1)
    {
        int tmp = 0;
        tmp = tmpx - (tmpx / 10) * 10;
        a[++CNT]=tmp;
        if (tmpx < 10)
        {
            break;
        }
        tmpx = tmpx / 10;
    }
    double res=0;
    for(int i=1;i<=cnt;++i)
    {
        if(a[i]>5)a[i]=0,++a[i+1];
    }
    for(int i=1;i<=CNT;++i)
    {
        res+=a[i]*pow(10,i-1);
    }
    cout<<int(res/pow(10,cnt));
    return ;
}
int main()
{
    //freopen("a.in","r",stdin);
    cin>>n>>d;
    ans=d*pow(2,n);
    Sovle(ans);
    return 0;
}