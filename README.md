# Brainfuck interpreter

This is an implementation of a [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) interpreter.
It features the original alphabet with the addition of a debug symbol (#) that outputs information of the current data point.

It makes use of a 30,000 byte array, akin to the original implementation, but the data pointer wraps around, meaning it's possible to move the data pointer infinetly in both directions.

Some examples of BF code can be found in the [examples](examples/) directory. 

## Example

The string of Brainfuck code:
```
++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.
```

Outputs the following:
```
Hello World!
```

## Buliding

### Requirements
- **git**
- **gcc** or other C compiler supporting C99 (the Makefile will have to be edited to use that compiler instead)
- **make**

```bash
git clone git@github.com:Apmds/BFinterpreter.git
cd BFinterpreter
make
```
The executable will be found at the ```bin``` directory.

## Running

The ```-d``` flag enables the debug symbol, which is ignored otherwise.
```bash
./bin/bfint -d ./examples/       # This runs the hello world example with debug mode on
```
