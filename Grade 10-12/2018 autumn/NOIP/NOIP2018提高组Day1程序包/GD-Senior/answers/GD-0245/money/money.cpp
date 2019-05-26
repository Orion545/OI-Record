#include<cstdio>
#include<cstring>

using namespace std;
int i,t,n,l,j,m,a[2000000],bz[30000],tree[2000000],num,max,x,num1;

void up(int x){
	while (tree[x]<tree[x/2]&&x!=1){
		tree[0]=tree[x];
		tree[x]=tree[x/2];
		tree[x/2]=tree[0];
		x/=2;
	}
}

void down(int x){
	int s;
	while ((tree[x*2]<tree[x]||tree[x*2+1]<tree[x])&&(x*2<=num)){
		s=x*2;
		if (tree[s+1]<tree[s]&&s+1<=num)
			s++;
		tree[0]=tree[s];
		tree[s]=tree[x];
		tree[x]=tree[0];
		x=s;	
	}
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for (l=1;l<=t;l++){
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(bz,0,sizeof(bz));
		max=0;
		num=0;
		for (i=1;i<=n;i++){
			num++;
			tree[num]=a[i];
			if (a[i]>max)
				max=a[i];
			bz[a[i]]=1;
			up(num);	
		}
		m=n;
		while (tree[1]<max){
			for (i=1;i<=num;i++)
				a[i]=tree[i];
			num1=num;
			if (tree[1]*3<=max){
				if (bz[tree[1]*3]){
					bz[tree[1]*3]=0;
					m--;	
				}
				else{
					num++;
					tree[num]=tree[1]*3;
					up(num);	
				}
			}
			for (i=1;i<=num1;i++){
				x=tree[1]+a[i];
				if (x>max)
					continue;
				if (bz[x]){
					bz[x]=0;
					m--;
				} 
				else{
					num++;
					tree[num]=x;
					up(num);	
				}
			}
			tree[0]=tree[1];
			tree[1]=tree[num];
			tree[num]=tree[0];
			num--;
			down(1);
		}
		printf("%d\n",m);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
