#include<stdio.h>
//�����¶Ⱥ������¶�ת����ʽ
//��=��5/9��*��F-32��

int main()
{
	int max(int x,int y);//�������� max(int x,int y);  
	int a, b, c;
	scanf("%d,%d",&a,&b);
	//%��ʾ�������λ��
	//%d��ʾ������
	//&a��ʾȡ 
	/*
		�������� 
	 scanf("%d,%d",&a,&b);Imput must like the 13,15 �س���һ�ν���  
	 scanf("%d %d",&a,&b);Imput�ո��ܼ�
     scanf("%d%d",&a,&b);
    ��������һ���ַ���һ�λس�ȷ��;Ҳ���� �ÿո�ָ���ȫ��������ٻس� 
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
