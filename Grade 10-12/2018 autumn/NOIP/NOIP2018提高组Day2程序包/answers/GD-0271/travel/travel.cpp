#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
int i,j,n,m,x,y,su=0,t,a[5001][100];
int v[5001],ans[5001];
stack<int> s;

int minn(int q){
	int y=a[q][1];
	for(j=2;j<=a[q][0];j++){
		y=min(y,a[q][j]);
	}
	return y;
}

void del(int p){
	int y=minn(p);
	for(j=1;j<=a[p][0];j++){
		if(y==a[p][j]){
			a[p][j]=a[p][a[p][0]];
			a[p][0]-=1;
		}
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n >> m;
	for(i=1;i<=m;i++){
		cin >> x >> y;
		a[x][++a[x][0]]=y;
		a[y][++a[y][0]]=x;
	}
	su=0;
	s.push(1);
	v[1]=1;
	su++;
	ans[su]=1;
	while(su<n){
		while(a[s.top()][0]==0){
			s.pop();
			
		}
		int o=s.top();
		while(v[minn(o)]!=0&&a[o][0]>0){
			del(o);
		}
		while(a[s.top()][0]==0){
			s.pop();
			int o=s.top();
			while(v[minn(o)]!=0&&a[o][0]>0){
				del(o);
			}
		}
		t=minn(s.top());
		s.push(t);
		v[t]++;
		su++;
		ans[su]=t;
	}
	for(i=1;i<=n;i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
