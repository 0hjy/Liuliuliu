package com._07_reusing;// reusing/DetergentDelegation.java
// TIJ4 Chapter Reusing, Exercise 11, page 248
// Modify Detergent.java so that is uses delegation.
import static net.mindview.util.Print.*;
//------实现代理------------
class Cleanser {
	private String s = "Cleanser";
	public void append(String a) { s += a; }
	public void dilute() { append(" dilute()"); }
	public void apply() { append(" apply()"); }
	public void scrub() { append(" scrub()"); }
	public String toString() { return s; }
	public static void main(String[] args) {
		Cleanser x = new Cleanser();
		print(x);
	}
}

public class _11_DetergentDelegation {
	private String s = "DetergentDelegation";	//------------单例？？？自己创建自己的对象
	Cleanser c = new Cleanser();
	public void append(String a) { s += a; }
	// two methods delegated entirely to Cleanser c:
	public void dilute() { //---------------------------封装父类方法在子类方法中，
		c.dilute(); 
	}
	public void apply() {
		c.apply(); 
		}
	// method delegated in part to Cleanser c:
	public void scrub() {
		append(" DetergentDelegation.scrub()");
		c.scrub(); 
	}
	public void foam() { append(" foam()"); } 
	public String toString() { return s + " " + c; }	
	public static void main(String[] args) {
		DetergentDelegation x = new DetergentDelegation();
		x.dilute();
		x.apply();
		x.scrub();
		x.foam();
		print(x);
		print("Testing base class:");
		Cleanser.main(args);
	}
}