#include<iostream>
#include<cstring>
using namespace std;
class student{
	public:
		student(string n,int nn,int f){
			name=n;num=nn;grade=f;
		}
		string name;
		int num,grade;
		student *next;
};
int main(){
	student *head=NULL;
	int n;cin>>n;
	string a;int b,c;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		student *tmp=new student(a,b,c);
		tmp->next=head;
		head=tmp;
	}
	student *travel=head;
	do{
		cout<<travel->name<<"	"<<travel->num<<"	"<<travel->grade<<endl;
		travel=travel->next;
	}while(travel!=NULL);
}
