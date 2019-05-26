#include <cstdio>
const int N=1e5+5,P=1e4+2;
int n,A[N],nex[N],las[P],vid[N],cc,res,fir[P];
void solve(int l,int r,int c,int del){
	if(l>r) return;
	while(c<=cc&&(fir[vid[c]]>r||fir[vid[c]]<l)) c++;
	if(c>cc) return;
	res+=(vid[c]-del);
	solve(l,fir[vid[c]]-1,c+1,vid[c]);
	while(nex[fir[vid[c]]]&&nex[fir[vid[c]]]<=r){
		solve(fir[vid[c]]+1,nex[fir[vid[c]]]-1,c+1,vid[c]);
		fir[vid[c]]=nex[fir[vid[c]]];
	}
	solve(fir[vid[c]]+1,r,c+1,vid[c]);
	fir[vid[c]]=nex[fir[vid[c]]];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",A+i);
	for(int i=1;i<=n;i++){
		if(las[A[i]]) nex[las[A[i]]]=i;
		if(!fir[A[i]]) fir[A[i]]=i;
		las[A[i]]=i;
	}
	for(int i=0;i<=P;i++){
		if(!las[i]) continue;
		vid[++cc]=i;
	}
	solve(1,n,1,0);
	printf("%d",res);
	fclose(stdin); fclose(stdout);
	return 0;
}
