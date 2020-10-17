#include<stdio.h>
#include<string.h>
#include<ctype.h>
void chuanhoa(char s[]){
	char *p=strtok(s," ");
	char s1[100]="";
	p=strtok(NULL," ");
	while(p!=NULL){
		p[0]=toupper(p[0]);
		for(int i=1;i<strlen(p);i++){
			p[i]=tolower(p[i]);
		}
		strcat(s1,p); strcat(s1," ");
		p=strtok(NULL," ");
	}
	s1[strlen(s1)-1]='\0';
	p=strtok(s," ");
	strupr(p);
	strcat(s1,", ");
	strcat(s1,p);
	puts(s1);
	
}
main(){
	int t;
	char s[51];
	scanf("%d",&t);
	gets(s);
	while(t--){
		gets(s);
		chuanhoa(s);
	}
}
