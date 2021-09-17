package com._02_object;
// object/DataOnlyTest.java
// TIJ4 Chapter Object Exercise 4 page 90
// Turn the DataOnly code fragments into a program that compiles and runs

public class _04_DataOnlyTest {//创建对象调用方法	
	public static void main(String[] args) {
		class DataOnly {
			int i;
			double d;
			boolean b;
			void show() {
				System.out.println(i);
				System.out.println(d);
				System.out.println(b);	
			}
		}	
		DataOnly data = new DataOnly();
		data.i = 3;
		data.d = 2.71828;
		data.b = false;		
		data.show();
	}
}