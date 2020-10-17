#include<bits/stdc++.h>
using namespace std;
void check(string a){
    int x=a.length()-1;
    if(a[0]==a[x]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		string a; cin>>a;
        check(a);
	}
}

