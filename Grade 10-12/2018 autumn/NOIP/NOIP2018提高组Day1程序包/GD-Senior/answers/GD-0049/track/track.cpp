#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int N=50010;
int hea[N],nex[N<<1],ver[N<<1],edg[N<<1];
vector<int> ch[N];
int M,ans,pt=0;
char vi[N];

void put(int x,int y,int z){
	ver[++pt]=y;edg[pt]=z;
	nex[pt]=hea[x];hea[x]=pt;
}

int sr(int x){
	vi[x]=true;ch[x].clear();
	for(int i=hea[x];i;i=nex[i]){
		if(vi[ver[i]]==true)	continue;
		ch[x].push_back(sr(ver[i])+edg[i]);
	}
	sort(ch[x].begin(),ch[x].end());
	vector<int>::iterator l=ch[x].begin(),r=ch[x].end();
	while(l!=r&&*(r-1)>=M)	--r,++ans;
	if(l==r)	return 0;
	int mil=0;
	while(l<(r-1)){
		if(*l+*(r-1)>=M)	++l,--r,++ans;
		else mil=*l,++l;
	}
	if(l==r){
//		if((*(l-1)+*l)>=M)	return 0;
//		else	return
		return mil;
	}
	else return *(r-1);
}

void read(int &x){
	register char tmp=getchar();x=0;
	while(tmp<=32)	tmp=getchar();
	while(tmp>32)	x=(x<<1)+(x<<3)+tmp-'0',tmp=getchar();
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,a,b,l,ml=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;++i)	read(a),read(b),read(l),put(a,b,l),put(b,a,l),ml+=l;
	int le=1,ri=ml,fans=0;
	M=((le+ri)>>1)+((le+ri)&1);
	while(le<ri){
		memset(vi,0,sizeof(vi));
		ans=0;
		sr(1);
//		printf("%d %d %d %d\n",le,ri,M,ans);
		if(ans>=m)	le=M,fans=le;
		else	ri=M-1;
		M=((le+ri)>>1)+((le+ri)&1);
	}
	printf("%d\n",fans);
	return 0;
}
