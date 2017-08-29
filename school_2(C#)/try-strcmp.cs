using System;

namespace School
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			// bir do-while sonsuz dongusu. bu donguden cikmak icin bir harf girilsin.
			do
			{
				Console.WriteLine("Donguden cikmak icin dogru karakteri giriniz.");
				char harf;
				try
				{
					harf = Convert.ToChar(Console.ReadLine());
					if (harf.Equals('K') || harf.Equals('k'))
					{
						Console.WriteLine("Donguden cikiliyor.");
						break;
					}
				}
				catch (FormatException)
				{
					Console.WriteLine("Bir karakter girmediniz.");
				}

			} while (true);
		}
	}
}
