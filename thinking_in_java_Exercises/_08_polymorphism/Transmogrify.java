//: polymorphism/Transmogrify.java 
// Dynamically changing the behavior of an object 
// via composition (the "State" design pattern). 
import static net.mindview.util.Print.*; 
//pdf   198     eage    304

//通过继承来表达两个类的差异，
//sage通过组合来表达状态的变化（创造一个方法来实现引用转变，而不是再次使用继承来更换状态）

class Actor { 
 public void act() {} 
} 

class HappyActor extends Actor { 
 public void act() { print("HappyActor"); } 
} 

class SadActor extends Actor { 
 public void act() { print("SadActor"); } 
} 

class Stage { 
 private Actor actor = new HappyActor(); 
 public void change() { actor = new SadActor(); }    //把actor引用的对象转换为 SadActor
 public void performPlay() { actor.act(); } 
} 


public class Transmogrify { 
 public static void main(String[] args) { 
 Stage stage = new Stage(); 
 stage.performPlay(); 
 stage.change(); 
 stage.performPlay(); 
 } 
} /* Output: 
HappyActor 
SadActor 
*///:~ 

//把引用在运行时进行了替换，状态也就随之改变。
//我们在运行期间获得了动态灵活性，（也称为状态模式）
/*
我们可以设计在运行时改变状态，只能在编译期间确定对象。
 Thus you gain dynamic flexibility at run time. 
(This is also called the State Pattern.
 See Thinking in Patterns (with Java) at www.MindView.com.) In contrast, you can’t decide
*/
/*
A general guideline is “Use inheritance to express differences in behavior, and fields to 
express variations in state.” In the preceding example, both are used; two different classes 
are inherited to express the difference in the act( ) method, and Stage uses composition to 
allow its state to be changed. In this case, that change in state happens to produce a change 
in behavior.
*/