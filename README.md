# General Language Syntax Compiler
A compiler for a general language syntax that can be mapped 1-1 to common languages like TypeScript or Python.

### Syntax

Each line contains a single command, a colon, and a list of arguments of any amount. For example, the following line calls the `print line` command, with the single argument `"GLS!"`

    print line : "GLS!"
* *TypeScript equivalent:* `console.log("GLS!");`
* *Python equivalent*: `print("GLS!")`

You can use parenthesis (`()`) to allow spaces in your argument.

    print line : ("Hello world!")
* *TypeScript equivalent:*: `console.log("Hello world!");`
* *Python equivalent*: `print("Hello !")`

You can use curly brackets (`{}`) to have commands parsed to be arguments for other commands.

    comment line : { print line : (\"Hello world!\") }
* *TypeScript equivalent:*: `// console.log("Hello world!");`
* *Python equivalent*: `# print("Hello !")`

See [Samples/basic.gls](Samples/basic.gls) for examples of the syntax in use.

### Supported Commands (theoretically)

Bold commands are currently implemented. Regular commands are in progress.

* **class constructor end**
* **class constructor start**
* **class end**
* **class member function call**
* **class member function end**
* **class member function start**
* **class member variable declare**
* **class member variable get**
* **class member variable set**
* **class new**
* **class start**
* **comment block**
* **comment inline**
* **comment line**
* **comparison**
* **file end**
* **file start**
* **for end**
* **for numbers start**
* **function call**
* **function end**
* **function return**
* **function start**
* **if condition start**
* **if end**
* **if variable start**
* **main start**
* **main end**
* **operation**
* **operation change**
* **print line**
* **variable declare**
* **variable declare partial**
* **while condition start**
* **while end**
* **while variable start**
