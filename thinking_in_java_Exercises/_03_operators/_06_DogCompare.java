package com._03_operators;
// operators/DogCompare.java
// TIJ4 Chapter Operators, Exercise 6, page 105
/* Create a class called Dog containing two Strings: name and says.
* Following exercise 5, create a new Dog reference and assign it to spot's
* object. Test for comparison using == and equals() for all references.
*/
//
import org.greggordon.tools.*;
//==与 equals 比较  创建新引用
class Dog {//Duplicate class found in the file 'E:\Demo\thinking_in_java_exercises\src\com\_03_operators\_05_DogTest.java'
	String name;
	String says;
	void setName(String n) {
		name = n;
	}
	void setSays(String s) {
		says = s;
	}
	void showName() {
		Print.println(name);//P.
	}
	void speak() {
		Print.println(says);
	}
}

public class _06_DogCompare {
	public static void main(String[] args) {
		Dog spot = new Dog();//新索引
		spot.setName("Spot");
		spot.setSays("Ruff!");
		Dog scruffy = new Dog();
		scruffy.setName("Scruffy");
		scruffy.setSays("Wurf!");
		spot.showName();
		spot.speak();
		scruffy.showName(); 
		scruffy.speak();
		Dog butch = new Dog();
		butch.setName("Butch");
		butch.setSays("Hello!");
		butch.showName();
		butch.speak();
		Print.println("Comparison: ");
		Print.println("spot == butch: " + (spot == butch));
		Print.println("spot.equals(butch): " + spot.equals(butch));
		Print.println("butch.equals(spot): " + butch.equals(spot));
		Print.println("Now assign: spot = butch");
		spot = butch;
		Print.println("Compare again: ");
		Print.println("spot == butch: " + (spot == butch));
		Print.println("spot.equals(butch): " + spot.equals(butch));
		Print.println("butch.equals(spot): " + butch.equals(spot));
		Print.println("Spot: ");
		spot.showName();
		spot.speak();
		Print.println("Butch: ");
		butch.showName();
		butch.speak();
			
	}
}

