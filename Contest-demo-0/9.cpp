#include<bits/stdc++.h>
using namespace std;
bool tang(string a){
    for(int i=1;i<a.length();i++)
        if((a[i]-'0')<(a[i-1]-'0')){
            return 0;
        }
    return 1;
}
bool giam(string a){
    for(int i=1;i<a.length();i++)
        if((a[i]-'0')>(a[i-1]-'0')){
            return 0;
        }
    return 1;
}
int main(){
	int t; cin >> t;
	while(t--){
		string a;
        cin>>a;
        if(tang(a) || giam(a)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
	}
}

