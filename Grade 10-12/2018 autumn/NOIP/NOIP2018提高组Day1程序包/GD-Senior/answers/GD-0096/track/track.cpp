#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct node{
	int x,y,c,next;
}a[210000];int len,last[110000];
struct hehe{
	int d,id;
}b[210000];int g[210000];
void ins(int x,int y,int c){
	a[++len].x=x;a[len].y=y;a[len].c=c;
	a[len].next=last[x];last[x]=len;
}
int cmp(const void *xx,const void *yy){
	hehe n1=*(hehe *)xx;
	hehe n2=*(hehe *)yy;
	return n1.d-n2.d;
}
int cmp2(const void *xx,const void *yy){
	int n1=*(int *)xx;
	int n2=*(int *)yy;
	return n1-n2;
}
bool bk[210000];
int fa[210000],dis[210000];
void dfs(int x){
	bk[x]=false;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(bk[y]) fa[y]=x,dis[y]=dis[x]+a[k].c,dfs(y);
	}
}
int mymin(int x,int y) {return x<y?x:y;}
int mymax(int x,int y) {return x>y?x:y;}
int sum4,sum5=0;int hh[210000],h[210000];
void dfs3(int x){
	bk[x]=false;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(bk[y]) sum5++,hh[k]=sum5;
	}
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(bk[y]) fa[y]=x,dfs3(y);
	}
}
bool bk2[210000];
int dfs2(int x,int mid){
	int max1=0,max2=0,minn=hh[last[x]],maxx=-1;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(fa[y]==x){
			int t=dfs2(y,mid)+a[k].c;
			h[hh[k]]=t;
			maxx=hh[k];
		}
	}
	if(maxx!=-1){
		qsort(h+minn,maxx-minn+1,sizeof(int),cmp2);
		for(int i=maxx;i>=minn;i--) bk2[i]=true;
		int anss=0,id=1;
		for(int i=maxx;i>=minn;i--){
			if(h[i]>=mid) sum4++;
			else if(i>1&&h[i]+h[i-1]>=mid) sum4++;
			else {anss=h[i];break;}
		}
		return anss;
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,sum=0;scanf("%d%d",&n,&m);
	len=0;memset(last,0,sizeof(last));
	bool pd2=true,pd3=true;
	for(int i=1;i<=n-1;i++){
		int x,y,c;scanf("%d%d%d",&x,&y,&c);
		ins(x,y,c);ins(y,x,c);sum+=c;
		if(x!=1) pd2=false;
		if(y!=x+1) pd3=false;
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) bk[j]=true,dis[j]=0;
			dfs(i);
			for(int j=1;j<=n;j++) ans=mymax(ans,dis[j]);
		}
		printf("%d\n",ans);
		return 0;
	}
	if(pd2){
		int len2=0;
		for(int i=1;i<=len;i++){
			if(a[i].x==1) b[++len2].id=a[i].y,b[len2].d=a[i].c;
		}
		qsort(b+1,n-1,sizeof(hehe),cmp);
		if(m<=(n-1)/2){
			int ans=999999999;
			for(int i=n-1;i>=n-2*m;i--)
				ans=mymin(ans,b[i].d+b[2*n-2*m-1-i].d);
			printf("%d\n",ans);
		}
		else{
			int t=2*m-n+1,ans=999999999;
			for(int i=n-1;i>=n-t;i--)
				ans=mymin(ans,b[i].d);
			for(int i=1;i<n-t;i++)
				ans=mymin(ans,b[i].d+b[n-t-i].d);
			printf("%d\n",ans);
		}
		return 0;
	}
	if(pd3){
		int l=1,r=sum,ans;
		for(int i=1;i<=len;i++) if(a[i].x==a[i].y+1) g[a[i].x]=a[i].c;
		while(l<=r){
			int mid=(l+r)/2;
			int sum1=0,sum2=0;
			for(int i=1;i<=n-1;i++){
				sum1+=g[i];
				if(sum1>=mid) sum1=0,sum2++;
			}
			if(sum2>=m) ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
		return 0;
	}
	memset(bk,true,sizeof(bk));dfs3(1);
	int l=1,r=sum,ans;
	while(l<=r){
		int mid=(l+r)/2;
		sum4=0;int t=dfs2(1,mid);
		if(sum4>=m) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
