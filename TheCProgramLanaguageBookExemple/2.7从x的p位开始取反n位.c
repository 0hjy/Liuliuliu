/* invert: inverts the n bits of x -------that begin at position p */
/* 取反x的n位在怕位置开始 */ 

/* x 异或 屏蔽码(1取反，0不变) */ 
main(){
} 
unsigned invert(unsigned x, int p, int n) {
	
	return x ^ ( ~(~0 <<n) << (p + 1 - n)  ) ;

}
/* 先取反--->屏蔽--->位与--- 的方法 */ 
unsigned inverts(unsigned x, int p, int n) {
	x & ~( ~(~0 <<n)   <<(p + 1 - n)  );	
	unsigned y = x ;
	y = (~y)& ~(~0 <<n)   <<(p + 1 - n) ;
	return x | y ;

}

