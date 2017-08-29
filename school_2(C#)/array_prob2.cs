/*
Elemanlari 0 100 arasinda rasgele degerler olan 30 elemanli bir dizideki tum elemanlarin ortalamsini bulan
elemanlarin en buyugunu ve en kucuklerini bulan, bunlari ekrana yazdiran kodu yaziniz.

*/

using System;

namespace Problem2
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            Random rnd = new Random();
            int[] random_array = new int[30];
            random_array[0] = rnd.Next(0, 100);
            float ortalama = 0;
            int kucuk = random_array[0];
            int buyuk = random_array[0];
            for(int i = 1; i < 30; i++)
            {
                int element = rnd.Next(0, 100);
                random_array[i] = element;
                ortalama += element;
                
                if(element > buyuk)
                    buyuk = element;
                
                if(element < kucuk)
                    kucuk = element;
            }
            ortalama /= 30;
            Console.WriteLine("Ortalama: {0}, Max: {1}, Min:{2}", ortalama, buyuk, kucuk);
        }
    }
}
