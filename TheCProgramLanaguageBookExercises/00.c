#include<stdio.h>

#define abs(x)  ((x) < 0 ? -(x) : (x) )
//将数字n转换成字符串并存入s[]数组

void itoa(int n, char s[])
{
  int i, sign;
  void reverse(char s[]);//颠倒字符串顺序
  sign = n;
  i = 0;
  do{
    s[i++] = abs(n % 10) + '0';
  }while((n /= 10)!= 0);
  if(sign<0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}
main() {//test method
  int a=3450;
  char b[16];
  itoa(a,b);
  	for(int i=0;i<=16;i++)
	{
		printf("%c",b[i]);
	}

  return 0;
}
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
