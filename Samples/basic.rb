"""
Basic GLS Syntax
Version 0.0.1
Josh Goldberg
""" 
# Function Definitions
def sayHello():
    puts "Hello world!" 
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

# Main
if __name__ == '__main__':
    # Basic Usage
    puts "Hello world!"  # Basic printing here...
    
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
        puts "d is true!" 
    if c < 14:
        puts "c is less than 14!" 
    
    # While Loops
    while d:
        puts "d is", d 
        d = False
    while c > 3:
        puts "c is", c 
        c -= 1
    
    # For Loops
    for i in range(0, 7):
        puts "i plus one is", i + 1 
    
    # Calling Functions
    sayHello()
    combineStrings("hello", "world")
    combineStrings("hello" + " ", "world")
    combineStrings(combineStrings("hello", "world"), "world")
    
    # Class Usage
    g = Point(3, 7)
    g.setX(4)
    puts g.getManhattanTotal()  

# fin
