//: operators/AutoInc.java 
//pdf 76    page 102
//演示-- ++？
//java=c++--，确实精简了不少，但也不是说java就比c++在其他方面容易很多。
// Demonstrates the ++ and -- operators. 
import static net.mindview.util.Print.*; 
public class AutoInc { 
 public static void main(String[] args) { 
 //后++，后--实质上是把原值存入temp进行运算的同时，自身已经改变值了，走在=前面。
 int i = 1; 
 print("i : " + i); 
 print("++i : " + ++i); // Pre-increment 
 print("i++ : " + i++); // Post-increment 
 print("i : " + i); 
 print("--i : " + --i); // Pre-decrement 
 print("i-- : " + i--); // Post-decrement 
 print("i : " + i); 
 } 
} /* Output: 
i : 1 
++i : 2 
i++ : 2 
i : 3 
--i : 2 
i-- : 2 
i : 1 
*///:~ 
