// Elemanlari 0 ile 100 arasinda olan 30 boyutlu bir rasgele elemanli dizi olusturun. Uretilen sayilari buyukten kucuge, 
// kucukten buyuge siralayan; siralanmis iki diziyi dizi2 ve dizi3'e kopyalayan programi yaziniz.

using System;

namespace Problem1
{
    class MainClass
    {
        
        static void print_array(int[] array)
        {
            int index = 0;
            foreach(int element in array)
            {
                Console.WriteLine("{0}. {1}", index, element);
                index++;
            }
        }
        
        public static void Main(string[] args)
        {
            // 30 elemanli 1-100 arasi degerlerden olusan dizi olusturur
            Random rnd = new Random();
            int[] random_array = new int[30];
            for(int i = 0; i < 30; i++)
                random_array[i] = rnd.Next(0, 100);
            
            int[] dizi2 = new int[30];
            int[] dizi3 = new int[30];
            
            // diziyi kucukten buyuge siralayip dizi2 ye kopyalar
            Array.Sort(random_array);
            random_array.CopyTo(dizi2, 0);
            
            // kucukten buyuge siralanmis diziyi tersine cevirerek buyukten kucuk yapar ve dizi3'e kopyalar
            Array.Reverse(random_array);
            random_array.CopyTo(dizi3, 0);
            
            Console.WriteLine("Kucukten Buyuge...");
            print_array(dizi2);
            Console.WriteLine("Buyukten Kucuge...");
            print_array(dizi3);
        }
    }
}
