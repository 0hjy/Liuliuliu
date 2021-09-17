//: operators/AllOps.java 
// Tests all the operators on all the primitive data types 
// to show which ones are accepted by the Java compiler. 
public class AllOps { 
 // To accept the results of a boolean test: 
 void f(boolean b) {} 
 void boolTest(boolean x, boolean y) { 
 // Arithmetic operators: 
 //! x = x * y; 
 //! x = x / y; 
 //! x = x % y; 
 //! x = x + y; 
 //! x = x - y; 
 //! x++; 
 //! x--; 
 //! x = +y; 
 //! x = -y; 
 // Relational and logical: 
 //! f(x > y); 
 //! f(x >= y); 
 //! f(x < y); 
 //! f(x <= y); 
 f(x == y); 
 f(x != y); 
 f(!y); 
 x = x && y; 
 x = x || y; 
 // Bitwise operators: 
 //! x = ~y; 
 x = x & y; 
 x = x | y; 
 x = x ^ y; 
 //! x = x << 1; 
 //! x = x >> 1; 
 //! x = x >>> 1; 
 // Compound assignment: 
 //! x += y; 
 //! x -= y; 
 //! x *= y; 
 //! x /= y; 
 //! x %= y; 
 //! x <<= 1; 
 //! x >>= 1; 
 //! x >>>= 1; 
 x &= y; 
 x ^= y; 
 x |= y; 
 // Casting: 
84 Thinking in Java Bruce Eckel //! char c = (char)x; 
 //! byte b = (byte)x; 
 //! short s = (short)x; 
 //! int i = (int)x; 
 //! long l = (long)x; 
 //! float f = (float)x; 
 //! double d = (double)x; 
 } 
 void charTest(char x, char y) { 
 // Arithmetic operators: 
 x = (char)(x * y); 
 x = (char)(x / y); 
 x = (char)(x % y); 
 x = (char)(x + y); 
 x = (char)(x - y); 
 x++; 
 x--; 
 x = (char)+y; 
 x = (char)-y; 
 // Relational and logical: 
 f(x > y); 
 f(x >= y); 
 f(x < y); 
 f(x <= y); 
 f(x == y); 
 f(x != y); 
 //! f(!x); 
 //! f(x && y); 
 //! f(x || y); 
 // Bitwise operators: 
 x= (char)~y; 
 x = (char)(x & y); 
 x = (char)(x | y); 
 x = (char)(x ^ y); 
 x = (char)(x << 1); 
 x = (char)(x >> 1); 
 x = (char)(x >>> 1); 
 // Compound assignment: 
 x += y; 
 x -= y; 
 x *= y; 
 x /= y; 
 x %= y; 
 x <<= 1; 
 x >>= 1; 
 x >>>= 1; 
 x &= y; 
 x ^= y; 
 x |= y; 
 // Casting: 
 //! boolean bl = (boolean)x; 
 byte b = (byte)x; 
 short s = (short)x; 
 int i = (int)x; 
 long l = (long)x; 
 float f = (float)x; 
 double d = (double)x; 
 } 
 void byteTest(byte x, byte y) { 
 // Arithmetic operators: 
 x = (byte)(x* y); 
 x = (byte)(x / y); 
 x = (byte)(x % y); 
Operators 85 x = (byte)(x + y); 
 x = (byte)(x - y); 
 x++; 
 x--; 
 x = (byte)+ y; 
 x = (byte)- y; 
 // Relational and logical: 
 f(x > y); 
 f(x >= y); 
 f(x < y); 
 f(x <= y); 
 f(x == y); 
 f(x != y); 
 //! f(!x); 
 //! f(x && y); 
 //! f(x || y); 
 // Bitwise operators: 
 x = (byte)~y; 
 x = (byte)(x & y); 
 x = (byte)(x | y); 
 x = (byte)(x ^ y); 
 x = (byte)(x << 1); 
 x = (byte)(x >> 1); 
 x = (byte)(x >>> 1); 
 // Compound assignment: 
 x += y; 
 x -= y; 
 x *= y; 
 x /= y; 
 x %= y; 
 x <<= 1; 
 x >>= 1; 
 x >>>= 1; 
 x &= y; 
 x ^= y; 
 x |= y; 
 // Casting: 
 //! boolean bl = (boolean)x; 
 char c = (char)x; 
 short s = (short)x; 
 int i = (int)x; 
 long l = (long)x; 
 float f = (float)x; 
 double d = (double)x; 
 } 
 void shortTest(short x, short y) { 
 // Arithmetic operators: 
 x = (short)(x * y); 
 x = (short)(x / y); 
 x = (short)(x % y); 
 x = (short)(x + y); 
 x = (short)(x - y); 
 x++; 
 x--; 
 x = (short)+y; 
 x = (short)-y; 
 // Relational and logical: 
 f(x > y); 
 f(x >= y); 
 f(x < y); 
 f(x <= y); 
 f(x == y); 
 f(x != y); 
86 Thinking in Java Bruce Eckel //! f(!x); 
 //! f(x && y); 
 //! f(x || y); 
 // Bitwise operators: 
 x = (short)~y; 
 x = (short)(x & y); 
 x = (short)(x | y); 
 x = (short)(x ^ y); 
 x = (short)(x << 1); 
 x = (short)(x >> 1); 
 x = (short)(x >>> 1); 
 // Compound assignment: 
 x += y; 
 x -= y; 
 x *= y; 
 x /= y; 
 x %= y; 
 x <<= 1; 
 x >>= 1; 
 x >>>= 1; 
 x &= y; 
 x ^= y; 
 x |= y; 
 // Casting: 
 //! boolean bl = (boolean)x; 
 char c = (char)x; 
 byte b = (byte)x; 
 int i = (int)x; 
 long l = (long)x; 
 float f = (float)x; 
 double d = (double)x; 
 } 
 void intTest(int x, int y) { 
 // Arithmetic operators: 
 x = x * y; 
 x = x / y; 
 x = x % y; 
 x = x + y; 
 x = x - y; 
 x++; 
 x--; 
 x = +y; 
 x = -y; 
 // Relational and logical: 
 f(x > y); 
 f(x >= y); 
 f(x < y); 
 f(x <= y); 
 f(x == y); 
 f(x != y); 
 //! f(!x); 
 //! f(x && y); 
 //! f(x || y); 
 // Bitwise operators: 
 x = ~y; 
 x = x & y; 
 x = x | y; 
 x = x ^ y; 
 x = x << 1; 
 x = x >> 1; 
 x = x >>> 1; 
 // Compound assignment: 
 x += y; 
Operators 87 x -= y; 
 x *= y; 
 x /= y; 
 x %= y; 
 x <<= 1; 
 x >>= 1; 
 x >>>= 1; 
 x &= y; 
 x ^= y; 
 x |= y; 
 // Casting: 
 //! boolean bl = (boolean)x; 
 char c = (char)x; 
 byte b = (byte)x; 
 short s = (short)x; 
 long l = (long)x; 
 float f = (float)x; 
 double d = (double)x; 
 } 
 void longTest(long x, long y) { 
 // Arithmetic operators: 
 x = x * y; 
 x = x / y; 
 x = x % y; 
 x = x + y; 
 x = x - y; 
 x++; 
 x--; 
 x = +y; 
 x = -y; 
 // Relational and logical: 
 f(x > y); 
 f(x >= y); 
 f(x < y); 
 f(x <= y); 
 f(x == y); 
 f(x != y); 
 //! f(!x); 
 //! f(x && y); 
 //! f(x || y); 
 // Bitwise operators: 
 x = ~y; 
 x = x & y; 
 x = x | y; 
 x = x ^ y; 
 x = x << 1; 
 x = x >> 1; 
 x = x >>> 1; 
 // Compound assignment: 
 x += y; 
 x -= y; 
 x *= y; 
 x /= y; 
 x %= y; 
 x <<= 1; 
 x >>= 1; 
 x >>>= 1; 
 x &= y; 
 x ^= y; 
 x |= y; 
 // Casting: 
 //! boolean bl = (boolean)x; 
 char c = (char)x; 
88 Thinking in Java Bruce Eckel byte b = (byte)x; 
 short s = (short)x; 
 int i = (int)x; 
 float f = (float)x; 
 double d = (double)x; 
 } 
 void floatTest(float x, float y) { 
 // Arithmetic operators: 
 x = x * y; 
 x = x / y; 
 x = x % y; 
 x = x + y; 
 x = x - y; 
 x++; 
 x--; 
 x = +y; 
 x = -y; 
 // Relational and logical: 
 f(x > y); 
 f(x >= y); 
 f(x < y); 
 f(x <= y); 
 f(x == y); 
 f(x != y); 
 //! f(!x); 
 //! f(x && y); 
 //! f(x || y); 
 // Bitwise operators: 
 //! x = ~y; 
 //! x = x & y; 
 //! x = x | y; 
 //! x = x ^ y; 
 //! x = x << 1; 
 //! x = x >> 1; 
 //! x = x >>> 1; 
 // Compound assignment: 
 x += y; 
 x -= y; 
 x *= y; 
 x /= y; 
 x %= y; 
 //! x <<= 1; 
 //! x >>= 1; 
 //! x >>>= 1; 
 //! x &= y; 
 //! x ^= y; 
 //! x |= y; 
 // Casting: 
 //! boolean bl = (boolean)x; 
 char c = (char)x; 
 byte b = (byte)x; 
 short s = (short)x; 
 int i = (int)x; 
 long l = (long)x; 
 double d = (double)x; 
 } 
 void doubleTest(double x, double y) { 
 // Arithmetic operators: 
 x = x * y; 
 x = x / y; 
 x = x % y; 
 x = x + y; 
 x = x - y; 
Operators 89 x++; 
 x--; 
 x = +y; 
 x = -y; 
 // Relational and logical: 
 f(x > y); 
 f(x >= y); 
 f(x < y); 
 f(x <= y); 
 f(x == y); 
 f(x != y); 
 //! f(!x); 
 //! f(x && y); 
 //! f(x || y); 
 // Bitwise operators: 
 //! x = ~y; 
 //! x = x & y; 
 //! x = x | y; 
 //! x = x ^ y; 
 //! x = x << 1; 
 //! x = x >> 1; 
 //! x = x >>> 1; 
 // Compound assignment: 
 x += y; 
 x -= y; 
 x *= y; 
 x /= y; 
 x %= y; 
 //! x <<= 1; 
 //! x >>= 1; 
 //! x >>>= 1; 
 //! x &= y; 
 //! x ^= y; 
 //! x |= y; 
 // Casting: 
 //! boolean bl = (boolean)x; 
 char c = (char)x; 
 byte b = (byte)x; 
 short s = (short)x; 
 int i = (int)x; 
 long l = (long)x; 
 float f = (float)x; 
 } 
} ///:~ 
Note that boolean is quite limited. You can assign to it the values true and false, and you 
can test it for truth or falsehood, but you cannot add booleans or perform any other type of 
operation on them. 
In char, byte, and short, you can see the effect of promotion with the arithmetic operators. 
Each arithmetic operation on any of those types produces an int result, which must be 
explicitly cast back to the original type (a narrowing conversion that might lose information) 
to assign back to that type. With int values, however, you do not need to cast, because 
everything is already an int. Don’t be lulled into thinking everything is safe, though. If you 
multiply two ints that are big enough, you’ll overflow the result. The following example 
demonstrates this: 
//: operators/Overflow.java 
// Surprise! Java lets you overflow. 
public class Overflow { 
 public static