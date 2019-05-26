#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
} 
int n;
int pri[5000010],cnt,vis[5000010],minn[5000010];bool isp[5000010];
void init(){
    int i,j;isp[1]=1;minn[1]=1;
    for(i=2;i<=5000000;i++){
        if(!isp[i]) pri[++cnt]=i,minn[i]=i;
        for(j=1;j<=cnt&&i*pri[j]<=5000000;j++){
            isp[i*pri[j]]=1;minn[i*pri[j]]=pri[j];
            if(i%pri[j]==0) break; 
        }
    }
}
bool check(int x){
	while(x>1){
		if(vis[minn[x]]) return 0;
		x/=minn[x];
	}
	return 1;
}
int main(){
	n=read();init();
	int i,t1,tmp;
	for(i=1;i<=n;i++){
		t1=read();tmp=t1;
		while(t1>1){
			if(vis[minn[t1]]) goto jump;
			t1/=minn[t1];
		}
		t1=tmp;printf("%d ",t1);
		while(t1>1){
			vis[minn[t1]]=1;t1/=minn[t1];
		}
	}
//	cout<<"finish\n";
	return 0;
	jump:
	while(++tmp){
		if(check(tmp)){
			printf("%d",tmp);
			while(tmp>1){
				vis[minn[tmp]]=1;tmp/=minn[tmp];
			} 
			break;
		}
	}
	i++;int j=1;
	while(i<=n){
		t1=read();
		while(vis[pri[j]]) j++;
		vis[pri[j]]=1;
		printf(" %d",pri[j]);i++;
	}
}
