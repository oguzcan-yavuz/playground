using System;

namespace School
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			int parola = 372;
			int sayac = 10;
			int check;
			Console.WriteLine("Parola 3 basamakli pozitif bir tam sayidir. Parolayi tahmin etmek icin " + sayac + " hakkiniz var!\n");
			do
			{
				Console.WriteLine(sayac + " hakkiniz kaldi\n");
				check = Convert.ToInt32(Console.ReadLine());
				sayac--;
				bool birler = ((check % 100) % 10 == (parola % 100) % 10);
				bool onlar = ((check / 10) % 10 == (parola / 10) % 10);
				bool yuzler = (check / 100 == parola / 100);
				if (sayac < 0)
				{
					Console.WriteLine("Hakkiniz doldu! Dogru parola: " + parola);
					break;
				}
				else if (check == parola)
				{
					Console.WriteLine("Parola Dogru!");
					break;
				}
				else if (yuzler)
				{
					if (onlar)
					{
						Console.WriteLine("Yuzler ve onlar basamagi tuttu!");
					}
					else if (birler)
						Console.WriteLine("Yuzler basamagi ve birler basamagi tuttu!");
					else
					{
						Console.WriteLine("Yuzler basamagi tuttu!");
					}
				}
				else if (onlar)
				{
					if (birler)
					{
						Console.WriteLine("Onlar ve birler basamagi tuttu!");
					}
					else
					{
						Console.WriteLine("Onlar basamagi tuttu!");
					}
				}
				else if (birler)
				{
					Console.WriteLine("Birler basamagi tuttu!");
				}
				else
				{
					Console.WriteLine("Hicbir rakam tutmadi!");
				}
			} while (true);
		}
	}
}
