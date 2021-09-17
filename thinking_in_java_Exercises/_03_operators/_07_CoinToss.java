package com._03_operators;
//: operators/CoinToss.java
// TIJ4 Chapter Operators, Exercise 7, page 106
// Write a program that simulates coin-flipping
//模拟抛硬币-random随机
import java.util.*; 
import org.greggordon.tools.*;

public class _07_CoinToss {
	public static void main(String[] args) {
		Random rand = new Random();//
		int coin = rand.nextInt();//
		if(coin % 2 == 0) Print.println("heads");//P.rintln("heads");
		else Print.println("tails");	//P.rintln("tails");
	}
}
