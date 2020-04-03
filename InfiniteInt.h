//
// Joseph McFarland
// 9072511679
// mcfarland3@wis.edu
// https://canvas.wisc.edu/courses/188843/files for slides
// Made in CLion with commits to GitHub
//

#ifndef A5_CS368_INFINITEINT_H
#define A5_CS368_INFINITEINT_H

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class InfiniteInt {

private:
    /*
     * A container to store the digits of the InfiniteInt
     */
    vector<unsigned int> *digits;

    /*
     * A constant unsigned integer to represent the base of your number
     */
    const unsigned int radix = 10;

public:
    /*
     *  A getter function for the digits member variable
     */
    vector<unsigned int> *getDigits();

    /*
     *  a default constructor for InfiniteInt that sets the value of your InfiniteInt to
     *  a default value of 0
     */
    InfiniteInt();

    /*
     *  a parameterized constructor for InfiniteInt that sets the starting
     *  value to val
     */
    InfiniteInt(unsigned long long val);

    /*
     *  a parameterized constructor for InfiniteInt that sets the starting
     *  value equal to the digits pointed to by new_digits
     */
    explicit InfiniteInt(std::vector<unsigned int>* new_digits);

    /*
     * a copy constructor for InfiniteInt that allocates new memory for
     * digits and then copies each digit from the obj vector to the newly
     * allocated vector.
     */
    InfiniteInt(const InfiniteInt &obj);

    /*
     * Overload the copy-assignment operator. This will look similar to the
     * copy constructor
     */
    InfiniteInt& operator=(const InfiniteInt &obj);

    /*
     * a destructor for InfiniteInt which frees any allocated heap memory.
     */
    ~InfiniteInt();

    /*
     * display the integer value of the InfiniteInt as if it was a regular
     * unsigned int.
     */
    friend ostream &operator << (ostream &out, const InfiniteInt &obj);

    /*
     *  This operator should wait for the user to enter a single string of
     *  numbers, which will then be parsed into the vector of digits. If the
     *  user enters any characters other than valid digit numbers (0-9) in
     *  their input string, you should print "Invalid entry" with an endl
     *  character to cout and return without modifying the digits of the
     *  InfiniteInt
     */
    friend InfiniteInt &operator >> (istream &in, InfiniteInt &obj);

    /*
     * an overloaded operator < that returns whether or not the value of the
     * left hand side InfiniteInt is less than the other InfiniteInt.
     */
    bool operator < (InfiniteInt const &obj);

    /*
     * an overloaded operator > that returns whether or not the value of the
     * left hand side InfiniteInt is greater than the other InfiniteInt.
     */
    bool operator > (InfiniteInt const &obj);

    /*
     *  an overloaded operator <= that returns whether or not the value of
     *  the left hand side InfiniteInt is less than or equal to the other InfiniteInt.
     */
    bool operator <= (InfiniteInt const &obj);

    /*
     * an overloaded operator >= that returns whether or not the value of the
     * left hand side InfiniteInt is greater than or equal to the other InfiniteInt.
     */
    bool operator >= (InfiniteInt const &obj);

    /*
     * an overloaded operator == that returns whether or not the value of the
     * left hand side InfiniteInt is equal to the other InfiniteInt.
     */
    bool operator == (InfiniteInt const &obj);

    /*
     * an overloaded operator != that returns whether or not the value of the
     * left hand side InfiniteInt is not equal to the other InfiniteInt.
     */
    bool operator != (InfiniteInt const &obj);

    /*
     * an overloaded operator + that returns a InfiniteInt that is the sum of
     * two InfiniteInts. Make sure to carry out and create a new most
     * significant digit when necessary.
     */
    InfiniteInt operator + (InfiniteInt &obj);

    /*
     *  an overloaded operator - that returns a InfiniteInt that is the
     *  difference of two InfiniteInts. If the result of this subtraction
     *  would create a negative number, return an InfiniteInt with a value of 0.
     */
    InfiniteInt operator - (InfiniteInt &obj);

    /*
     *  an overloaded operator += that adds the right operand and the left
     *  operand and stores the new value in the left operand.
     */
    InfiniteInt operator += (InfiniteInt &obj);

    /*
     * an overloaded operator -= that subtracts the right operand from the
     * left operand and stores the new value in the left operand.
     */
    InfiniteInt operator -= (InfiniteInt &obj);

    /*
     * an overloaded pre-increment operator, ++, that adds 1 to the current
     * InfiniteInt and returns the changed InfiniteInt.
     */
    InfiniteInt operator ++();

    /*
     * an overloaded pre-decrement operator, --, that subtracts 1 from the
     * current InfiniteInt and returns the changed InfiniteInt.
     */
    InfiniteInt operator --();

    /*
     *  an overloaded post-increment operator, ++, that adds 1 to the current
     *  InfiniteInt and returns the original InfiniteInt.
     */
    InfiniteInt operator++ (int);

    /*
     *  an overloaded post-decrement operator, --, that subtracts 1 from the
     *  current InfiniteInt and returns the original InfiniteInt.
     */
    InfiniteInt operator-- (int);
};

/*
 * both explained in class
 */
ostream &operator << (ostream &out, const InfiniteInt &obj);

InfiniteInt &operator >> (istream &in, InfiniteInt &obj);

#endif //A5_CS368_INFINITEINT_H
