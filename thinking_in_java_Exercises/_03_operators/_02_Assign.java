package com._03_operators;
//: operators/Assign.java
// TIJ4 Chapter Operators, Exercise 2, page 97 
// Create a class containing a float and use it to demonstrate aliasing

//demonstrate aliasing 演示别名
import org.greggordon.tools.*;

class Tube {
	float level;
}

public class _02_Assign {
	public static void main(String[] args) {
		Tube t1 = new Tube();
		Tube t2 = new Tube();
		t1.level = 0.9f;
		t2.level = 0.47f;
		Print.println("1: t1.level: " + t1.level + ", t2.level: " + t2.level);
		//P.rintln("1: t1.level: " + t1.level + ", t2.level: " + t2.level);
		t1 = t2;//别名现象aliasing
		Print.println("2: t1.level: " + t1.level + ", t2.level: " + t2.level);
		//P.rintln("2: t1.level: " + t1.level + ", t2.level: " + t2.level);
		t1.level = 0.27f;
		Print.println("3: t1.level: " + t1.level + ", t2.level: " + t2.level);
		//P.rintln("3: t1.level: " + t1.level + ", t2.level: " + t2.level);
	}
}

