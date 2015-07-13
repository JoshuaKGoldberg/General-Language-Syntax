"""
Basic GLS Syntax
Version 0.0.1
Josh Goldberg
""" 
# Function Definitions
def sayHello()
    puts "Hello world!" 
end
def combineStrings(a, b)
    return a + b
end

# Class Declarations
class Point
    x = None
    y = None
    
    def __init__(x, y)
        this.x = x
        this.y = y
    end
    
    def setX(x)
        this.x = x
    end
    
    def setY(y)
        this.y = y
    end
    
    def getX()
        return this.x
    end
    
    def getY()
        return this.y
    end
    
    def getManhattanTotal()
        return this.x + this.y
    end

# Main
if __name__ == '__main__':
    # Basic Usage
    puts "Hello world!"  # Basic printing here...
    
    # Variables
    a = "Hello world!"
    b = 7
    c = 11.7
    d = true
    
    # Operations
    e = 1 + 2
    f = b < c
    
    # If Statements
    if d
        puts "d is true!" 
    end
    if c < 14
        puts "c is less than 14!" 
    end
    
    # While Loops
    while d
        puts "d is", d 
        d = false
    end
    while c > 3
        puts "c is", c 
        c -= 1
    end
    
    # For Loops
    for i in range(0, 7)
        puts "i plus one is", i + 1 
    end
    
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
