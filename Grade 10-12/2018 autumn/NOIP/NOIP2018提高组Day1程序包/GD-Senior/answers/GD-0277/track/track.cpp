#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define max(a,b)(a>b?a:b)
#define link(x,y,z)(ne[++js]=la[x],la[x]=js,to[js]=y,le[js]=z)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
#define ll long long
using namespace std;
const int N=1e5+5;
int n,m,la[N],to[N],ne[N],le[N],d[N],js,x,y,z,fa[N];
int Q,an,zs,len[N],ma[N],tt,li[N];
bool bz[N];
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,2,n)scanf("%d%d%d",&x,&y,&z),link(x,y,z),link(y,x,z),zs+=z;
	for(Q=1;Q<zs;Q<<=1);
	d[1]=1;
	for(int t=0,w=1;x=d[t+1],t++<w;)
		ff(i,x)if(fa[x]!=(y=to[i]))fa[y]=x,d[++w]=y;
	for(;Q;Q>>=1){
		an+=Q;
		tt=0;
		fd(i,1,n){
			x=d[i];zs=0;
			ff(j,x)if((y=to[j])!=fa[x])len[++zs]=ma[y]+le[j];
			sort(len+1,len+zs+1);
			fo(j,1,zs)bz[j]=0,li[j]=0;
			int j=1;
			fd(l,1,zs){
				if(len[l]>=an){
					tt++;bz[l]=1;continue;
				}
				for(;j<l&&len[j]+len[l]<an;)j++;
				if(j<l&&len[j]+len[l]>=an){
					li[j]=l,tt++,bz[j]=bz[l]=1,j++;
				}
				if(j>=l)break;
			}
			fd(l,1,zs)if(li[l]){
				for(j=li[l];j-1>l&&!bz[j-1]&&len[j-1]+len[l]>=an;)j--;
				bz[li[l]]=0;bz[j]=1;
			}
			ma[x]=0;
			fd(l,1,zs)if(!bz[l]){ma[x]=len[l];break;}
		}
		if(tt<m)an-=Q;
	}
	printf("%d",an);
	fclose(stdin);fclose(stdout);return 0;
}
