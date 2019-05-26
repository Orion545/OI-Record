#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
using namespace std;
const int N=1e4+5;
int n,m,bs,x,y,st[N],en[N],d[N],ds,z[N],zs;
int an[N];
struct no{
	int x,y;
}b[N];
bool bz[N],bb[N];
bool cmp(no x,no y){return x.x<y.x||x.x==y.x&&x.y<y.y;}
bool go(int x,int ff){
	d[++ds]=x;bb[x]=1;
	fo(i,st[x],en[x])if(b[i].y!=ff){
		if(bb[b[i].y]){
			for(;d[ds+1]!=b[i].y;)z[++zs]=d[ds--];
			return 1;
		}
		if(go(b[i].y,x))return 1;
	}
	ds--;bb[x]=0;
	return 0;
}
void get(int x,int ff){
	d[++ds]=x;
	fo(i,st[x],en[x])if(b[i].y!=ff&&(!bz[b[i].x]||!bz[b[i].y]))get(b[i].y,x);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m)scanf("%d%d",&x,&y),b[++bs]=(no){x,y},b[++bs]=(no){y,x};
	sort(b+1,b+bs+1,cmp);
	fo(i,1,bs){
		x=b[i].x;y=b[i].y;
		if(!st[x])st[x]=i;
		en[x]=i;
	}
	if(n==m){
		fo(i,1,n)an[i]=n+1;
		go(1,0);
		fo(i,1,zs){
			bz[z[i]]=1;bz[z[i%zs+1]]=1;
			ds=0;get(1,0);
			bool ck=0;
			fo(j,1,n)if(d[j]<an[j]){
				ck=1;break;
			}else 
			if(d[j]>an[j]){
				ck=0;break;
			}
			if(ck)
				fo(i,1,n)an[i]=d[i];
			bz[z[i]]=0;bz[z[i%zs+1]]=0;
		}
	}else{
		ds=0,get(1,0);
		fo(i,1,n)an[i]=d[i];
	}
	fo(i,1,n)printf("%d ",an[i]);
	fclose(stdin);fclose(stdout);return 0;
}
