using System;

namespace School
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			// normal dizi
			int[] dizi = new int[5];
			
			// direk icerigini degisken tanimlama esnasinda verebiliriz
			string[] str_dizi = {"lol", "idk"};
			
			// boyutu tanimlamadan dizi olusturmak
			List<int> dynmc = new List<int>();
			dynmc.Add(15);
			
			// iki boyutlu dizi
			double[,] two_dimensional = new double[5, 5];
			two_dimensional[0, 1] = 0.3;	// dizinin elemanlarina deger atama
			
			// uc boyutlu dizi
			int[, ,] three_dim = new int[3, 2, 5];
			
			foreach (string element in str_dizi)
			{
				Console.WriteLine(element);
			}
		}
	}
}
