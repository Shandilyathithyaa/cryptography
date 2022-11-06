#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 2 || n == 3)
        return true;
    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int phi(int n)
{
	if(isPrime(n))
	return n-1;
	return 0;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
	return abs(a*b)/gcd(a,b);
}

void parallel_ass(int &old_r,int &r, int quotient)
{
	int prov = r;
	r = old_r - quotient * prov;
	old_r = prov;
}

int ext_Euclid(int a, int b)
{
	int old_r = a; 
	int r = b;
	int old_s = 1; 
	int s = 0;
	int old_t = 0; 
	int t = 1;
    
    while(r != 0)
    {
    	int quotient = old_r/r;
    	parallel_ass(old_r,r,quotient);
    	parallel_ass(old_s,s,quotient);
    	parallel_ass(old_t,t,quotient);
	}
	return max(old_s,old_t);
}

int main()
{
	//Key Generation
	//Choose two large prime numbers p and q
	int p = 37;
	int q = 97;
	
	//	Compute n = pq
	int n = p*q;
	
	//	Compute lambda(n)
	int n_lambda = lcm(phi(p),phi(q));
	
	//	Choose an integer e such that 1 < e < lambda(n) and gcd(e, lambda(n)) = 1; that is, e and lambda(n) are coprime.
	int e = 457;
	
	//	Determine d as d = e-1 (mod lambda(n)); that is, d is the modular multiplicative inverse of e modulo lambda(n).
	int d = ext_Euclid(e,n_lambda);
	cout<<d<<endl;
	
	//Encryption
	int m = 13;
	unsigned long long c = pow(m,e);
	cout<<c<<endl;
	
	//Decryption
	cout<<pow(c,d)<<endl;
	return 0;
}
