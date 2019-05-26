#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
#define rep(a,b,c) for (int a=b;a<=c;a++)
#define per(a,b,c) for (int a=b;a>=c;a--)
const int N=1010;
int n,mx,ans,hav[N],ori_hav[N],a[N];
void table_add(int x){
	if (hav[x]) return;
	rep(i,0,mx) if (hav[i]){
		rep(j,1,mx){
			if (i+j*x>mx) break;
			hav[i+j*x]=1;
		}
	}
}
void work(){
	scanf("%d",&n);
	mx=ans=0;
	memset(hav,0,sizeof(hav));
	rep(i,1,n){
		scanf("%d",a+i);
		mx=max(mx,a[i]);
	}
	hav[0]=1;
	rep(num,1,n) table_add(a[num]);
	memcpy(ori_hav,hav,sizeof(hav));
	memset(hav,0,sizeof(hav));
	hav[0]=1;
	rep(i,1,mx){
		if (!ori_hav[i]) continue;
		if (hav[i]) continue;
		++ans;
		table_add(i);
	}
	printf("%d\n",ans);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int tc;
	scanf("%d",&tc);
	while (tc--) work();
	return 0;
}

