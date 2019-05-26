#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int in[200],mi[30000],n,mxn=0;

void sr(){
	for(int i=1;i<=mxn;++i){
		if(mi[i]){
			for(int j=1;j<=n&&in[j]!=mi[i]&&in[j]+i<=mxn;++j)
			mi[i+in[j]]=in[j];
			mi[i+mi[i]]=mi[i];
		}
	}
}

void read(int &x){
	register char tmp=getchar();x=0;
	while(tmp<=32)	tmp=getchar();
	while(tmp>32)	x=(x<<1)+(x<<3)+tmp-'0',tmp=getchar();
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(mi,0,sizeof(mi));
		n=0,mxn=0;
		scanf("%d",&n);
//		for(int i=1;i<=n;++i)	scanf("%d",in+i);
		for(int i=1;i<=n;++i)	read(in[i]);
		sort(in+1,in+n+1);
		for(int i=1;i<=n;++i){
			mi[in[i]]=in[i];mxn=mxn>in[i]?mxn:in[i];
		}
		sr();
		int ans=0;
		for(int i=1;i<=n;++i)
			if(mi[in[i]]==in[i])	++ans;
		printf("%d\n",ans);
	}
	return 0;
}
