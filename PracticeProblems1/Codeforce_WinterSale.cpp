/*
https://codeforces.com/group/MWSDmqGsZm/contest/326175/problem/A
The winter sale began, and Mrs. Sarah wants to buy a T-shirt for her son. The T-shirt has a ticket
that indicates a discount of 𝑋% and its price 𝑃 after the discount. She now wants to know the price
before the discount to know if the discount was worthy. Help her!

Input
Only one line containing two numbers 𝑋 and 𝑃 (1≤𝑋≤99,1≤𝑃≤4×104) – the discount percentage,
and the price of the T-shirt after the discount.

Output
Print the price of the T-shirt before the discount rounded up to two decimal places.
*/

#include <iostream>
#include <iomanip>

int main(){
    double x,p;
    std::cin>>x>>p;
    double res = (100*p)/(100-x);
    std::cout<<std::fixed<<std::setprecision(2)<<res;
}