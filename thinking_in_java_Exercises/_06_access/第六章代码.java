//: access/FullQualification.java 
//143
//210
//全名指定来使用类：冗长
public class FullQualification { 
 public static void main(String[] args) { 
 java.util.ArrayList list = new java.util.ArrayList(); 
 } 
} ///:~ 

//: access/SingleImport.java 
//143
//210
//使用 import关键字导入类
import java.util.ArrayList; 
public class SingleImport { 
 public static void main(String[] args) { 
 ArrayList list = new java.util.ArrayList(); 
 } 
} ///:~ 





//: access/mypackage/MyClass.java 
//
//
//类名和唯一的公共类同名
package access.mypackage; 
public class MyClass { 
 // ... 
} ///:~


//: access/QualifiedMyClass.java

//使用import导入的效果，更简洁 
public class QualifiedMyClass { 
 public static void main(String[] args) { 
 access.mypackage.MyClass m = 
 new access.mypackage.MyClass(); 
 } 
} ///:~
//: access/ImportedMyClass.java 
//144 
import access.mypackage.*; 
public class ImportedMyClass { 
 public static void main(String[] args) { 
 MyClass m = new MyClass(); 
 } 
} ///:~


//包中的俩程序
//: net/mindview/simple/Vector.java 
// Creating a package. 
package net.mindview.simple; 
public class Vector { 
 public Vector() { 
 System.out.println("net.mindview.simple.Vector"); 
 } 
} ///:~
//: net/mindview/simple/List.java 
// Creating a package. 
package net.mindview.simple; 
public class List { 
 public List() { 
 System.out.println("net.mindview.simple.List"); 
 } 
} ///:~


//配置好import导入的类的路径后，下m面的文件就可以随便放位置了，都能找到 Vector和List
//: access/LibTest.java 
// Uses the library. 
import net.mindview.simple.*; 
public class LibTest { 
 public static void main(String[] args) { 
 Vector v = new Vector(); 
 List l = new List(); 
 } 
} /* Output: 
net.mindview.simple.Vector 
net.mindview.simple.List 
*///:~


//使用静态导入类来减少输出负担，
//: net/mindview/util/Print.java 
// Print methods that can be used without 
// qualifiers, using Java SE5 static imports: 
package net.mindview.util; 
import java.io.*; 
public class Print {//----------------------------------- 
 // Print with a newline: 
 public static void print(Object obj) { 
 System.out.println(obj); 
 } 
 // Print a newline by itself: 
 public static void print() { 
 System.out.println(); 
 } 
 // Print with no line break: 
 public static void printnb(Object obj) { 
 System.out.print(obj); 
 } 
 // The new Java SE5 printf() (from C): 
 public static PrintStream 
 printf(String format, Object... args) { 
 return System.out.printf(format, args); 
 } 
} ///:~


//: access/PrintTest.java 
// Uses the static printing methods in Print.java. 
import static net.mindview.util.Print.*; 
public class PrintTest { 
 public static void main(String[] args) { 
 print("Available from now on!"); 
 print(100); 
 print(100L); 
 print(3.14159); 
 } 
} /* Output: 
Available from now on! 
100 
100 
3.14159 
Access Control 151*///:~


//创建的新的工具都可以导入到自己的库中
//: net/mindview/util/Range.java 
// Array creation methods that can be used without 
// qualifiers, using Java SE5 static imports: 
package net.mindview.util; 
public class Range { 
 // Produce a sequence [0..n) 
 public static int[] range(int n) { 
 int[] result = new int[n]; 
 for(int i = 0; i < n; i++) 
 result[i] = i; 
 return result; 
 } 
 // Produce a sequence [start..end) 
 public static int[] range(int start, int end) { 
 int sz = end - start; 
 int[] result = new int[sz]; 
 for(int i = 0; i < sz; i++) 
 result[i] = start + i; 
 return result; 
 } 
 // Produce a sequence [start..end) incrementing by step 
 public static int[] range(int start, int end, int step) { 
 int sz = (end - start)/step; 
 int[] result = new int[sz]; 
 for(int i = 0; i < sz; i++) 
 result[i] = start + (i * step); 
 return result; 
 } 
} ///:~ 




//: access/dessert/Cookie.java 
// Creates a library. 
package access.dessert; 
public class Cookie { 
 public Cookie() { 
 System.out.println("Cookie constructor"); 
 } 
 void bite() { System.out.println("bite"); } 
} ///:~

//: access/Dinner.java 
// Uses the library. 
import access.dessert.*; 
public class Dinner { 
 public static void main(String[] args) { 
 Cookie x = new Cookie(); //----------使用包内的类
 //! x.bite(); // Can’t access     //不在包中
 } 
} /* Output: 
Cookie constructor 
*///:~ 


//同目录的类默认在同一个包下
//: access/Cake.java 
// Accesses a class in a separate compilation unit. 
class Cake { 
 public static void main(String[] args) { 
 Pie x = new Pie(); 
 x.f(); 
 } 
} /* Output: 
Pie.f() 
*///:~

//: access/Pie.java 
// The other class. 
class Pie { 
 void f() { System.out.println("Pie.f()"); } 
} ///:~





//private 在多线程下非常重要
//: access/IceCream.java 
// Demonstrates "private" keyword.

class Sundae { 
 private Sundae() {} //---该类的助手方法都私有
 static Sundae makeASundae() { 
 return new Sundae(); 
 } 
} 
public class IceCream { 
 public static void main(String[] args) { 
 //! Sundae x = new Sundae(); 
 Sundae x = Sundae.makeASundae(); 
 } 
} ///:~



//: access/ChocolateChip.java 
// Can’t use package-access member from another package. 
import access.dessert.*; 
public class ChocolateChip extends Cookie { 
 public ChocolateChip() { 
 System.out.println("ChocolateChip constructor"); 
 } 
 public void chomp() { 
 //! bite(); // Can’t access bite    //----无法直接用别的类的方法---------------------
 } 
 public static void main(String[] args) { 
 ChocolateChip x = new ChocolateChip(); 
 x.chomp(); 
 } 
} /* Output: 
Cookie constructor 
ChocolateChip constructor 
*///:~ 


////protected 保护包外的继承类也可以使用，比默认宽，默认只有包内的。
//: access/cookie2/Cookie.java 
package access.cookie2; 
public class Cookie { 
 public Cookie() { 
 System.out.println("Cookie constructor"); 
 } 
 protected void bite() { //----------对于所以的继承类都可以使用他了，不论是包内包外，
    //bite可以被外包访问，但是仅限于继承类
 System.out.println("bite"); 
 } 
} ///:~
//: access/ChocolateChip2.java 
import access.cookie2.*; 
public class ChocolateChip2 extends Cookie { 
 public ChocolateChip2() { 
 System.out.println("ChocolateChip2 constructor"); 
 } 
 public void chomp() { bite(); } // Protected method 
 public static void main(String[] args) { 
 ChocolateChip2 x = new ChocolateChip2(); 
 x.chomp(); 
 } 
} /* Output: 
Cookie constructor 
ChocolateChip2 constructor 
bite 
*///:~


Access control is often referred to as implementation hiding. Wrapping data and methods 
within classes in combination with implementation hiding is often called encapsulation.5
The result is a data type with characteristics and behaviors.

5 However, people often refer to implementation hiding alone as encapsulation
//访问限制也是一种封装，数据和方法装入类中，是具体实现的封装。

//: access/OrganizedByAccess.java 
//把public放在前面，阅读方便，首先看到可以被直接嗲用的部分
public class OrganizedByAccess { 
 public void pub1() { /* ... */ } 
 public void pub2() { /* ... */ } 
 public void pub3() { /* ... */ } 
 private void priv1() { /* ... */ } 
 private void priv2() { /* ... */ } 
 private void priv3() { /* ... */ } 
 private int i; 
 // ... 
} ///:~ 


//一个类不可以是 private 和protected  只能说包访问和public，为哈？
//内部类是特例，除外
//: access/Lunch.java 
// Demonstrates class access specifiers. Make a class 
// effectively private with private constructors: 
class Soup1 { 
 private Soup1() {} //--------------------封装限制对象的创建1.--通过另一个方法来创建对象-可以做对象数量的记录
 // (1) Allow creation via static method: 
 public static Soup1 makeSoup() { //---------指明了返回值类型
 return new Soup1(); 
 } 
} 
class Soup2 { //--------使用了单例模式-singleton//有且仅有一个对象，-----私有属性来创建自己对象-另一个方法来获取
 private Soup2() {} 
 // (2) Create a static object and return a reference 
 // upon request.(The "Singleton" pattern): 
 private static Soup2 ps1 = new Soup2(); 
 public static Soup2 access() { 
 return ps1; 
 } 
 public void f() {} 
} 
// Only one public class allowed per file: 
public class Lunch { 
 void testPrivate() { 
 // Can’t do this! Private constructor: 
 //! Soup1 soup = new Soup1(); 
 } 
 void testStatic() { 
 Soup1 soup = Soup1.makeSoup(); //--------方法创建对象
 } 
 void testSingleton() { 
 Soup2.access().f(); //------------//单例，通过方法直接使用对象
 } 
} ///:~


// access/local/PackagedClass.java 
package access.local; 
class PackagedClass { 
 public PackagedClass() { 
 System.out.println("Creating a packaged class"); 
 } 
}

// access/foreign/Foreign.java 
package access.foreign; 
import access.local.*; 
public class Foreign { 
 public static void main(String[] args) { 
 PackagedClass pc = new PackagedClass(); 
 } 
}
//报错原因，packageclass的默认被访问只能说包内