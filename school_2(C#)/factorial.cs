using System;

namespace Factorial
{
    class MainClass
    {
        public static int factorial(int n)
        {
            int result = 1;
            for(; n > 1; n--)
                result *= n;
            return result;
        }
        
        public static void Main(string[] args)
        {
            Console.WriteLine("Faktoriyeli alinacak sayiyi giriniz.");
            Console.WriteLine("Sonuc: {0}", factorial(Convert.ToInt32(Console.ReadLine())));
        }
    }
}