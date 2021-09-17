#include<stdio.h>

#define MAXHIST 10 /* max length of histgram  */
#define MAXWORD 11 /* max length of word      */ 
#define IN       1 /* inside of a word */
#define OUT      0 /* outside of a word */

/* print vertial histgram. */
/*��ӡ��ֱֱ��ͼ*/  
//������� a aa aa  aaaa aaaa  aaaa aaaa aaa aaa aaa  aaaaa aaaaa aaaaa aaaaa aaaaa 
//aaaaa aaaaaaaaaaaaaaaaaaaa vbbbbbbbbbbbbbbbbbbbbb
main(){
	printf("please input ! \n");
	int c, i, j, nc, state; //i j ����ѭ�� 
	int len;          /* length of each ber       */
	int maxvalue;     /* maxmum value for wl[]    */
	int ovflow;       /* number of overflow words */
	int wl[MAXWORD];  /* word length counters */
	
	state = OUT;
	nc = 0;
	ovflow = 0;
	
	//��ʼ���� wl[0] = 0 ������ 
	for (i = 0; i < MAXWORD; ++i)
		wl[i] = 0;
		
	//����	
	while ((c= getchar() )!= EOF) { 
	    
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (nc > 0) {
				if (nc < MAXWORD)
					++wl[nc];//�������� 
			} else
					++ovflow; //���ʳ��� 
		nc = 0;//������� 
		}  else if (state == OUT) {
			state = IN;
			nc = 1;        /* begining of a new word ��һ�ζ��볤��=1*/ 
		} else {
			++nc;		   /* inside of a word */
		}
			 
	} 
	
	//�ҳ��������ֵ ���������� 
	maxvalue = 0; 
	for(i = 1; i < MAXWORD; ++i)// wl[0] = 0 ������  ����i��1��ʼ
		if(wl[i] > maxvalue )
			maxvalue = wl[i];
			
	//print 
	printf("****************��**ֱ**ֱ**��**ͼ:********************\n");
	printf("*******************************************************\n");
	
	for(i = MAXHIST; i > 0; --i) {
			printf("     ");
			for(j =1 ; j < MAXWORD; ++j) 
				
				if((wl[j]  * MAXHIST / maxvalue) >= i)//�������� 
					printf("   *");
				else
					printf("    ");
					
			putchar('\n');
	}
		
	
	printf("����:");		
	for(i = 1; i < MAXWORD; ++i) 
		printf("%4d", i);
	putchar('\n');
	
	printf("  ֵ:");
	for(i = 1; i < MAXWORD; ++i) 
		printf("%4d", wl[i]);
	putchar('\n');
	
	if(ovflow > 0) 
			printf("There are %d words length >= %d\n", ovflow, MAXWORD);//
}



