#include <bits/stdc++.h>
using namespace std;
int n = 0, ans = 0;
#define re register
bool Sovle(int x)
{
    int cnt = 0;
    while (1)
    {
        int tmp = 0;
        tmp = x - (x / 10) * 10;
        cnt++;
        if (cnt % 2 == 0)
        {
            if (tmp % 2 != 0)
                return 0;
        }
        else if (cnt % 2 == 1)
        {
            if (tmp % 2 != 1)
                return 0;
        }
        if (x < 10)
        {
            if (cnt % 2 == 0)
            {
                if (x % 2 != 0)
                {
                    return 0;
                }
            }
            else if (cnt % 2 == 1)
            {
                if (x % 2 != 1)
                    return 0;
            }
            break;
        }
        x = x / 10;
    }
    return 1;
}
int main()
{
    // cout<<Sovle(11);
    cin>>n;
    for(re int i=1;i<=n;++i)
    {
        if(Sovle(i))
        {
            //cout<<i<<endl;
            ans++;
        }    
    }
    cout<<ans<<endl;
    return 0;
}