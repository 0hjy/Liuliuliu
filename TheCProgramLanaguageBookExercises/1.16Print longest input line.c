#include<stdio.h>

#define MAXLINE 1000   /*允许的输入行的最大长度 */
 

int getline(char line[], int maxline);
void copy(char to[], char form[]);
 
/* print longest input line. */
/* 打印任意长度输入行长度+输入行. */
// 输入行长度包括换行符 
/* 打印最长输入行. */
main()
{
	printf("please input !回车中断，Ctrl + z 结束getchar（）\n输入行长度包含换行符\\n\n");
	printf("打印输入行:带\\n,所以会出现空行\n");
	printf("无输入回车,只有换行符\\n,长度=1 不计入;\n");
	printf("单字符+\\n输入回车,,长度=2时开始计入\n\n"); 
	printf("注释:-------------------------\n");
	printf("-----换行符--输出显示为--空行>\n");
	printf("注释:-------------------------\n");
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	max = 0;//初始化
	while ((len = getline(line,MAXLINE)) > 0) {//getline(）获取行，存入 line[]
		printf("当前行长度:%d  \n当前输入行:%s", len, line);
		if(len > max) {
			max = len;
			copy(longest, line);  //copy()//存入longest[]				
		}
		printf("\n当前最大长度输入行长度:");
		printf("%d\n\n\n", max) ;
}
	
	if(max > 0) 
		printf("最终最长输入行:%s  \n长度:%d \n空行:换行符\\n", longest, max); //输出 
		
	return 0;
} 
int getline(char s[], int lim) 
{//读当前行每个字符   and limit length,,除\n达到limit-1 或者\n \0 结束
 
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
void copy(char to[], char form[]) 
{//依次读入字符，除\0外。 
	int i;
	i = 0;
	while((to[i] = form[i]) != '0')
		++i; 
}


