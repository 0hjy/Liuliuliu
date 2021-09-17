#include<stdio.h>
#include<string.h>
/*字符串s中找字符串t的位置，方法1，方法2*/
//方法1
//// 算法 
//取字符串s的第一个字符
//			1.和t第一个匹配，匹配成功，接着匹配直到匹配失败或成功；
//			2.if匹配成功，记录位置 pos
//取s下一个字符直到结束
//返回pos
//utf-8 strrindex找到字符串t 在字符串s 中最右边出现的位置。如果不包含 返回 -1
int strrindex(char s[], char t[])
{
	int i, j, k, pos;//i指向 s的每个字符的位置；
	pos = -1;//返回值初始化为-1；

	for(i = 0;s[k] != '\0'; i++){//遍历s数组，

		for (j = i, k = 0; t[k] !='\0' && s[j] ==t[k];j++,k++){
		//从i位置开始匹配，第一个字符匹配上 就一直匹配。第一个都没匹配上就结束。
			;
		}

		if (k > 0 && t[k] == '\0') //匹配到t的最右侧，说明完全匹配
			pos = i;

 	}
	return pos;
}	
//方法2
//从右到左推进t的长度个字符来开始匹配，匹配不到，再向左一个位置再匹配。
//效率更高，第一个找到的即使所求的。可以立刻返回值结束函数。
int strrindexx(char s[], char t[])
{
	int i, j, k;

	for(i = strlen(s) - strlen(); i >= 0; i++){
		for(j = 1, k=0; t[k]!='\0' && s[j] == t[k];j++,k++){
			;
		}
		if(k > 0 &&t[k] == '\0')
			return i;
	}
	return -1;
}