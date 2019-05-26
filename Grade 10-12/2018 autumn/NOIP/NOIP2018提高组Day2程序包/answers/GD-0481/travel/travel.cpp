#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define REG register
#define REP(i,x,y) for(REG int i=x;i<=y;i++)
#define UP(i,x,y) for(REG int i=x;i>=y;i--)
#define ll long long
#define mm(x,y) memset(x,y,sizeof(x))
const int maxn=50005;
char buf[1<<14],*p1=buf,*p2=buf;
#define G getchar
int _(){
	int s=0,w=1;char ch=G();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=G();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=G();
	return s*w;
}

int n,m,tot,cnt;
int pt[maxn],xx[maxn],yy[maxn];
bool vis[maxn];
priority_queue<int> Q;
int temp;

void solve(){
	mm(vis,0);
	int tmp=1,bj=0; pt[++cnt]=1;
	REP(cs,1,maxn){
		REP(i,1,m){
			if(!vis[i]){
				if(xx[i]==tmp){
					if(Q.size())if(yy[i]<(-Q.top())){
						while(Q.size()) Q.pop();
						vis[bj]=0;
						bj=i;
					}
					Q.push(-yy[i]);
					vis[i]=1;
				}
				else if(yy[i]==tmp){
					if(Q.size())if(xx[i]<(-Q.top())){
						while(Q.size()) Q.pop();						
						vis[bj]=0;
						bj=i;
					}
					Q.push(-xx[i]);
					vis[i]=1;
				}
			}
		}
		if(Q.size()) pt[++cnt]=-Q.top(),Q.pop();
		tmp=pt[cnt];
		//while(Q.size()) Q.pop();
		//if(temp!=tmp) temp=tmp,printf("%d\n",temp);
		if(cnt==n) break;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	n=_(),m=_();
	REP(i,1,m){
		xx[i]=_(),yy[i]=_();
	}
	solve();
	REP(i,1,n) printf("%d ",pt[i]);
	puts("");
	
	fclose(stdin);fclose(stdout);
	return 0;
}
