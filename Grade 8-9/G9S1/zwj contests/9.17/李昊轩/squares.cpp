#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct node{
	int x,y;
}a[50010];
int n,k,i,j,ans=0,tmp;
bool cmp(node l,node r){
	return l.x<r.x;
}
int read(){
	char c=getchar();int re=0,flag=1;
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-'){
		flag=-1;c=getchar();
	}
	while(c>='0'&&c<='9') re=re*10+int(c-48),c=getchar();
	return re*flag;
}
int main(){
	freopen("squares.in","r",stdin);
	freopen("squares.out","w",stdout);
	n=read();k=read();
//	cin>>n>>k;
//	cout<<n<<ends<<k;
	for(i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
	sort(a+1,a+n+1,cmp);
//	for(i=1;i<=n;i++) cout<<a[i].x<<ends<<a[i].y<<endl;
	for(i=1;i<=n;i++){
		for(j=i+1;a[j].x<a[i].x+k&&j<=n;j++){
			if(a[j].y<a[i].y+k&&a[j].x<a[i].x+k){
//				cout<<i<<ends<<j<<endl;
				if(ans==1){
					printf("-1");return 0;
				}
				else{
					ans++;tmp=(k-abs(a[i].x-a[j].x))*(k-abs(a[i].y-a[j].y));
				}
			}
//			else if(a[j].x==a[i].x+k&&a[j].y<a[i].y+k){
//				cout<<i<<ends<<j<<endl;
//				if(ans==1){
//					printf("-1");return 0;
//				}
//				else{
//					ans++;tmp=ans;
//				}
//			}
		}
	}
	if(ans) printf("%d",tmp);
	else printf("0");
}
