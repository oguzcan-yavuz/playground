using System;

namespace School
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			// Konsol ekraninda 0 5 10 15 20 ... 100 seklinde cikti veren programi yaziniz
			//					25 30 35 40 45
			for(int i = 0; i <= 100; i += 5)
			{
				for(int j = 0; j < 5; j++) {
					Console.WriteLine("{0}\t", i);
				}
				Console.WriteLine("\n");
			}
		}
	}
}
