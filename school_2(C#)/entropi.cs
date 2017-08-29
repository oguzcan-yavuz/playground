using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lolzz
{
    class Program
    {
        /* macin oynanip oynanmayaca��na karar veren program:
         * log tabani: 2
         * entropi: h(Sicaklik) = 4 / 5 * log(4/5) + 1 / 5 * log(1 / 5)
         * entropi dusukse etkenin g�c� daha b�y�k
         * 
         * */

        static double entropi(double[] katsayi)
        {
            double toplam = 0;
            foreach (double kat in katsayi)
            {
                toplam += kat * Math.Log(kat, 2);
            }
            return toplam;
        }


        static void Main(string[] args)
        {
            double[] katsayi = { 0.8, 0.2 };
            double sonuc1 = entropi(katsayi);
            double[] katsayi2 = { 0.4, 0.6 };
            double sonuc2 = entropi(katsayi2);
            double[] katsayi3 = { 0.4, 0.4, 0.2 };
            double sonuc3 = entropi(katsayi3);
            Console.WriteLine("Sicaklik: {0}, Mac: {1}, Hava: {2}", sonuc1, sonuc2, sonuc3);
        }
    }
}
