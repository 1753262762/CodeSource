#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int x[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i];
    }
    while (m--)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            int len,len2;
            cin >> len;
            int a[maxn], a2[maxn];
            for (int i = 1; i <= len; ++i)
                cin >> a[i];
            cin>>len2;
            for (int i = 1; i <= len2; ++i)
                cin >> a2[i];
            for (int i = 1; i <= n; ++i)
            {
                int flag = 1;
                for (int j = 1; j <= len; ++j)
                {
                    if (a[j] != x[i + j - 1])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    int tmp[maxn];
                    for(int j=1;j<i;++j)
                    {
                    	tmp[j]=x[j];
					}
					for(int j=1;j<=len2;++j)
					{
						tmp[i+j-1]=a2[j];
					}
					for(int j=i+len2-1;j<=n+len2-len1;++j)
					{
						tmp[j]=
					}
                    // i += len - 1;
                }
            }
        }
        else if (opt == 2)
        {
            for (int i = 1; i < n; ++i)
            {
                if ((x[i] + x[i + 1]) % 2 == 0)
                {
                    for (int j = n + 1; j >= i + 2; --j)
                    {
                        x[j] = x[j - 1];
                    }
                    n++;
                    x[i + 1] = (x[i] + x[i + 2]) / 2;
                    i++;
                }
            }
        }
        else if (opt == 3)
        {
            int l, r;
            cin >> l >> r;
            while (l <= r)
            {
                swap(x[l], x[r]);
                l++, r--;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << x[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}