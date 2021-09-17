#include<stdio.h>
//sublime  utf-8
//将整数n转换为以b为底的数，转换结果保存在字符串数组s
//例如 等价于把n转换为b进制的数
/*
*
 生成b进制的数
	1.%b取余  将余数转为字符数存入低位数
	2./b取整  删除低位
 不断循环1.2. 直到 取整<=0。将全部b进制逆序存入字符串

 调用reverse（）函数做一次颠倒
*/
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

void itob(int n, char s[], int b)
{
	int i, j, sign;
	void reverse(char s []);//

	if((sign = n) < 0)//sign判断正负
		n = -n;
	i = 0;
	do{
		j = n % b;//取余
		s[i++] = (j <= 9) ? j+'0' : j+'a'-10;//转为字符编码
	}while( (n /= b) > 0);//取整
	
	if(sign < 0)//存入符号
		s[i++] = '-';
	s[i] ='\0';

	reverse(s);
}	
 main()
	int a, b;
	a = 127;
	b = 16;
	char c[15];
	void itob(a, c, b);
	/* code */
	return 0;
}