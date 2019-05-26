#include<bits/stdc++.h>
using namespace std;

long long tt,n,a,b,c,tot=0;
long long ans;
int p[101],t[101];

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>tt;
	while(tt--){
		tot=0;
		for(int i=1;i<=100;i++) p[i]=0;
		ans=0;
		scanf("%d",&n);
		
		for(int i=1;i<=n;i++) scanf("%d",&t[i]);
		sort(t+1,t+n+1);
		if(n==1){
			cout<<'1'<<endl;
			continue;
		}
		if(n==2){
			if(t[2]%t[1]==0){
				cout<<'1'<<endl;
				continue;
			}
			cout<<'2'<<endl;
			continue;
		}
		if(n==3){
			a=t[1],b=t[2],c=t[3];
			if(c>a*b-a-b){
				if(b%a==0){
					cout<<'1'<<endl;
					continue;
				}
				cout<<'2'<<endl;
				continue;
			}
			if(b%a==0){
				cout<<'1'<<endl;
				continue;
			}
			cout<<'3'<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(t[i]&&t[j]%t[i]==0) t[j]=0;		
		for(int i=1;i<=n;i++)
			if(t[i]) p[++tot]=t[i];
		sort(p+1,p+tot+1);
		a=p[1],b=p[2];
		for(int i=1;i<=n;i++) 
			if(t[i]>a*b-a-b)
				t[i]=0;
		for(int i=1;i<=n;i++)
			if(t[i]) ans++;
		cout<<ans<<endl;
	}
}
