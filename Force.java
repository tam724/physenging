package force;
import java.util.*;

public class Force {
	// Initialisierung der Variablen
	private double x1;
	private double x2;
	private double x3;
	private double length;
	private boolean isLengthSet;

	boolean unterbestimmt = true;
	boolean definiert = false;

	// Checks if Vector of Force has no value
	// returns false if Vector has Values
	// returns true if Vector is 0
	boolean isNull() {
		if (getX1() == 0 && x2 == 0 && x3 == 0) {
			return true;
		} else {
			return false;
		}
	}

	public String toString() {
		return "(" + x1 + "; " + x2 + "; " + x3 + ")";
	}

	// Rechnen mit den Vektoren
	Force add(Force a) {
		Force b = new Force();
		b.x1 = a.x1 + this.x1;
		b.x2 = a.x2 + this.x2;
		b.x3 = a.x3 + this.x3;
		return b;
	}

	// Setter und Getter
	public double getX1() {
		return x1;
	}
	
	public double getA1() {
		if (isLengthSet) {
			return java.lang.Math.asin(x1/length);
		}
		else {
			System.out.println("Keine Länge gesetzt! Länge setzten:");
			Scanner scanner = new Scanner(System.in);
			this.setLength(scanner.nextDouble());
			scanner.close();
			return java.lang.Math.asin(x1/length);
		}
	}

	public void setX1(double x1) {
		this.x1 = x1;
	}

	public void setX1(double a, double length) {
		if (isLengthSet) {
			if (this.length == length) { // alright!
				this.x1 = length * java.lang.Math.sin(a);
			} else {
				System.out.println("lengths differ! x not set!"); // lengths
																	// differ
			}
		} else { // saving length in variable and alright!
			this.length = length;
			this.x1 = length * java.lang.Math.sin(a);
		}
	}

	public double getX2() {
		return x2;
	}
	
	public double getA2() {
		if (isLengthSet) {
			return java.lang.Math.asin(x2/length);
		}
		else {
			System.out.println("Keine Länge gesetzt! Länge setzten:");
			Scanner scanner = new Scanner(System.in);
			this.setLength(scanner.nextDouble());
			scanner.close();
			return java.lang.Math.asin(x2/length);
		}
	}

	public void setX2(double x2) {
		this.x2 = x2;
	}

	public void setX2(double a, double length) {
		if (isLengthSet) {
			if (this.length == length) { // alright!
				this.x2 = length * java.lang.Math.sin(a);
			} else {
				System.out.println("lengths differ! x not set!"); // lengths
																	// differ
			}
		} else { // saving length in variable and alright!
			this.length = length;
			this.x2 = length * java.lang.Math.sin(a);
		}
	}

	public double getX3() {
		return x3;
	}
	
	public double getA3() {
		if (isLengthSet) {
			return java.lang.Math.asin(x3/length);
		}
		else {
			System.out.println("Keine Länge gesetzt! Länge setzten:");
			Scanner scanner = new Scanner(System.in);
			this.setLength(scanner.nextDouble());
			scanner.close();
			return java.lang.Math.asin(x3/length);
		}
	}

	public void setX3(double x3) {
		this.x3 = x3;
	}

	public void setX3(double a, double length) {
		if (isLengthSet) {
			if (this.length == length) { // alright!
				this.x3 = length * java.lang.Math.sin(a);
			} else {
				System.out.println("lengths differ! x not set!"); // lengths
																	// differ
			}
		} else { // saving length in variable and alright!
			this.length = length;
			this.x3 = length * java.lang.Math.sin(a);
		}
	}

	public void setX(double x1, double x2, double x3) {
		this.x1 = x1;
		this.x2 = x2;
		this.x3 = x3;
	}
	
	public void setLength(double length) {
		this.length = length;
		isLengthSet= true;
	}
}
