//pdf   194     page   298
//: polymorphism/ReferenceCounting.java 
// Cleaning up shared member objects. 
//引用对象作为参数来创建另一个对象后，对于新建对象的清理需要 addref跟踪参数对象的引用计数， 
//在外层dispare方法 ，中使用这个计数器来决定是否清理内层对象。 
import static net.mindview.util.Print.*; 
//
class Shared { 
    private int refcount = 0; 
    private static long counter = 0;  
    private final long id = counter++; //实例化计数
    public Shared() { 
    print("Creating " + this); 
    } 
    public void addRef() { refcount++; }  //引用计数？？？？用于清理时判定是否实施清理
    protected void dispose() { 
    if(--refcount == 0) 
    print("Disposing " + this); //清理计数
    } 
 public String toString() { return "Shared " + id; } 
} 

//
class Composing { 
 private Shared shared; 
 private static long counter = 0; 
 private final long id = counter++; //实例化计数
 public Composing(Shared shared) { 
 print("Creating " + this); 
 this.shared = shared; 
 this.shared.addRef(); //
 } 
 protected void dispose() { 
 print("disposing " + this); 
 shared.dispose(); 
 } 
 public String toString() { return "Composing " + id; } 
} 


public class ReferenceCounting { 
    public static void main(String[] args) { 
    Shared shared = new Shared();  
    Composing[] composing = { new Composing(shared), 
    new Composing(shared), new Composing(shared), 
    new Composing(shared), new Composing(shared) }; 
    
    for(Composing c : composing)   //for循环清理 
        c.dispose(); 
     } 
} /* Output: 
Creating Shared 0 
Creating Composing 0 
Creating Composing 1 
Creating Composing 2 
Creating Composing 3 
Creating Composing 4 
disposing Composing 0 
disposing Composing 1 
disposing Composing 2 
disposing Composing 3 
disposing Composing 4 
Disposing Shared 0 
*///:~ 