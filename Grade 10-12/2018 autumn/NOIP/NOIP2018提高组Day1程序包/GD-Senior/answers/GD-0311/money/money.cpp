#include <cstdio>
int money[101],n,count;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T,temp;
	scanf("%d",&T);
	for(int k=0; k<T; k++)
	{
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		scanf("%d",&money[i]);
		count=n;
		for(int i=0; i<n-1; i++)
		for(int j=0; j<n-i-1; j++)
			if(money[j]<money[j+1])
			{ temp=money[j]; money[j]=money[j+1]; money[j+1]=temp; }
		for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
		{
			temp=money[i];
			for(int h=j; h<n; h++)
				temp=temp%money[h];
			if(temp==0) { count--; break; }
		}
		printf("%d",count);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
