#include<iostream>
using namespace std;
class edge{
	public:
	int data;
	edge *next=NULL;
};
class head{
	public:
	edge *first=NULL;
	int* visall(){
		int *a={0},num=0;
		if(first==NULL) return a;
		edge *tmp=first;
		while(1){
			a[++num]=(*tmp).data;
			if((*tmp).next!=NULL)*tmp=*((*tmp).next);
			else return a;
		}
		
	}
}; 
int main(){
	cout<<1<<endl;
	head a[100001];
	cout<<2<<endl;
	edge b[1000001];
	cout<<3<<endl;
	int n,m,x,y,z;cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;//start,end,weight
		b[i].data=z;
		*(b[i].next)=*(a[x].first);
		*(a[x].first)=b[i];
	}
	return 0;
}
