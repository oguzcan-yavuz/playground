using System;

namespace School
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int a = 5;
            reference(ref a);
            Console.WriteLine("A: {0}", a);
            Console.WriteLine(buyuk(3, buyuk(5, 1)));
        }
        static int buyuk(int a, int b)
        {
            return a > b ? a : b;
        }
        static void reference(ref int a)
        {
            a = 10;
        }
    }
}
