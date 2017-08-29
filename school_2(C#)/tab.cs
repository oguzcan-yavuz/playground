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
				if (i != 0 && i % 25 == 0)
					Console.WriteLine();
				Console.Write("{0, 3}", i);
			}
		}
	}
}
