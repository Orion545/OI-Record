#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 100005;

int n;
int d[N];
int nxt[N],pre[N];
LL ans;
int num[N];

bool cmp(int x,int y){return d[x]>d[y];}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=get();
	fo(i,1,n)d[i]=get();
	fo(i,1,n-1)nxt[i]=i+1;
	fo(i,2,n)pre[i]=i-1;
	ans=0;
	fo(i,1,n)num[i]=i;
	sort(num+1,num+1+n,cmp);
	fo(i,1,n-1){
		int x=num[i];
		int y=pre[x];
		if (nxt[x]&&(!y||d[nxt[x]]>d[y]))y=nxt[x];
		ans=ans+d[x]-d[y];
		if(y==pre[x]){
			nxt[y]=nxt[x];
			if (nxt[y])pre[nxt[y]]=y;
		}
		else{
			pre[y]=pre[x];
			if (pre[y])nxt[pre[y]]=y;
		}
	}
	ans=ans+d[num[n]];
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
