package com._02_object;// object/Rainbow.java
// TIJ4 Chapter Object, Exercise 11, page 90
// Turn the AllColorsOfTheRainbow into a program that compiles and runs.


public class _11_Rainbow {//通过方法给属性赋值
	public static void main(String[] args) {
		AllTheColorsOfTheRainbow atc = new AllTheColorsOfTheRainbow();
		System.out.println("atc.anIntegerRepresentingColors = " + atc.anIntegerRepresentingColors);
		atc.changeColor(7);//-----------
		atc.changeTheHueOfTheColor(77);//---------
		System.out.println("After color change, atc.anIntegerRepresentingColors = " + atc.anIntegerRepresentingColors);
		System.out.println("atc.hue = " + atc.hue);	
	}
}

class AllTheColorsOfTheRainbow {
	int anIntegerRepresentingColors = 0;
	int hue = 0;
	void changeTheHueOfTheColor(int newHue) {//通过方法给属性赋值
		hue = newHue;
	}
	int changeColor(int newColor) {//通过方法给属性赋值
		return anIntegerRepresentingColors = newColor;		
	}
}
