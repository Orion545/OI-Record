#include <cmath>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
//Constant
const int N=50000;
const int E=(N-1)*2;
//Quick Read
int Read(){
	int x=0;
	bool neg=false;
	char c=getchar();
	while(isdigit(c)==false)neg^=c=='-',c=getchar();
	while(isdigit(c)==true)x=x*10+c-'0',c=getchar();
	return x;
}
void Read(int &x){x=Read();}
//Edge Directory
struct Edge_Directory{
	int len,head[N+1],to[E+1],dis[E+1],next[E+1];
	inline void Insert(int x,int y,int d){to[++len]=y,dis[len]=d,next[len]=head[x],head[x]=len;}
}ed;
//Tree DP
int aim,f[N+1],g[N+1];
void Tree_DP(int x,int fa){
	f[x]=g[x]=0;
	int max1=0,max2=0;
	for(int e=ed.head[x];e!=0;e=ed.next[e]){
		int y=ed.to[e];
		if(y==fa)continue;
		Tree_DP(y,x),f[x]+=f[y];
		int now=g[y]+ed.dis[e];
		if(now>max1)max2=max1,max1=now;
		else if(now>max2)max2=now;
	}
	if(max2>=aim)f[x]+=2;
	else if(max1>=aim)++f[x],g[x]=max2;
	else if(max1+max2>=aim)++f[x];
	else g[x]=max1;
}
//Count1
int temp1[N+1];
int Count1(int n){
	int l=2,r=n,ans=0;
	while(l<r){
		if(temp1[r]>=aim)++ans,--r;
		else{
			while(l<r){
				if(temp1[r]+temp1[l]>=aim){
					++ans,++l,--r;
					break;
				}
				++l;
			}
		}
	}
	return ans;
}
//Main
int deg[N+1];
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n=Read(),m=Read(),sum=0;
	bool task1=true,task3=true;
	for(int i=1;i<n;++i){
		int x=Read(),y=Read(),d=Read();
		temp1[y]=d;if(x!=1)task1=false;
		++deg[x];if(deg[x]>3)task3=false;
		++deg[y];if(deg[y]>3)task3=false;
		ed.Insert(x,y,d),ed.Insert(y,x,d);
		sum+=d;
	}
	if(task3==true){
		int l=1,r=sum,ans;
		while(l<=r){
			aim=l+r>>1,Tree_DP(1,0);
			if(f[1]<m)r=aim-1;
			else l=aim+1,ans=aim;
		}
		printf("%d\n",ans);
		return 0;
	}
	if(task1==true){
		std::sort(temp1+2,temp1+1+n);
		int l=1,r=sum,ans;
		while(l<=r){
			aim=l+r>>1;
			if(Count1(n)<m)r=aim-1;
			else l=aim+1,ans=aim;
		}
		printf("%d\n",ans);
		return 0;
	}
	int l=1,r=sum,ans;
	while(l<=r){
		aim=l+r>>1,Tree_DP(1,0);
		if(f[1]<m)r=aim-1;
		else l=aim+1,ans=aim;
	}
	printf("%d\n",ans);
	return 0;
}
