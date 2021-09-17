
---------------------------------------------------------------------
7.7 向上转型

//: reusing/Wind.java 
// Inheritance & upcasting. 
class Instrument { 
 public void play() {} 
 static void tune(Instrument i) { 
 // ... 
 i.play(); 
 } 
} 
// Wind objects are instruments 
// because they have the same interface: 
public class Wind extends Instrument { //-------子类
 public static void main(String[] args) { 
 Wind flute = new Wind(); 
 Instrument.tune(flute); // Upcasting--------------------子类引用代替父类作为参数，call method
 } 
} ///:~
there’s no method that tune( ) could call      for an Instrument that isn’t also in Wind. 

对于不在风中的乐器，tune（）无法被调用。（对于机翻需要把后置定语移到前面理解）

---------------------------
7.7.1 Why “upcasting”?
----------------------------
7.8 final
//一个永不改变的编译时常量---在编译时提前计算减小运行负担--必须基本类型，声明时赋值
//一个运行时初始化，但再不改变
//: reusing/FinalData.java 
// The effect of final on fields. 
//static 强调一份   final强调 常量
//恒定初始值的static final 常量 通常大写 下划线_分隔_字母
//final表示不可变，值不变或者指向的引用不变

import java.util.*; 
import static net.mindview.util.Print.*; 
class Value { 
 int i; // Package access 
 public Value(int i) { this.i = i; } 
} 
public class FinalData { 
 private static Random rand = new Random(47); 
 private String id; 
 public FinalData(String id) { 
    this.id = id; 
    } 
 // Can be compile-time constants: 
 private final int valueOne = 9; //--------------------------
 private static final int VALUE_TWO = 99; //--compile-time constants) 
 // Typical public constant: 
 public static final int VALUE_THREE = 39; //经典定义-方式---public包外可以用
 // Cannot be compile-time constants: 
 private final int i4 = rand.nextInt(20); //----------------
 static final int INT_5 = rand.nextInt(20); //------------------
 private Value v1 = new Value(11); 
 private final Value v2 = new Value(22); //--------------------
 private static final Value VAL_3 = new Value(33); //-----------
 // Arrays: 
 private final int[] a = { 1, 2, 3, 4, 5, 6 }; //-----
 public String toString() { 
 return id + ": " + "i4 = " + i4 + ", INT_5 = " + INT_5; 
 } 
 public static void main(String[] args) { 
 FinalData fd1 = new FinalData("fd1"); 
 //! fd1.valueOne++; // Error: can’t change value 
 fd1.v2.i++; // Object isn’t constant! 
 fd1.v1 = new Value(9); // OK -- not final 

 for(int i = 0; i < fd1.a.length; i++) 
 fd1.a[i]++; // Object isn’t constant! 
 //! fd1.v2 = new Value(0); // Error: Can’t 
 //! fd1.VAL_3 = new Value(1); // change reference 
 //! fd1.a = new int[3]; 
 print(fd1); 
 print("Creating new FinalData"); 
 FinalData fd2 = new FinalData("fd2"); 
 print(fd1); //-------------------------------
 print(fd2); 
 } 
} /* Output: 
fd1: i4 = 15, INT_5 = 18 
Creating new FinalData 
fd1: i4 = 15, INT_5 = 18 
fd2: i4 = 13, INT_5 = 18 
*///:~Reusing Classes 183 

空白final
//: reusing/BlankFinal.java 
// "Blank" final fields. 
class Poppet { 
 private int i; 
 Poppet(int ii) { i = ii; } 
} 
public class BlankFinal { 
 private final int i = 0; // Initialized final 
 private final int j; // Blank final ---------------------------------//
 private final Poppet p; // Blank final reference ---------------引用-//
 // Blank finals MUST be initialized in the constructor: 
 public BlankFinal() { 
 j = 1; // Initialize blank final 
 p = new Poppet(1); // Initialize blank final reference 
 } 
 public BlankFinal(int x) { 
 j = x; // Initialize blank final 
 p = new Poppet(x); // Initialize blank final reference 
 } 
 public static void main(String[] args) { 
 new BlankFinal(); 
 new BlankFinal(47); 
 } 
} ///:~


final 参数
嗲用方法的时候无法改变引用的指向
f() g() 展示了，之后用于向匿名内部类传参（可以读不可以修改）
//: reusing/FinalArguments.java 
// Using "final" with method arguments. 
class Gizmo { 
 public void spin() {} 
} 
public class FinalArguments { 
 void with(final Gizmo g) { 
 //! g = new Gizmo(); // Illegal -- g is final 
 } 
 void without(Gizmo g) { 
 g = new Gizmo(); // OK -- g not final 
 g.spin(); 
 } 
 // void f(final int i) { i++; } // Can’t change --------------//
 // You can only read from a final primitive: 
 int g(final int i) { //----------------------------///
    return i + 1; } 
 public static void main(String[] args) { 
 FinalArguments bf = new FinalArguments(); 
Reusing Classes 185186 Thinking in Java Bruce Eckel
 bf.without(null); 
 bf.with(null); 
 } 
} ///:~ 


-------------------------
7.8.2 final方法
1.防止覆写修改，保持不变。（出于设计考虑）
2.过去的原因（效率），同意编译器执行方法嗲用机制  转为方法嵌入 现在不这样做了，优化交给编译器和jvm 
//: reusing/FinalOverridingIllusion.java 
// It only looks like you can override 
// a private or private final method. 
import static net.mindview.util.Print.*; 
class WithFinals { 
 // Identical to "private" alone: 
 private final void f() { print("WithFinals.f()"); }//------------- 
 // Also automatically "final": 
 private void g() { print("WithFinals.g()"); } 
} 
                                                           
1 Don’t fall prey to the urge to prematurely optimize. If you get your system working and it’s too slow, it’s doubtful that you 
can fix it with the final keyword. http://MindView.net/Books/BetterJava has information about profiling, which can be 
helpful in speeding up your program.

class OverridingPrivate extends WithFinals { 
 private final void f() { //-------------------------
 print("OverridingPrivate.f()"); 
 } 
 private void g() { 
 print("OverridingPrivate.g()"); 
 } 
} 
class OverridingPrivate2 extends OverridingPrivate { 
 public final void f() { //------------------------------------
 print("OverridingPrivate2.f()"); 
 } 
 public void g() { 
 print("OverridingPrivate2.g()"); 
 } 
} 
public class FinalOverridingIllusion { 
 public static void main(String[] args) { 
 OverridingPrivate2 op2 = new OverridingPrivate2(); 
 op2.f(); 
 op2.g(); 
 // You can upcast: 
 OverridingPrivate op = op2; //--------upcast
 // But you can’t call the methods: 
 //! op.f(); 
 //! op.g(); 
 // Same here: 
 WithFinals wf = op2; 
 //! wf.f(); 
 //! wf.g(); 
 } 
} /* Output: 
OverridingPrivate2.f() 
OverridingPrivate2.g() 
*///:~ 
Overriding” can only occur if something is part of the base-class interface. That is, you must 
be able to upcast an object to its base type and call the same method (the point of this will 
become clear in the next chapter). If a method is private, it isn’t part of the base-class 
interface. It is just some code that’s hidden away inside the class, and it just happens to have 
that name, but if you create a public, protected, or package-access method with the same 
name in the derived class, there’s no connection to the method that might happen to have 
that name in the base class. You haven’t overridden the method; you’ve just created a new 
method. Since a private method is unreachable and effectively invisible, it doesn’t factor 
into anything except for the code organization of the class for which it was defined. 
？？？？？？？？



7.8.3 final 类
不允许继承
自然内部的方法也是不允许重写的，隐式 final
//: reusing/Jurassic.java 
// Making an entire class final. 
class SmallBrain {} 
final class Dinosaur { //------------------
 int i = 7; 
 int j = 1; 
 SmallBrain x = new SmallBrain(); 
 void f() {} 
} 
//! class Further extends Dinosaur {} 
// error: Cannot extend final class ‘Dinosaur’ 
public class Jurassic { 
 public static void main(String[] args) { 
 Dinosaur n = new Dinosaur(); 
 n.f(); 
 n.i = 40; 
 n.j++; 
 } 
} ///:~ 

---------------------------------
7.9.1 继承与初始化

//: reusing/Beetle.java 
// The full process of initialization. 
import static net.mindview.util.Print.*; 
class Insect { 
 private int i = 9; 
 protected int j; 
 Insect() { 
 print("i = " + i + ", j = " + j); 
 j = 39; 
 } 
 private static int x1 = 
 printInit("static Insect.x1 initialized"); 
 static int printInit(String s) { 
                                                           
2 The constructor is also a static method even though the static keyword is not explicit. So to be precise, a class is first 
loaded when any one of its static members is accessed. print(s); 
 return 47; 
 } 
} 
public class Beetle extends Insect { 
 private int k = printInit("Beetle.k initialized"); 
 public Beetle() { 
 print("k = " + k); 
 print("j = " + j); 
 } 
 private static int x2 = 
 printInit("static Beetle.x2 initialized"); 
 public static void main(String[] args) { 
 print("Beetle constructor"); 
 Beetle b = new Beetle(); 
 } 
} /* Output: 
static Insect.x1 initialized 
static Beetle.x2 initialized 
Beetle constructor 
i = 9, j = 0 
Beetle.k initialized 
k = 47 
j = 39 
*///:~ 

The constructor is also a static method even though the static keyword is not explicit. So to be precise, a class is first 
loaded when any one of its static members is accessed