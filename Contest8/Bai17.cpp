#include <bits/stdc++.h> 
using namespace std; 
#define pp pair<int,int>
#define pp2 pair<pair<int,int>,int>
int smat;
char a[105][105];
pp x1,x2;
void nhap(){
    cin>>smat;
	for(int i=0;i<smat;i++){
		for(int j=0;j<smat;j++) 
            cin>>a[i][j];
	}
	cin>>x1.first>>x1.second>>x2.first>>x2.second;
}
int minStep(){
	queue<pp2> q;
	set<pp> check;
	check.insert(x1);
	q.push(pp2(x1,0));
	while(!q.empty()){
		pp2 t=q.front();
		q.pop();
		if(t.first==x2) 
            return t.second;
		for(int i=t.first.first-1;i>=0;i--){
			if(a[i][t.first.second]=='X') 
                break;
			if(check.find( pp(i,t.first.second) ) == check.end()){
				q.push( pp2(pp(i,t.first.second),t.second+1) );
				check.insert(pp(i,t.first.second));
			}
		}
		for(int i=t.first.first+1;i<smat;i++){
			if(a[i][t.first.second]=='X') 
                break;
			if(check.find( pp(i,t.first.second) ) == check.end()){
				q.push( pp2(pp(i,t.first.second),t.second+1) );
				check.insert(pp(i,t.first.second));
			}
		}
		for(int i=t.first.second-1;i>=0;i--){
			if(a[t.first.first][i]=='X') 
                break;
			if(check.find( pp(t.first.first,i) ) == check.end()){
				q.push( pp2(pp(t.first.first,i),t.second+1) );
				check.insert(pp(t.first.first,i));
			}
		}
		for(int i=t.first.second+1;i<smat;i++){
			if(a[t.first.first][i]=='X') 
                break;
			if(check.find( pp(t.first.first,i) ) == check.end()){
				q.push( pp2(pp(t.first.first,i),t.second+1) );
				check.insert(pp(t.first.first,i));
			}
		}
			
	}
	return 0;
}
int main(){
	nhap();
	cout<<minStep();
    cout<<endl;
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