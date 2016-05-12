vector<int> Solution::sieve(int A) {
    vector<int> primes;
    bool prime[A+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=A; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=A; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=A; p++)
       if (prime[p])
            primes.push_back(p);
    return primes;
}
