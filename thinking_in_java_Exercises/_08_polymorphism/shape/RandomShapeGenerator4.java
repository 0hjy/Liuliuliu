//shape4添加
import java.util.*;
public class RandomShapeGenerator4 {
private Random rand = new Random();
public Shape next() {
	switch(rand.nextInt(4)) {
		default:
		case 0: return new Circle();
		case 1: return new Square();
		case 2: return new Triangle();
		//新增 
		case 3: return new Rectangle();
	}
}
}
