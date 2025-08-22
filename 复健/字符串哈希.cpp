#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define re register
const int Mod=100000007;
const int Max_M = 1500 +10;
bool Book[100000007];
// ull POW[110]={1,2,4,8,16,32,64,128};

int Hash(char *a)
{
    int Len=strlen(a);
    ull Ret=0;
    for(re int i=0;i<Len;++i)
    {
        Ret+=int(a[i])*pow(2,i);
        Ret%=Mod;
    }
    return Ret;
}

const ull P = 113;
const ull P2 = 233;
static inline const ull Hash(char *s)
{
    ull res = 0;
    int s_len = strlen(s);
    for (re int i = 0; i < s_len; ++i)
    {
        res = (ull)(res * P + s[i]);
    }
    return res;
}
static inline const ull Hash2(char *s)
{
    ull res = 0;
    int s_len = strlen(s);
    for (re int i = 0; i < s_len; ++i)
    {
        res = (ull)(res * P2 + s[i]);
    }
    return res;
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

int main()
{
    int N=read(),ans=0;
    while (N--)
    {
        char S[Max_M];
        cin>>S;
        if(Book[Hash(S)]==0)
        {
            cout<<Hash(S)<<endl;
            ans++;
            Book[Hash(S)]=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}