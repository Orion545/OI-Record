#include<map>
#include<set>
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
#define Maxn 50000
#define INF 2147483647
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
struct Edge{
	int x,y,c,next;
}a[2*Maxn+1];int len,first[Maxn+1];
void ins(int x,int y,int c){
	len++;
	a[len].x=x;a[len].y=y;a[len].c=c;
	a[len].next=first[x];first[x]=len;	
}
int ret,mid,f[Maxn+1];
std::set<int>::iterator it;
void check(int x,int fa){
	std::set<int>s;
	std::map<int,int>v;
	for(int k=first[x];k>0;k=a[k].next){
		int y=a[k].y;
		if(y!=fa){
			check(y,x);
			int sum=f[y]+a[k].c;
			s.insert(sum);
			v[sum]++;
		}
	}
	int max=0;
	while(1){
		if(s.begin()==s.end()){
			f[x]=max;
			break;
		}
		else{
			int min=*s.begin();
			if(--v[min]==0)s.erase(min);
			if(min>=mid)ret++;
			else{
				it=s.lower_bound(mid-min);
				if(it!=s.end()){
					if(*it>=mid){
						ret++;
						if(--v[*it]==0)s.erase(*it);
						max=std::max(max,min);
					}
					else if(*it+min>=mid){
						ret++;
						if(--v[*it]==0)s.erase(*it);
					}
					else max=std::max(max,min);
				}
				else max=std::max(max,min);
			}
		}
	}
}
int n,m,l,r,ans;
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	qread(n),qread(m);
	len=0;mes(first,0);
	r=0;
	for(int i=1;i<n;i++){
		int qread(x),qread(y),qread(c);
		ins(x,y,c);
		ins(y,x,c);
		r+=c;	
	}
	l=1;r/=m;
	while(l<=r){
		mid=(l+r)/2;
		mes(f,0);
		ret=0;check(1,0);
		if(ret>=m){
			ans=mid;
			l=mid+1;	
		}
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
/*
-------
InPut1
-------
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
-------
OutPut1
-------
31
-------
InPut1
-------
9 3
1 2 6
2 3 3
3 4 5
4 5 10
6 2 4
7 2 9
8 4 7
9 4 4
-------
OutPut1
-------
15
*/
