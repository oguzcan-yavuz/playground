using System;

class MainClass
{
    
    static int fibo(int n, int a = 0, int b = 1)
    {
        Console.Write(b + " ");
        if(n == 1)
            return a + b;
        return fibo(n - 1, b, a + b);
    }
    
    public static void Main(string[] args)
    {
        Console.Write("Dizi: 0 ");
        Console.WriteLine("\nSonuc: {0}", fibo(5));
    }
}
