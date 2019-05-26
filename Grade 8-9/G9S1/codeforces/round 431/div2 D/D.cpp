#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int n,w,h,g[100100],p[100100],t[100100]; 
vector<int>group[200100];
int main(){
	int i;
	scanf("%d%d%d",&n,&w,&h);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&g[i],&p[i],&t[i]);
		group[p[i]-t[i]+100000].push_back(i);
	}
}
