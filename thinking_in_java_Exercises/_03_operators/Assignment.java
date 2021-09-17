//: operators/Assignment.java 
//pdf 73    page 96
// Assignment with objects is a bit tricky. 
//我们真正操作的是对象的引用，对象的赋值传递实质上是引用的传递。指向同一个对象
import static net.mindview.util.Print.*; 
class Tank { 
 int level; 
} 
public class Assignment { 
 public static void main(String[] args) { 
 Tank t1 = new Tank(); //对象1
 Tank t2 = new Tank(); //对象2
 t1.level = 9; 
 t2.level = 47; 
 print("1: t1.level: " + t1.level + 
 ", t2.level: " + t2.level); 
 t1 = t2; //引用传递，t1被覆盖，原来的那个对象会被 垃圾回收器 自动清理
 print("2: t1.level: " + t1.level + 
 ", t2.level: " + t2.level); 
 t1.level = 27; //对象修改值， 指向该对象的两个引用的效果都变
 print("3: t1.level: " + t1.level + 
 ", t2.level: " + t2.level); 
 } 
} /* Output: 
1: t1.level: 9, t2.level: 47 
2: t1.level: 47, t2.level: 47 
3: t1.level: 27, t2.level: 27 
*///:~
