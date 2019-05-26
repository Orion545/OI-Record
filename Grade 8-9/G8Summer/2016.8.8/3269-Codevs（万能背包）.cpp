#include<iostream>
using namespace std;
long long n,v,c[1001],w[1001],p[1001],f[1000001];
int main(){
	cin>>n>>v;
	for(long long i=1;i<=n;i++) cin>>c[i]>>w[i]>>p[i];
	
	for(long long i=1;i<=n;i++){
		if(p[i]==-1){
			for(long long j=c[i];j<=v;j++){
				f[j]=max(f[j],f[j-c[i]]+w[i]);
			}
		}
		else{
			long long tmp=p[i],k=1; 
			while(tmp>0){
				if(tmp<k) k=tmp;
				tmp-=k;
				for(int j=v;j>=c[i]*k;j--){
					f[j]=max(f[j-k*c[i]]+w[i]*k,f[j]);
				}
				k*=2;
			}
		}
	}
	cout<<f[v];
} 
