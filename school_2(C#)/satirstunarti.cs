using System;

namespace School
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			// ekrana girilen satir stun degeri kadar "+" yazdiran programi yaziniz.
			int satir, sutun;
			Console.WriteLine("Satir ve stun degerlerini giriniz.");
			satir = Convert.ToInt32(Console.ReadLine());
			sutun = Convert.ToInt32(Console.ReadLine());

			for (int i = 0; i < satir; i++)
			{
				for (int j = 0; j < sutun; j++)
					Console.Write("+");
				Console.WriteLine();
			}
		}
	}
}
