#include<cstdio>
long long B,P,K;
long long qpow(int base,int p){
	if(p==1){
		return base;
	}else if(p==0){
		return 1;
	}else{
		long long ans=qpow(base,p/2)%K;
		long long ans1=(ans%K*ans%K)%K;
		if(p%2==1){
			ans1=(ans1%K*base%K)%K;
		}
		ans1=ans1%K;
		return ans1;
	}
} 
int main(){
	scanf("%lld%lld%lld",&B,&P,&K);
	long long ans=qpow(B,P);
	ans=ans%K;
	printf("%lld^%lld mod %lld=%lld",B,P,K,ans);
	return 0;
}