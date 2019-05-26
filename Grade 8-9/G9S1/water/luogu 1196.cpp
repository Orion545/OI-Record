#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[30010],d[30010],n;
int find(int k){
	return ((f[k]==k)?k:(f[k]=find(f[k])));
}
void join(int x,int y){
	f[x]=y;d[y]+=d[x];
}
int main(){
	std::ios::sync_with_stdio(false);
	int i,t1,t2,f1,f2;char ch;
	cin>>n;
	for(i=1;i<=30000;i++) f[i]=i,d[i]=1;
	for(i=1;i<=n;i++){
		cin>>ch>>t1>>t2;
		if(ch=='C'){
			f1=find(t1);f2=find(t2);
			if(f1!=f2) printf("-1\n");
			else printf("%d\n",abs(d[t1]-d[t2]-1)); 
		}
		else{
			f1=find(t1);f2=find(t2);
			join(f1,f2);
		}
	}
}
