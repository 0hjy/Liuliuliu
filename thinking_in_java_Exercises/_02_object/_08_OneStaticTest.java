package com._02_object;

// object/OneStaticTest.java
// TIJ4 Chapter Object, Exercise 8, page 90
/* Write a program that demonstrates that, no matter how many objects you
* create of a particular class, there is only one instance of a particular
* static field of that class.
*/
//static块 只有一个实例对象， 以类名为对象名

/*  _06_中有了
class StaticTest {
	static int i = 47;
}

class Incrementable {
	static void increment() { StaticTest.i++; }
}
*/

public class _08_OneStaticTest {
	public static void main(String[] args) {
		System.out.println("StaticTest.i= " + StaticTest.i);//------------
		StaticTest st1 = new StaticTest();
		StaticTest st2 = new StaticTest();
		System.out.println("st1.i= " + st1.i);
		System.out.println("st2.i= " + st2.i);
		Incrementable.increment();//类名.方法 直接调用--------
		System.out.println("After Incrementable.increment() called: ");
		System.out.println("st1.i = " + st1.i);
		System.out.println("st2.i = " + st2.i);
		Incrementable.increment();//-------------------
		System.out.println("After Incrementable.increment called: ");
		System.out.println("st1.i = " + st1.i);
		System.out.println("st2.i = " + st2.i);
		st1.i = 3;
		System.out.println("After st1.i = 3, ");
		System.out.println("st1.i = " + st1.i);
		System.out.println("st2.i = " + st2.i);
		System.out.println("Create another StaticTest, st3.");
		StaticTest st3 = new StaticTest();
		System.out.println("st3.i = " + st3.i);
	}
}
