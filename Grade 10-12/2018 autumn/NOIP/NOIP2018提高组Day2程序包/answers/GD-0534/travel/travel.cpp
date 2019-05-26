#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<int>pth[5001];
int ptn[5001];
bool use[5001];

int stk[5001],stn=0;

void cp(int k){
	while(1){
		int min=0x7fffffff;
		for(int z=0;z<pth[k].size();z++){
			int p=pth[k][z];
			if(!use[p]&&p<min)
				min=p;
		}
		if(ptn[k]||min==0x7fffffff){
			for(int z=0;z<stn;z++){
				int p=stk[z];
				if(((!use[p]&&ptn[p])||min==0x7fffffff)&&p<min)
					return;
			}
		}
		if(min==0x7fffffff)
			return;
			
		printf(" %d",min);
		use[min]=1;
		
		int stn1=stn;
		for(int z=0;z<pth[k].size();z++){
			int p=pth[k][z];
			if(!use[p])
				stk[stn++]=p;
		}
		
		cp(min);
		
		stn=stn1;
	}
}				


void cr(int m){
	queue<int>q;
	for(int z=1;z<=m;z++)
		if(ptn[z]==1)
			q.push(z);
	while(!q.empty()){
		int z=q.front();
		use[z]=1;
		q.pop();
		if(ptn[z]==1){
			ptn[z]=0;
			for(int x=0;x<pth[z].size();x++){
				int c=pth[z][x];
				if(!use[c]){ 
					ptn[c]--;
					if(ptn[c]==1)
						q.push(c);
				}
			}
		}
	}
	memset(use,0,sizeof use);
}
			
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int n,m;scanf("%d%d",&n,&m);
	for(int z=1,u,v;z<=m;z++){
		scanf("%d%d",&u,&v);
		pth[u].push_back(v);
		pth[v].push_back(u);
		ptn[u]++;
		ptn[v]++;
	}
	
	cr(m);
	
	printf("1");
	use[1]=1;
	cp(1);
	
	return 0;
}
