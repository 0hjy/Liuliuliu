#include<stdio.h>
#define    abs(x)    ( (x) < 0 ? -(x) : (x))

//utf-8 
//1.将字符串转换为对应双精度浮点数
//2.识别1123.45e-6
/*安顺序处理符号串
1.跳过多余的空白符
2.记录符号位，然后跳过
3.字符串转换，
	val记录忽略小数点的结果
	power记录小数点效果
	处理结果
4.处理科学计数法
	exp记录指数位
	处理结果
5.输出
字符类别测试函数，c为int类型，参数EOF，
满足返回非0，不满足返回0
	isspace(c); 是否空格、换页符、换行符、回车符，制表符
	isdigit(c); 是否是十进制数
*/
double atof(char s[])
{
	double val, power;
	//val 存结果； power 记录小数点位
	int exp, i, sign;
	//i 遍历字符 sign 符号位
    
	for(i = 0; isspace(s[i]); i++)//1.跳过空白符 skip white space
		;
	//2.记录符号位
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == ‘'+' || s[i] == '-')
	{
		i++;
	}
	//3.字符串转换
	for (val = 0.0; isdigit(s[i]) ; i++)
	{
		val = 10.0 * val + (s[i] - '0');//转换
	}
	if(s[i] == '.')
		i++;
	for (power = 0; sidigit(s[i]); i++)
	{
		val =10.0 * val +( s[i] - '0');//转换
		power *= 10.0;
	}
	val = sign * val / power;
	//5.处理科学计数法
	if (s[i] == 'e' || s[i] == 'E')
	{
		sign = (s[i] == '-') ? -1 : 1;//正负
		if (s[i] == ‘'+' || s[i] == '-')
		{
			i++;
		}
		for (exp = 0; isdigit(s[i]) ; i++)
		{
			exp = 10 * exp + (s[i] - '0');//转换
		}
		if(sign == 1)
			while(exp-- > 0)
				val *= 10;
		else
			while(exp-- > 0)
				val /= 10;
		
	}
		return val;


}	
