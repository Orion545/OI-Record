#include <cmath>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
//Constant
const int N=5000;
const int E=(N-1)*2;
//Quick Read
int Read(){
	int x=0;
	bool neg=false;
	char c=getchar();
	while(isdigit(c)==false)neg^=c=='-',c=getchar();
	while(isdigit(c)==true)x=x*10+c-'0',c=getchar();
	return neg==true?-x:x;
}
inline void Read(int &x){x=Read();}
//Edge Directory
struct Edge_Directory{
	int len,head[N+1],to[E+1],next[E+1];
	inline void Insert(int x,int y){to[++len]=y,next[len]=head[x],head[x]=len;}
}ed;
////Find Circle
//int pre[N+1],tot,circle[N+1];
//bool visit[N+1],incircle[N+1];
//void Find(int x){
//	visit[x]=true;
//	for(int e=ed.head[x];e!=0;e=ed.next[e]){
//		int y=ed.to[e];
//		if(y==pre[x])continue;
//		if(visit[y]==true){
//			while(y!=0)circle[++tot]=y,incircle[y]=true,y=pre[y];
//			int pos=tot;
//			while(incircle[x]==false)circle[++tot]=x,incircle[x]=true,x=pre[x];
//			std::reverse(circle+pos+1,circle+1+tot);
//			for(int i=1;i<=tot;++i)
//				if(circle[i]==x){
//					int k=pos-i;
//					for(int j=i+1;j<=pos;++j)incircle[circle[j]]=false;
//					for(int j=pos+1;j<=tot;++j)circle[j-k]=circle[j];
//					tot-=k;
//					break;
//				}
//			return;
//		}
//		pre[y]=x,Find(y);
//		if(tot!=0)return;
//	}
//}
//DFS
int temp[N+1][N+1];
void DFS(int x,int fa){
	printf("%d ",x);
	int tot=0;
	for(int e=ed.head[x];e!=0;e=ed.next[e])
		if(ed.to[e]!=fa/*&&incircle[ed.to[e]]==false*/)temp[x][++tot]=ed.to[e];
	std::sort(temp[x]+1,temp[x]+1+tot);
	for(int i=1;i<=tot;++i)DFS(temp[x][i],x);
}
////Build
//int father[N+1],min[N+1];
//void Build(int x){
//	for(int e=ed.head[x];e!=0;e=ed.next[e]){
//		int y=ed.to[e];
//		if(y==father[x]||incircle[y]==true)continue;
//		father[y]=x,Build(y);
//		if(min[x]==0)min[x]=y;
//		else min[x]=std::min(min[x],y);
//	}
//}
////Solve
//int pre[N+1];
//bool into[N+1];
//inline int Next(int x){return x==tot?1:x+1;}
//inline int Last(int x){return x==1?tot:x-1;}
//void Solve(int p){
//	if(pre[p]!=0&&)
//}
//Main
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n=Read(),m=Read();
	for(int i=1;i<=m;++i){
		int x=Read(),y=Read();
		ed.Insert(x,y),ed.Insert(y,x);
	}
	if(m==n-1)DFS(1,0);
//	else{
//		Find(1);
//		for(int i=1;i<=n;++i)Build(circle[i]);
//		if(incircle[1]==false){
//			DFS(1,father[1]);
//			while(father[x]!=0)printf("%d ",x),x=father[x];
//			printf("%d ",x);
//			for(int i=1;i<=tot;++i)
//				if(circle[i]==x){
//					pre[i]=n+1,into[i]=true,Solve(i);
//					break;
//				}
//		}
//		else for(int i=1;i<=tot;++i)
//			if(circle[i]==1){
//				Solve(i);
//				break;
//			}
//		DFS(1,father[1]);
//		int x=father[1];
//		while(father[x]!=0)printf("%d ",x),x=father[x];
//		printf("%d ",x);
//		if(tot==1)return 0;
//		int p,sum=1;
//		for(int i=1;i<=tot;++i)
//			if(circle[i]==x){
//				p=i;
//				break;
//			}
//		int p1=Last(p),p2=Next(p);
//		if(circle[p1]<circle[p2]){
//			while(circle[p1]<circle[p2]&&sum<tot)
//			DFS(circle[p1],0),++sum,p1=Last(p1);
//			while(sum<tot)
//			DFS(circle[p2],0),++sum,p2=Next(p2);
//		}
//		else{
//			while(circle[p2]<circle[p1]&&sum<tot)DFS(circle[p2],0),++sum,p2=Next(p2);
//			while(sum<tot)DFS(circle[p1],0),++sum,p1=Last(p1);
//		}
//	}
	return 0;
}

