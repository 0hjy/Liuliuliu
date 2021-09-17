//: operators/EqualsMethod.java 
//pdf 78    page 105
//实质上是47在常量池中存放，两个引用的常量池对象是同一个
public class EqualsMethod { 
 public static void main(String[] args) { 
 Integer n1 = new Integer(47); 
 Integer n2 = new Integer(47); 
 System.out.println(n1.equals(n2)); //比较两个对象是否相同
 } 
} /* Output: 
true 
*///:~




