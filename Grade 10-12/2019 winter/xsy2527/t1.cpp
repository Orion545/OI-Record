#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,x[10010],y[10010],c[10010],cnt,a[10010];
int main(){
	n=read();int i,t1,t2,t3,t4,t5,t6,len;
	while(n--){
		t6=read();
		if(t6==1){
			cnt++;
			x[cnt]=read();y[cnt]=read();c[cnt]=read();
//			cout<<"read in "<<x[cnt]<<' '<<y[cnt]<<' '<<c[cnt]<<'\n';
		}
		else{
			t1=read();t2=read();t3=read();t4=read();t5=read();
			len=0;
			for(i=1;i<=cnt;i++){
				if(x[i]>=t1&&x[i]<=t3&&y[i]>=t2&&y[i]<=t4) a[++len]=-c[i];
			}
//			cout<<"query "<<len<<'\n';
			nth_element(a+1,a+t5,a+len+1);
			printf("%d\n",-a[t5]);
		}
	}
}
