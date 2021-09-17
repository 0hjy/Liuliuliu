#include<stdio.h>
//华氏温度和摄氏温度转换公式
//℃=（5/9）*（F-32）

int main()
{
	int max(int x,int y);//声明函数 max(int x,int y);  
	int a, b, c;
	scanf("%d,%d",&a,&b);
	//%表示参数替代位置
	//%d表示是整数
	//&a表示取 
	/*
		三种输入 
	 scanf("%d,%d",&a,&b);Imput must like the 13,15 回车键一次结束  
	 scanf("%d %d",&a,&b);Imput空格不能加
     scanf("%d%d",&a,&b);
    可以输入一个字符，一次回车确认;也可以 用空格分隔，全部输入后再回车 
	  */ 
	c=max(a,b);
	printf("max=%d\n",c);
	
}
int max(int x,int y)
{
	int z;
	if(x>y) z=x;
	else z=y;
	return(z);
}
