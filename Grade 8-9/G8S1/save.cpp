//save.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define inf 0x7fffffff
using namespace std;
const int dx[9]={0,-1,-1,-1,0,1,1,1,0};
const int dy[9]={0,-1,0,1,1,1,0,-1,-1};
int m,n;
int x1,x2,y1,y2;
int in[501][501]={0};
struct node{
	int next,v;//v==value
};
vector<node>a[25001];
int ans[25001],way[25001]={0};
struct que{
	int pt;
};
int link[2500001];
bool vis[25001]={0};
void em(){}
void spfa(){
	int head=0,tail=1;
	ans[(x1-1)*m+y1]=0;
	link[1]=(x1-1)*m+y1;vis[link[1]]=1;way[link[1]]=1;
	while(head<tail){
		head++;
		//for(int i=head;i<=tail;i++){
		//	cout<<link[i]<<ends;
		//}
		//cout<<endl;
		//cout<<"in "<<link[head]<<endl;
		for(int i=0;i<a[link[head]].size();i++){
			int tn=a[link[head]][i].next,tv=a[link[head]][i].v;
			if((ans[link[head]]+tv<ans[tn])||(ans[link[head]]+tv==ans[tn]&&!way[tn])){
				//cout<<"into(1) "<<tn<<ends<<tv<<endl;
				ans[tn]=ans[link[head]]+tv;
				way[tn]=way[link[head]]+1;
				if(vis[tn]) goto ed1;
				//cout<<"new node"<<endl;
				tail++;
				link[tail]=tn;vis[tn]=1;
			}
			if(ans[link[head]]+tv==ans[tn]&&way[tn]>way[link[head]]+1){
				//cout<<"into(2) "<<tn<<ends<<tv<<endl;
				ans[tn]=tv;
				way[tn]=way[link[head]]+1;
				if(vis[tn]) goto ed1;
				//cout<<"new node"<<endl;
				tail++;
				link[tail]=tn;vis[tn]=1;
			}
			ed1:em();
		}
		vis[link[head]]=0;
		//for(int i=1;i<=21;i++) cout<<ans[i]<<ends;cout<<endl;
	}
}
int main(){
	for(int i=0;i<=25000;i++) ans[i]=inf;
	cin>>n>>m;
	cin>>x1>>y1>>x2>>y2;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			in[i][j+1]=s[j]-'0';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int tx,ty;
			for(int k=1;k<=8;k++){
				tx=i+dx[k];ty=j+dy[k];
				if(in[tx][ty]){
					node tmp;
					tmp.next=(tx-1)*m+ty;
					tmp.v=((in[tx][ty]==in[i][j])?0:1);
					a[(i-1)*m+j].push_back(tmp);
				}
			}
		}
	}
	spfa();
	cout<<way[(x2-1)*m+y2]<<" "<<ans[(x2-1)*m+y2];
} 
/*
3 7
1 1
3 7
2100212
2121010
2221012
*/
