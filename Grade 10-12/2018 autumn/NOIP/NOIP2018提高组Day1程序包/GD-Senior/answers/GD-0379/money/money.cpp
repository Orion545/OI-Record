#include <bits/stdc++.h>
#define N 110
#define M 25000
using namespace std;

int a[N],n,c[N],cnt=0,sz;
bool f[25005];

inline void read(int &x){
	int y=0;char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(!(c<'0' || c>'9')) y=y*10+c-'0',c=getchar();
	x=y;
}
inline bool check(int ll){
	if(ll==cnt) return 1;
	memset(f,0,sizeof(f));
	f[0]=1;
	int tot=0,i,j;
	for(i=1;i<=ll;++i){
		for(j=a[i];j<=a[cnt];++j) f[j]|=f[j-a[i]];
	}
	for(i=ll+1;i<=cnt;++i) if(f[a[i]]) tot++;
	return (tot==cnt-ll);
}

int main(){
	register int t,i,j;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	read(t);
	while(t--){
		memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
		cnt=0;
		read(n);
		for(i=1;i<=n;++i) read(c[i]);
		sort(c+1,c+n+1);
		sz=unique(c+1,c+n+1)-c-1;
		for(i=2;i<=sz;++i){
			for(j=1;j<i;++j){
				if(c[j]){
					if(c[i]%c[j]==0){
						c[i]=0;		
						break;
					}					
				}
			}
		}
		for(i=1;i<=sz;++i) if(c[i]) a[++cnt]=c[i];
		int l=1,r=cnt;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
}
