//: operators/Equivalence.java
//pdf 77    page 103 
//测试对象的等价性
public class Equivalence { 
 public static void main(String[] args) { 
 Integer n1 = new Integer(47); 
 Integer n2 = new Integer(47); 
 System.out.println(n1 == n2);//比较的是对象的引用。   
 System.out.println(n1 != n2); 
 } 
} /* Output: 
false 
true 
*///:~

