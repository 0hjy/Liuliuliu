
//: operators/Exponents.java 
//pdf 81
//page 109
//指数的表示，10的幂次
// "e" means "10 to the power." 
public class Exponents { 
 public static void main(String[] args) { 
 // Uppercase and lowercase ‘e’ are the same: 
 float expFloat = 1.39e-43f; //编译器默认指数为double，所以后缀加f，
 //否则报错：必须将double转化为float。
 expFloat = 1.39E-43f; 

 System.out.println(expFloat); 
 double expDouble = 47e47d; // ‘d’ is optional 
 double expDouble2 = 47e47; // Automatically double 
 System.out.println(expDouble); 
 } 
} /* Output: 
1.39E-43 
4.7E48 
*///:~ 