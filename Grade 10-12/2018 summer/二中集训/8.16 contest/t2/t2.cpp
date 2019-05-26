#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
struct BIT{
	int a[100010];
	void init(){
		memset(a,0,sizeof(a));
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int x,int val){
		for(;x<=n;x+=lowbit(x)) a[x]+=val;
	}
	int sum(int x){
		int re=0;
		for(;x>0;x-=lowbit(x)) re+=a[x];
		return re;
	}
}T;
int a[100010][3],rev0,rev1,anti0,anti1;
//rev: 自转的次数
//anti: 逆序对 
int main(){
	n=read();int i,tmp;
	for(i=1;i<=n;i++) a[i][0]=read();
	for(i=1;i<=n;i++) a[i][1]=read();
	for(i=1;i<=n;i++) a[i][2]=read();
	for(i=1;i<=n;i++){
		if((a[i][0]%3==0&&a[i][1]==a[i][0]-1&&a[i][2]==a[i][1]-1)||(a[i][2]%3==0&&a[i][0]==a[i][1]-1&&a[i][1]==a[i][2]-1)) continue;
		puts("No");return 0;
	}
//	cout<<"pass availability test\n";
	T.init();
	for(i=1;i<=n;i+=2){
		if(a[i][0]%3==0) rev1++,tmp=a[i][0]/3;
		else tmp=a[i][2]/3;
		if((tmp&1)==0){
			puts("No");return 0;
		}
		anti1+=((i+1)>>1)-T.sum(tmp-1)-1;
		T.add(tmp,1);
	}
	T.init();
	for(i=2;i<=n;i+=2){
		if(a[i][0]%3==0) rev0++,tmp=a[i][0]/3;
		else tmp=a[i][2]/3;
		if((tmp&1)==1){
			puts("No");return 0;
		}
		anti0+=(i>>1)-T.sum(tmp-1)-1;
		T.add(tmp,1);
	}
//	cout<<anti0<<' '<<rev0<<' '<<anti1<<' '<<rev1<<'\n';
	if((rev1&1)==(anti0&1)&&(rev0&1)==(anti1&1)) puts("Yes");
	else puts("No");
} 
