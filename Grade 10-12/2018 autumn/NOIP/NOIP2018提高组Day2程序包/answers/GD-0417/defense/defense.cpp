#include<cstdio>
using namespace std;
int n, m, i, j, k, l, temp1, temp2, temp3, temp4;
char what[5];
long long ans = 0;
int pay[2010],temppay[2010],min[2010], way[2010][2010], judge[2010];
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d ", &n, &m);
	scanf("%s", what);
	for(i = 1; i <= n; i++){
		scanf("%d", &pay[i]);
		temppay[i] = pay[i];
	}
	for(i = 1; i < n; i++){
		scanf("%d%d", &temp1, &temp2);
		way[temp1][temp2] = 1;
		way[temp2][temp1] = 1;
	}
	for(i = 1; i <= n; i++){
		temp1 = 123456;
		temp2 = 0;
		for(j = 1; j <= n; j++){
			if(temppay[i] < temp1){
				temp1 = pay[i];
				temp2 = j;
				temppay[i] = 123456;
			}
		}
		min[i] = temp2;
	}
	for(i = 1; i <= m; i++){
		ans = 0;
		scanf("%d%d%d%d", &temp1, &temp2,&temp3, &temp4);
		for(j = 1; j <= n; j++){
			judge[j] = 0;
		}
		for(j = 1; j <= n; j++){
			if(min[j] == temp1){
				if(temp2 == 0)continue;
				if(temp2 == 1){
					ans += pay[min[i]];
					judge[min[i]] = 1;
					for(k = 1; k <= n; k++){
						if(way[k][min[i]] == 1){
							if(k == temp3){
								if(temp4 == 1)judge[k] = 1;
							}
							else
								judge[k] = 1;
						}
					}
				}
			}
			if(min[j] == temp3){
				if(temp4 == 0)continue;
				if(temp4 == 1){
					ans += pay[min[i]];
					judge[min[i]] = 1;
					for(k = 1; k <= n; k++){
						if(way[k][min[i]] == 1){
							if(k == temp1){
								if(temp2 == 1)judge[k] = 1;
							}
							else
								judge[k] = 1;
						}
					}
				}
			}
			if(judge[min[j]] == 0){
				judge[min[j]] = 1;
				ans += pay[min[j]];
				for(k = 1; k <= n; k++){
					if(way[min[j]][k] == 1){
						judge[k] = 1;
						if(k == temp1)
							if(temp2 == 0)
								judge[k] = 0;
						if(k == temp3)
							if(temp4 == 0)
								judge[k] = 0;
					}
				}
			}
		}
		int flat = 0;
		for(j = 1; j <= n; j++){
			if(judge[j] == 0){
				flat = 1;
				break;
			}
		}
		if(flat == 1)printf("-1\n");
		else{
			printf("%lld\n",ans);
		}
	}
	return 0;
}   
