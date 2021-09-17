#include<stdio.h>
#define MAXCOL 10  /*maxinum column of input */ 
#define TABINC 8   /*Tab increment size  */ 

char line[MAXCOL];
int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

/* fold long input lines into two or more shorter lines */
/*
	逐字符读入*******************************************************
		1.存入line[] 
		2.读到\t，执行exptab(pos)---->转为blanks存入。
		3.读到\n, 执行printl(pos);--->输出一行字符串，pos置0. 
		4.超出TABINC
			5.findblnk() 回找空格返回下一位position，找不到就返回TABINC	  
			6.printl()  
			7.newpos()  pos归0;计入余留，新pos，(继续) 
		4.超出TABINC 
	逐字符读入 ******************************************************
	
	printl(pos);
		输出一行 
	exptab(pos);
		\t——>blanks;  
		没超出return pos；
   		超出，执行printl(),return 0; 
	findblnk(); 
		找当前行前一个空格 ，避免一个单词分两行， 
		找不到就算了 
	newpos();***
		接收预留字符，新pos记录字符串 
*/
 
/*
	nb = TABINC - (pos - 1 ) % TABINC;
	需要补充的空格位= 一个表格单位  -（去除制表符后的长度）除以制表单位所得的余数    即：
	需要补充的空格位= 一个表格单位  -  已占的长度 
*/
	 
main()
{
	printf("please input !回车中断，Ctrl + z 结束getchar（）\n输入行长度包含换行符\\n\n");
	printf("打印输入行:带\\n,所以会出现空行\n");
	printf("无输入回车,只有换行符\\n,长度=1 不计入;\n");
	printf("单字符+\\n输入回车,,长度=2时开始计入\n\n"); 
	printf("注释:-------------------------\n");
	printf("-----换行符--输出显示为--空行>\n");
	printf("注释:-------------------------\n");

	int c, pos;/*c当前字符；pos字符位置；*/
	 
	pos = 0;
	while ((c =getchar()) != EOF) {
		line[pos] = c;
		if (c == '\t')
			pos = exptab(pos);
		else if (c == '\n') {
			printl(pos);
			pos = 0;
		} else if (++pos >= MAXCOL) {
			pos = findblnk(pos);
			printl(pos);
			pos = newpos(pos);
		}
	}
}

/* printl: print line until pos column */
void printl(int pos)//输出line[0]-->line[pos-1]  \n； 
{
	int i;
	for(i = 0; i< pos; ++i)
		putchar(line[i]);
	if(pos > 0)					/*any chars printed?????????????????*/
		putchar('\n');
}

/* exptab: expand tab into blanks */
int exptab(int pos)
{
	line[pos] =' ';              /*tab is at least one blank */
	for (++pos; pos < MAXCOL && pos % TABINC != 0;++pos )
		line[pos] = ' ';		
	if  (pos < MAXCOL)          /* room left in current line */
		return pos;
	else {						/* current line is full */ 
		printl(pos);             
		return 0;               /* reset current position */ 
	}
}

/*findblnk: find blanks's position */
int findblnk(int pos)
{
	while (pos > 0 && line[pos] != ' ')
		--pos;
	if(pos == 0)                           /* no blanks in the line ? */ 
		return MAXCOL; 
	else								   /* at least one blank      */
		return pos+1;					   /* position after the blank */ 
}

/* newpos: rearrange line with new position */ 
int newpos(int pos)
{
	int i, j;
	
	if (pos <= 0 || pos >= MAXCOL) 
		return 0;                           /* nothing to rerrange */
	else {
		i = 0;
		for (j = pos; j < MAXCOL; ++j) {
			line[i] = line[j];
			++i;//++j却 
		}
		return i;                           /* new position in line */ 
	}
}

