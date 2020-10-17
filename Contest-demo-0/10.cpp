#include<bits/stdc++.h>
using namespace std;
void chuanhoa(string a){
    int i=0;
    string x;
    while(i < a.length()){
        string name ;
        int j = i;
		while(a[j] == ' ' && j < a.length()){ // tim ki tu dau tien khac khoang trang
			j++;
		}
        i=j;
        a[i]=toupper(a[i]);
        name += a[i];
        i++;
        while(a[i] != ' ' && i < a.length()){ // cong khi khac khoang trang
		    a[i]=tolower(a[i]);
			name += a[i];
			i++;
		}
        x+= name ;
        x+=' ';
    }
    cout<<x<<endl;
}
int main(){
	int t; cin >> t;
    string a;
    getline(cin, a);
	while(t--){
        getline(cin, a);
        chuanhoa(a);
	}
    
}

