 //Solution includes, in package interfaces.ex6:
package interfaces.ex6;
interface Ex6 {
void sayOne();
void sayTwo();
void sayThree();
}

public class Ex6b implements Ex6 {
// Error: cannot assign weaker access to public methods:
// void sayOne() { System.out.println("one"); } // implies package *							// access
// protected void sayTwo() { System.out.println("two"); }
// private void sayThree() { System.out.println("three"); }
// must be maintained public:
public void sayOne() { System.out.println("one"); }
public void sayTwo() { System.out.println("two"); }
public void sayThree() { System.out.println("three"); }
} 
