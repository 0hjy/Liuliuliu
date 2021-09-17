//: operators/HelloDate.java 
//pdf 71    page 93
//1.使用导入的新类库，java5加的static import
import java.util.*; 
import static net.mindview.util.Print.*; //2.需要下载代码包，并配置classpath
public class HelloDate { 
 public static void main(String[] args) { 
 print("Hello, it’s: "); 
 print(new Date()); 
 //3.print可以简化代码，但是少量输出的话还是用system.out.println
 } 
} /* Output: (55% match) 
Hello, it’s: 
Wed Oct 05 14:39:05 MDT 2005 
*///:~









