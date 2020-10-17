#include<bits/stdc++.h>
using namespace std;
int n; 
struct node{
	int value;
	struct node *left;
    struct node *right;
};

node *MakeNode(int val){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->value=val;
	return temp;
}

node* TaoTree(){
    //sử dụng map lưu 
    map<int, node*> mp;
    node *root = NULL;
    while(n--){
        int a,b; char x;
        cin>>a>>b>>x;
        node *father = MakeNode(a);
        //tìm đến cuối nếu ko có thì là bố
        if(mp.find(a)==mp.end()){
            mp[a]=father;
            if(root==NULL) root=father;
        }
        else
            father=mp[a];
        
        node *child=MakeNode(b);
        if(x=='L') father->left=child;
		if(x=='R') father->right=child;
		mp[b]=child;
    }
    return root;
}
void Sumright(node* root,bool c,int &sum){
    if(root==NULL)  
        return;

    if(c==true && !root->left && !root->right)
        sum+=root->value;

    Sumright(root->left,false,sum);
    //gặp trái thì false
    Sumright(root->right,true,sum);
}


int main() {
    int t; cin>>t;
	while (t--){
        cin>>n;
        node *root=TaoTree();
        int sum=0;
        bool c=true;
        Sumright(root,c,sum);
        cout<<sum;
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

