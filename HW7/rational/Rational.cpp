/**
 * Charles Tung Fang
 * CSE 374, 6/4 2019
 * Rational is able to construct a new rational object
 * return numererator and denominator of a particular Rational
 * in the lowest term. 
 * It also allows user to do basic arithmetic
 */

#include "Rational.h"
#include <cmath>

int getGCD(int a, int b);

namespace rational374
{
// ----------- CONSTRUCTORS -----------    
// Construct Rational 0/1
Rational::Rational(){
    Rational(0,1);
}

// Construct Rational n/1
Rational::Rational(int n){
    Rational(n, 1);
}

// Construct Rational n/d
Rational::Rational(int n, int d){
    // check the sign of the rational
    int sign = n * d;
    if (sign >= 0) {
        sign = 1;
    } else {
        sign = -1;
    }

    int gcd = getGCD(abs(n), abs(d));

    // if input a denominator 0, just put it into the
    // rational
    if (gcd != 0) {
        denom_ = sign * d / abs(gcd);
        numer_ = sign * n / abs(gcd);
    } else {
        numer_ = n;
        denom_ = d;
    }
}

// ----------- ACCESSORS -----------
// Return the numererator of this rational in lowest term
int Rational::n() const{
    return numer_;
}

// Return the denominator of this rational in lowest term
int Rational::d() const{
    return denom_;  
}

// ----------- ARITHMETIC -----------
// Given other rational and return the sum of this and other rational
Rational Rational::plus(Rational other) const{
    int res_num;
    int res_den;

    res_den = denom_ * other.denom_;
    res_num = numer_ * other.denom_ + other.numer_ * denom_;

    return Rational(res_num, res_den);
}

// Given other rational and return the subtartion
//  of this and other rational
Rational Rational::minus(Rational other) const{
    int res_num;
    int res_den;

    res_den = denom_ * other.denom_;
    res_num = numer_ * other.denom_ - other.numer_ * denom_;
    return Rational(res_num, res_den);
}

// Given other rational and return the multiplication
// of this and other rational
Rational Rational::times(Rational other) const{
    int res_num;
    int res_den;

    res_den = denom_ * other.denom_;
    res_num = numer_ * other.numer_;
    return Rational(res_num, res_den);
}

// Given other rational and return the division
//  of this and other rational
Rational Rational::div(Rational other) const{
    int res_num;
    int res_den;

    res_den = denom_ * other.numer_;
    res_num = numer_ * other.denom_;
    return Rational(res_num, res_den);
}
} // namespace rational374

// Given two integers and find the greate common divider
// between two numbers
// Resource: Euclidean algorithm
int getGCD(int a, int b){
    if (b==0) {
		return a;
	} else {
		return getGCD((int)abs(b), (int)abs(a) % (int)abs(b));
	}
}
