#include<stdio.h>
#include<math.h>
 
int nt(int n){
	if(n<2) return false;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0) return 0;
	return 1;
}
 
struct so{
	int so;
	int solan;
};
 
so a[10005];
int t=0;
int tim(int n){
	for(int i=0;i<t;i++){
		if(a[i].so==n) return i;
	}
	return -1;
}
int ktra(int n){
	int t;
	while(n){
		t=n%10;
		if(nt(t)==0) return 0;
		n=n/10;
	}
	return 1;
}
 
void nhap(so a[],int &t){
	int n;
	while(scanf("%d",&n)!=-1){
		int i=tim(n);
		if(i==-1 && ktra(n)==1){
			a[t].so=n;
			a[t].solan=1;
			t++;
		}
		else{
			a[i].solan++;
		}
 
	}
	for(int i=0;i<t;i++){
	 	printf("%d %d\n",a[i].so,a[i].solan);
	}
}
int main(){
	nhap(a,t);
}