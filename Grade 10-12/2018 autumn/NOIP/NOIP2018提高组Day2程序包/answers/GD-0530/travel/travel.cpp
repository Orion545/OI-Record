#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n,i,j,point,x;  //z用来与MIN比较 
	
	cin>>m>>n;
	
	const int z = m,y = n;
	
	int a[2][z],b[z],MIN=n+1; //b数组用来储存最小字典序 

	for(j = 0; j < z; j ++)
		cin >> a[0][j] >> a[1][j];
		
	for(point = 1, j = 1; j <m ; j++)
	{
		if(a[0][j] == a[0][j-1]) point++;
		if(point==1) i = j - 1;
	}
	x = 0;
	while(x < point) //将这个连续数段内的城市 
	{
		for(j = 0; j < point; j++ )
		{
			if(MIN > a[1][j])
			{
				MIN = a[1][j];
				a[1][j] = y+1;
			}
		}
		b[x] = MIN;
		x++;
	}
	
	for(j = 0; j < m; j++)
	{
		if(j = 0 && a[0][j] != a[0][j+1])
		{
			
		}
		if(a[0][j]==a[0][j-1])
		{
			
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
