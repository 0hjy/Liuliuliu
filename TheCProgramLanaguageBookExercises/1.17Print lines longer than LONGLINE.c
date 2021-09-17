#include<stdio.h>

#define MAXLINE  1000   /*maxinum input line size */
#define LONGLINE   10

int getline(char line[], int maxline);
 
/* print lines longer than LONGLINE. */
/* 打印任意长度输入行长度+输入行. */
// 输入行长度包括换行符 
/* 打印最长输入行. */
main()
{
	printf("please input !回车确认，Ctrl + z 结束getchar（）\n输入行长度包含换行符\\n\n");
	printf("打印输入行:带\\n,所以会出现空行\n");
	printf("注释:-------------------------\n");
	printf("-----换行符--输出显示为--空行>\n");
	printf("注释:-------------------------\n");
	printf("-----------输入行超过LONGLINE,print lines--------------\n");
	printf("-----------LONGLINE=%d--------------\n", LONGLINE);
	int len; 
	char line[MAXLINE];
	
	while ((len = getline(line,MAXLINE)) > 0) {//getline(）获取行，存入 line[]
		
		if(len > LONGLINE) {			
			printf("当前行长度:%d  \n当前输入行:%s\n", len,line); 
			printf("please input next lines"); 				
		}				

	}				
	return 0;
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



