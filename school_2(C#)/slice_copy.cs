using System;
 
public class Test
{
	public static void Main()
	{
		char[] dizi1 = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
		char[] dizi2 = {'9', '8', '7', '6', '5', '4', '3', '2', '1', '0'};
		Array.Copy(dizi1, 6, dizi2, 4, 3);
		foreach (char element in dizi2)
			Console.Write(element + " ");
	}
}
