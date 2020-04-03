//
// Joseph McFarland
// 9072511679
// mcfarland3@wis.edu
// https://canvas.wisc.edu/courses/188843/files for slides
// Made in CLion with commits to GitHub
//

#include "InfiniteInt.h"

int main() {
    // Default constructor
    InfiniteInt infiniteInt0;
    for (auto digit: *infiniteInt0.getDigits())
        cout << digit;
    cout << endl;

    // Val parameterized constructor
    InfiniteInt infiniteInt1(139);
    for (auto digit: *infiniteInt1.getDigits())
        cout << digit;
    cout << endl;

    // List parameterized constructor
    auto* new_digits = new vector<unsigned int>;
    new_digits->push_back(2);
    new_digits->push_back(3);
    new_digits->push_back(4);
    InfiniteInt infiniteInt2(new_digits);
    for (auto digit: *infiniteInt2.getDigits())
        cout << digit;
    cout << endl;
    delete new_digits;

    // Copy constructor
    InfiniteInt infiniteInt3 = infiniteInt2;
    for (auto digit: *infiniteInt3.getDigits())
        cout << digit;
    cout << endl;

    // Copy-assignment constructor
    InfiniteInt infiniteInt4;
    infiniteInt4 = infiniteInt2;
    for (auto digit: *infiniteInt4.getDigits())
        cout << digit;
    cout << endl;

    // Print out operand
    cout << infiniteInt0 << endl;

    // Read input operand
    cin >> infiniteInt2;
    cout << infiniteInt2 << endl;

    // Less than operand
    if (infiniteInt0 < infiniteInt1)
        cout << infiniteInt0 << " < " << infiniteInt1 << " T" << endl;
    else
        cout << infiniteInt0 << " < " << infiniteInt1 << " F" << endl;

    // Greater then operand
    if (infiniteInt3 > infiniteInt4)
        cout << infiniteInt3 << " > " << infiniteInt4 << " T" << endl;
    else
        cout << infiniteInt3 << " > " << infiniteInt4 << " F" << endl;

    // Less than or equal operand
    if (infiniteInt3 <= infiniteInt0)
        cout << infiniteInt3 << " <= " << infiniteInt0 << " T " << endl;
    else
        cout << infiniteInt3 << " <= " << infiniteInt0 << " F" << endl;

    // Greater than or equal operand
    if (infiniteInt3 >= infiniteInt0)
        cout << infiniteInt3 << " >= " << infiniteInt0 << " T " << endl;
    else
        cout << infiniteInt3 << " >= " << infiniteInt0 << " F" << endl;

    // Equal to operand
    if (infiniteInt3 == infiniteInt4)
        cout << infiniteInt3 << " == " << infiniteInt4 << " T " << endl;
    else
        cout << infiniteInt3 << " == " << infiniteInt4 << " F" << endl;

    // Unequal to operand
    if (infiniteInt3 != infiniteInt4)
        cout << infiniteInt3 << " != " << infiniteInt4 << " T " << endl;
    else
        cout << infiniteInt3 << " != " << infiniteInt4 << " F" << endl;

    // Addition operand
    cout << infiniteInt1 << " + " << infiniteInt4 << " = " << infiniteInt1 +
        infiniteInt4 << endl;

    // Subtraction operand
    cout << infiniteInt4 << " - " << infiniteInt1 << " = " << infiniteInt4 -
        infiniteInt1 << endl;

    // Add/Equal operand
    infiniteInt4 += infiniteInt1;
    cout << 234 << " += " << infiniteInt1 << " = " << infiniteInt4 <<
        endl;

    // Minus/Equal operand
    infiniteInt4 -= infiniteInt1;
    cout << 373 << " -= " << infiniteInt1 << " = " << infiniteInt4 <<
         endl;

    // Pre-increment
    cout << "++" << infiniteInt4 << " = " << ++infiniteInt4 << endl;

    // Pre-decrement
    cout << "--" << infiniteInt4 << " = " << --infiniteInt4 << endl;

    // Post-increment
    cout << infiniteInt4++ << "++ = " << infiniteInt4 << endl;

    // Post-decrement
    cout << infiniteInt4-- << "-- = " << infiniteInt4 << endl;
}
