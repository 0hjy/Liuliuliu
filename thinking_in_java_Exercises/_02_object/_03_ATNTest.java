package com._02_object;// TIJ4 Chapter Object, Exericise 3, page 90
// object/ATNTest.java
// Find the code fragments involving ATypeName and turn them into a program
// that compiles and runs.

public class _03_ATNTest {//创建对象，调用方法		
	public static void main(String[] args) {
		class ATypeName {
			int i;
			double d;
			boolean b;
			void show() {
				System.out.println(i);
				System.out.println(d);
				System.out.println(b);	
			}
		}	
		ATypeName a = new ATypeName();////object
		a.i = 3;
		a.d = 2.71828;
		a.b = false;		
		a.show();
	}
}