package com._07_reusing;// reusing/Cartoon2.java
// TIJ4 Chapter Reusing, Exercise 3, page 245, pdf 162 
/* Prove the previous sentence. (Even if you don't create a constructor for
* Cartoon(), the compiler will synthesize a default constructor for you that
* calls the base-class constructor.
*/

import static org.greggordon.tools.Print.*;

class Art {
	Art() { println("Art constructor"); }
}

class Drawing extends Art {//
	Drawing() { println("Drawing constructor"); }
}

public class _03_Cartoon2 extends Drawing {
	public static void main(String[] args) {
		Cartoon2 x = new Cartoon2();
	}
}