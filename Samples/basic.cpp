/*
Basic GLS Syntax
Version 0.0.1
Josh Goldberg
*/

// Basic Usage
cout("Hello world!"); // Basic printing here...

// Variables
string a = "Hello world!";
int b = 7;
double c = 11.7;
boolean d = true;

// Operations
int e = 1 + 2;
boolean f = b < c;

// If Statements
if (d) {
    cout("d is true!");
}
if (c < 14) {
    cout("c is less than 14!");
}

// While Loops
while (d) {
    cout("d is", d);
    d = false
}
while (c > 3) {
    cout("c is", c);
    c -= 1
}

// For Loops
for (int i = 0; i < 7; i += 1) {
    cout("i plus one is", i + 1);
}

// Function Definitions
 sayHello() {
    cout("Hello world!");
}
 combineStrings(string a, string b) {
    return a + b;
}

// Calling Functions
sayHello();
combineStrings("hello", "world");
combineStrings("hello" + " ", "world");
combineStrings(combineStrings("hello", "world"), "world");

// Class Declarations
class Point {
    public int x;
    public int y;
    
    (int x, int y) {
        this.x = x;
        this.y = y;
    }
    
    public setX(int x) {
        this.x = x;
    }
    
    public setY(int y) {
        this.y = y;
    }
    
    public getX() {
        return this.x;
    }
    
    public getY() {
        return this.y;
    }
    
    public getManhattanTotal() {
        return this.x + this.y;
    }
};

// Class Usage
Point g = new Point(3, 7);
g.setX(4)
cout(g.getManhattanTotal());

// fin
