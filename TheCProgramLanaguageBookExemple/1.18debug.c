#include<stdio.h>
/*BUG为49行，当输入只有enter 数组下标越界,*/ 
#define MAXLINE 1000   /*允许的输入行的最大长度 */
 
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
	
	int a;
	char line[MAXLINE];
	
	while (getline(line,MAXLINE) > 0) { //getline(）获取行，存入 line[]
		printf("注释:----------------------------------while(a() > 0)执行------>\n");
		
		printf("当前输入行:%s",  line);
		printf("\n注释:-------------------------\n");
		
		if((a = remov(line)) > 0) {	
			printf("注释:-------------------------if(remov(line) > 0)执行1--remov()=%d--->\n", a);	
			printf("注释:-------------------------if(remov(line) > 0)执行------>\n");	
			printf("注释:---------%s----------------\n", line); 
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
	printf("注释1:------------------------------if(i>= > 0)执行1--i=%d--->\n", i);
	
	--i;               /* back off from '\n' */
	printf("注释2:------------------------------if(i>= > 0)执行2--i=%d--->\n", i);
	while(s[i] >= 0 &&(s[i] = ' ' || s[i] == '\t')) /*delete ' ' '\t'*/
		{
			i=i-1;
			printf("注释4:---------------------------------------执行3--i=%d------>\n", i);

		}
	printf("注释3:---------------------------------------执行3--i=%d------>\n", i);
	
	if(i >= 0) {			/* Is it a nonblank line? */
		++i;				
		s[i] = '\n';		/* put newline charater back */
		++i;
		s[i] = '\0'; 		/* termiate the string */

		printf("注释:---------------------------------if(i>= > 0)执行------>\n");	
				
		printf("注释:-------if------%d------------\n",i);
	}	
	printf("注释:---------------------------------if(i>= > 0)执行3------>\n");
	printf("注释:-----int remov(char s[])----%d----------------\n", i);
	return i;
}

int getline(char s[], int lim) 
{//读行   and limit length,,除\n达到limit-1 或者\n \0 结束
 
	int c, i, j;
	//j出现三次  字符\n \0  
	//i出现两次   字符\n 
	//i=数组长度 带\N除\0 ;   j=字符数=所占字节数  
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

