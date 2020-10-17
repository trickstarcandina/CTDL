#include <bits/stdc++.h> 
using namespace std; 
string str,str2;
string kt,kt2;
void xuly(){
    int n=str.length();
    stack<char> st;
    int i;
    for(i=0;i<n;i++){
        if(str[i]=='('){
            char c=str[i-1];
            if(c=='-' || c=='+') st.push(c);
            if(c=='(' && !st.empty()) st.push(st.top());
        }
        if(!st.empty() && st.top()=='-'){
            if(str[i]=='-') str[i]='+';
            else if(str[i]=='+') str[i]='-';
        }
        if(str[i]== ')' && !st.empty()) st.pop();
    }
    for(int i=0;i<n;i++){
        if(str[i]=='(' || str[i]==')') continue;
            kt+=str[i];
    }
} 
void xuly2(){
    int n=str2.length();
    stack<char> st;
    int i;
    for(i=0;i<n;i++){
        if(str2[i]=='('){
            char c=str2[i-1];
            if(c=='-' || c=='+') st.push(c);
            if(c=='(' && !st.empty()) st.push(st.top());
        }
        if(!st.empty() && st.top()=='-'){
            if(str2[i]=='-') str2[i]='+';
            else if(str2[i]=='+') str2[i]='-';
        }
        if(str2[i]== ')' && !st.empty()) st.pop();
    }
    for(int i=0;i<n;i++){
        if(str2[i]=='(' || str2[i]==')') continue;
            kt2+=str2[i];
    }
} 
bool check(){
    if(kt.length()!=kt2.length()) return false;
    for(int i=0;i<kt.length();i++){
        if(kt[i]!=kt2[i]) return false;
    }
    return true;
}
int main() { 
    int t; cin>>t;
    while (t--){
        cin >>str>>str2;
        xuly(); 
        xuly2();
        //cout<<kt<<" "<<kt2;
        if(check()) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
	return 0; 
} 
/*
Trickstar Candina
                              _,add8ba,
                            ,d888888888b,
                           d8888888888888b                        _,ad8ba,_
                          d888888888888888)                     ,d888888888b,
                          I8888888888888888 _________          ,8888888888888b
                __________`Y88888888888888P"""""""""""baaa,__ ,888888888888888,
            ,adP"""""""""""9888888888P""^                 ^""Y8888888888888888I
         ,a8"^           ,d888P"888P^                           ^"Y8888888888P'
       ,a8^            ,d8888'                                     ^Y8888888P'
      a88'           ,d8888P'                                        I88P"^
    ,d88'           d88888P'                                          "b,
   ,d88'           d888888'                                            `b,
  ,d88'           d888888I                                              `b,
  d88I           ,8888888'            ___                                `b,
 ,888'           d8888888          ,d88888b,              ____            `b,
 d888           ,8888888I         d88888888b,           ,d8888b,           `b
,8888           I8888888I        d8888888888I          ,88888888b           8,
I8888           88888888b       d88888888888'          8888888888b          8I
d8886           888888888       Y888888888P'           Y8888888888,        ,8b
88888b          I88888888b      `Y8888888^             `Y888888888I        d88,
Y88888b         `888888888b,      `""""^                `Y8888888P'       d888I
`888888b         88888888888b,                           `Y8888P^        d88888
 Y888888b       ,8888888888888ba,_          _______        `""^        ,d888888
 I8888888b,    ,888888888888888888ba,_     d88888888b               ,ad8888888I
 `888888888b,  I8888888888888888888888b,    ^"Y888P"^      ____.,ad88888888888I
  88888888888b,`888888888888888888888888b,     ""      ad888888888888888888888'
  8888888888888698888888888888888888888888b_,ad88ba,_,d88888888888888888888888
  88888888888888888888888888888888888888888b,`"""^ d8888888888888888888888888I
  8888888888888888888888888888888888888888888baaad888888888888888888888888888'
  Y8888888888888888888888888888888888888888888888888888888888888888888888888P
  I888888888888888888888888888888888888888888888P^  ^Y8888888888888888888888'
  `Y88888888888888888P88888888888888888888888888'     ^88888888888888888888I
   `Y8888888888888888 `8888888888888888888888888       8888888888888888888P'
    `Y888888888888888  `888888888888888888888888,     ,888888888888888888P'
     `Y88888888888888b  `88888888888888888888888I     I888888888888888888'
       "Y8888888888888b  `8888888888888888888888I     I88888888888888888'
         "Y88888888888P   `888888888888888888888b     d8888888888888888'
            ^""""""""^     `Y88888888888888888888,    888888888888888P'
                             "8888888888888888888b,   Y888888888888P^
                              `Y888888888888888888b   `Y8888888P"^
                                "Y8888888888888888P     `""""^
                                  `"YY88888888888P'
                                       ^""""""""'
*/