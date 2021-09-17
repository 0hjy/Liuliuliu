
//: operators/EqualsMethod2.java 
//pdf 78    page 105
// Default equals() does not compare contents. 
//实质上，equals()默认比较引用，比较对象需要重写。
class Value { 
 int i; 
} 
public class EqualsMethod2 { 
 public static void main(String[] args) { 
 Value v1 = new Value(); 
 Value v2 = new Value(); 
 v1.i = v2.i = 100; 
 System.out.println(v1.equals(v2)); 
 } 
} /* Output: 
false 
*///:~
