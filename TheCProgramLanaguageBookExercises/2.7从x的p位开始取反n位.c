/* invert: inverts the n bits of x -------that begin at position p */
/* ȡ��x��nλ����λ�ÿ�ʼ */ 

/* x ��� ������(1ȡ����0����) */ 
main(){
} 
unsigned invert(unsigned x, int p, int n) {
	
	return x ^ ( ~(~0 <<n) << (p + 1 - n)  ) ;

}
/* ��ȡ��--->����--->λ��--- �ķ��� */ 
unsigned inverts(unsigned x, int p, int n) {
	x & ~( ~(~0 <<n)   <<(p + 1 - n)  );	
	unsigned y = x ;
	y = (~y)& ~(~0 <<n)   <<(p + 1 - n) ;
	return x | y ;

}

