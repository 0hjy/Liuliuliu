package _02_object;
// object/ITest.java
// TIJ4 Chapter Object, Exercise 7, page 90
// Turn the Incrementable code fragments into a working program.

class StaticTest {
	static int i = 47;
}
class Incrementable {
	static void increment() { StaticTest.i++; }
}

public class _07_ITest {
	public static void main(String[] args) {
	System.out.println("StaticTest.i= " + StaticTest.i);//1.类名.输出静态常量
	StaticTest st1 = new StaticTest();//创建对象
	StaticTest st2 = new StaticTest();
	System.out.println("st1.i= " + st1.i);//2.对象. 输出静态常量
	System.out.println("st2.i= " + st2.i);
	Incrementable sf = new Incrementable();
	sf.increment();//3.对象调用方法
	System.out.println("After sf.increment() called: ");
	System.out.println("st1.i = " + st1.i);
	System.out.println("st2.i = " + st2.i);
	Incrementable.increment();
	System.out.println("After Incrementable.increment called: ");
	System.out.println("st1.i = " + st1.i);
	System.out.println("st2.i = " + st2.i);
	}
}

