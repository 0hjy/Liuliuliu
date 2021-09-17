#include<stdio.h>

int any(char s1[],char s2[]);
int anyy(char s1[],char s2[]);
main()
{
	char s1[10] ={1,2,3,4,5,6,7,8,9,0};
	char s2[4]  ={5,6,7};
	printf("初始位置为0\n");
	printf("方法一：课本原函数any()结果 %d\n", any(s1,s2));
	printf("方法二：上一道例题修改函数结果 %d\n", anyy(s1,s2));

}

int anyy(char s1[],char s2[])/*for寻找不存在，如果不存在，输出 -1；如果不存在不存在，输出i */ 
{
	int i, j;
	
	for(i = 0;s1[i] != '\0'; i++) {
		
		for (j = 0;s2[j] != '\0' &&s2[j] != s1[i]; j++)
			;
			
		if (s2[j] != '\0')    /*end of string -on match */
			return i ;
	
	}
	if (s1[i] == '\0')    /*end of string -on match */
		return -1 ;
}

int any(char s1[],char s2[])/*寻找存在，putout--i；找不到putout-1*/ 
{
	int i, j;
	
	for(i = 0;s1[i] != '\0'; i++) {
		
		for (j = 0;s2[j] != '\0' ; j++)			
			if (s2[j] == s1[i])    
				return i ;	
	}
	return -1 ;
}

