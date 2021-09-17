#include<stdio.h>

 #define MAXLINE 1000   /*maxinum input line size.  */ 

int getline(char line[], int maxline);
int remov(char s[]);
//[����]��ɾ�����ĳ�ͻ���� 
//c����,�������룬���������Ҫ���濼�� 

/* Remove trailing blanks and tabs, and delete blank lines. */
main()
{
	printf("please input !�س��жϣ�Ctrl + z ����getchar����\n�����г��Ȱ������з�\\n\n");
	printf("��ӡ������:��\\n,���Ի���ֿ���\n");
	printf("������س�,ֻ�л��з�\\n,����=1 ������;\n");
	printf("���ַ�+\\n����س�,,����=2ʱ��ʼ����\n\n"); 
	printf("ע��:-------------------------\n");
	printf("-----���з�--�����ʾΪ--����>\n");
	printf("ע��:-------------------------\n");
	

	char line[MAXLINE];  /*current input line  */ 
	
	while (getline(line,MAXLINE) > 0)  //getline(����ȡ�У����� line[]		
		if(remov(line) > 0)
			printf("ע��:---------%s----------------\n", line); 
	    
	return 0;		
} 

/* Remove trailing blanks and tabs from charaters string s. */
int remov(char s[])
{
	int i;
	
	i = 0;
	while(s[i] != '\n')/*find newline charater*/
		++i;
			
	--i;               /* back off from '\n' */

	while(s[i] >= 0 &&(s[i] = ' ' || s[i] == '\t')) /*\\delete ' ' '\t'*/
		--i;
	
	if(i >= 0)
	{			/* Is it a nonblank line? */
		++i;				
		s[i] = '\n';		/* put newline charater back */
		++i;
		s[i] = '\0'; 		/* termiate the string */
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

