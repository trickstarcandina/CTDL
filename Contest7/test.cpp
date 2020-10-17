
#include <bits/stdc++.h> 
using namespace std; 
int pre(char str){
    if(str=='+' || str=='-')
        return 1;
    if(str=='*' || str=='/')
        return 2;
    return 0;
}
int biendoi(int a,int b,char str){
    if(str=='+') return a+b;
    if(str=='-') return a-b;
    if(str=='*') return a*b;
    if(str=='/') return a/b;
}
int evaluate(string str){ 
	int i; 
    int n=str.length();
	stack <int> res; 
	stack <char> x; 
	for(i = 0; i < n; i++){ 
		if(str[i] == ' ') 
			continue;  
		else if(str[i] == '('){ 
			x.push(str[i]); 
		} 
		else if(isdigit(str[i])){ 
			int val = 0;  
			while(i < n && isdigit(str[i])) { 
				val = (val*10) + (str[i]-'0'); 
				i++; 
			}
			res.push(val); 
		} 
		else if(str[i] == ')') { 
			while(!x.empty() && x.top() != '(') { 
				int temp1 = res.top(); res.pop(); 
                int temp2 = res.top(); res.pop();  
                char temp = x.top(); x.pop(); 
                res.push(biendoi(temp2,temp1,temp)); 
			} 
			if(!x.empty()) 
			    x.pop(); 
		}  
		else{  
			while(!x.empty() && pre(x.top()) >= pre(str[i])){ 
				int temp1 = res.top(); res.pop(); 
                int temp2 = res.top(); res.pop();  
                char temp = x.top(); x.pop(); 
                res.push(biendoi(temp2,temp1,temp)); 
			} 
			x.push(str[i]); 
		} 
	} 
	while(!x.empty()){ 
		int temp1 = res.top(); res.pop(); 
        int temp2 = res.top(); res.pop();  
        char temp = x.top(); x.pop(); 
        res.push(biendoi(temp2,temp1,temp));
	}  
	return res.top(); 
} 

int main() { 
	cout << evaluate("10 + 2 * 6") << "\n"; 
	cout << evaluate("100 * 2 + 12") << "\n"; 
	cout << evaluate("100 * ( 2 + 12 )") << "\n"; 
	cout << evaluate("100 * ( 2 + 12 ) / 14"); 
    /*
    6*3+2-(6-4/2)
    100+99*22
    6*((4*3)+5)
    1-2
    */
	return 0; 
} 

// This code is contributed by Nikhil jindal. 
