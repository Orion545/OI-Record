#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<ctime>
#include<cstdlib>
using namespace std;
char ch;
#define ll long long
#define MM 100010
#define N 120
#define mo 1000000007

ll xxx;ll fff;
inline ll readll(){
	xxx=0;fff=1;ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')fff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xxx=(xxx<<1)+(xxx<<3)+ch-'0';
		ch=getchar();
	}
	return xxx*fff;
}
int xx;int ff;
inline int read(){
	xx=0;ff=1;ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xx=(xx<<1)+(xx<<3)+ch-'0';
		ch=getchar();
	}
	return xx*ff;
}
int n;int a[N];bool f[MM];int ans=0;bool has[N];
map <int,int > b;
queue <int> q;
int maxn;
inline void bfs(int x){
	while(!q.empty())q.pop();
	q.push(x);
	int y;
	while(!q.empty()){
		y=q.front();q.pop();
		if(f[y])continue;
		f[y]=1;
		for(int i=1;i<=n;++i){
			if(has[i]&&(y+a[i]<=maxn))q.push(y+a[i]);
		}
	}
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=0;
	scanf("%d",&T);
while(T--){
	maxn=0;
	scanf("%d",&n);ans=0;
	bool anss=0;
	b.clear();
	for(int i=1;i<=n;++i){
		a[i]=read();
		maxn=max(maxn,a[i]);
		b[a[i]]=i;
		if(a[i]==1){anss=1;break;}
	}
	if(anss==1){
		printf("%d\n",1);
		continue;
	}
	//sort(a+1,a+1+n);
	memset(f,0,sizeof(f));
	memset(has,0,sizeof(has));
	f[0]=1;//int p=1;
	for(int i=1;i<=maxn;++i){
		if((!f[i])&&(b[i])){
			//cerr<<"i="<<a[p]<<endl;
			++ans;has[b[i]]=1;
			//while(f[a[p]])++p;
			//for(int j=i+a[k];j<MM;j+=a[k]){f[j]=1;}
			bfs(i);
		}
	}
	printf("%d\n",ans);
}
	fclose(stdin);fclose(stdout);
	return 0;
}

