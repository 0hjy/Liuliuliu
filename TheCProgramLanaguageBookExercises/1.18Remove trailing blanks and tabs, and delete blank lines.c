#include<stdio.h>

 #define MAXLINE 1000   /*maxinum input line size.  */ 

int getline(char line[], int maxline);
int remov(char s[]);
//[错误]“删除”的冲突类型 
//c函数,参数传入，传出设计需要认真考虑 

/* Remove trailing blanks and tabs, and delete blank lines. */
main()
{
	printf("please input !回车中断，Ctrl + z 结束getchar（）\n输入行长度包含换行符\\n\n");
	printf("打印输入行:带\\n,所以会出现空行\n");
	printf("无输入回车,只有换行符\\n,长度=1 不计入;\n");
	printf("单字符+\\n输入回车,,长度=2时开始计入\n\n"); 
	printf("注释:-------------------------\n");
	printf("-----换行符--输出显示为--空行>\n");
	printf("注释:-------------------------\n");
	

	char line[MAXLINE];  /*current input line  */ 
	
	while (getline(line,MAXLINE) > 0)  //getline(）获取行，存入 line[]		
		if(remov(line) > 0)
			printf("注释:---------%s----------------\n", line); 
	    
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

