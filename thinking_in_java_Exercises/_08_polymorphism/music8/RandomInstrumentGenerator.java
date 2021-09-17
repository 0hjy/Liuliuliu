// polymorphism/music8/Music8.java
// TIJ4 Chapter Polymorphism, Exercise 8, page 289
/* Modify Music3.java so that it randomly creates Instrument objects the way
* Shapes.java does.
*/
//Solution includes, in same package:
import java.util.*;
public class RandomInstrumentGenerator {
	private Random rand = new Random();
	public Instrument next() {
		switch(rand.nextInt(7)) {
			default:
			case 0: return new Wind();
			case 1: return new Percussion();
			case 2: return new Stringed();
			case 3: return new Keyboard();
			case 4: return new Brass();
			case 5: return new Woodwind();
			case 6: return new Piano();
		}
	}
}
