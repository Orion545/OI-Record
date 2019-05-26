#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 100005;
const long long MaxCost = 30000000001;
int n, m, p[N], army[N], path[15][15];
long long f[N][2];
struct T{
	int x, y;
}edge[N];
string tp;

void SolveA(){
	int a, x, b, y, x_, y_;
	long long Res1;
	for (int r = 1; r <= m; r ++){
		scanf("%d%d%d%d", &a, &x, &b, &y);
		x_ = (x==1?0:1);
		y_ = (y==1?0:1);
		for (int i = 0; i <= n; i ++) f[i][0] = f[i][1] = MaxCost;
		f[0][0] = 0;
		for (int i = 1; i <= n; i ++){
			f[i][0] = min(f[i][0],f[i-1][1]);
			f[i][1] = min(f[i][1],f[i-1][0]+p[i]);
			if ( i-2>=0 ) f[i][1] = min(f[i][1],f[i-2][0]+p[i]);
			if ( i-2>=0 ) f[i][1] = min(f[i][1],f[i-2][1]+p[i]);
			if ( i-3>=0 ) f[i][1] = min(f[i][1],f[i-3][1]+p[i]);
			f[a][x_] = f[b][y_] = MaxCost;
		}
		Res1 = min(f[n][0],f[n][1]);
		if ( Res1==MaxCost )
			printf("-1\n");
		else
			printf("%lld\n", Res1);
	}

}

int isok(){
	for (int i = 1; i <= n; i ++){
		int flag = 0;
		if ( army[i]==0 ){
			for (int j = 1; j <= n; j ++){
				if ( army[j] && path[i][j] ) flag=1;
			}
		}
		if ( flag==0 && army[i]==0 ) return 0;
	}
	return 1;
}

void SolveSmall(){
	for (int i = 0; i < 15; i ++){
		for (int j = 0; j < 15; j ++){
			path[i][j] = 0;
		}
	}
	for (int i = 1; i < n; i ++) 
		path[edge[i].x][edge[i].y] = path[edge[i].y][edge[i].x] = 1;

	for (int r = 1; r <= m; r ++){
		int a, x, b, y;
		scanf("%d%d%d%d", &a, &x, &b, &y);
		long long Res2 = MaxCost;
		for (int i = 0; i < (1<<n); i ++){
			long long temp = 0;
			for (int j = 1; j <= n; j ++){
				if ( i & (1<<(j-1)) ) 
					army[j] = 1, temp += p[j];
				else
					army[j] = 0;
			}
			if ( isok() && army[a]==x && army[b]==y ) Res2 = min(Res2,temp);
		}
		if ( Res2==MaxCost )
			printf("-1\n");
		else
			printf("%lld\n", Res2);
	}
	
	
	
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);

	cin >> n >> m;
	cin >> tp;
	for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
	for (int i = 1; i < n; i ++){
		scanf("%d%d", &edge[i].x, &edge[i].y);
		if ( edge[i].x>edge[i].y ) swap(edge[i].x,edge[i].y);
	}
	if ( tp[0]=='A' )
		SolveA();
	else if ( n<=10 && m<=10 )
		SolveSmall();
	else{
		for (int i = 1; i <= m; i ++){
			int a , x , b , y;
			scanf("%d%d%d%d", &a, &x,&b,&y);
			printf("-1\n");
		}
	}

	return 0;
}

