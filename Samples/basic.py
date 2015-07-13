"""
Basic GLS Syntax
Version 0.0.1
Josh Goldberg
"""
Function not found: file start

# Basic Usage
print("Hello world!") # Basic printing here...

# Variables
a = "Hello world!"
b = 7
c = 11.7
d = True

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
    d = False
while c > 3:
    print("c is", c)
    c -= 1

# For Loops
for i in range(0, 7):
    print("i plus one is", i + 1)

# Calling Functions
sayHello()
combineStrings("hello", "world")
combineStrings("hello" + " ", "world")
combineStrings(combineStrings("hello", "world"), "world")

# Class Usage
g = Point(3, 7)
g.setX(4)
print(g.getManhattanTotal())


# Function Definitions
def sayHello():
    print("Hello world!")
def combineStrings(a, b):
    return a + b

# Class Declarations
class Point:
    x = None
    y = None
    
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def setX(self, x):
        self.x = x
    
    def setY(self, y):
        self.y = y
    
    def getX(self):
        return self.x
    
    def getY(self):
        return self.y
    
    def getManhattanTotal(self):
        return self.x + self.y
Function not found: file end

# fin
