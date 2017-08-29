using System;

namespace Vize
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int a = 140;
            int b = 71;
            int c = a | b;
            int d = a & b;
            
            Console.WriteLine("C: {0}\nD: {1}", c, d);
        }
    }
}
