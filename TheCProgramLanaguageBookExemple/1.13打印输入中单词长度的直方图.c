#include<stdio.h>
/*output a words histgram*/
/*打印输入单词长度的直方图*/
/*
	用一个数组显示 下标表示单词长度， 内容表示单词个数	
	直方图
		横轴 为 单词长度1--MAXWORD
	 	纵轴 为  对应长度单词的个数 1--MAHIST 
*/ 

#define MAXHIST 15 /* max length of histgram 直方图长度 */
#define MAXWORD 11 /* max length of word    单词max长度0--10 11个 */ 
#define IN       1 /* inside of a word */
#define OUT      0 /* outside of a word */

/* print horizontal histgram. */
/*windows阻塞式Enter终止输入后，需要输入Ctrl+z流结束标志，再次Enter。*/  
//输入测试 aa aaaa aaaa aaa aaa aaa 
//aaaaa aaaaaaaaaaaaaaaaaaaa vbbbbbbbbbbbbbbbbbbbbb
main(){
	printf("please input ! \n");
	int c, i, nc, state; //c表示当前单词， nc  当前单词长度 
	int len;          /* length of each ber ******长度 */
	int maxvalue;     /* maxmum value for wl[] */
	int ovflow;       /* number of overflow words */
	int wl[MAXWORD];  /* word length counters */
	
	state = OUT;
	nc = 0;
	ovflow = 0;
	
	//初始化且 wl[0] = 0 不变了 
	for (i = 0; i < MAXWORD; ++i)
		wl[i] = 0;
		
	//计数	
	while ((c= getchar() )!= EOF) { 
	    
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (nc > 0) {
				if (nc < MAXWORD)
					++wl[nc];//单词正常 
			} else
					++ovflow; //单词超长 
		nc = 0;//长度清空 
		}  else if (state == OUT) {
			state = IN;
			nc = 1;        /* begining of a new word 第一次读入长度=1*/ 
		} else {
			++nc;		   /* inside of a word */
		}
			 
	} 
	
	//找出数组最大值 ，最多个数的 
	maxvalue = 0; 
	for(i = 1; i < MAXWORD; ++i)// wl[0] = 0 不变了  所有i从1开始
		if(wl[i] > maxvalue )
			maxvalue = wl[i];
	printf("*******水平直方图*******\n");
	printf("单词长度--值 : \n");//一个汉字等于两个数字位		
	for(i = 1; i < MAXWORD; ++i) {
		printf("%7d-%4d : ", i, wl[i]);//output head. 长度i，个数wl[i] 
		if(wl[i] > 0) {
			if((len = wl[i] * MAXHIST / maxvalue) <= 0) //计算**长度； 百分比*最大长度maxhist 
				len = 1;//不足一个*按一个算 
		} else
			len = 0;
		while (len > 0) {
			putchar ('*');//output *
			--len;
		}
		putchar('\n');
	}
	if(ovflow > 0)
			printf("T"); 
		printf("There are %d words length >= %d\n", ovflow, MAXWORD);

} 
