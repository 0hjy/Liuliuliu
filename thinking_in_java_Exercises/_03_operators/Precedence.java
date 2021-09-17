//: operators/Precedence.java 
//pdf 72    page 95
public class Precedence { 
 public static void main(String[] args) { 
 int x = 1, y = 2, z = 3; 
 int a = x + y - 2/2 + z; // (1) 先乘除后加减
 int b = x + (y - 2)/(2 + z); // (2) 最好用括号解决
 System.out.println("a = " + a + " b = " + b); 
 } 
} /* Output: 
a = 5 b = 1 
*///:~ 