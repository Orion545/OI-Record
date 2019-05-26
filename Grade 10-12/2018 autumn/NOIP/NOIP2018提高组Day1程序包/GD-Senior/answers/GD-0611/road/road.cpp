#include<cstring>
#include<cstdio>

using namespace std;

int n,sta[100100],ans=0,top=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);sta[0]=0;
	for(int i=1;i<=n;++i){
		int x;scanf("%d",&x);
		if(top&&x<sta[top]){
			while(top&&sta[top]>x)--sta[top];
		}else ans+=x-sta[top];sta[++top]=x;
	}printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}

