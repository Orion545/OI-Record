#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=2300055;
int l[N],fa[N],ch[N][3],last=1,cnt=1,n,m,q[500055],head,tail;
int dp[N],len[N];
char s[N];
 
void ins(int c)
{
	int p=last,np=++cnt;last=np;l[np]=l[p]+1;
	for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if(!p) fa[np]=1;
	else
	{
		int q=ch[p][c];if(l[p]+1==l[q]) fa[np]=q;
		else
		{
			int nq=++cnt;l[nq]=l[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q];fa[q]=fa[np]=nq;
			for(;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
		}
	}
}
 
void getlen()
{
	int now=1,ll=0;
	for(int i=1;i<=n;i++)
	{
		int to=s[i]-'0';
		if(ch[now][to]) now=ch[now][to],ll++;
		else
		{
			while(now&&!ch[now][to]) now=fa[now];
			if(!now) ll=0,now=1;
			else
			{
				ll=l[now]+1;now=ch[now][to];
			}
		}
		len[i]=ll;
	}
}
int check(int li)
{
	dp[0]=q[0]=0;
	head=1;tail=0;
	cout<<"check "<<li<<'\n';
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(i-li<0) continue;
		while(head<=tail&&dp[q[tail]]-q[tail]<dp[i-li]+li-i) tail--;
		q[++tail]=i-li;
		while(head<=tail&&q[head]<i-len[i]) head++;
		if(head<=tail) dp[i]=max(dp[i],dp[q[head]]-q[head]+i);
		cout<<"	"<<i<<' '<<dp[i]<<'\n';
	}
	cout<<"finish check "<<dp[n]<<' '<<n<<'\n';
	return dp[n]*10>=9*n;
}
 
int ef()
{
	getlen();
	int l=0,r=n,mid,ans=0;
	while(r>=l)
	{
		mid=l+r>>1;
		if(check(mid)) 
		{
			ans=mid;l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);int llen=strlen(s+1);
		for(int j=1;j<=llen;j++) ins(s[j]-'0');
		ins(2); 
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s+1);n=strlen(s+1);
		printf("%d\n",ef());
	}
	return 0;
}
