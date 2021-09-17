#include<stdio.h>

/*replace tabs and backspace with visble charachers.*/

/*替换制表符，回退符*/
main(){
	
	int c;
	//output \t \t \\.*/
	while((c= getchar() )!= EOF){
		if(c == '\t')
			printf("\\t");//用\\双斜杠显示斜杠  然后t显示t 
		if(c == '\b')
			printf("\\t");
		if(c =='\\')
			printf("\\\\");	//用\\双斜杠显示斜杠两次。 	
	}

}  
