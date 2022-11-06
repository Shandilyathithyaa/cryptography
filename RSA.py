import random

def is_prime(n: int) -> bool:
    """Primality test using 6k+-1 optimization."""
    if n <= 3:
        return n > 1
    if not n%2 or not n%3:
        return False
    i = 5
    stop = int(n**0.5)
    while i <= stop:
        if not n%i or not n%(i + 2):
            return False
        i += 6
    return True


def gcd(x,y):
    t1 = 0
    t2 = 1
    if x > y:
        a=x
        b=y
    else:
        a=y
        b=x
    while b != 0:
        q = a//b
        r = a%b
        t = t1 - (q*t2)
        a = b
        b = r
        t1 = t2
        t2 = t
    if t1 < 0:
        return t1+t2
    else:
        return t1

p = int(input("Enter the first prime number : "))
q = int(input("Enter the second prime number : "))
m = int(input("Enter the message to encrypted : "))

n = p*q
phi = (p-1)*(q-1)
e = random.randrange(2,phi-1)
while(is_prime(e) != 0):
    e = random.randrange(2,phi-1)
d = gcd(e,phi)
cipher = (m**e) % n
decrypted_message = (cipher**d) % n

print("p : ", p)
print("q : ", q)
print("e : ", e)
print("d: ", d)
print("cipher : ", cipher)
print("Decrypted Message : ", decrypted_message)