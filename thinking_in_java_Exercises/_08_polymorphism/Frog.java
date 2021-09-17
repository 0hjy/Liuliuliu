//pdf   192 page   295

//: polymorphism/Frog.java 
// Cleanup and inheritance. 
//通过组合和继承的方式来创建新类，子类对象的清理dispare需要特殊动作，覆盖了父类。
//父类需要嗲用
package polymorphism; 
import static net.mindview.util.Print.*; 
class Characteristic { //特征class
 private String s; 
 Characteristic(String s) { 
 this.s = s; 
 print("Creating Characteristic " + s); 
 } 
 protected void dispose() { //清理method
 print("disposing Characteristic " + s); 
 } 
} 
class Description { //描述class
 private String s; 
 Description(String s) { 
 this.s = s; 
 print("Creating Description " + s); 
 } 
 protected void dispose() { 
 print("disposing Description " + s); 
 } 
} 
class LivingCreature { //生物class
    //对象的组合
 private Characteristic p =  new Characteristic("is alive"); 
 private Description t =  new Description("Basic Living Creature"); 
 LivingCreature() { 
 print("LivingCreature()"); 
 } 
 protected void dispose() { 
 print("LivingCreature dispose"); 
 t.dispose(); 
 p.dispose(); 
 } 
} 

class Animal extends LivingCreature { 
 private Characteristic p =  new Characteristic("has heart"); 
 private Description t =  new Description("Animal not Vegetable"); 
 
 Animal() { print("Animal()"); } 
 protected void dispose() { 
 print("Animal dispose"); 
 t.dispose(); //1.分别调用 清理method
 p.dispose(); //2.the derived-class cleanup first
 super.dispose();//3. 先子类后父类
 } 
} 

class Amphibian extends Animal { 
 private Characteristic p =  new Characteristic("can live in water"); 
 private Description t =  new Description("Both water and land"); 
 
 Amphibian() { 
 print("Amphibian()"); 
 } 
 protected void dispose() { 
 print("Amphibian dispose"); 
 t.dispose(); 
 p.dispose(); 
 super.dispose(); 
 //That’s because the derived-class cleanup could 
 //call some methods in the base class that require the base-class components to be alive, 
//so you must not destroy them prematurely.
// From the output you can see 
 //that all parts of the Frog object are disposed in reverse order of creation. 
 } 
} 


//From the output you can see that all parts of the Frog object 
//are disposed in reverse order of creation. 

//From this example, you can see that although you don’t always need to perform cleanup, 
//when you do, the process requires care and awareness.
public class Frog extends Amphibian { 
    private Characteristic p = new Characteristic("Croaks"); 
    private Description t = new Description("Eats Bugs"); 
    public Frog() { print("Frog()"); } 
    protected void dispose() { //覆写父类方法
        print("Frog dispose"); 
        t.dispose(); 
        p.dispose(); 
        super.dispose(); 
    } 
    public static void main(String[] args) { 
        Frog frog = new Frog(); //属于自己的成员对象
        print("Bye!"); 
        frog.dispose(); 
 } 
} /* Output: 
Creating Characteristic is alive 
Creating Description Basic Living Creature 
Polymorphism 207LivingCreature() 
Creating Characteristic has heart 
Creating Description Animal not Vegetable 
Animal() 
Creating Characteristic can live in water 
Creating Description Both water and land 
Amphibian() 
Creating Characteristic Croaks 
Creating Description Eats Bugs 
Frog() 
Bye! 
Frog dispose 
disposing Description Eats Bugs 
disposing Characteristic Croaks 
Amphibian dispose 
disposing Description Both water and land 
disposing Characteristic can live in water 
Animal dispose 
disposing Description Animal not Vegetable 
disposing Characteristic has heart 
LivingCreature dispose 
disposing Description Basic Living Creature 
disposing Characteristic is alive 
*///:~

