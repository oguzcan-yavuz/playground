using System;

namespace School
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			// byte turunden verilen sayinin butun bitlerini ekrana yazdiran program.
			int sayi = Convert.ToInt32(Console.ReadLine());
			string binary = Convert.ToString(sayi, 2).PadLeft(8, '0');
			Console.WriteLine("{0}", binary);
		}
	}
}
