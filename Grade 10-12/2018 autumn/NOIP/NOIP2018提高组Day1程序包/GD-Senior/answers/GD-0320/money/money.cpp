#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
inline int read(){
	int f = 1,x = 0;
	char c = getchar();
	while(c > '9' || c < '0'){if(c == '-')f = -1;c = getchar();}
	while(c <= '9' && c >= '0'){x = x*10 + c-'0';c = getchar();}
	return x*f;
}
const int MAXN = 110;
int n,T,a[MAXN],ans;
vector<int> co;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T = read();
	while(T--){
		co.clear();
		ans = 0;
		n = read();
		for(int i = 0;i < n;i++)
			a[i] = read();	
		if(n==1) ans = 1;
		else if(n==2){
			int x = a[0],y = a[1];
			if(x%y && y%x) ans = 2;
			else ans = 1;
		}
		else{
			sort(a,a+n);
			co.push_back(a[0]);
			for(int i = 1;i < n;i++){
				int flag = 1;
				for(int j = 0;j < co.size();j++){
					int y = co[j],x = a[i];//¼ÓÈë 
					while(x > 0){
						for(int k = 0;k < co.size();k++){
							int z = co[k];
							if(x%z == 0){
								flag = 0;
								break;	
							}
						}
						if(!flag) break;
						x-=y;
					}
					if(!flag) break;	
				}
				if(flag)co.push_back(a[i]);
			}	
			ans = co.size();
		}
	printf("%d\n",ans);
	}
	return 0;
}
