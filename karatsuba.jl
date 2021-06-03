function karatsuba(num1,num2)
    if num1<10 || num2<10
        return num1*num2
    else
        m=max(length(string(num1)),length(string(num2)))
        m2=div(m,2)

        a=div(num1,10^(m2))
        b=num1%10^(m2)
        c=div(num2,10^(m2))
        d=num2%10^(m2)

        z0 = karatsuba(b,d)
        z1 = karatsuba((a+b),(c+d))
        z2 = karatsuba(a,c)
    

    return (z2 * 10^(2*m2)) + ((z1 - z2 - z0) * 10^(m2)) + z0
    end
end


    
