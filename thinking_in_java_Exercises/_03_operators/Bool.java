
//: operators/Bool.java 
//pdf 78    page 105
// Relational and logical operators. 
//关系运算符和逻辑运算符
import java.util.*; 
import static net.mindview.util.Print.*; 
public class Bool { 
 public static void main(String[] args) { 
 Random rand = new Random(47); 
 int i = rand.nextInt(100); 
 int j = rand.nextInt(100); 
 print("i = " + i); 
 print("j = " + j); 
 print("i > j is " + (i > j)); 
 print("i < j is " + (i < j)); 
 print("i >= j is " + (i >= j)); 
 print("i <= j is " + (i <= j)); 
 print("i == j is " + (i == j)); 
 print("i != j is " + (i != j)); 
 
 //不同于c++，java的非boolean值不能参与逻辑运算运算
 //与或非只能操作布尔类型的值
 // Treating an int as a boolean is not legal Java: 
//! print("i && j is " + (i && j));//这种注释会被自动移除 
//! print("i || j is " + (i || j)); 
//! print("!i is " + !i); 
 print("(i < 10) && (j < 10) is " 
 + ((i < 10) && (j < 10)) ); 
 print("(i < 10) || (j < 10) is " 
 + ((i < 10) || (j < 10)) ); 
 }  
} /* Output: 
i = 58 
j = 55 
i > j is true 
i < j is false 
i >= j is true 
i <= j is false 
i == j is false 
i != j is true 
(i < 10) && (j < 10) is false 
(i < 10) || (j < 10) is false 
*///:~ 


