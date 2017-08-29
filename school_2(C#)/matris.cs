/*
matris_a = 2i+j
matris_b = i*i + 4j

3 metot: 1 ikisini toplayan
2: ikisini carpan
3: terslerini alan
*/

using System;

class MainClass
{
    static void matris_topla(double[,] matris_a, double[,] matris_b)
    {
        for(int i = 0; i < matris_a.GetLength(0); i++)
        {
            for(int j = 0; j < matris_a.GetLength(1); j++)
                Console.Write(matris_a[i, j] + matris_b[i, j] + " ");
            Console.WriteLine();
        }
    }
    
    static void matris_carp(double[,] matris_a, double[,] matris_b)
    {
        double[,] matris_multiplied = new double[3, 3];
        
        for(int i = 0; i < matris_a.GetLength(0); i++)
        {
            for(int j = 0; j < matris_a.GetLength(1); j++)
            {
                for(int k = 0; k < 3; k++)
                    matris_multiplied[j, i] += matris_a[j, k] * matris_b[k, i];
            }
        }
        print_matris(matris_multiplied);
    }
    
    static void matris_inverse(double[,] matris)
    {
        double a = matris[0, 0];
        double b = matris[0, 1];
        double c = matris[0, 2];
        double d = matris[1, 0];
        double e = matris[1, 1];
        double f = matris[1, 2];
        double g = matris[2, 0];
        double h = matris[2, 1];
        double k = matris[2, 2];
    
        double det = (a * e * k) + (d * h * c) + (g * b * f) - (a * h * f) - (g * e * c) - (d * b * k);
        
        if(det == 0)
            Console.WriteLine("Matrisin determinanti 0'a esit oldugundan dolayi tersi yoktur.");
        
        double a1 = ((e * k) - (f * h)) * 1 / det;
        double b1 = ((c * h) - (b * k)) * 1 / det;
        double c1 = ((b * f) - (c * e)) * 1 / det;
        double d1 = ((f * g) - (d * k)) * 1 / det;
        double e1 = ((a * k) - (c * g)) * 1 / det;
        double f1 = ((c * d) - (a * f)) * 1 / det;
        double g1 = ((d * h) - (e * g)) * 1 / det;
        double h1 = ((b * g) - (a * h)) * 1 / det;
        double k1 = ((a * e) - (b * d)) * 1 / det;
        
        double[,] matrix_inverted = {
            {a1, b1, c1},
            {d1, e1, f1},
            {g1, h1, k1}
        };
        print_matris(matrix_inverted);
    }
    
    static void print_matris(double[,] matris)
    {
        for(int i = 0; i < matris.GetLength(0); i++)
        {
            for(int j = 0; j < matris.GetLength(1); j++)
                Console.Write(matris[i, j] + " ");
            Console.WriteLine();
        }
    }
    
    public static void Main(string[] args)
    {
        double[,] matris_a = new double[3, 3];
        double[,] matris_b = new double[3, 3];
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                matris_a[i, j] = (2 * i) + j;
                matris_b[i, j] = (i * i) + (4 * j);
            }
        }
        Console.WriteLine("Matris_1");
        print_matris(matris_a);
        Console.WriteLine("Matris_2");
        print_matris(matris_b);
        Console.WriteLine("Toplam");
        matris_topla(matris_a, matris_b);
        Console.WriteLine("Ters Matris");
        matris_inverse(matris_a);
        Console.WriteLine("Matris Carpim");
        matris_carp(matris_a, matris_b);
    }
}
