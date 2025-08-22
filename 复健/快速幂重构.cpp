#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long 
#define ll long long

using namespace std;

ull pow(ull a,ull x,ull p);//a的x方对p取模

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

int a,b,p;
inline void input()
{
    a=read(),b=read(),p=read();
}
inline void solve()
{
    cout<<pow(a,b,p)<<endl;
}
int main()
{
    input();
    solve();
    return 0;
}
ull pow(ull a,ull x,ull p)
{
    if(x==1)return a%p;
    ull tmp = pow(a, x/2,p)%p;
    return x%2 ? (ull)(tmp*tmp*a)%p :(ull)(tmp*tmp)%p;
}