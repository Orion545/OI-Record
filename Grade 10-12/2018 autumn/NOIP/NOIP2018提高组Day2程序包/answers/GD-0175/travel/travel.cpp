#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define qread(x) x=read()
#define mes(x,y) memset(x,y,sizeof(x))
#define mpy(x,y) memcpy(x,y,sizeof(x))
#define Maxn 5000
#define INF 2147483647
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
struct Edge{
	int x,y,next;
}a[2*Maxn+1];int len,first[Maxn+1];
void ins(int x,int y){
	len++;
	a[len].x=x;a[len].y=y;
	a[len].next=first[x];first[x]=len; 
}
int ans[Maxn+1];
bool v[Maxn+1];
void no_circle(int x){
	std::priority_queue<int,std::vector<int>,std::greater<int> >q;
	ans[++ans[0]]=x;
	for(int k=first[x];k>0;k=a[k].next){
		int y=a[k].y;
		if(v[y]==false){
			v[y]=true;
			q.push(y);
		}
	}
	while(q.empty()==false){
		int y=q.top();q.pop();
		no_circle(y);
	}
}
int id,cnt,sum,dfn[Maxn+1],low[Maxn+1],belong[Maxn+1];
std::stack<int>s;
void find_circle(int x,int fa){
	dfn[x]=low[x]=++id;v[x]=true;
	s.push(x);
	for(int k=first[x];k>0;k=a[k].next){
		int y=a[k].y;
		if(dfn[y]==0&&y!=fa){
			find_circle(y,x);
			low[x]=std::min(low[x],low[y]);
		}
		else if(v[y]==true&&y!=fa)low[x]=std::min(dfn[x],low[y]);
	}
	if(dfn[x]==low[x]){
		cnt++;
		int i,tmp=0;
		do{
			i=s.top();s.pop();
			belong[i]=cnt;
			tmp++;	
		}while(i!=x);
		if(tmp>1)sum=cnt;
	}
}
void circle(int x,int c,int next){
	std::priority_queue<int,std::vector<int>,std::greater<int> >q;
	ans[++ans[0]]=x;v[x]=true;
	int p[2];mes(p,0);
	for(int k=first[x];k>0;k=a[k].next){
		int y=a[k].y;
		if(v[y]==false){
			if(belong[y]==sum){
				if(p[0]==0)p[0]=y;
				else{
					p[1]=y;
					if(p[0]>p[1])std::swap(p[0],p[1]);	
				}
			}
			q.push(y);
		}
	}
	while(q.empty()==false){
		int y=q.top();q.pop();
		if(v[y]==false){
			if(q.empty()==true&&belong[y]==sum&&c<y)break;
			else if(q.empty()==true&&c==y&&next<c)break;
			else if(p[1]!=0&&y==p[0])circle(y,p[1],(q.empty()==false?q.top():INF));
			else circle(y,c,(q.empty()==false?q.top():INF));
		}
	}
}
int n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	qread(n),qread(m);
	len=0;mes(first,0);
	for(int i=1;i<=m;i++){
		int qread(x),qread(y);
		ins(x,y);
		ins(y,x);
	}
	mes(ans,0);	
	if(n==m-1){
		v[1]=true;mes(v,false);
		no_circle(1);
	}
	else{
		id=cnt=0;
		mes(dfn,0);mes(low,0);
		for(int i=1;i<=n;i++){
			if(dfn[i]==0){
				mes(v,false);
				find_circle(i,i);
			}
		}
		mes(v,false);
		v[1]=true;circle(1,INF,INF);
	}
	for(int i=1;i<n;i++)printf("%d ",ans[i]);printf("%d\n",ans[n]);
}
/*
-------
InPut1
-------
6 5
1 3
2 3
2 5
3 4
4 6
-------
OutPut1
-------
1 3 2 5 4 6
-------
InPut2
-------
6 6
1 3
2 3
2 5
3 4
4 5
4 6
-------
OutPut2
-------
1 3 2 4 5 6
*/
