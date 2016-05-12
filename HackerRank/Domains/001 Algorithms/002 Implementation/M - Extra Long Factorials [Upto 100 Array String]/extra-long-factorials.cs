using System;
using System.Numerics;
using System.IO;
class Solution {
    static void Main(String[] args) {
        int N=Convert.ToInt32(Console.ReadLine());
        BigInteger result = Fact(N);
        var res=result.ToString();
        Console.WriteLine(res,"\n");
    }
    private static BigInteger Fact(int num){
        if(num==0)
            return 1;
        else
            return num*Fact(num-1);
    }
}
