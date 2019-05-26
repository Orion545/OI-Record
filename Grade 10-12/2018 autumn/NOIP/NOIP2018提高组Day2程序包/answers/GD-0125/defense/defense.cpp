#include<bits/stdc++.h>
using namespace std;

int n,m,tu,tv,a,x,b,y;
char typ[2];
int p[100001],zhujun[100001];
long long cost=0;
vector<int> bian[100001];

void cal(){
	if (typ[0]=='A'){
		if (typ[1]=='1'){
			cost+=p[1];
			if (y) {
				zhujun[b]=1;
				cost+=p[b];
			}
			int pos=2;
			while (pos<=n){
				if (!zhujun[pos]){
					if (p[pos]<p[pos+1]){
						zhujun[pos]=1;
						cost+=p[pos];
						pos+=2;
					}else{
						
					}
				}
			}
			
			return;
		}
		if (x) {
			cost+=p[a];
			zhujun[a]=1;
		}
		if (y) {
			cost+=p[b];
			zhujun[b]=1;
		}
		int pos=a;
		while (pos>1){
			if (!zhujun[pos]){
				zhujun[pos-1]=1;
				zhujun[pos+1]=1;
				cost+=p[pos-1]+p[pos+1];
				po
			}
		}
	}
}

bool xl(int xx,int yy){
	for (int i=0;i<bian[yy].size();i++){
		if (bian[yy][i]==xx)return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>typ;
	memset(p,127,sizeof(p));
	for (int i=1;i<=n;i++)cin>>p[i];
	for (int i=1;i<=n-1;i++){
		cin>>tu>>tv;
		bian[tu].push_back(tv);
		bian[tv].push_back(tu);
	}
	while(m--){
		cin>>a>>x>>b>>y;
		memset(zhujun,0,sizeof(zhujun));
		cost=0;
		if (typ[0]=='A'&&x==0&&y==0&&abs(x-y)==1){
			cout<<-1<<endl;
			continue;
		}
		if (xl(a,b)&&x==0&&y==0){
			cout<<-1<<endl;
			continue;
		}
		cal();
		cout<<cost<<endl;
	}
		
	return 0;
}
