using System;

class Dortgen
{
    public static int en, boy;
    
    public static int Alan(int en, int boy)
    {
        return en * boy;
    }
    
    public static void Yaz()
    {
        Console.WriteLine("En: {0}\nBoy: {1}\nAlan: {2}", en, boy, Alan(en, boy));
    }
}

class MainClass
{
    public static void Main(string[] args)
    {
        Dortgen.en = 30;
        Dortgen.boy = 50;
        Dortgen.Yaz();
    }
}
