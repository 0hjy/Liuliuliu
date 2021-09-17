//: reusing/SprinklerSystem.java 
// Composition for code reuse. 
//pdf158    
//page237
//一个类中组合了多个类对象和基本类型----
class WaterSource { 
 private String s; 
 WaterSource() { 
 System.out.println("WaterSource()"); 
 s = "Constructed"; 
 } 
 public String toString() { return s; } //--------
} 
public class SprinklerSystem { 
 private String valve1, valve2, valve3, valve4; 
 private WaterSource source = new WaterSource(); 
 private int i; 
 private float f; 
 public String toString() { //------------------需要把多个string连接时。写tostring方法
 return  "valve1 = " + valve1 + " " + 
 "valve2 = " + valve2 + " " + 
 "valve3 = " + valve3 + " " + 
 "valve4 = " + valve4 + "\n" + 
 "i = " + i + " " + "f = " + f + " " + 
 "source = " + source; 
 } 
 public static void main(String[] args) { 
 SprinklerSystem sprinklers = new SprinklerSystem(); 
 System.out.println(sprinklers); 
 } 
} /* Output: 
WaterSource() 
valve1 = null valve2 = null valve3 = null valve4 = null 
i = 0 f = 0.0 source = Constructed 
*///:

, there’s still no guarantee that 
you’ll perform any initialization before you send a message to an object reference—e
//---------1.在声明时初始化
//---------2.构造器中初始化
//---------3.实例初始化
//---------4.惰性初始化
//: reusing/Bath.java 
// Constructor initialization with composition. 
import static net.mindview.util.Print.*; 
class Soap { //----------------------在
 private String s; 
Soap() { 
 print("Soap()"); 
 s = "Constructed"; 
 } 
 public String toString() { return s; } 
} 
public class Bath { 
 private String // Initializing at point of definition: //1.在定义对象的地方初始化，优先于构造器
 s1 = "Happy", 
 s2 = "Happy", 
 s3, s4; 
 private Soap castille; //--------------创建引用
 private int i; 
 private float toy; 
 public Bath() {//-----------------print输出在所有初始化之前， 不在构造中初始化对象的话，不能保证交给引用前就初始化好了
                //意思就是最好在构造初始化，其他地方没保证。 先执行构造还是属性？？？？？？？？？？
 print("Inside Bath()"); 
 s3 = "Joy"; 
 toy = 3.14f; 
 castille = new Soap(); //-----2.构造中初始化
 //--------引用指向对象，？？？？？？？/这种写法可以吗？？？？/
 } 
 // Instance initialization: 
 { i = 47; } 
 public String toString() { //----------------保证s4被填充
 if(s4 == null) // Delayed initialization: 
 s4 = "Joy"; //----------4.惰性初始化，使用前
 return 
 "s1 = " + s1 + "\n" + 
 "s2 = " + s2 + "\n" + 
 "s3 = " + s3 + "\n" + 
 "s4 = " + s4 + "\n" + 
 "i = " + i + "\n" + 
 "toy = " + toy + "\n" + 
 "castille = " + castille; 
 } 
 public static void main(String[] args) { 
 Bath b = new Bath(); //----------------------//---------3.实例初始化
 print(b); 
 } 
} /* Output: 
Inside Bath() 
Soap() 
s1 = Happy 
s2 = Happy 
s3 = Joy 
s4 = Joy 
i = 47 
toy = 3.14 
castille = Constructed 
*///:~ 


//: reusing/Detergent.java 
// Inheritance syntax & properties. 
//继承的声明
import static net.mindview.util.Print.*; 
class Cleanser { 
 private String s = "Cleanser"; 
 public void append(String a) { s += a; } //-------------+=唯二重载用于String处理的操作符，连接
 public void dilute() { append(" dilute()"); } 
 public void apply() { append(" apply()"); } 
 public void scrub() { append(" scrub()"); } 
 public String toString() { return s; } 
 public static void main(String[] args) { //--------------为每一个类写main方法可以方便测试，完成测试也不必删除
 Cleanser x = new Cleanser(); 
 x.dilute(); x.apply(); x.scrub(); 
 print(x); 
 } 
} 
//继承的声明
//---------------继承是对类的复用
public class Detergent extends Cleanser { 
 // Change a method: 
 public void scrub() { 
 append(" Detergent.scrub()"); 
 super.scrub(); // Call base-class version 
 } 
 // Add methods to the interface: 
 public void foam() { append(" foam()"); } 
 // Test the new class: 
 public static void main(String[] args) { //--------------main方法不管自己的类是默认还是public 都可以通过 java 类名 来嗲用，由于静态
 Detergent x = new Detergent(); 
 x.dilute(); 
 x.apply(); 
 x.scrub(); 
 x.foam(); 
 print(x); 
 print("Testing base class:"); 
 Cleanser.main(args); 
 } 
} /* Output: 
Cleanser dilute() apply() Detergent.scrub() scrub() foam() 
Testing base class: 
Cleanser dilute() apply() scrub() 
*///:~ 


//: reusing/Cartoon.java 
// Constructor calls during inheritance. 
//构造的构建过程从父类开始，即便不给子类构造，子类也会默认父类的
//子类对象都包含着基类对象，基类对象被包装在内部。
import static net.mindview.util.Print.*; 
class Art { 
 Art() { print("Art constructor"); } 
} 
class Drawing extends Art { 
 Drawing() { print("Drawing constructor"); } 
} 
public class Cartoon extends Drawing { 
 public Cartoon() { print("Cartoon constructor"); } 
 public static void main(String[] args) { 
 Cartoon x = new Cartoon(); 
 } 
} /* Output: 
Art constructor 
Drawing constructor 
Cartoon constructor 
*///:~ 



//: reusing/Chess.java 
// Inheritance, constructors and arguments. 
//调用基类有参构造必须显式
//super()
import static net.mindview.util.Print.*; 
class Game { 
 Game(int i) { 
 print("Game constructor"); 
 } 
} 
class BoardGame extends Game { 
 BoardGame(int i) { 
 super(i); //-------------------------------不调用基类构造，编译器会抱怨的，所以是有参构造必做的事情。
 print("BoardGame constructor"); 
 } 
} 
public class Chess extends BoardGame { 
 Chess() { 
 super(11); //-----------------------------------
 print("Chess constructor"); 
 } 
 public static void main(String[] args) { 
 Chess x = new Chess(); 
 } 
} /* Output: 
Game constructor 
BoardGame constructor 
Chess constructor 
*///:~ 


//: reusing/SpaceShipControls.java 
public class SpaceShipControls { //-----代理==继承和组合的中庸之道，java没有直接提供支持
 void up(int velocity) {} 
 void down(int velocity) {} 
 void left(int velocity) {} 
 void right(int velocity) {} 
 void forward(int velocity) {} 
 void back(int velocity) {} 
 void turboBoost() {} 
} ///:~ 
//1.继承方式---暴露了父类的所有方法-------子类其实包含了父类
//: reusing/SpaceShip.java 
public class SpaceShip extends SpaceShipControls { 
 private String name; 
 public SpaceShip(String name) { this.name = name; } 
 public String toString() { return name; } 
 public static void main(String[] args) { 
 SpaceShip protector = new SpaceShip("NSEA Protector"); 
 protector.forward(100); //----------暴露了父类方法
 } 
} ///:~

//2.代理模式-----拥有更多控制力，可以选择只提供方法的一个子集
//: reusing/SpaceShipDelegation.java 
public class SpaceShipDelegation { 
 private String name; 
 private SpaceShipControls controls =  new SpaceShipControls();//1.类中private属性创建自己的对象，通过方法调用， 
 public SpaceShipDelegation(String name) { 
 this.name = name; 
 } 

 // Delegated methods: 
 public void back(int velocity) { //---2.把父类对象的方法使用 藏在子类的方法体里（通过方法调用）
 controls.back(velocity); 
 } 
 public void down(int velocity) { 
 controls.down(velocity); 
 } 
 public void forward(int velocity) { 
 controls.forward(velocity); 
 } 
 public void left(int velocity) { 
 controls.left(velocity); 
 } 
 public void right(int velocity) { 
 controls.right(velocity); 
 } 
 public void turboBoost() { 
 controls.turboBoost(); 
 } 
 public void up(int velocity) { 
 controls.up(velocity); 
 } 
 public static void main(String[] args) { 
 SpaceShipDelegation protector =  new SpaceShipDelegation("NSEA Protector"); 
 protector.forward(100); 
 } 
} ///:~ 