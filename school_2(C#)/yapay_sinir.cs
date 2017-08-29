    
    /* gercek cikti: 1
    beklenen cikti ise -1 cikmasi gerekiyor. O yuzden omegalari(agirlik) degistirmemiz gerekiyor. 
    omega_new[0] = omega[0] + lambda * x[0]   (lambda = 0.2)
    veya
    omega_new[0] = omega[0] - lambda * x[0]
    beklenen cikti eger buyukse fazla tahmin ediyor, bunu asagi cekmem lazim o yuzden eksilten formulu kullanacagiz
    yeni metot: omega dizisinin elemanlarini, x dizisinin elemanlarinin lambda
    degerleriyle carpimlarindan cikararak yeni bir agirlik
    dizisi olusturacak
    */

using System;

namespace School
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            double[] giris = {0.6, -0.1, -0.7, 0.5, 0.3, 0.6, -0.3, 0.2};
            double[] agirlik = {0.3, 0.9, 0.1, -0.2, -0.4, 0.7, 0.9, -0.3};
            double net = network(giris, agirlik);
            int iteration = 1;
            do
            {
                Console.WriteLine("Iterasyon: {0}\nNet: {1}\nAktivasyon: {2}\nGÇ: {3}", iteration, net, ak(net), ak(net) < 0 ? -1 : 1);
                iteration++;
                agirlik = new_weigth(giris, agirlik, true);
                net = network(giris, agirlik);
            } while(ak(net) >= 0);
        }
        
        static double network(double[] giris, double[] agirlik)
        {
            double net = 0;
            for(int i = 0; i < giris.Length; i++)
                net += giris[i] * agirlik[i];
            return net;
        }
           
        static double ak(double net)
        {
            double e = Math.E;
            return 1 / (1 + Math.Pow(e, -net));
        }
        
        static double[] new_weigth(double[] x, double[] omega, bool sign) 
        {
            double[] new_weigth = new double[x.Length];
            double lambda = 0.2;
            for(int i = 0; i < x.Length; i++)
                new_weigth[i] = sign == true ? omega[i] - (lambda * x[i]) : omega[i] + (lambda * x[i]);
            return new_weigth;
        }
    }
}
