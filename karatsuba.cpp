#include <bits/stdc++.h>
using namespace std;

long long int karatsuba (long long int num1, long long int num2){
	if (num1 < 10 || num2 < 10)
		return num1*num2;

	int len1 = to_string(num1).length();
	int len2 = to_string(num2).length();

	int m = min(len1, len2);

	int m2 = (int)(m/2);

	string num1_s = to_string(num1);
	string num2_s = to_string(num2);

	long long int a, b, c, d;
	
	a = (long long int) (pow(num1/10, m2)+0.5);
	b = (long long int) (pow(num1%10, m2)+0.5);
	c = (long long int) (pow(num2/10, m2)+0.5);
	d = (long long int) (pow(num2%10, m2)+0.5);


	long long int z0, z1, z2;
	z0 = karatsuba(b, d);
	z1 = karatsuba((a+b), (c+d));
	z2 = karatsuba(a, c);

	long long int res;
	res = z2 * pow(10, m2*2) + ((z1 - z2 - z0) * (pow(10, m2))) + z0;
	printf("%lli\n\n\n", res);
	return res;
}

int main(void){
	printf("%lli\n", karatsuba(12345, 65673));
	printf("%lli\n", 12345*65673);
	return 0;
}

