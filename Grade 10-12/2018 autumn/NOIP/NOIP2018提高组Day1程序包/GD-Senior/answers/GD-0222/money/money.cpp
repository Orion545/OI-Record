#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
int t,n,a[103],ans[23],ans1=0,js;



int pd(int be,int wz,int x){
	int i=be+2,j,k=0,u,v,w;
	u=a[be],v=a[be+1];
	if(i>wz){
		int kk,ks,kv,kvv;
		kk=x/u;
		ks=x%u;
		kv=v/u;
		kvv=v%u;
		if(ks==0) k=1;
		else if(kvv%ks==0&&kv*(kvv/ks)<=kk) k=1;
	}
	while(i<=wz){
		w=a[i];
		int kk,ks,kv,kvv;
		kk=x/u;
	ks=x%u;
	kv=v/u;
	kvv=v%u;
	if(ks==0) k=1;
	else if(kvv%ks==0&&kv*(kvv/ks)<=kk) k=1;
		u+=v;v=w;
		i++;
	}
	if(k==1) return 1;
	else return 0;
}

int main(){
	int i,j,k,st,w;
	ifstream fin;
	fin.open("money.in");
	fin>>t;
	for(int i1=1;i1<=t;i1++){
		fin>>n;
		for(i=1;i<=n;i++) fin>>a[i];
		sort(a+1,a+n+1);
		w=a[1];
		i=2;
		while((a[i]%a[1])==0&&i<=n) i++;
		if(i>n){
			ans1++;ans[ans1]=1;
		}
		else{
			js=2;
			a[i-1]=w;
			//cout<<a[i-1]<<a[i]<<endl;
			st=i-1;
			i++;int bb=i;
			for(bb=i;bb<=n;bb++){
				if(pd(st,bb-1,a[bb])==0) js++;
			}
			ans1++;ans[ans1]=js;
		}
	}
	fin.close();
	ofstream fout;
	fout.open("money.out");
	for(i=1;i<=ans1;i++) fout<<ans[i]<<endl;
	fout.close();
	return 0;
}
