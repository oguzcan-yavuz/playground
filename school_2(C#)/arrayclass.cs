using System;

namespace School
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            // CreateInstance
            Array dizi = Array.CreateInstance(typeof(int), 5, 4, 5);
            for(int i = 0; i < 5; i++)
                for(int j = 0; j < 4; j++)
                    for(int k = 0; k < 5; k++)
                        // SetValue
                        dizi.SetValue(i * j * k, i, j, k);
            
            for(int i = 0; i < 5; i++)
                for(int j = 0; j < 4; j++)
                    for(int k = 0; k < 5; k++)
                        // GetValue
                        Console.WriteLine(dizi.GetValue(i, j, k));
                        
            Console.WriteLine("Diziler...");
            
            char[] dizi1 = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
            // To<Type>Array
            char[] dizi2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".ToCharArray();
            // CopyTo
            dizi1.CopyTo(dizi2, 2);
            // Array.Copy
            Array.Copy(dizi1, dizi2, 4);
            
            
            string[] metin1 = {"Ahmet", "Mehmet", "Ali", "Veli", "Oya", "Ayse", "Mustafa", "Kadir", "Suleyman", "Hatice"};
            // Array Sort
            Array.Sort(metin1);
            
            int index = 0;
            
            foreach(string item in metin1)
            {
                Console.WriteLine("{0}. {1}", index, item);
                index++; 
            }
            
            // Array.BinarySearch
            Console.WriteLine("Binary Search 'Oya': {0}", Array.BinarySearch(metin1, "Oya"));
            
            // Array.Reverse
            Array.Reverse(metin1, 1, 3);
            
        }
    }
}
