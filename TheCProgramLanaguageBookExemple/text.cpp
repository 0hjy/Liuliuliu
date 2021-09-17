#include<stdio.h>

#define MAXLINE 1000
 
int getline(char line[], int maxline);
int remov(char s[]);

main()
{
	char line[MAXLINE];
	int len;
	int a;

	while ((len = getline(line,MAXLINE)) > 0) { //getline(����ȡ�У����� line[]
		printf("ע��:---������Ϊ:%s\n", line);
		printf("��ǰ�г���:%d  \n", len);
		printf("ע��:-------getline()=%d-----------------\n", getline(line,MAXLINE));
		if((a=remov(line)) > 0) {	
			
			printf("ע��:------remov()---%s----------------\n",  remov(line)); 
	    }
	    
	}	
	return 0;		
} 

int remov(char s[])
{
	int i;
	i = 0;
	while(s[i] != '\n')/*find newline charater*/
		++i;
		
	--i;               /* back off from '\n' */
	
	while(s[i] >= 0 &&(s[i] = ' ' || s[i] == '\t')) /*delete ' ' '\t'*/
		--i;
	
	if(i >= 0) {			/* Is it a nonblank line? */
		++i;				
		s[i] = '\n';		/* put newline charater back */
		++i;
		s[i] = '\0'; 		/* termiate the string */
		printf("ע��:-------------%d------------\n",i);
	}	
	return i;
}

int getline(char s[], int lim) 
{
 
	int c, i, j;
	j = 0; 
	for(i = 0; (c=getchar()) != EOF && c != '\n'; ++i) //��ֵ�س� i=0 
		if(i < lim-2) {
			s[j] = c;
			++j;
		}
		if(c == '\n') {
			s[j] = c;
			++j;
			++i;
		}		
	s[j] = '\0';
	return i;	
} 

