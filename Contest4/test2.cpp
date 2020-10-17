#include<bits/stdc++.h> 
using namespace std;
vector <long long > a;
void sinh(){ // sinh do dai day
	long long x = 1; int i = 1; a.push_back(1);
	while(i<=52){
		x *= 2;//x=2 //4 //8
		long long tmp = a[i-1]+x;//=a[0]+2=1+2=3 //a[1]+4=3+4=7 //a[2]+8=7+8=15
		a.push_back(tmp);//3
		i++;
	}
}
//dem so bit 1 trong doan
void xuly(long long n, long long vt, long long length,long long res,long long & dem){ 
	if(n<=0 || vt <=0 || length<=0) return ;
	//if(length == 3 && vt <=length && vt > 0){
	//	if(vt == 1) dem+= n/2;
	//	if(vt == 2) dem += n%2 + n/2;
	//	if(vt == 3) dem+=n;
	//	return;
	//}
	if(vt >= length){ //neu lon hon thi 
		dem+=n;
		if(vt > length) dem+= res%2; 
		long long v = vt - length-1;
		xuly(n/2,v,length/2,n,dem);
	}
	else 
        xuly(n/2,vt,length/2,n,dem);
}
main(){
	sinh();
	int t; cin >> t;
	while(t--){
		long long n,r,l; cin>>n>>l>>r;
		long long length = 0; 
		for(int i =0 ; i < a.size() ; i++){
			if(a[i] >= n){ //tim do dai day 
				length = a[i];
				break;
			}
		}
        //so bit 1 trong doan [l,r] = doan [1,r] - doan[1,l-1]
        long long deml=0; xuly(n,l-1,length,0,deml);
        long long demr=0; xuly(n,r,length,0,demr);
		cout<< demr-deml <<endl;
	}

}