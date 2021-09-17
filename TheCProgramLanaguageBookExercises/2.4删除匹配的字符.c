#include<stdio.h>

/*
	------目的：存入一个新的s1[]数组-------- 
	1.---for-i++ 读入s1[]一位，判断是否可以存入 
			2.---for-j++找s2[]和s1[i]相同的字符 ，找不到接着找	
					-----找到；----不存  
					---未找到；s1[i]存入新s1[k], k+1 判断下一位 
	--------2.----for
			4.存入 字符串终结符\0 
	1.---for 
*/

/*squeeze: delete each char in s1 which is in s2 */
main(){
}
void squeeze(char s1[], char s2[] )
{
	int i, j, k;//删除后的数组下标会变，所以设置新下标k 
	
	for(i = k = 0;s1[i] != '\0'; i++) {
		
		for (j = 0;s2[j] != '\0' &&s2[j] != s1[i]; j++)
			;
			
		if (s2[j] == '\0')    /*end of string -on match */
			s1[k++] = s1[i];
	
	}
	s1[k] = '\0'; 	          /* input the end of characters */
} 

