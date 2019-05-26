#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=50010;

inline int read()//非负
{
	int re=0;char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9') re=re*10+(ch^48),ch=getchar();
	return re;
}

int n,m;
struct E{int y,c,next;}e[MAXN*2];int len=1,last[MAXN];
void ins(int x,int y,int c)
{
	e[++len]=(E){y,c,last[x]};last[x]=len;
}

int cnt,mid;
vector<int> ve[MAXN];
int dp(int x,int fa)
{
	ve[x].clear();
	for(int k=last[x];k;k=e[k].next)
	{
		int y=e[k].y;
		if(y==fa) continue;
		int tmp=dp(y,x)+e[k].c;//debug +e[k].c
		if(tmp>=mid) cnt++;
		else ve[x].push_back(tmp);
	}
	
	int re=0;
	sort(ve[x].begin(),ve[x].end());
	/*int sz=ve[x].size();
	int rp=sz-1,ri=ve[x][sz-1];
	int lp=lower_bound(ve[x].begin(),ve[x].begin()+rp,mid-ri)-ve[x].begin();///??
	if(lp<rp)
	{
		cnt++;
		if(lp>0) re=ve[x][lp-1];
	}
	else return ri;*/
	int lp=0,rp=ve[x].size()-1;
	for(;lp<rp;rp--,lp++)//千万不要成真！！！！！ //debug [lp,rp]之间的数都是未选过的 
	{
		int nlp=lower_bound(ve[x].begin()+lp,ve[x].begin()+rp,mid-ve[x][rp])-ve[x].begin();//在[lp,rp)中找一个位置 
		if(lp<nlp) re=ve[x][nlp-1];lp=nlp;////debug lp也可以被选 nlp是马上选 
		if(lp<rp) cnt++;
		else return ve[x][rp];
	}
	if(lp<=rp) return ve[x][rp];
	else return re;
}

bool check()
{
	cnt=0;
	dp(1,0);
//	if(mid>=20000) printf("%d %d))\n",mid,cnt);
	return cnt>=m;
}

int main()
{
//	freopen("track3.in","r",stdin);
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	int sum=0;
	n=read(),m=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read(),c=read();
		ins(x,y,c);ins(y,x,c);sum+=c;
	}
	
//	mid=26282;
//	if(check()) return 1;
	
	int l=1,r=sum/m,ans=-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check()) ans=mid,l=mid+1;
		else r=mid-1;
//		printf("%d\n",ans);//
	}
	printf("%d\n",ans);
	return 0;
}
/*
5 1
1 2 8
1 3 8
1 4 8
1 5 7

5 3
2 1 8
3 2 4
3 5 1
5 4 2

5 3
1 2 6
1 3 4
1 4 8
1 5 3

*/
