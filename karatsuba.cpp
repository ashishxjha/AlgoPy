#include <bits/stdc++.h>
#include "boost.h"
using namespace std;

boost::multiprecision::int128_t karatsuba (int128_t num1, int128_t num2){
	if (num1 < 10 || num2 < 10)
		return num1*num2;

	int len1 = to_string(num1).length();
	int len2 = to_string(num2).length();

	int m = min(len1, len2);

	int m2 = (int)(m/2);

	string num1_s = to_string(num1);
	string num2_s = to_string(num2);

	boost::multiprecision::int128_t a, b, c, d;
	
	a = (int128_t) pow(num1/10, m2);
	b = (int128_t) pow(num1%10, m2);
	c = (int128_t) pow(num2/10, m2);
	d = (int128_t) pow(num2%10, m2);


	boost::multiprecision::int128_t z0, z1, z2;
	z0 = karatsuba(b, d);
	z1 = karatsuba((a+b), (c+d));
	z2 = karatsuba(a, c);

	boost::multiprecision::int128_t res;
	res = z2 * pow(10, m2*2) + ((z1 - z2 - z0) * (pow(10, m2))) + z0;

	return res;
}

int main(void){
	printf("%lli", karatsuba(12345, 65673));
	return 0;
}


