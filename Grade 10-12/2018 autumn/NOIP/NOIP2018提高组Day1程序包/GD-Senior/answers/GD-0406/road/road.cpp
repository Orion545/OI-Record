#include <iostream>
#include <cstdio>
#include <cstring>

inline int nxi(){
	int x=0;
	char c;
	while((c=getchar())>'9'||c<'0');
	while(x=x*10-48+c,(c=getchar())>='0'&&c<='9');
	return x;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int lst=0,ans=0,n=nxi();
	for(int i=1;i<=n;++i){
		int tp=nxi();
		if(tp<lst) ans+=lst-tp;
		lst=tp;
	}
	printf("%d\n",ans+lst);
	return 0;
}
