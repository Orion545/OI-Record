#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int a[25007];
int t;

int cmp(int x,int y)
{
	return x<y;
}


int dfs()
{
	//int back=a[3];
	//int stk=0;
	for(int i=1;i<=(a[3]/a[2]);i++)     //大 
	{
		for(int j=1;j<=(a[3]/a[1]);j++)      //小 
		{
			//cout<<i*a[2]+j*a[1]<<"  1"<<endl;
			if((i*a[2]+j*a[1])==a[3]) return 1;
			//stk=i*a[2]+j*[2];
		}
	}
	return 0;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	int n,x;
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		if(n==2)
		{
			int p,q;
			scanf("%d%d",&p,&q);
			if(p%q==0||q%p==0)
			{
				printf("1\n");
			}else{
				printf("2\n");
			}
		}else if(n==3)
		{
			//int p,q,z;
			int sum=1;
			scanf("%d%d%d",&a[1],&a[2],&a[3]);
			sort(a+1,a+4,cmp);
			//cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
			if(a[2]%a[1]!=0)
			{
				sum++;
				int k=dfs();
				if(k!=1) sum++;
			}else if(a[3]%a[1]!=0) sum++;
			printf("%d\n",sum);
		}else if(n==4)
		{
			int num=n;
			int sum=1;
			scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
			sort(a+1,a+5,cmp);
			for(int i=1;i<4;i++)   //除数 
			{
				for(int j=1;j<=4;j++)  //被除数 
				{
					//cout<<"1"<<endl;
					if(j>i&&a[j]!=0&&a[i]!=0)
					{
						//cout<<a[j]<<" "<<a[i]<<endl;
						int mod=a[j]%a[i];
						//cout<<mod<<"   1 11"<<endl;
						/*if(mod==0)
						{
							a[j]=0;
							num--;
						}*/
					}
					
				}
			}
			if(num==3)
			{
				sort(a+1,a+5,cmp);
				if(a[2]%a[1]!=0)
				{
					sum++;
					int k=dfs();
					if(k!=1) sum++;
				}else if(a[3]%a[1]!=0) sum++;
				printf("%d\n",sum);
			}else if(num==1)
			{
				printf("1\n");
			}else if(num==2)
			{
				printf("2\n");
			}else if(num==4)
			{
				/*int jp=0
				for(int i=1;i<=2;i++)
				{
					for(int j=i+1;j<=3;j++)
					{
						jp=dfs_2(i,j);
						
					}
				}*/
				printf("1\n");
			}else{
				for(int i=1;i<=n;i++)
				{
					scanf("%d",a[i]);
				}
				printf("3\n");
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
