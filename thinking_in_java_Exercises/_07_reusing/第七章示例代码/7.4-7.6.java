
//: reusing/PlaceSetting.java 
//pdf165
//page249
//继承和组合，只需要导入包就可以实现新共功能
//构造器内不会强制初始化成员对象，需要自己来。
// Combining composition & inheritance. 

import static net.mindview.util.Print.*; 
class Plate { 
 Plate(int i) { 
 print("Plate constructor"); 
 } 
} 
class DinnerPlate extends Plate { //---继承
 DinnerPlate(int i) { 
 super(i); 
 print("DinnerPlate constructor"); 
 } 
} 
class Utensil { 
 Utensil(int i) { 
 print("Utensil constructor"); 
 } 
} 
class Spoon extends Utensil { //---继承
 Spoon(int i) { 
 super(i); 
 print("Spoon constructor"); 
 } 
} 
class Fork extends Utensil { //---继承
 Fork(int i) { 
 super(i); 
 print("Fork constructor"); 
 } 
Reusing Classes 173} 
class Knife extends Utensil { //---继承
 Knife(int i) { 
 super(i); 
 print("Knife constructor"); 
 } 
} 
// A cultural way of doing something: 
class Custom { 
 Custom(int i) { 
 print("Custom constructor"); 
 } 
} 
public class PlaceSetting extends Custom {  //---继承 
 private Spoon sp; 
 private Fork frk; 
 private Knife kn; 
 private DinnerPlate pl; 
 public PlaceSetting(int i) { //----构造体内组合
 super(i + 1); 
 sp = new Spoon(i + 2); //-----------组合
 frk = new Fork(i + 3); //
 kn = new Knife(i + 4); 
 pl = new DinnerPlate(i + 5); 
 print("PlaceSetting constructor"); 
 } 
 public static void main(String[] args) { 
 PlaceSetting x = new PlaceSetting(9); 
 } 
} /* Output: 
Custom constructor 
Utensil constructor 
Spoon constructor 
Utensil constructor 
Fork constructor 
Utensil constructor 
Knife constructor 
Plate constructor 
DinnerPlate constructor 
PlaceSetting constructor 
*///:~ 


//: reusing/CADSystem.java 
// Ensuring proper cleanup.
//7.4.1正确使用清理
//除了内存之外，其他的垃圾最好自己清理，特别是有依赖关系的，要先清理外侧的。 
package reusing; 
import static net.mindview.util.Print.*; 
class Shape { 
 Shape(int i) { print("Shape constructor"); } 
 void dispose() { print("Shape dispose"); } 
} 
class Circle extends Shape { 
 Circle(int i) { 
 super(i); 
 print("Drawing Circle"); 
 } 
 void dispose() { 
 print("Erasing Circle"); 
 super.dispose(); 
 } 
} 
class Triangle extends Shape { 
 Triangle(int i) { 
 super(i); 
 print("Drawing Triangle"); 
 } 
 void dispose() { 
 print("Erasing Triangle"); 
 super.dispose(); 
 } 
} 
class Line extends Shape { 
 private int start, end; 
 Line(int start, int end) { 
 super(start); 
 this.start = start; 
 this.end = end; 
 print("Drawing Line: " + start + ", " + end); 
 } 
 void dispose() { 
 print("Erasing Line: " + start + ", " + end); 
 super.dispose(); 
 } 
} 
public class CADSystem extends Shape { 
 private Circle c; 
 private Triangle t; 
 private Line[] lines = new Line[3]; 
 public CADSystem(int i) { 
 super(i + 1); 
Reusing Classes 175 for(int j = 0; j < lines.length; j++) 
 lines[j] = new Line(j, j*j); 
 c = new Circle(1); 
 t = new Triangle(1); 
 print("Combined constructor"); 
 } 
 public void dispose() { 
 print("CADSystem.dispose()"); 
 // The order of cleanup is the reverse 
 // of the order of initialization: 
 t.dispose(); //-----------------------------后创建的先清理
 c.dispose(); 
 for(int i = lines.length - 1; i >= 0; i--) 
 lines[i].dispose(); 
 super.dispose(); 
 } 
 public static void main(String[] args) { 
 CADSystem x = new CADSystem(47); 
 try { 
 // Code and exception handling... 
 } finally { 
 x.dispose(); 
 } 
 } 
} /* Output: 
Shape constructor 
Shape constructor 
Drawing Line: 0, 0 
Shape constructor 
Drawing Line: 1, 1 
Shape constructor 
Drawing Line: 2, 4 
Shape constructor 
Drawing Circle 
Shape constructor 
Drawing Triangle 
Combined constructor 
CADSystem.dispose() 
Erasing Triangle 
Shape dispose 
Erasing Circle 
Shape dispose 
Erasing Line: 2, 4 
Shape dispose 
Erasing Line: 1, 1 
Shape dispose 
Erasing Line: 0, 0 
Shape dispose 
Shape dispose 
*///:~

--------------------------------------
//7.4.2名称屏蔽
//: reusing/Hide.java 
// Overloading a base-class method name in a derived 
// class does not hide the base-class versions. 
//derived 
//基类和子类中都可以有重载（c++不允许，怕你犯错）
import static net.mindview.util.Print.*; 
class Homer { 
 char doh(char c) { //----------1
 print("doh(char)"); 
 return ‘d’; 
 } 
 float doh(float f) { //----------2
 print("doh(float)"); 
 return 1.0f; 
 } 
} 
class Milhouse {} 
class Bart extends Homer { 
 void doh(Milhouse m) { //-------------3
 print("doh(Milhouse)"); 
 } 
} 
public class Hide { 
 public static void main(String[] args) { 
 Bart b = new Bart(); 
 b.doh(1); 
 b.doh(‘x’); 
 b.doh(1.0f); 
 b.doh(new Milhouse()); 
 } 
} /* Output: 
doh(float) 
doh(char) 
doh(float) 
doh(Milhouse) 
*///:~ 
Reusing Classes 177


//: reusing/Lisa.java 
// {CompileTimeError} (Won’t compile) 
//重写的注解
//避免你在准备重写的过程中没重写，而是仅仅是重载了 这一情况的发生。
//要求你一定得重写
class Lisa extends Homer { 
 @Override 
 void doh(Milhouse m) { 
 System.out.println("doh(Milhouse)"); 
 } 
} ///:~
-------------------------------------------------
7.5 在组合和继承之间选择
两者都允许在新类中创建子对象，组合显式，继承隐式
//: reusing/Car.java 
// Composition with public objects. 
//
class Engine { 
 public void start() {} 
 public void rev() {} 
 public void stop() {} 
} 
class Wheel { 
 public void inflate(int psi) {} 
} 
class Window { 
 public void rollup() {} 
 public void rolldown() {} 
} 
class Door { 
 public Window window = new Window(); 
 public void open() {} 
 public void close() {} 
} 

public class Car { 
 public Engine engine = new Engine(); //---public暴露一部分成员对象
 public Wheel[] wheel = new Wheel[4]; //car的组合也是问题分析的一部分，public有利于问题分析
 public Door                           //一般都是private修饰
 left = new Door(), 
 right = new Door(); // 2-door 

 public Car() { 
 for(int i = 0; i < 4; i++) 
 wheel[i] = new Wheel(); 
 } 
 public static void main(String[] args) { 
 Car car = new Car(); 
 car.left.window.rollup(); 
 car.wheel[0].inflate(72); 
 } 
} ///:~ 

-------------------------------------
7.6 protected 关键字
//: reusing/Orc.java 
// The protected keyword. 
//子类访问父类的protected方法
import static net.mindview.util.Print.*; 
class Villain { 
 private String name; 
 protected void set(String nm) { name = nm; } //protected-------2
 public Villain(String name) { this.name = name; } //---------constructor
 public String toString() { 
 return "I’m a Villain and my name is " + name; 
 } 
} 
public class Orc extends Villain { 
 private int orcNumber; 
 public Orc(String name, int orcNumber) { //----constructor
 super(name); 
 this.orcNumber = orcNumber; 
 } 
 public void change(String name, int orcNumber) { //----1.
 set(name); // Available because it’s protected -------
 this.orcNumber = orcNumber; 
 } 
 public String toString() { //----
 return "Orc " + orcNumber + ": " + super.toString(); 
 } 
 public static void main(String[] args) { 
 Orc orc = new Orc("Limburger", 12); 
 print(orc); 
 orc.change("Bob", 19); 
 print(orc); 
 } 
} /* Output: 
Orc 12: I’m a Villain and my name is Limburger 
Orc 19: I’m a Villain and my name is Bob 
*///:~
