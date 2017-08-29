/*
Metotlarin imzasi: Metotlarin isimlerini duzgun vermek ve kac parametreden olustugu.  
params: Degisken yapisinda bir parametreyi temsil eder.
*/
using System;

namespace School
{
    class MainClass
    {
        static void Metot1(string x, string y)
        {
            Console.WriteLine("1.metot");
        }
        
        static void Metot1(float x, float y)
        {
            Console.WriteLine("2.metot");
        }
        
        static void Metot1(int x, int y)
        {
            Console.WriteLine("3.metot");
        }
        
        static void Topla(params int[] sayilar)
        {
            int sonuc = 0;
            foreach(int sayi in sayilar)
                sonuc += sayi;
            Console.WriteLine("Sonuc: {0}", sonuc);
        }
        
        static void Yaz(int bicim, params object[] o)
        {
            if(bicim == 0)
            {
                foreach(object obj in o)
                {
                    Console.Write(obj.ToString() + " ");
                }
                Console.Write("\n");
            }
        }
       
        static void Opsiyonel(int x = 2, int y = 5)
        {
            Console.WriteLine(x + y);
        }
        
        static int factorial(int x)
        {
            if (x == 2)
                return 2;       
            return x * factorial(x - 1);
        }
        
        static void BitYaz(int sayi)
        {
            if(sayi == 0)
                return;
            BitYaz(sayi >> 1);
            Console.Write(sayi & 1);
        }
        
        public static void Main(string[] args)
        {
            Metot1("lool", "lmao");
            Metot1(5, 6);
            Metot1(10f, 56f);
            Topla(5);
            Topla(5, 10);
            Topla(5, 10, 15);
            Yaz(1, "lol", "ayy");
            Yaz(0, "lmao", "lel");
            Opsiyonel(3, 2);
            Opsiyonel(2);
            Console.WriteLine(factorial(6));
            BitYaz(256);
            Console.WriteLine();
        }
    }
}
