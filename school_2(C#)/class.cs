using System;

class ExampleClass
{
    public int Topla(params int[] numbers)
    {
        int result = 0;
        foreach(int number in numbers)
            result += number;
        return result;
    }
}

class MainClass
{
    public static void Main(string[] args)
    {
        // eger ulasilacak fonksiyon static ise class 
        // icin nesne olusturarak ulasamayiz.
        
        // this keywordu, kendisini cagiran nesneyi temsil eder.
        
        // Bahsi gecen konular: indexer, operator overloading, readonly, structure
        ExampleClass ex = new ExampleClass();
        Console.WriteLine(ex.Topla(3, 5, 10));
    }
}
