#include<cstdio>
long long n,dep[100005],zl=0,minn=99999999,l,r,ans;

void findlst(){
	long long dcl=1,dcr=0,dcminn=99999999;
	for(register int i=1;i<=n;i++){
		if(dep[i]!=0){
			dcr++;
			if(dcminn>dep[i])dcminn=dep[i];
		}
		else{
			if((r-l)<=(dcr-dcl))l=dcl,r=dcr,minn=dcminn;
			dcminn=99999999;dcl=i+1;dcr=dcl-1;
		}
	}
	if((r-l)<=(dcr-dcl))l=dcl,r=dcr,minn=dcminn;		
}

inline long long in(){
	char n=getchar();int e=0;
	while(n>'9'||n<'0')n=getchar();
	while(n<='9'&&n>='0')e=e*10+n-'0',n=getchar();
	return e;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in();
	for(register int i=1;i<=n;i++){
		dep[i]=in();
		if(dep[i]<minn)minn=dep[i];
	}
	if(minn)
		for(register int i=1;i<=n;i++)
			dep[i]=dep[i]-minn;
	if(minn)ans=minn;
	for(register int i=1;i<=n;i++)
		zl+=dep[i];
	while(zl!=0){
		l=1;r=0;
		minn=99999999;
		findlst();
		//printf("%lld %lld\n",l,r);
		zl-=(r-l+1)*minn;
		for(register int i=l;i<=r;i++)dep[i]-=minn;
		ans+=minn;
	//	printf("%d\n",ans);
	}
	printf("%lld",ans);
	/*l=1;r=0;n=6;
	minn=99999999;
	findlst();
	printf("%d %d %d\n",l,r,minn);*/
	return 0;
}
