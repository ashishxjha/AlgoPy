#include <bits/stdc++.h>
using namespace std;

long long int ipow(long long int x, int n){
	long long res = 1;
	while (n--)
		res *= x;
	return res;
}

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
	
	a = ipow(num1/10, m2);
	b = ipow(num1%10, m2);
	c = ipow(num2/10, m2);
	d = ipow(num2%10, m2);


	long long int z0, z1, z2;
	z0 = karatsuba(b, d);
	z1 = karatsuba((a+b), (c+d));
	z2 = karatsuba(a, c);

	long long int res;
	res = z2 * pow(10, m2*2) + ((z1 - z2 - z0) * (pow(10, m2))) + z0;
	return res;
}

int main(void){
	int i = 0;
	printf("test begin with 120, 999\n");
	while (++i != 10){
		
		printf("(case - %d) %d\n", karatsuba(120+i, 999+i) == (120+i)*(999 + i));
		
	}
	printf("failed for case %d\n", i);
	return 0;

}

