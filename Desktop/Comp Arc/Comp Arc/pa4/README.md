
## CS 211: Computer Architecture

# Programming Assignment 4: Circuit Simulator


## Introduction

You have to write a circuit simulator. One of the inputs to your program will be a circuit description file
that will describe a circuit using various directives. Your program will print the output of the circuit for all
possible input values.

### Circuit Description Directives

The input variables used in the circuit are provided using the *INPUTVAR* directive. The *INPUTVAR* directive
is followed by the number of input variables and the names of the input variables. All the input variables
will be named with capitalized identifiers. An identifier consists of at least one character (A-Z) followed by a
series of zero or many characters (A-Z) or digits (0-9). For example, some identifiers are *IN1,IN2, andIN3*.
An example specification of the inputs for a circuit with three input variables:*IN1,IN2,IN3* is as follows:
```
INPUTVAR 3 IN1 IN2 IN
```

The outputs produced by the circuit is specified using theOUTPUTVARdirective. TheOUTPUTVARdirective is
followed by the number of outputs and the names of the outputs.

An example specification of the circuit with output *OUT1* is as follows:

OUTPUTVAR 1 OUT
The circuits used in this assignment will be built using the following building blocks: NOT,AND,OR,NAND,
NOR, andXOR.

The building blocks can produce temporary variables as outputs, and can use either the input variables or
temporary variables as input. Output variables will never be used as inputs in a building block.

All the temporary variables will also be named with lower case identifiers (i.e.,temp1,temp2,temp3, ...).

The specification of each building block is as follows:

- NOT: for example,
```
NOT IN1 OUT
```
- AND: for example,
```
AND IN1 IN2 OUT
```
- OR: for example,
```
OR IN1 IN2 OUT
```
- NAND: for example,
```
NAND IN1 IN2 OUT
```
- NOR: for example,
```
NOR IN1 IN2 OUT
```
-XOR: for example,
```
XOR IN1 IN2 OUT
```
### Describing Circuits using the Directives

It is possible to describe any combinational circuit using the above set of directives. For example, the circuit
```OUT1 = IN1.IN2 + IN1.IN3 ```can be described as follows:
```
INPUTVAR 3 IN1 IN2 IN
OUTPUTVAR 1 OUT
AND IN1 IN2 temp
AND IN1 IN3 temp
OR temp1 temp2 OUT
```

*Note* that *OUT1* is the output variable *IN1,IN2, and IN3* are input variables.*temp1andtemp2* are temporary
variables.

A circuit description is a sequence of directives. You can assume that every temporary variable occurs as a
output variable in the sequence before occurring as an input variable.

*Note:* A temporary variable can occur as an output variable in at most one directive.

### Format of the Input Files
Your program will be given one file as input, containing the description of a circuit using the directives
described above.

For example:

INPUTVAR 3 IN1 IN2 IN
OUTPUTVAR 1 OUT
AND IN1 IN2 temp
AND IN1 IN3 temp
OR temp1 temp2 OUT

## The problem
You have to write a program calledfirstas described above. You are guaranteed that the circuit descriptions
given as input to your program will be sorted. Let’s look at an example we have encountered before.

**Example Execution**
Suppose a circuit description file named circuit.txt has the description for the circuit```OUT1 = IN1.IN2 + IN1.IN```
```
INPUTVAR 3 IN1 IN2 IN
OUTPUTVAR 1 OUT
AND IN1 IN2 temp
AND IN1 IN3 temp
OR temp1 temp2 OUT
```

Then, on executing the program with the above circuit description file, your program should produce the
following output:
```
./first circuit.txt
0 0 0 0
0 0 1 0
0 1 0 0
0 1 1 0
1 0 0 0
1 0 1 1
1 1 0 1
1 1 1 1
```

The output of the first three columns are *INPUTVAR IN1,IN2, andIN3* respectively. And the last column
denotes the* OUTPUTVAR OUT1*.

*Note:* the values of the input and output variables should be space separated and be in the same order as the
output variables in the*INPUTVAR and OUTPUTVAR* directive, e.g., if the circuit description file has the directive
```INPUTVAR 3 IN1 IN2 IN3```, and```OUTPUTVAR 3 OUT1 OUT2 OUT3,``` then the first values should be those of the
input variables *IN1,IN2, andIN3*, and output variable *OUT1*, followed by that of *OUT2*, and then that of
*OUT3*.

### Submission
Please submit a tar file named pa4.tar on Canvas. To create this file, put everything that you are submitting
into a directory (folder) named pa4. Then, cd into the directory containing pa4 (that is, pa4’s parent
directory) and run the following command:
```
tar cvf pa4.tar pa
```

To check that you have correctly created the tar file, you should copy it (pa4.tar) into an empty directory
and run the following command:
```
tar xvf pa4.tar
```

This should create a directory named pa4 in the (previously) empty directory.

The pa4 directory in your tar file must contain one subdirectory. The subdirectory should be named first
(in lower case). Each directory should contain your source files, header files, and a make file. Running the
makefile in the first folder, should produce the binary first.

Use the autograder to test your submission during development and before submission as you had done with
your other assignments.
