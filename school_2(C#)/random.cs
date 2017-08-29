using System;

namespace School
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			Random rand = new Random();
			int maximum = 100;
			int minimum = 0;
			int random = rand.Next(minimum, maximum);
			double random2 = rand.NextDouble() * (maximum - minimum) + minimum;
			Console.WriteLine("{0}, {1}", random, random2);
		}
	}
}
