def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


# Taking input from the user
x = int(input("Enter the first number: "))
y = int(input("Enter the second number: "))

# Finding the GCD using the Euclidean algorithm
result = gcd(x, y)

# Printing the result
print(f"The GCD of {x} and {y} is: {result}")
