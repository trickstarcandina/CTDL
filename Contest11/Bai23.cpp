#include <bits/stdc++.h>
using namespace std;
int ans;

struct Node {
    int data, height;
    Node *left, *right;
};

void printPostOrderBST(Node *root) {
    if (root == nullptr) return;
    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* cur = s1.top();
        s1.pop();
        s2.push(cur);

        if (cur->left) s1.push(cur->left);
        if (cur->right) s1.push(cur->right);
    }

    while (!s2.empty()) {
        Node* cur = s2.top();
        s2.pop();
        cout << cur->data << " ";
    }
}

Node* buildPreOrderBST(int* a, int n, int h){
    if (n <= 0) return nullptr;
    Node* root = new Node;
    root->data = a[0];
    root->height = h;
    ans = max(ans, h);
    int i = 0;
    for (i = 1; i < n; i++)
        if (a[i] > a[0]) break;
    root->left = buildPreOrderBST(&a[1], i-1, h+1);
    root->right = buildPreOrderBST(&a[i], n-i, h+1);
}

bool verifyPreOrderBST(int* a, int n){
    if (n <= 0) return true;
    int i = 0, j;
    for (i = 1; i < n; i++)
        if (a[i] > a[0]) break;
    for (j = 1; j < i; j++) {
        if (a[0] <= a[j]) {
            cout << "NO";
            return false;
        }
    }
    for (j = i; j < n; j++) {
        if (a[0] >= a[j]) {
            cout << "NO";
            return false;
        }
    }
    return (true && verifyPreOrderBST(&a[1], i-1) && verifyPreOrderBST(&a[i], n-i));
}

void preOrderToPostOrderBST(int* a, int n){
    ans = 0;
    if (!verifyPreOrderBST(a, n)) return;
    Node *root = buildPreOrderBST(a, n, 0);
    cout << ans << endl;
}

main(){
    int a[1000], t, n, i;
    cin >> t;

    while (t--){
        cin >> n;
        for (i=0; i<n; i++) cin >> a[i];
        preOrderToPostOrderBST(a, n);
    }
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



