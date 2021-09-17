#include<stdio.h>
/*折半查找*/

/*方法1*/ 
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n-1;
	while (low <= high){
		if (x < v[mid])
			high = mid - 1;   //1.应为3会判断=mid，所以排除mid 
		else if ( x > v[mid]) //2. 
			low = mid + 1;
		else
			return mid;      //3. =mid
	}
	
	return -1;
}


/*方法2*/
 
int binsearchh(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n-1;
	mid = (low + high) / 2;
	while (low < high && x != mid){
		if (x < v[mid])
			high = mid - 1;
		else 
			low = mid + 1;
		mid = (low + high) / 2;/*重记 mid*/ 
		
	}
	
	if(x == v[mid])
		return mid;       /*found match */
	else
		return -1;         /*not match */
}
