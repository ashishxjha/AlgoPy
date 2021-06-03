def karatsuba(num1,num2):
    if(num1<10 or num2<10):
        return (num1*num2)
    else:
        m=max(len(str(num1)),len(str(num2)))
        m2=int(m/2)
        a=int(num1/10**m2)
        b=int(num1%10**m2)
        c=int(num2/10**m2)
        d=int(num2%10**m2)

        z0 = karatsuba(b,d)
        z1 = karatsuba((a+b),(c+d))
        z2 = karatsuba(a,c)

        return (z2*10 ** (m2*2)) + ((z1 - z2 - z0)*10**m2) + z0

print(karatsuba(1234567, 8757382))





