//
// Joseph McFarland
// 9072511679
// mcfarland3@wis.edu
// https://canvas.wisc.edu/courses/188843/files for slides
// Made in CLion with commits to GitHub
//

#include "InfiniteInt.h"

vector<unsigned int> *InfiniteInt::getDigits() {
    return digits;
}

InfiniteInt::InfiniteInt() {
    digits = new vector<unsigned int>;
    digits->push_back(0);
}

InfiniteInt::InfiniteInt(unsigned long long val) {
    digits = new vector<unsigned int>;
    while (val != 0) {
        digits->push_back(val % radix);
        val = (val - (val % radix)) / radix;
    }
    reverse(digits->begin(), digits->end());
}

InfiniteInt::InfiniteInt(std::vector<unsigned int> *new_digits) {
    digits = new vector<unsigned int>;
    for (auto digit: *new_digits) {
        digits->push_back(digit);
    }
}

InfiniteInt::InfiniteInt(const InfiniteInt &obj){
    digits = new vector<unsigned int>;
    for (auto digit: *obj.digits) {
        digits->push_back(digit);
    }
}

InfiniteInt &InfiniteInt::operator=(const InfiniteInt &obj) {
    if (this != &obj) {
        delete digits;
        digits = new vector<unsigned int>;
        for (auto digit: *obj.digits) {
            digits->push_back(digit);
        }
    }
    return *this;
}

InfiniteInt::~InfiniteInt() {
    delete digits;
    digits = nullptr;
}

ostream & operator<<(ostream &out, const InfiniteInt &obj) {
    for (auto digit: *obj.digits)
        out << digit;
    return out;
}

InfiniteInt & operator>>(istream &in, InfiniteInt &obj) {
    InfiniteInt inDigits;
    inDigits.digits->clear();
    string input;
    getline(in, input);
    for (auto digit: input) {
        if (48 <= digit and digit <= 57) {
            digit -= 48;
            inDigits.digits->push_back(digit);
        } else {
            cout << "Invalid entry" << endl;
            return obj;
        }
    }
    obj = inDigits;
    return obj;
}

bool InfiniteInt::operator<(InfiniteInt const &obj) {
    if (digits->size() < obj.digits->size())
        return true;
    else if (digits->size() > obj.digits->size())
        return false;
    auto digit1 = digits->begin();
    auto digit2 = obj.digits->begin();
    for (;digit1 < digits->end() and digit2 < obj.digits->end(); ++digit1,
            ++digit2) {
        if (*digit1 < *digit2)
            return true;
        else if (*digit1 > *digit2)
            return false;
    }
    return false;
}

bool InfiniteInt::operator>(InfiniteInt const &obj) {
    if (digits->size() > obj.digits->size())
        return true;
    else if (digits->size() < obj.digits->size())
        return false;
    auto digit1 = digits->begin();
    auto digit2 = obj.digits->begin();
    for (;digit1 < digits->end() and digit2 < obj.digits->end(); ++digit1,
            ++digit2) {
        if (*digit1 > *digit2)
            return true;
        else if (*digit1 < *digit2)
            return false;
    }
    return false;
}

bool InfiniteInt::operator<=(InfiniteInt const &obj) {
    if (digits->size() < obj.digits->size())
        return true;
    else if (digits->size() > obj.digits->size())
        return false;
    auto digit1 = digits->begin();
    auto digit2 = obj.digits->begin();
    for (;digit1 < digits->end() and digit2 < obj.digits->end(); ++digit1,
            ++digit2) {
        if (*digit1 < *digit2)
            return true;
        else if (*digit1 > *digit2)
            return false;
    }
    return true;
}

bool InfiniteInt::operator>=(InfiniteInt const &obj) {
    if (digits->size() > obj.digits->size())
        return true;
    else if (digits->size() < obj.digits->size())
        return false;
    auto digit1 = digits->begin();
    auto digit2 = obj.digits->begin();
    for (;digit1 < digits->end() and digit2 < obj.digits->end(); ++digit1,
            ++digit2) {
        if (*digit1 > *digit2)
            return true;
        else if (*digit1 < *digit2)
            return false;
    }
    return true;
}

bool InfiniteInt::operator==(InfiniteInt const &obj) {
    if (digits->size() != obj.digits->size())
        return false;
    auto digit1 = digits->begin();
    auto digit2 = obj.digits->begin();
    for (;digit1 < digits->end() and digit2 < obj.digits->end(); ++digit1,
            ++digit2) {
        if (*digit1 != *digit2)
            return false;
    }
    return true;
}

bool InfiniteInt::operator!=(InfiniteInt const &obj) {
    if (digits->size() != obj.digits->size())
        return true;
    auto digit1 = digits->begin();
    auto digit2 = obj.digits->begin();
    for (;digit1 < digits->end() and digit2 < obj.digits->end(); ++digit1,
            ++digit2) {
        if (*digit1 != *digit2)
            return true;
    }
    return false;
}

InfiniteInt InfiniteInt::operator+(InfiniteInt &obj) {
    unsigned int carry = 0;
    InfiniteInt infiniteInt;
    infiniteInt.digits->clear();
    auto digit1 = digits->rbegin();
    auto digit2 = obj.digits->rbegin();

    for (;digit1 < digits->rend() and digit2 < obj.digits->rend(); ++digit1,
            ++digit2) {
        infiniteInt.digits->push_back(*digit1 + *digit2);
    }

    if (digits->size() > obj.digits->size()) {
        for (;digit1 < digits->rend(); ++digit1) {
            infiniteInt.digits->push_back(*digit1);
        }
    } else {
        for (;digit2 < obj.digits->rend(); ++digit2) {
            infiniteInt.digits->push_back(*digit2);
        }
    }

    reverse(infiniteInt.digits->begin(), infiniteInt.digits->end());

    auto digit = infiniteInt.digits->rbegin();
    while (digit < infiniteInt.digits->rend()) {
        *digit += carry;
        carry = *digit / radix;
        *digit = *digit - (carry*radix);
        ++digit;
    }

    if (carry != 0) {
        InfiniteInt infiniteIntSig(carry);
        for (auto sigDigit: *infiniteInt.digits) {
            infiniteIntSig.digits->push_back(sigDigit);
            ++sigDigit;
        }
        return infiniteIntSig;
    }
    return infiniteInt;
}

InfiniteInt InfiniteInt::operator-(InfiniteInt &obj) {
    int carry = 0;
    InfiniteInt infiniteInt;
    infiniteInt.digits->clear();
    auto digit1 = digits->rbegin();
    auto digit2 = obj.digits->rbegin();

    for (; digit1 < digits->rend() and digit2 < obj.digits->rend(); ++digit1,
            ++digit2) {
        int int1 = *digit1;
        int int2 = *digit2;
        if (int1 < (int2 + carry)) {
            infiniteInt.digits->push_back((int1 - int2 - carry) + radix);
            carry = 1;
        } else {
            infiniteInt.digits->push_back(int1 - int2 - carry);
            carry = 0;
        }
    }

    if (digits->size() > obj.digits->size()) {
        for (; digit1 < digits->rend(); ++digit1) {
            infiniteInt.digits->push_back(*digit1 - carry);
            carry = 0;
        }
    } else {
        for (; digit2 < obj.digits->rend(); ++digit2) {
            infiniteInt.digits->push_back(*digit2 - carry);
            carry = 0;
        }
    }

    reverse(infiniteInt.digits->begin(), infiniteInt.digits->end());

    auto sigDigit = infiniteInt.digits->begin();
    if (*sigDigit == 0) {
        ++sigDigit;
        InfiniteInt infiniteIntSig;
        infiniteIntSig.digits->clear();
        for (; sigDigit < infiniteInt.digits->end(); ++sigDigit) {
            infiniteIntSig.digits->push_back(*sigDigit);
        }
        return infiniteIntSig;
    }
    return infiniteInt;
}

InfiniteInt InfiniteInt::operator+=(InfiniteInt &obj) {
    *this = obj + *this;
    return *this;
}

InfiniteInt InfiniteInt::operator-=(InfiniteInt &obj) {
    *this = *this - obj;
    return *this;
}

InfiniteInt InfiniteInt::operator++() {
    InfiniteInt infiniteInt(1);
    *this = infiniteInt + *this;
    return *this;
}

InfiniteInt InfiniteInt::operator--() {
    InfiniteInt infiniteInt(1);
    *this = *this - infiniteInt;
    return *this;
}

InfiniteInt InfiniteInt::operator++(int) {
    InfiniteInt infiniteInt(1);
    InfiniteInt thisCopy = *this;
    *this = infiniteInt + *this;
    return thisCopy;
}

InfiniteInt InfiniteInt::operator--(int) {
    InfiniteInt infiniteInt(1);
    InfiniteInt thisCopy = *this;
    *this = *this - infiniteInt;
    return thisCopy;
}




