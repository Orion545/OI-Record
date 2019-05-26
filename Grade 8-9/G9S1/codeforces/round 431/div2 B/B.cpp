#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
double n,a[1010];
bool vis[1010];
bool check(double k,double b){
	int i,cnt=n,tmp1,tmp2;double tk=k,tb=b;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++){
		if(a[i]-b==k*i){
			vis[i]=1;cnt--;
		}
	}
//	cout<<"cnt "<<cnt<<endl;
	if(cnt==0) return 0;
	if(cnt==1) return 1;
	for(i=1;i<=n;i++){
		if(vis[i]==0){
			tmp1=i;break;
		}
	}
	for(i=tmp1+1;i<=n;i++){
		if(vis[i]==0){
			tmp2=i;break;
		}
	}
	k=(a[tmp2]-a[tmp1])/(tmp2-tmp1);
	b=a[tmp1]-k*tmp1;
//	cout<<tmp1<<ends<<tmp2<<ends<<k<<ends<<b<<ends<<tk<<ends<<tb<<endl;
	if(tk!=k) return 0;
	vis[tmp1]=vis[tmp2]=1;cnt-=2;
	for(i=tmp2+1;i<=n;i++){
		if(vis[i]==0&&a[i]-b==k*i){
			vis[i]=1;cnt--;
		}
	}
	if(cnt==0) return 1;
	else return 0;
}
int main(){
	int i;
	scanf("%lf",&n);
	for(i=1;i<=n;i++) scanf("%lf",&a[i]);
	bool ans=0;
	ans|=check(a[2]-a[1],a[1]*2.0-a[2]*1.0);
	ans|=check(a[3]-a[2],a[2]*3.0-a[3]*2.0);
	ans|=check((a[3]-a[1])/2.0,a[1]*1.5-a[3]*0.5);
	if(ans) cout<<"Yes";
	else cout<<"No";
}
//a3=1.5a3-1.5a1+b,b=1.5a1-0.5a3
