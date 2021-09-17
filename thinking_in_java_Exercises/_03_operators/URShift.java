//: operators/URShift.java 
//pdf 83
//page 113
//位移操作
//对byte和short进行位移操作，会先被转化为int，再右移，然后被截断赋值给原来的类型。
//会得到错误的结果
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
 byte b = -1;   //---------------------变为short增加长度，再变回来截取长度，失去了位运算的效果
 print(Integer.toBinaryString(b)); 
 b >>>= 10; 
 print(Integer.toBinaryString(b)); 
 
 b = -1; //----------------------------
 print(Integer.toBinaryString(b)); 
 print(Integer.toBinaryString(b>>>10)); //---没有，正确输出
 } 
} /* Output: 
11111111111111111111111111111111 
1111111111111111111111 
1111111111111111111111111111111111111111111111111111111111111111 
111111111111111111111111111111111111111111111111111111 
11111111111111111111111111111111        ////--变为short增加长度，再变回来截取长度，失去了位运算的效果
11111111111111111111111111111111        //
11111111111111111111111111111111        //
11111111111111111111111111111111        //
11111111111111111111111111111111 
1111111111111111111111                  //
*///:~

