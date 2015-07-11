/*
Basic GLS Syntax
Version 0.0.1
Josh Goldberg
*/

// Basic Usage
cout("Hello world!"); // Basic printing here...

// Variables
stringa = "Hello world!";
intb = 7;
doublec = 11.7;
booleand = true;

// Operations
inte = 1 + 2;
booleanf = b < c;

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
for (inti = 0; i < 7; i += 1) {
    cout("i plus one is", i + 1);
}

// Function Definitions
 sayHello() {
    cout("Hello world!");
}
 combineStrings(stringa, stringb) {
    return a + b;
}

// Calling Functions
sayHello();
combineStrings("hello", "world");
combineStrings("hello" + " ", "world");
combineStrings(combineStrings("hello", "world"), "world");

// Class Declarations
class Point {
    public intx;
    public inty;
    
    (intx, inty) {
        this.x = x;
        this.y = y;
    }
    
    public setX(intx) {
        this.x = x;
    }
    
    public setY(inty) {
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
}

// Class Usage
Pointg = new Point(3, 7);
g.setX(4)
cout(g.getManhattanTotal());

// fin
