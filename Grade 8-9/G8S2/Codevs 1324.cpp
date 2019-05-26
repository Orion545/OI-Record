#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 0x7fffffff
using namespace std;
struct data{
	int to,level,next,price;
	data(){
		level=1;next=-1;
	}
}edge[100110];
int n,l,cl,m=0;
int first[110];
int pt[110];
int ans[110];
bool in[110]={0};

void spfa(){
	int link[100010],head=0,tail=1;
	link[1]=1;in[1]=0;
	while(head<tail){
		head++;int k=first[link[head]];in[link[head]]=0;
		cout<<"doing node "<<link[head];
		while(k!=-1){
			int t=edge[edge[k].to].price;
			if(t<=ans[edge[k].to]&&edge[edge[k].to].level>=cl-l){
//				?????????????????
				ans[edge[k].to]=ans[edge[edge[k].to].to]+t;
//				?????????????????
				if(!in[edge[k].to]){
					tail++;link[tail]=edge[k].to;
				}
			}
			k=edge[k].next;
		} 
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	cin>>l>>n;
	int pp,ll,xx,mm,nn,tt=-1,ttt;
	first[1]=1;
	for(int i=1;i<=n;i++){
		ans[i]=inf;
		cin>>pp>>ll>>xx;ttt=-1;pt[i+1]=ll;
		edge[++m].to=i+1;edge[m].next=tt;
		edge[m].price=pp;tt=m;
		for(int j=1;j<=xx;j++){
			cin>>mm>>nn;first[i+1]=++m;
			edge[m].to=mm+1;edge[m].next=ttt;
			edge[m].price=nn;ttt=m;
		}
	}
	for(int i=1;i<=m;i++) edge[m].level=pt[edge[m].to];
	cl=edge[1].level;
	cout<<"begin"<<endl;
	spfa();
	cout<<"end"<<endl;
	int minn=inf;
	for(int i=1;i<=n;i++){
		minn=min(minn,ans[i]);
	}
	cout<<minn;
}
