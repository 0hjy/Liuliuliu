package com._03_operators;
// operators/DogTest.java
// TIJ4 Chapter Operators, Exercise 5, page 105
/* Create a class called Dog containing two Strings: name and says.
* In main(), create two dog objects with names "spot" (who says "Ruff!") and
* "scruffy" (who says "Wurf!").  Then display their names and what they say.
*/

import org.greggordon.tools.*;
//创建里啊狗，输出狗叫
class Dog {
	String name;
	String says;
	void setName(String n) {
		name = n;
	}
	void setSays(String s) {
		says = s;
	}
	void showName() {
		Print.println(name);
	}
	void speak() {
		Print.println(says);
	}
}

public class _05_DogTest {
	public static void main(String[] args) {
		Dog spot = new Dog();
		spot.setName("Spot");
		spot.setSays("Ruff!");

		Dog scruffy = new Dog();
		scruffy.setName("Scruffy");
		scruffy.setSays("Wurf!");
		spot.showName();
		spot.speak();
		scruffy.showName(); 
		scruffy.speak();
	}
}  
