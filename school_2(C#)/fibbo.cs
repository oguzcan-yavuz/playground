using System;

class MainClass
{
    public static int fibo(int n, int x = 0, int y = 1, int iteration = 1)
    {
        if(n == 0)
            return -1;
        Console.WriteLine("Fibo({0})={1}", iteration, y);
        return fibo(n - 1, y, x + y, iteration + 1);
    }
    
    public static void Main(string[] args)
    {
        Console.WriteLine("Fibo(0)=0");
        fibo(20);
    }
}
