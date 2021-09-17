#include<stdio.h>

#define MAXLINE 1000   /*maxinum input line size.  */ 

int getline(char line[], int maxline);

void reverse(char s[]);

/* REverse input line, a line at a line */
main()
{
	printf("----------------------------ע��:-----------------------------------\n");
	printf("----|-���з�--δ�Կɼ���ʽ��ʾ��                                ---|\n");
	printf("----|-Enter���һ������;         Ctrl + z ��������              ---|\n");
	printf("----|                                                           ---|\n");
	printf("----|print����:��-\\n,���Ի���ֻ���                             ---|\n");
	printf("----|reverse��Ļ��з�Ҳ��������β                              ---|\n");
	printf("----------------------------ע��:-----------------------------------\n");
	
	char line[MAXLINE];  /*current input line  */ 
	
	while (getline(line,MAXLINE) > 0)  {//getline(����ȡ�У����� line[]		
		reverse(line);
		printf("%s", line); 
	}
} 

/* Reverse: reverse string s */
void reverse(char s[])
{
	int i, j;//i:max---->0 ;  j:0----->max;
	char temp;
	
	//����888\n������\0 
	i = 0;
	while(s[i] != '\0')/*find newline charater*/
		++i;
			
	--i;               /* back off from '\0' */	
	if(s[i] == '\n')   /* back off from '\n' */
		--i;
	
	j = 0;
	while(j < i) {/*//frist,end, reverse*/
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		--i;
		++j;
	}
}

/* getline:get line.*/
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

