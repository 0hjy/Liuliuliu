//* Solution includes, in package polymorphism.shape: 
 import static net.mindview.util.Print.*;
 public class Circle extends Shape {
   @Override public void draw() { print("Circle.draw()"); }
   @Override public void erase() { print("Circle.erase()"); }
   //shape3添加
   @Override public void amend() { print("Circle.amend()"); }

 }
