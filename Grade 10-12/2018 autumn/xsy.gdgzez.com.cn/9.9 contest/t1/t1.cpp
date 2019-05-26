#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n;
//f:original sequence:1 2 2 3 3 4 4 4 5 5 5 6 6 6 6......
//g:the last occurance of specific element:[1] [3 5] [8 11] [15 19 23] [......
//p:the last position of the portion of sequence
//q:the real value of the starting element
ll p[15000010],q[15000010];
int main(){
	n=read();ll i,j,top,lim;
	if(n==1){puts("1");return 0;}
	if(n==2||n==3){puts("2");return 0;}
	if(n==4||n==5){puts("3");return 0;}
	p[2]=5;q[2]=2;p[3]=11;q[3]=4;top=3;
	for(i=3;p[top]<n;i++){
		lim=(p[i]-p[i-1])/i;
//		cout<<i<<' '<<p[i]<<' '<<q[i]<<' '<<p[i-1]<<' '<<q[i-1]<<' '<<lim<<'\n';
		for(j=1;j<=lim;j++){
			p[top+1]=p[top]+i*(q[i]+j-1);
			q[top+1]=p[i-1]+1+(j-1)*i;
			top++;
			if(p[top]>=n) break;
		}
	}
	ll cur=q[top]+(n-p[top-1]-1)/top;
	printf("%lld\n",cur);
}
