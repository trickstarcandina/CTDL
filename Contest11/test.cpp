#include <bits/stdc++.h> 
using namespace std; 
struct Node { 
	int data; 
	struct Node *left, *right; 
}; 
struct nhap{
    int u,v;
    char c;
};
nhap a[1001];
int n;
void cmp(nhap &x,nhap &y){
    if(x.u>y.u) swap(x,y);
     
}
void cmp2(nhap &x,nhap &y){
    if(x.u==y.u){
        if(x.c=='R' && y.c=='L') swap(x,y);
    }
}
void nhapdulieu(){
    for(int i=0;i<n;i++){
        cin>>a[i].u>>a[i].v>>a[i].c;
    }
    sort(a,a+n,cmp);
    sort(a,a+n,cmp2);
}
void printLevelOrder(Node *root) { 
	if (root == NULL) return; 
	queue<Node *> q; 
	q.push(root); 
	while (q.empty() == false){ 
		Node *node = q.front(); 
		cout << node->data << " "; 
		q.pop(); 
		if (node->left != NULL) 
			q.push(node->left); 
		if (node->right != NULL) 
			q.push(node->right); 
	} 
} 
Node* newNode(int data) { 
	Node *temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
int main() 
{ 
	// Let us create binary tree shown in above diagram 
	Node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 

	cout << "Level Order traversal of binary tree is \n"; 
	printLevelOrder(root); 
	return 0; 
} 
