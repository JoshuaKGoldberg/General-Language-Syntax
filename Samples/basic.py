"""
Basic GLS Syntax
Version 0.0.1
Josh Goldberg
"""

# Basic Usage
print("Hello world!") # Basic printing here...

# Variables
a = "Hello world!"
b = 7
c = 11.7
d = true

# Operations
e = 1 + 2
f = b < c

# If Statements
if d:
    print("d is true!")
if c < 14:
    print("c is less than 14!")

# While Loops
while d:
    print("d is", d)
    d = false
while c > 3:
    print("c is", c)
    c -= 1

# For Loops
for i = 0 i < 7 i += 1:
    print("i plus one is", i + 1)

# Function Definitions
def sayHello():
    print("Hello world!")
def combineStrings(a, b):
    return a + b

# Calling Functions
sayHello()
combineStrings("hello", "world")
combineStrings("hello" + " ", "world")
combineStrings(combineStrings("hello", "world"), "world")

# Class Declarations
class Point {
    public x
    public y
    
    def __init__(x, y):
        this.x = x
        this.y = y
    
    public setX(self, x):
        this.x = x
    
    public setY(self, y):
        this.y = y
    
    public getX(self):
        return this.x
    
    public getY(self):
        return this.y
    
    public getManhattanTotal(self):
        return this.x + this.y
}

# Class Usage
g = new Point(3, 7)
g.setX(4)
print(g.getManhattanTotal())

# fin
