#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,i,j;
	int a,b;
	
	char type;

	cin>>n>>m>>type;
	
	const int N = n, M= m;
	
	int p[N+1]; //p是城市价格，下标为城市序号 
	int x[2][N+1];//该数组用于存放城市军队状态（第0维度是城市序号，第1维度是城市军队数量） 
	int tu[2][N+1]; //城市布局
	int fee[M]; //输出 
	

	for(i = 0; i < n; i++) //输入费用 
		cin >> p[i];
		
	for(j = 0; j < n;j ++) //输入tu 
		cin>>tu[0][j]>>tu[1][j];
		
	for(j = 0; j < m; j++) //国王要求 
	{
    	i = b = a = j = 0;
    	cin >> i >> b >> j >> a ;
    	if(b) x[i][1]++;
    	if(a) x[j][1]++;
    	n = 0;
    	while(n < N)
    	{
    		if(n == 0) 
			{
				fee[j] = x[0][0] * p[0];
				n = 2;
			}else 
			{
				if(n <= N-1 && !x[1][n] && !x[1][n-1] && !x[1][n+1])
				{
					if(p[n] < p[n+1] && p[n] < p[n-1])
					{
						x[1][n] = 1;
						fee[j] += p[n];
					}else 
					{
						if(p[n+1] < p[n-1])
						{
							x[1][n+1] = 1;
							fee[j] += p[n+1];
						}else
						{
							x[1][n-1] = 1;
							fee[j] += p[n-1];
						}
					}
					n += 3; 
				}else
				{
					fee[j] += x[1][n] * p[n] + x[1][n+1] * p[n] + x[1][n-1] * p[n+1];
					n += 3;
				}
			}
    	}
	}
	for(n=0;n<m;n++) cout<<fee[n]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
