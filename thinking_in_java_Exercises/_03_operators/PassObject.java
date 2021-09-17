
//: operators/PassObject.java
//pdf 74    page 967
// Passing objects to methods may not be 
// what you’re used to. 
//对象传递的别名问题是复杂的，要多注意。
//传递给方法体之后的引用的作用对象还是方法体外的旧对象，而不是方法体内
import static net.mindview.util.Print.*; 
class Letter { 
 char c; 
} 
public class PassObject { 
 static void f(Letter y) { 
 y.c = 'z'; 
 } 
 public static void main(String[] args) { 
 Letter x = new Letter(); 
 x.c = 'a'; 
 print("1: x.c: " + x.c); 
 f(x); //f()看起来是复制了参数的副本，实质上只是传递了一个引用 
 print("2: x.c: " + x.c); 
 } 
} /* Output: 
1: x.c: a 
2: x.c: z 
*///:~
