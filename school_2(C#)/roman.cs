using System;

namespace Roman
{
    class MainClass
    {
        private static int n;
        
        public static string roman(int n)
        {
            string[,] roman = new string[2, 11] {
                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"},
                {"", "X", "XX", "XXX", "XL", "L", "", "", "", "", ""}
            };
            string result = "";
            int onlar = n / 10;
            int birler = n % 10;
            
            result += roman[1, onlar];
            result += roman[0, birler];
             
            return result;
        }
       
        public static void Check()
        {
            try
            {
                n = Convert.ToInt16(Console.ReadLine());
                if(n > 50 || n < 0)
                {
                    Console.WriteLine("1 ile 50 arasinda bir deger giriniz...");
                    Check();
                }
            }
            catch (Exception ex)
            {
                if(ex is FormatException)
                    Console.WriteLine("Sadece tamsayi giriniz.");
                else if(ex is OverflowException)
                    Console.WriteLine("2 byte'den buyuk bir deger girmeyiniz.");
                Check();
            }
            
        }
         
        public static void Main(string[] args)
        {
            Console.WriteLine("1 ile 50 arasinda bir deger giriniz...");
            Check();
            string result = roman(n);
            Console.WriteLine("Sonuc: {0}", result);
        }
    }
}
