#include<stdio.h>
#define    abs(x)    ( (x) < 0 ? -(x) : (x))
//将整数n转换为以b为底的数，转换结果保存在字符串数组s
//例如 等价于把n转换为b进制的数


void reverse(char s[])
{
	int i, j;//i:max---->0 ;  j:0----->max;
	char temp;
	
	//´æÈë888\n£¬²»´æ\0 
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

//接收三个参数 n整数  s[]转化为字符  w 最小字段宽度
//必要时在左边填充空格
void itoa(int n, char s[], int w)
{
	int i, sign;
	void reverse(char s []);//声明

	sign = n;
	do{
		s[i++] = abs(n % 10) + '0';//转化
	}while( (n /= 10) != 0);
	
	if(sign < 0)//符号
		s[i++] = '-';
	while(i < w)//补充空格
		s[i++] = ' ';
	s[i] = '\0';//结束符
	reverse(s);//颠倒字符串

}	
 main()
{

}