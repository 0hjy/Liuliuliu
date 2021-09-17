//: polymorphism/PolyConstructors.java 
// Constructors and polymorphism 
// don’t produce what you might expect. 


import static net.mindview.util.Print.*; 
class Glyph { 
//在父类构造器中calls了自己的普通方法（动态绑定方法），造成的问题。
    void draw() { print("Glyph.draw()"); } 
 
    Glyph() { 
        print("Glyph() before draw()"); 
        draw(); 
        print("Glyph() after draw()"); 
    } 
} 

class RoundGlyph extends Glyph { 
    private int radius = 1; 

    RoundGlyph(int r) { 
        radius = r; 
        print("RoundGlyph.RoundGlyph(), radius = " + radius); 
    } 

    void draw() { 
        print("RoundGlyph.draw(), radius = " + radius); 
    } 
} 

public class PolyConstructors { 
    public static void main(String[] args) { 
        new RoundGlyph(5); 
    } 
} 

/* Output: 
Glyph() before draw()       ////结果先执行父类的构造，和父类构造中的父类方法，
RoundGlyph.draw(), radius = 0 //？？？？？？？？？
Glyph() after draw()            //
RoundGlyph.RoundGlyph(), radius = 5 //最后执行子类的构造器中的方法
*///:~

//As a result, a good guideline for constructors is, 
//编写构造器的一条准则
// “Do as little as possible to set the object into a good state, 
// and if you can possibly avoid it, don’t call any other methods in this class.” 
//尽可能的用少的东西来设置构造，尽可能避免调用其他方法。
// The only safe methods to call inside a constructor are those that are final in the base class.
//  (This also applies to private methods, which are automatically final.) 
//  These cannot be overridden and thus cannot produce this kind of surprise.
//唯一安全的方法就是只在构造中调final方法和 private方法。 
//  You may not always be able to follow this guideline,
//   but it’s something to strive towards


