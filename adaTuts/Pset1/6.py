# 6. Multiplying Complex Numbers with Three Multiplications:

# To multiply two complex numbers a + ib and c + id using at most three multiplications, you can use the following formulas:

def multiply_complex_numbers(a, b, c, d):
    # Base case: if only one multiplication is needed
    if (b == 0 and d == 0) or (b != 0 and d != 0):
        return a * c - b * d, a * d + b * c

    # Split each complex number into its real and imaginary parts
    a_real, a_imag = a, b
    b_real, b_imag = c, d

    # Recursive steps
    ac_real, ac_imag = multiply_complex_numbers(a_real, a_imag, b_real, b_imag)
    bd_real, bd_imag = multiply_complex_numbers(a_real, a_imag, b_real, b_imag)
    ad_bc_real, ad_bc_imag = multiply_complex_numbers(a_real - a_imag, a_real + a_imag, b_real - b_imag, b_real + b_imag)

    # Combine the results
    real_part = ac_real - bd_real
    imaginary_part = ad_bc_real + bd_imag

    return real_part, imaginary_part


a, b, c, d = 2, 3, 4, 5
result = multiply_complex_numbers(a, b, c, d)
print(f"The product of ({a} + {b}i) and ({c} + {d}i) is: {result}")
