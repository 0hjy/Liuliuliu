#include<stdio.h>

#define MAXLINE 1000   /*maxinum input line size.  */ 

int getline(char line[], int maxline);

void reverse(char s[]);

/* REverse input line, a line at a line */
main()
{
	printf("----------------------------注释:-----------------------------------\n");
	printf("----|-换行符--未以可见方式显示！                                ---|\n");
	printf("----|-Enter完成一行输入;         Ctrl + z 结束程序              ---|\n");
	printf("----|                                                           ---|\n");
	printf("----|print内容:带-\\n,所以会出现换行                             ---|\n");
	printf("----|reverse后的换行符也必须在行尾                              ---|\n");
	printf("----------------------------注释:-----------------------------------\n");
	
	char line[MAXLINE];  /*current input line  */ 
	
	while (getline(line,MAXLINE) > 0)  {//getline(）获取行，存入 line[]		
		reverse(line);
		printf("%s", line); 
	}
} 

/* Reverse: reverse string s */
void reverse(char s[])
{
	int i, j;//i:max---->0 ;  j:0----->max;
	char temp;
	
	//存入888\n，不存\0 
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
	for(i = 0; (c=getchar()) != EOF && c != '\n'; ++i) //空值回车 i=0 
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

