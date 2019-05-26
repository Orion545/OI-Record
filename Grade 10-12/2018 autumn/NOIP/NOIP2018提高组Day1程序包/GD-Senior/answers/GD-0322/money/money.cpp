#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=105,maxm=25005;
vector<int> v;
int a[maxn],f[maxm];
int n,T;
inline void read(int &x){
	int w=0,X=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')w^=ch=='-',ch=getchar();
	while(ch<='9'&&ch>='0')X=(((X<<2)+X)<<1)+(ch^48),ch=getchar();
	x=w?-X:X;
	return;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
inline void writeln(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
	puts("");
	return;
}
int ss(int last,int tar){
	if(tar%v[last]==0){
		f[tar]=1;
		return 1;
	}
	else if(last<=0)return 0;
	int tmp=tar/v[last];
	for(int i=0;i<=tmp;++i){
		if(v[last]*i>tar)continue;
		if(f[tar-i*v[last]]==1){
			return 1;
		}
		if(ss(last-1,tar-i*v[last])){
			f[tar-i*v[last]]=1;
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		v.clear();
		for(int i=1;i<=n;i++){
			read(a[i]);
		}
		sort(a+1,a+n+1);
		if(a[1]==1){
			writeln(1);
			return 0;
		}
		v.push_back(a[1]);
		for(int i=2;i<=n;i++){
			if(!ss(v.size()-1,a[i]))v.push_back(a[i]),f[a[i]]=1;
		}
		writeln(v.size());
	}
	return 0;
}
