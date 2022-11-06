#define ULL unsigned long long

bool isPrime(ULL n)
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

ULL gcd(ULL a, ULL b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
//ULL gcd(ULL a, ULL b)
//{
//	if(a<b)
//	{ULL temp = a;	a = b;	b = temp;}
//	//ULL x=a,y=b,r,q,s1=1,s2=0,t1=0,t2=1,s,t;
//	while(b>0)
//	{
//		q=a/b;
//		r=a%b;
//		if(r!=0)
//		{
//			s=s1-q*s2;
//			s1=s2;s2=s;
//			t=t1-q*t2;
//			t1=t2;t2=t;
//		}
//		a=b;b=r;
//		return a;
//	}
//}
