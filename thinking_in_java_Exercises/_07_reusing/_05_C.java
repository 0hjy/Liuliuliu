package com._07_reusing;
// reusing/Ex5/C.java
// TIJ4 Chapter Reusing, Exercise 5, page 245, pdf 163
/* Create two classes, A and B, with default constructors (empty argument
* lists) that announce themselves. Inherit a new class called C from A, and
* create a member of class B inside C. Do not create a constructor for C. Create
* an object of class C and observe the resluts. 
*/
 Ex5
import static org.greggordon.tools.Print.*;
//父类
class A { A(){ println("A()");} }
//子类
class B extends A { B(){ println("B()");} }

//子类继承
public class C extends A { 
	B b = new B(); // will then construct another A and then a B
	public static void main(String[] args) {
		C c = new C(); // will construct an A first
	}
}
