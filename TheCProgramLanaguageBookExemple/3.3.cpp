#include<stdio.h>
#include<string.h>
#include<ctype.h>

/*expand: expand shorthand notaion in s1 into string s2 */
//a-z��չΪabcdefg 
// a-a��ô������������������������������ 

 main(void){
	char s1[] = {'1','-','9','a','-','a','a','-','f'};
	char s2[100];

	char c;
	int i , j;
	i = j = 0;
	//c[0]Ϊ��һ������Ԫ�� 
	while( (c = s1[i]) != '\0' ){//����s1[i++] �������
		
		if(s1[i+1] == '-' && s1[i+2] >= c) {//��������  iΪ�ڶ�Ԫ��  
			  
			while(c < s1[i+2]){ //��ʼ��չ���      1<8
				s2[j++] = c++;}   
				               
			i++;//ָ����һ����ͷ
			
		} else{ 
			
			s2[j] = c;//��� 
			j++;		
			} 
			
		i++;  //ָ����һ��		    
		}
	s2[j] = '\0';

	for(int a=0;a<100;a++)
	{
		printf("%c",s2[a]);
	}

}

/*
void main(){
	
	char c;
	int i, j;
	i = j = 0;
	while( (c=s1[i]) != '\0'){
		i++;
		if(s1[i]='-' && s1[i+1] >= c){
			i++;
			while(c < s1[i]){
				s2[j] = c;
				j++;
				c++;
			}
							
		} else{
			s2[j] = c;
			j++;
		}
		
	}
����һ��ԭ����s1��һ��������s2
һ���ַ�����char c ��Ŷ�Ӧ�ַ�
���� ���� s1
	c=��һ���ַ�
	iָ��ڶ����ַ����ж��Ƿ��������  
		���� 
			iָ��������ַ�
				c<�������ַ�ʱ
				���c �����d e f
	    ������
			���c�� ָ����һ�����λ�� 
				 
		 
*/	 
	

