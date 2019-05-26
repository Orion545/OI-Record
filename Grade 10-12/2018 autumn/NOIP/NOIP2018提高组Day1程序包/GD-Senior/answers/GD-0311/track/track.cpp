#include <cstdio>
int map[50000][3];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,temp,sum=0;
	scanf("%d %d",&n,&m);
	for(int i=1; i<n; i++)
		scanf("%d %d %d",&map[i][0],&map[i][1],&map[i][2]);
	if(2*m<(n+1)/2)
	{
		for(int i=0; i<n-1; i++)
		for(int j=0; j<n-i-1; j++)
			if(map[j][2]<map[j+1][2])
			{ temp=map[j][2]; map[j][2]=map[j+1][2]; map[j+1][2]=temp; }
		temp=(n+1)/2-2*m;
	}
	for(int i=0; i<n-temp; i++) sum+=map[i][2];
		printf("%d",sum/(m+1));
	fclose(stdin);fclose(stdout);
	return 0;
}
