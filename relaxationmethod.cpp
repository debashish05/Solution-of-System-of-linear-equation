#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,j;
	cout<<"enter the number of equation: ";
	cin>>n;
	double x[n]={0},a[n][n],b[n];
	cout<<"enter coefficient of equations (first row then second....) \n";
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			cin>>a[i][j];
			a[i][j]*=(-1);
		}
	}	
	cout<<"enter the right hand side of equations: \n";
	for(i=0;i<n;++i)cin>>b[i];
	double r[n],ans[n]={0};
	for(i=0;i<n;++i)r[i]=b[i];
	while(true){
		//for(i=0;i<n;++i)cout<<r[i]<<" ";
		int index=0;
		for(i=1;i<n;++i){	//finding max ri
			if(abs(r[i])>abs(r[index]))index=i;
		}
		//cout<<r[index]<<" ";
		//for(i=0;i<n;++i)cout<<x[i]<<" ";
		x[index]=(-1)*r[index]/a[index][index];//updating xi
		//cout<<x[index]<<" ";
		ans[index]+=x[index];
		for(i=0;i<n;++i){		//updating residual values
			r[i]+=(a[i][index]*x[index]);
		}
		//cout<<"\n";
		for(i=0;i<n;++i){
			if(abs(r[i])>0.000001)break;
		}
		if(i==n)break;
	}
	cout<<"answers for system of linear equations are: \n";
	for(i=0;i<n;++i)cout<<ans[i]<<" ";
	return 0;
}