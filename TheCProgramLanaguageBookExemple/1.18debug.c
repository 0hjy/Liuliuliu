#include<stdio.h>
/*BUGΪ49�У�������ֻ��enter �����±�Խ��,*/ 
#define MAXLINE 1000   /*����������е���󳤶� */
 
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
	
	int a;
	char line[MAXLINE];
	
	while (getline(line,MAXLINE) > 0) { //getline(����ȡ�У����� line[]
		printf("ע��:----------------------------------while(a() > 0)ִ��------>\n");
		
		printf("��ǰ������:%s",  line);
		printf("\nע��:-------------------------\n");
		
		if((a = remov(line)) > 0) {	
			printf("ע��:-------------------------if(remov(line) > 0)ִ��1--remov()=%d--->\n", a);	
			printf("ע��:-------------------------if(remov(line) > 0)ִ��------>\n");	
			printf("ע��:---------%s----------------\n", line); 
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
	printf("ע��1:------------------------------if(i>= > 0)ִ��1--i=%d--->\n", i);
	
	--i;               /* back off from '\n' */
	printf("ע��2:------------------------------if(i>= > 0)ִ��2--i=%d--->\n", i);
	while(s[i] >= 0 &&(s[i] = ' ' || s[i] == '\t')) /*delete ' ' '\t'*/
		{
			i=i-1;
			printf("ע��4:---------------------------------------ִ��3--i=%d------>\n", i);

		}
	printf("ע��3:---------------------------------------ִ��3--i=%d------>\n", i);
	
	if(i >= 0) {			/* Is it a nonblank line? */
		++i;				
		s[i] = '\n';		/* put newline charater back */
		++i;
		s[i] = '\0'; 		/* termiate the string */

		printf("ע��:---------------------------------if(i>= > 0)ִ��------>\n");	
				
		printf("ע��:-------if------%d------------\n",i);
	}	
	printf("ע��:---------------------------------if(i>= > 0)ִ��3------>\n");
	printf("ע��:-----int remov(char s[])----%d----------------\n", i);
	return i;
}

int getline(char s[], int lim) 
{//����   and limit length,,��\n�ﵽlimit-1 ����\n \0 ����
 
	int c, i, j;
	//j��������  �ַ�\n \0  
	//i��������   �ַ�\n 
	//i=���鳤�� ��\N��\0 ;   j=�ַ���=��ռ�ֽ���  
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

