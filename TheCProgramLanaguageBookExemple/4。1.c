#include<stdio.h>
#define    abs(x)    ( (x) < 0 ? -(x) : (x))
//将整数n转换为以b为底的数，转换结果保存在字符串数组s
//例如 等价于把n转换为b进制的数

//utf-8 strrindex找到字符串t 在字符串s 中的位置后继续搜索。
int strrindex(char s[], char t[])
{
	int i, j, k, pos;

	pos = -1;//
	for(i = 0;s[k] != '\0'; i++){
		for (j = i, k = 0;; t[k] !='\0' && s[j] ==t[k];j++,k++){
			;
		}
		if (k > 0 && t[k] == '\0')
			pos = i;
	}
	return pos;
}	
 main()
{

}