#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1e5 + 10;
const int Inf = 0x3f3f3f;
#define re register

int gcd(int a, int b)
{
    return b > 0 ? gcd(b, a % b) : a;
}

inline int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

inline int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}

int n, a[Maxn],Ans[4],x[4];
int Sum=-Inf;
bool book[Maxn];
void dfs(int Dep)
{
    if(Dep==4)
    {
        // cout<<x[1]<<' '<<x[2]<<' '<<x[3]<<endl;
        int tmp = x[1]*x[2]*x[3]*(lcm(lcm(x[1],x[2]),x[3]))/lcm(x[1],x[2])/lcm(x[1],x[3])/lcm(x[2],x[3]);
        // cout<<tmp<<endl;
        if(tmp>Sum)
        {
            Ans[1]=x[1],Ans[2]=x[2],Ans[3]=x[3];
            Sum=tmp;
            return ;
        }
    }
    for(re int i=1;i<=n;++i)
    {
        if(!book[i])
        {
            x[Dep]=a[i];
            book[i]=1;
            dfs(Dep+1);
            x[Dep]=0;
            book[i]=0;
        }
    }
}
int main()
{
    freopen("a.in","r",stdin);
    n = read();
    for (re int i = 1; i <= n; ++i)
    {
        a[i] = read();
    }
    sort(a+1,a+1+n);
    dfs(1);
    cout<<Ans[1]<<' '<<Ans[2]<<' '<<Ans[3]<<endl;
    return 0;
}