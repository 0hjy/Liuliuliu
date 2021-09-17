#include<stdio.h>
//GBK  devc++
#define abs(x)  ((x) < 0 ? -(x) : (x) )
//������nת�����ַ���������s[]����
/* Reverse: reverse string s */
void reverse(char s[])
{
	int i, j;//i:max---->0 ;  j:0----->max;
	char temp;
	
	//����888\n������\0 
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
void itoa(int n, char s[])
{
  int i, sign;
  void reverse(char s[]);

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

