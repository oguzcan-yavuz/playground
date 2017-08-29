using System;

class MathMetotlari
{
    public static void Main(string[] args)
    {
        double pi = Math.PI;
        double e = Math.E;
        Console.WriteLine("Abs: {0}", Math.Abs(e - pi));
        Console.WriteLine("Acos: {0}", Math.Acos(0.5));
        Console.WriteLine("Asin: {0}", Math.Asin(0.3));
        Console.WriteLine("Atan2: {0}", Math.Atan2(e, pi));
        Console.WriteLine("Sqrt: {0}", Math.Sqrt(pi));
        Console.WriteLine("Round: {0}", Math.Round(pi));
        Console.WriteLine("Pow: {0}", Math.Pow(e, pi));
        Console.WriteLine("Log: {0}", Math.Log(e, pi));
        Console.WriteLine("Log10: {0}", Math.Log10(pi));
    }
}
