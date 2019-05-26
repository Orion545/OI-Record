#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,cnt=0;
int h[5010];
string s;
struct way{
	int to,nex;
}w[5010];
void add(int a,int b){
	w[++cnt].to=b;
	w[cnt].nex=h[a];
	h[a]=cnt;
}
int build(int k,int fa){
	int a[n],an=0;
	printf("%d ",k);
	for(int i=h[k];i!=-1;i=w[i].nex){
		int y=w[i].to;
		if(y!=fa){
			an++;
			a[an]=y;
		}
	}
	sort(a+1,a+1+an);
	for(int i=1;i<=an;i++){
		build(a[i],k);
	}
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(h,-1,sizeof(h));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	if(m=n-1){
		build(1,0);
	}
	if(m==n){
		
	}
	fclose(stdin);
	fclose(stdout);
}
