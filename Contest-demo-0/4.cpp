#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
 	for(int j=1;j<=t;j++){
        int a,i=2,d=0;
        cin>>a;
        cout<<"Test "<<j<<": ";
        while (a!=1){
        	if(a%i==0){
        		d++; a=a/i;
        		if (a%i!=0){
                    cout<<i<<"("<<d<<") ";
					d=0;
					}
				}
			else
				i++;
		}
		cout<<endl;
    }
}
