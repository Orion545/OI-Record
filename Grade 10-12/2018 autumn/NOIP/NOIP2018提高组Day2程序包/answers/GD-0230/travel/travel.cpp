#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
inline int read(){
	int p=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')t=-t;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		p=p*10+ch-48;
		ch=getchar();
	}
	return p*t;
}
struct line{
	int u,v;
	bool operator<(const line i)const{
		if(i.u==u)return v<i.v;
		return u>i.u;
	}
};
int n,m,fa[5005],vst[5005],point;
int found=0,p1,p2;
vector<int>son[5005],ti[5005];
vector<line>huan;
void dfs(int num,int dad){
	fa[num]=dad;
	for(int i=0;i<ti[num].size();i++){
		int p=ti[num][i];
		if(n==m&&((num==p1&&p==p2)||(num==p2&&p==p1)))continue;
		if(p==1||fa[p])continue;
		son[num].push_back(p);
		dfs(p,num);
	}
}
void dfs2(int num){
	printf("%d ",num);
	for(int i=0;i<son[num].size();i++){
		dfs2(son[num][i]);
	}
}
void solve1(){
	dfs(1,0);
	for(int i=1;i<=n;i++){
		sort(son[i].begin(),son[i].end());
	}
	dfs2(1);
}
void search(int num,int dad){
//	printf("%d %d\n",num,dad);
	if(found)return ;
	if(vst[num]){
		point=num;
		found=1;
		return;
	}
	vst[num]=1;
	for(int i=0;i<ti[num].size();i++){
		int p=ti[num][i];
		if(p==dad)continue;
		search(p,num);
		if(found==1){
			huan.push_back((line){num,p});
			huan.push_back((line){p,num});
			if(point==num)found=2;
			return ;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();
	m=read();
	for(int i=0;i<m;i++){
		int x,y;
		x=read();y=read();
		ti[x].push_back(y);
		ti[y].push_back(x);
	}
	if(n==m){
		search(1,0);
	//	printf("%d",huan.size());
		sort(huan.begin(),huan.end());
	//	for(int i=0;i<huan.size();i++)printf("%d %d\n",huan[i].u,huan[i].v);
		p1=huan[0].u,p2=huan[0].v;
	}
	solve1();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
