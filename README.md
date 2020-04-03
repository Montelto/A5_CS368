# A5_CS368
# Joseph McFarland
# 9072511679
# mcfarland3@wisc.edu

*Created in CLion and pushed to Github*

InfiniteInt consists of 3 files:
 InfiniteInt.h, InfiniteInt.cpp, and demo.cpp. The first being the header file, the second being the implementation of the modification functions, and the third being the main() function implementation to test these modification functions.
    
InfiniteInt.h: many consturctors, a destructor, a getDigit, and many poerand funtions to modify digits places into a vector.
  digits: A container to store the digits of the InfiniteInt
  radix: A constant unsigned integer to represent the base of your number

InfiniteInt.cpp: the implementaion of everything in InfiniteInt.h. 
  getDigits: A getter function for the digits member variable
  InfiniteInt constructors: Parameterized and defualt constructors.
  InfiniteInt copy-assignment: deletes old digits and reassigns pointers
  InfiniteInt destructor: deletes digits
  InfiniteInt iostream: to print out and write in digits
  InfiniteInt comparisons: compares two InfiniteInt's digits and returns a bool
  InfiniteInt operations: modifies InfiniteInt digits

demo.cpp executes a test for InfiniteInt.cpp functions.
   
**make InfiniteInt** 
