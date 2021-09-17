 // and:
 import static net.mindview.util.Print.*;
 public class Square extends Shape {
   @Override public void draw() { print("Square.draw()"); }
   @Override public void erase() { print("Square.erase()"); }
   //shape3添加
  @Override public void amend() { print("Square.amend()"); }

 }
