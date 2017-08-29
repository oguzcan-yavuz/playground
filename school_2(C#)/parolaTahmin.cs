using System;

namespace School
{
	class MainClass
	{
		static public bool Birler(int tahmin, int parola)
		{
			return ((tahmin % 100) % 10 == (parola % 100) % 10) ? true : false;
		}

		static public bool Onlar(int tahmin, int parola)
		{
			return ((tahmin / 10) % 10 == (parola / 10) % 10) ? true : false;
		}

		static public bool Yuzler(int tahmin, int parola)
		{
			return (tahmin / 100 == parola / 100) ? true : false;
		}


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
				else if (Yuzler(check, parola))
				{
					if (Onlar(check, parola))
					{
						Console.WriteLine("Yuzler ve onlar basamagi tuttu!");
					}
					else if (Birler(check, parola))
						Console.WriteLine("Yuzler basamagi ve birler basamagi tuttu!");
					else
					{
						Console.WriteLine("Yuzler basamagi tuttu!");
					}
				}
				else if (Onlar(check, parola))
				{
					if (Birler(check, parola))
					{
						Console.WriteLine("Onlar ve birler basamagi tuttu!");
					}
					else
					{
						Console.WriteLine("Onlar basamagi tuttu!");
					}
				}
				else if (Birler(check, parola))
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
