#include <bits/stdc++.h>

using namespace std;

long int karatsuba (long int num1, long int num2){
	if (num1 < 10 || num2 < 10)
		return num1*num2;

	int len1 = to_string(num1).length();
	int len2 = to_string(num2).length();

	int m = min(len1, len2);

	int m2 = (int)(m/2);

	string num1_s = to_string(num1);
	string num2_s = to_string(num2);

	int h1, h2, l1, l2;
	
	h1 = stoi(num1_s.substr(0, m2));
	h2 = stoi(num1_s.substr(m2, num2_s.length()));
	l1 = stoi(num2_s.substr(0, m2));
	l2 = stoi(num2_s.substr(m2, num2_s.length()));


	long int z0, z1, z2;
	z0 = karatsuba(l1, l2);
	z1 = karatsuba((l1 + h1), (l2 + h2));
	z2 = karatsuba(h1, h2);

	long int res;
	res = z2 * pow(10, m2*2) + ((z1 - z2 - z0) * (pow(10, m2))) + z0;

	return res;
}

int main(void){
	printf("%d", karatsuba(19,19));
	return 0;
}


