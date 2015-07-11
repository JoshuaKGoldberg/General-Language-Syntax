/*
Basic GLS Syntax
Version 0.0.1
Josh Goldberg
*/
// Basic Usage
console.log("Hello world!"); // Basic printing here...
// Variables
var a = "Hello world!";
var b = 7;
var c = 11.7;
var d = true;
// Operations
var e = 1 + 2;
var f = b < c;
// If Statements
if (d) {
    console.log("d is true!");
}
if (c < 14) {
    console.log("c is less than 14!");
}
while (d) {
    console.log("d is", d);
    d = false;
}
while (c > 3) {
    console.log("c is", c);
    c -= 1;
}
for (var i = 0; i < 7; i += 1) {
    console.log("i plus one is", i + 1);
}
// Function Definitions
function sayHello() {
    console.log("Hello world!");
}
function combineStrings(a, b) {
    return a + b;
}
// Calling Functions
sayHello();
combineStrings("hello", "world");
combineStrings("hello" + " ", "world");
combineStrings(combineStrings("hello", "world"), "world");
// Class Declarations
var Point = (function () {
    function Point(x, y) {
        this.x = x;
        this.y = y;
    }
    Point.prototype.setX = function (x) {
        this.x = x;
    };
    Point.prototype.setY = function (y) {
        this.y = y;
    };
    Point.prototype.getX = function () {
        return this.x;
    };
    Point.prototype.getY = function () {
        return this.y;
    };
    Point.prototype.getManhattanTotal = function () {
        return this.x + this.y;
    };
    return Point;
})();
// Class Usage
var g = new Point(3, 7);
e(setX, 4);
console.log(e(getManhattanTotal));
// fin
