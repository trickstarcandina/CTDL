#include <bits/stdc++.h> 
using namespace std; 

#define pp pair<int,int>

int a[505][505];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int day[505][505];
int R,C;
int ngay=0;
queue<pp> q;
void nhap(){
    cin>>R>>C;
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			cin>>a[i][j];
			if(a[i][j]==2){
				q.push(pp(i,j));
				day[i][j]=0;
			}
		}
	}
}
bool check(){
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++) 
            if(a[i][j]==1) return false;		
	}
	return true;
}

void xuly(){
    while(!q.empty()){
		pp t=q.front();
		q.pop();
		int x=t.first;
		int y=t.second;
		for(int i=0;i<4;i++){
			int u= x + dx[i];
			int v= y + dy[i];
			if(a[u][v]==1){
				a[u][v]=2;
				day[u][v]=day[x][y]+1;
				if(day[u][v]>ngay) ngay=day[u][v];
				q.push(pp(u,v));
			}
		}
	}
	
	if(check()) 
        cout<<ngay;
	else 
        cout<<-1;
}
int main(){
	nhap();
    xuly();
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