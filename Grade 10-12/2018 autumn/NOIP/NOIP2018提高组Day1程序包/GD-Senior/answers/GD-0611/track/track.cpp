#include<cstring>
#include<cstdio>
#define N 50010
#define fo(i,a,b) for(int i=a,_E_=b;i<=_E_;++i)

using namespace std;

int m,n,fir[N],nex[N+N],to[N+N],v[N+N],ans,top,mn,a[N],b[N],use[N];
#define link(x,y,c) to[++top]=y,v[top]=c,nex[top]=fir[x],fir[x]=top
void swap(int &a,int &b){int t=a;a=b;b=t;}
void sort(int h,int t){
	int v=b[h+t>>1],l=h,r=t;
	while(l<=r){
		while(l<=r&&b[l]<v)++l;while(l<=r&&b[r]>v)--r;
		if(l<=r)swap(b[l],b[r]),++l,--r;
	}
	if(h<r)sort(h,r);if(l<t)sort(l,t);
}
int dg(int x,int fa){
	int top=0;
	for(int i=fir[x];i;i=nex[i])if(to[i]!=fa)a[to[i]]=dg(to[i],x)+v[i];
	for(int i=fir[x];i;i=nex[i])if(to[i]!=fa)b[++top]=a[to[i]];
	if(!top)return 0;
	sort(1,top);
	while(top&&b[top]>=mn)--top,++ans;
	int r1=0,r2=0,i,j,res=0;
	for(i=1,j=top;i<j;++i,--j){
		while(i<j&&b[i]+b[j]<mn)++i;
		if(i<j)++r1;
	}
	for(i=1,j=top-1;i<j;++i,--j){
		while(i<j&&b[i]+b[j]<mn)++i;
		if(i<j)++r2;
	}
	if(r1==r2){
		ans+=r1;return b[top];
	}
	fo(i,1,top)use[i]=0;
	ans+=r1;
	for(i=1,j=top;i<j;++i,--j){
		while(i<j&&b[i]+b[j]<mn)res=b[i++];
		if(i<j)use[i]=use[j]=1;
	}
	for(int i=top;i;i--)if(!use[i])return b[i];
	return 0;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	top=0;
	fo(i,2,n){
		int x,y,c;scanf("%d %d %d",&x,&y,&c);
		link(x,y,c);link(y,x,c);
	}
	int h=1,t=5e8,res=0;
	while(h<=t){
		mn=h+t>>1;ans=0;
		dg(1,0);if(ans<m)t=mn-1;else h=mn+1,res=mn;
	}
	printf("%d",res);
	fclose(stdin);fclose(stdout);
	return 0;
}
