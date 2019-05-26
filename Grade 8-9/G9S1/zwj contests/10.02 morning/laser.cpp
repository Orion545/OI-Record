#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,l[10010],r[10010];
int max(int x,int y){return (x>y?x:y);};
bool a[10][10];
bool num[10010];
void check(int x,int pos){
//	cout<<"check "<<x<<ends<<pos<<endl;
	int i,tmp,p=pos,tx=x,kk;
	for(i=1;i<=9;i++){
//		cout<<"	to "<<i<<endl;
		x=tx;tmp=0;pos=p;
		while(--pos){
			tmp=tmp*10+x%10;
			x/=10;
		}
		kk=x%10;
		if(i==x%10) continue;
		x/=10;x*=10;x+=i;
//		cout<<"		changed"<<endl;
		while((++pos)<p) x*=10;
		x+=tmp;
//		cout<<"	now: "<<x<<endl;
		if(!num[x]) a[kk][i]=a[i][kk]=0;
	}
}
bool vis[11]={0};
void check2(int x){
	int i,j;
	for(i=1;i<x%10;i++){
		for(j=x%10;j<=9;j++){
			a[i][j]=a[j][i]=0;
		}
	}
}
void solve(int x){
//	cout<<"solve "<<x<<endl;
	int y,i,j;
	for(int tt=1;tt<=k;tt++){
		y=x%10;x/=10;
		for(i=1;i<y;i++){
			for(j=y;j<=9;j++) a[i][j]=0;
		}
	}
}
int main(){
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	scanf("%d%d",&n,&k);
	int i,j,x,maxn=0,tmp;
	for(i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]),maxn=max(maxn,max(l[i],r[i]));
	memset(a,1,sizeof(a));
	if(maxn<=6000&&n<=10){
		for(i=1;i<=n;i++) for(j=l[i];j<=r[i];j++) num[j]=1;
		for(j=1;j<=n;j++){
			for(i=l[j];i<=r[j];i++){
				for(x=1;x<=k;x++) check(i,x);
			}
		}
		for(i=1;i<=9;i++){
			if(!vis[i]){
				cout<<i;
				for(j=i+1;j<=9;j++) if(a[i][j]&&!vis[j]) vis[j]=1,cout<<j;
				cout<<endl;
			}
		}
	}
	else{
		if(n==1){
			int tip=1;
			for(i=1;i<=k;i++) tip*=10;
			solve(l[1]-(l[1]/tip)*tip);
			solve(r[1]-(r[1]/tip)*tip);
			for(i=1;i<=9;i++){
				if(!vis[i]){
					cout<<i;
					for(j=i+1;j<=9;j++) if(a[i][j]&&!vis[j]) vis[j]=1,cout<<j;
					cout<<endl;
				}
			}
		}
		else{
			if(k==1){
				for(i=1;i<=n;i++){
					check2(l[i]);
					check2(r[i]);
				}
				for(i=1;i<=9;i++){
					if(!vis[i]){
					cout<<i;
					for(j=i+1;j<=9;j++) if(a[i][j]&&!vis[j]) vis[j]=1,cout<<j;
					cout<<endl;
					}
				}
			}
			else puts("1\n2\n3\n4\n5\n6\n7\n8\n9");
		}
	}
} 
// 56789 56780 56700 56000 50000
// if k==3 then solve(56001,56789)
