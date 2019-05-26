#include <iostream>
#include <cstdio>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;

const int N=105;
int n,t,a[N],del[N];
int flag=0;

int dfs(int val,int pos,int rpos,int up);
int cmp(int a,int b) {return a<b;}
inline int read();

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	while(t--) {
		//init
		for (int i=1;i<=100;i++) a[i]=del[i]=0;
		
		n=read(); int minus=0;
		for (int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1,cmp);
		for (int i=2;i<=n;i++) { //
			for (int j=1;j<i;j++) {
				//cout<<a[i]<<' '<<a[j]<<' '<<(a[i]%a[j])<<endl;
				if (a[i]%a[j]==0) {
					minus++;
					del[i]=1;
				}
			}
		}
		//cout<<a[1]<<endl;
		//cout<<minus<<endl;
		for (int i=n;i>=1;i--) {
			if (del[i]==0) {
				flag=0;
				dfs(0,1,i,a[i]);
				//if (i==6) cout<<flag<<endl;
				//cout<<flag<<endl;
				if (flag) {
					del[i]=1;
					minus++;
				}
			}
		}
		//cout<<minus<<endl;
		cout<<n<<endl;
	}
	fclose(stdin); fclose(stdout);
	return 0;
}

int dfs(int val,int pos,int rpos,int up)
{
	if (flag) return 0;
	if (pos>=rpos) return 0;
	if (val==up) {
		flag=1;
		return 0;
	}
	int now=pos;
	if (flag) return 0;
	if (del[now]==1) {
		dfs(val,pos+1,rpos,up);
		return 0;
	}
	int cot=-1;
	val-=a[now];
	while(cot*a[now]<=up) {
		if (flag) return 0;
		cot++;
		val+=a[now];
		//cout<<val<<endl;
		dfs(val,now+1,rpos,up);
	}
	return 0;
}

inline int read()
{
	int ret=0,neg=0; char ch=getchar();
	while((ch<'0' || ch>'9') && ch!='-') ch=getchar();
	if (ch=='-') {neg=1;ch=getchar();}
	while(ch>='0' && ch<='9') {
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	if (neg) return -ret;
	return ret;
}

