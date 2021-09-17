package com._03_operators;//: operators/PrintTest.java
// TIJ4 Chapter Operators, Exercise 1, pager 94,pdf 71
// Write a program that uses the "short" and long form of print statement

//01-14

//简短打印
//导入jar包才能用
import static net.mindview.util.Print.*;
import org.greggordon.tools.*;

public class _01_PrintTest {
	public static void main(String[] args) {
		print("Hello, from short form.");//无换行   使用这个类//net.mindview.util.Print.*;
		//不知道咋用
		//P.rintln("Hello from greggordon form.");
		Print.println("Hello from long form.");//Cannot resolve symbol 'Print'
	}
}
