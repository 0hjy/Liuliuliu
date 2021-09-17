//: operators/Literals.java 
//pdf 80    page 108
//iteral value 
//通过字符填写相关信息，让编译器识别常量类型
import static net.mindview.util.Print.*; 
public class Literals { 
 public static void main(String[] args) { 
 int i1 = 0x2f; // Hexadecimal (lowercase) 
 print("i1: " + Integer.toBinaryString(i1)); 
 int i2 = 0X2F; // Hexadecimal (uppercase) 
 print("i2: " + Integer.toBinaryString(i2)); 
 int i3 = 0177; // Octal (leading zero) 
 print("i3: " + Integer.toBinaryString(i3)); 
 char c = 0xffff; // max char hex value 
Operators 73 print("c: " + Integer.toBinaryString(c)); 
 byte b = 0x7f; // max byte hex value 
 print("b: " + Integer.toBinaryString(b)); 
 short s = 0x7fff; // max short hex value 
 print("s: " + Integer.toBinaryString(s)); 
 long n1 = 200L; // long suffix 
 long n2 = 200l; // long suffix (but can be confusing) 
 long n3 = 200; 
 float f1 = 1; 
 float f2 = 1F; // float suffix 
 float f3 = 1f; // float suffix 
 double d1 = 1d; // double suffix 
 double d2 = 1D; // double suffix 
 // (Hex and Octal also work with long) 
 } 
} /* Output: 
i1: 101111 
i2: 101111 
i3: 1111111 
c: 1111111111111111 
b: 1111111 
s: 111111111111111 
*///:~ 








//: operators/URShift.java 
// Test of unsigned right shift. 
import static net.mindview.util.Print.*; 
public class URShift { 
 public static void main(String[] args) { 
 int i = -1; 
 print(Integer.toBinaryString(i)); 
 i >>>= 10; 
 print(Integer.toBinaryString(i)); 
 long l = -1; 
 print(Long.toBinaryString(l)); 
 l >>>= 10; 
 print(Long.toBinaryString(l)); 
 short s = -1; 
 print(Integer.toBinaryString(s)); 
 s >>>= 10; 
 print(Integer.toBinaryString(s)); 
 byte b = -1; 
 print(Integer.toBinaryString(b)); 
 b >>>= 10; 
 print(Integer.toBinaryString(b)); 
 b = -1; 
 print(Integer.toBinaryString(b)); 
 print(Integer.toBinaryString(b>>>10)); 
 } 
} /* Output: 
11111111111111111111111111111111 
1111111111111111111111 
1111111111111111111111111111111111111111111111111111111111111111 
111111111111111111111111111111111111111111111111111111 
11111111111111111111111111111111 
11111111111111111111111111111111 
11111111111111111111111111111111 
11111111111111111111111111111111 
11111111111111111111111111111111 
1111111111111111111111 
*///:~




//: operators/BitManipulation.java 
// Using the bitwise operators. 
import java.util.*; 
import static net.mindview.util.Print.*; 
public class BitManipulation { 
 public static void main(String[] args) { 
 Random rand = new Random(47); 
 int i = rand.nextInt(); 
 int j = rand.nextInt(); 
 printBinaryInt("-1", -1); 
 printBinaryInt("+1", +1); 
 int maxpos = 2147483647; 
 printBinaryInt("maxpos", maxpos); 
 int maxneg = -2147483648; 
 printBinaryInt("maxneg", maxneg); 
 printBinaryInt("i", i); 
 printBinaryInt("~i", ~i); 
Operators 77 printBinaryInt("-i", -i); 
 printBinaryInt("j", j); 
 printBinaryInt("i & j", i & j); 
 printBinaryInt("i | j", i | j); 
 printBinaryInt("i ^ j", i ^ j); 
 printBinaryInt("i << 5", i << 5); 
 printBinaryInt("i >> 5", i >> 5); 
 printBinaryInt("(~i) >> 5", (~i) >> 5); 
 printBinaryInt("i >>> 5", i >>> 5); 
 printBinaryInt("(~i) >>> 5", (~i) >>> 5); 
 long l = rand.nextLong(); 
 long m = rand.nextLong(); 
 printBinaryLong("-1L", -1L); 
 printBinaryLong("+1L", +1L); 
 long ll = 9223372036854775807L; 
 printBinaryLong("maxpos", ll); 
 long lln = -9223372036854775808L; 
 printBinaryLong("maxneg", lln); 
 printBinaryLong("l", l); 
 printBinaryLong("~l", ~l); 
 printBinaryLong("-l", -l); 
 printBinaryLong("m", m); 
 printBinaryLong("l & m", l & m); 
 printBinaryLong("l | m", l | m); 
 printBinaryLong("l ^ m", l ^ m); 
 printBinaryLong("l << 5", l << 5); 
 printBinaryLong("l >> 5", l >> 5); 
 printBinaryLong("(~l) >> 5", (~l) >> 5); 
 printBinaryLong("l >>> 5", l >>> 5); 
 printBinaryLong("(~l) >>> 5", (~l) >>> 5); 
 } 
 static void printBinaryInt(String s, int i) { 
 print(s + ", int: " + i + ", binary:\n " + 
 Integer.toBinaryString(i)); 
 } 
 static void printBinaryLong(String s, long l) { 
 print(s + ", long: " + l + ", binary:\n " + 
 Long.toBinaryString(l)); 
 } 
} /* Output: 
-1, int: -1, binary: 
 11111111111111111111111111111111 
+1, int: 1, binary: 
 1 
maxpos, int: 2147483647, binary: 
 1111111111111111111111111111111 
maxneg, int: -2147483648, binary: 
 10000000000000000000000000000000 
i, int: -1172028779, binary: 
 10111010001001000100001010010101 
~i, int: 1172028778, binary: 
 1000101110110111011110101101010 
-i, int: 1172028779, binary: 
 1000101110110111011110101101011 
j, int: 1717241110, binary: 
 1100110010110110000010100010110 
i & j, int: 570425364, binary: 
 100010000000000000000000010100 
i | j, int: -25213033, binary: 
 11111110011111110100011110010111 
i ^ j, int: -595638397, binary: 
 11011100011111110100011110000011 
78 Thinking in Java Bruce Eckeli << 5, int: 1149784736, binary: 
 1000100100010000101001010100000 
i >> 5, int: -36625900, binary: 
 11111101110100010010001000010100 
(~i) >> 5, int: 36625899, binary: 
 10001011101101110111101011 
i >>> 5, int: 97591828, binary: 
 101110100010010001000010100 
(~i) >>> 5, int: 36625899, binary: 
 10001011101101110111101011 
... 
*///:~



//: operators/TernaryIfElse.java 
Operators 79import static net.mindview.util.Print.*; 
public class TernaryIfElse { 
 static int ternary(int i) { 
 return i < 10 ? i * 100 : i * 10; 
 } 
 static int standardIfElse(int i) { 
 if(i < 10) 
 return i * 100; 
 else 
 return i * 10; 
 } 
 public static void main(String[] args) { 
 print(ternary(9)); 
 print(ternary(10)); 
 print(standardIfElse(9)); 
 print(standardIfElse(10)); 
 } 
} /* Output: 
900 
100 
900 
100 
*///:~ 




//: operators/StringOperators.java 
import static net.mindview.util.Print.*; 
public class StringOperators { 
 public static void main(String[] args) { 
 int x = 0, y = 1, z = 2; 
 String s = "x, y, z "; 
 print(s + x + y + z); 
 print(x + " " + s); // Converts x to a String 
80 Thinking in Java Bruce Eckel s += "(summed) = "; // Concatenation operator 
 print(s + (x + y + z)); 
 print("" + x); // Shorthand for Integer.toString() 
 } 
} /* Output: 
x, y, z 012 
0 x, y, z 
x, y, z (summed) = 3 
0 
*///:~ 
Note that the output from the first print statement is ‘o12’ instead of just ‘3’, which is what 
you’d get if it was summing the integers. This is because the Java compiler converts x, y, and 
z into t



//: operators/Casting.java 
public class Casting { 
 public static void main(String[] args) { 
 int i = 200; 
 long lng = (long)i; 
 lng = i; // "Widening," so cast not really required 
 long lng2 = (long)200; 
 lng2 = 200; 
 // A "narrowing conversion": 
 i = (int)lng2; // Cast required 
 } 
} ///:~ 
As you can see, it’s


//: operators/CastingNumbers.java 
// What happens when you cast a float 
// or double to an integral value? 
import static net.mindview.util.Print.*; 
public class CastingNumbers { 
 public static void main(String[] args) { 
 double above = 0.7, below = 0.4; 
 float fabove = 0.7f, fbelow = 0.4f; 
 print("(int)above: " + (int)above); 
 print("(int)below: " + (int)below); 
 print("(int)fabove: " + (int)fabove); 
82 Thinking in Java Bruce Eckel print("(int)fbelow: " + (int)fbelow); 
 } 
} /* Output: 
(int)above: 0 
(int)below: 0 
(int)fabove: 0 
(int)fbelow: 0 
*///:~


//: operators/RoundingNumbers.java 
// Rounding floats and doubles. 
import static net.mindview.util.Print.*; 
public class RoundingNumbers { 
 public static void main(String[] args) { 
 double above = 0.7, below = 0.4; 
 float fabove = 0.7f, fbelow = 0.4f; 
 print("Math.round(above): " + Math.round(above)); 
 print("Math.round(below): " + Math.round(below)); 
 print("Math.round(fabove): " + Math.round(fabove)); 
 print("Math.round(fbelow): " + Math.round(fbelow)); 
 } 
} /* Output: 
Math.round(above): 1 
Math.round(below): 0 
Math.round(fabove): 1 
Math.round(fbelow): 0 
*///:~ 

//: operators/Overflow.java 
// Surprise! Java lets you overflow. 
public class Overflow { 
 public static void main(String[] args) { 
90 Thinking in Java Bruce EckelOperators 91
 int big = Integer.MAX_VALUE; 
 System.out.println("big = " + big); 
 int bigger = big * 4; 
 System.out.println("bigger = " + bigger); 
 } 
} /* Output: 
big = 2147483647 
bigger = -4
*///:~ 
