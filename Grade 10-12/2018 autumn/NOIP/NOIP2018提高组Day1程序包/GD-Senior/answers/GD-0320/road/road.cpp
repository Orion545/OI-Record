#include<cstdio>
using namespace std;
inline long long read(){
	long long f = 1,x = 0;
	char c = getchar();
	while(c > '9' || c < '0'){if(c == '-')f = -1;c = getchar();}
	while(c <= '9' && c >= '0'){x = x*10 + c-'0';c = getchar();}
	return x*f;
}
const int MAXN = 100015;

long long n,ans;
struct Road{
	int pos,dpth;
}road[MAXN];
Road findmin(int l,int r){
	int temp = 1e9;
	int p;
	for(int i = l;i <= r;i++){
		if(road[i].dpth<temp){
			temp = road[i].dpth;
			p = road[i].pos;
		}	
	}
	return road[p];	
}
void work(int l,int r,int c){
	Road x = findmin(l,r);
	ans += (x.dpth-c);
	c += (x.dpth-c);
	int p = x.pos;
	if(p > l) work(l,p-1,c);
	if(p < r) work(p+1,r,c);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i++){
		road[i].dpth = read();
		road[i].pos = i;
	}
	work(1,n,0);
	printf("%lld",ans);	
	return 0;
}
