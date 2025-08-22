#include<bits/stdc++.h>
using namespace std;
//(((2+3)*4)-(5/(6*7)))
char ss[100+5];
int main()
{
	cin>>ss;
	int len=strlen(ss);
	for(int i=0;i<len;++i)
	{
		if(ss[i]==')')
		{
			for(int l=i-1;l>=0;--l)
			{
				if(ss[l]=='(')
				{	
					ss[l]=0,ss[i]=0;
					for(int k=l+1;k<=i-1;++k)
					{
						if(ss[k])
						{
							cout<<ss[k];	
							ss[k]=0;
						}
					}
					cout<<endl;
					break;
				}	
			}		
		}
	}
	return 0;
}