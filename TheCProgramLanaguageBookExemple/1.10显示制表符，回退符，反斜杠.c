#include<stdio.h>

/*replace tabs and backspace with visble charachers.*/

/*�滻�Ʊ�������˷�*/
main(){
	
	int c;
	//output \t \t \\.*/
	while((c= getchar() )!= EOF){
		if(c == '\t')
			printf("\\t");//��\\˫б����ʾб��  Ȼ��t��ʾt 
		if(c == '\b')
			printf("\\t");
		if(c =='\\')
			printf("\\\\");	//��\\˫б����ʾб�����Ρ� 	
	}

}  
