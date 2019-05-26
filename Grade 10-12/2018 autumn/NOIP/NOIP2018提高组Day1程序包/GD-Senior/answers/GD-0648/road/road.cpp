#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int readq(){
	int j=0,op=1;
	char c=getchar();
	while ((c<'0'||c>'9')&&c!='-') c=getchar();
	if (c=='-'){
		op=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9'){
		j=(j<<3)+(j<<1)+(c^48);
		c=getchar();
	}
	return op*j;
}
int n,last,ans,i;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=readq();
	while (n--){
		i=readq();
		if (i>last) ans+=i-last;
		last=i;
	}
	printf("%d",ans);
	return 0;
}
