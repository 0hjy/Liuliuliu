package com._03_operators;
// operators/LongValues.java
// TIJ4 Chapter Operaters, Exercise 8, page 109
// Show that hex and octal notations work with long values. 
// Use Long.toBinaryString to display the results.

import static net.mindview.util.Print.*;
//8和16进制 
public class _08_LongValues {
	public static void main(String[] args) {
		long n1 = 0xffff; // hexadecimal  //16直接常量
		long n2 = 077777; // octal		//
		print("long n1 in hex = " + Long.toBinaryString(n1));
		print("long n2 in oct = " + Long.toBinaryString(n2));
	}
}
