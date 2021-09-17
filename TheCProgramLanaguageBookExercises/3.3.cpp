#include<stdio.h>
#include<string.h>
#include<ctype.h>

/*expand: expand shorthand notaion in s1 into string s2 */
//a-z扩展为abcdefg 
// a-a怎么处理？？？？？？？？？？？？？？ 

 main(void){
	char s1[] = {'1','-','9','a','-','a','a','-','f'};
	char s2[100];

	char c;
	int i , j;
	i = j = 0;
	//c[0]为第一个数组元素 
	while( (c = s1[i]) != '\0' ){//最后的s1[i++] 溢出数组
		
		if(s1[i+1] == '-' && s1[i+2] >= c) {//条件成立  i为第二元素  
			  
			while(c < s1[i+2]){ //开始扩展输出      1<8
				s2[j++] = c++;}   
				               
			i++;//指向下一个开头
			
		} else{ 
			
			s2[j] = c;//输出 
			j++;		
			} 
			
		i++;  //指向下一个		    
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
声明一个原数组s1和一个空数组s2
一个字符变量char c 存放对应字符
遍历 数组 s1
	c=第一个字符
	i指向第二个字符，判断是否符合条件  
		符合 
			i指向第三个字符
				c<第三个字符时
				输出c 且输出d e f
	    不符合
			输出c， 指向下一个输出位置 
				 
		 
*/	 
	

