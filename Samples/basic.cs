/*
Basic GLS Syntax
Version 0.0.1
Josh Goldberg
*/
Function not found: file start
public static void Main() {
    // Basic Usage
    System.Console.WriteLine("Hello world!"); // Basic printing here...
    
    // Variables
    string a = "Hello world!";
    int b = 7;
    double c = 11.7;
    bool d = true;
    
    // Operations
    int e = 1 + 2;
    bool f = b < c;
    
    // If Statements
    if (d) {
        System.Console.WriteLine("d is true!");
    }
    if (c < 14) {
        System.Console.WriteLine("c is less than 14!");
    }
    
    // While Loops
    while (d) {
        System.Console.WriteLine("d is", d);
        d = false
    }
    while (c > 3) {
        System.Console.WriteLine("c is", c);
        c -= 1
    }
    
    // For Loops
    for (int i = 0; i < 7; i += 1) {
        System.Console.WriteLine("i plus one is", i + 1);
    }
    
    // Calling Functions
    sayHello();
    combineStrings("hello", "world");
    combineStrings("hello" + " ", "world");
    combineStrings(combineStrings("hello", "world"), "world");
    
    // Class Usage
    Point g = new Point(3, 7);
    g.setX(4)
    System.Console.WriteLine(g.getManhattanTotal());
}

// Function Definitions
void sayHello() {
    System.Console.WriteLine("Hello world!");
}
string combineStrings(string a, string b) {
    return a + b;
}

// Class Declarations
class Point {
    public int x;
    public int y;
    
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
    
    public void setX(int x) {
        this.x = x;
    }
    
    public void setY(int y) {
        this.y = y;
    }
    
    public int getX() {
        return this.x;
    }
    
    public int getY() {
        return this.y;
    }
    
    public int getManhattanTotal() {
        return this.x + this.y;
    }
};
Function not found: file end

// fin
