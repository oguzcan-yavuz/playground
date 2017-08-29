/*
1. Case anahtar sözcüğünün yanındaki ifadede değişken bulundurulamaz. Bu ifade sabit olmalı.
2. Bu sabit herhangi bir tamsayı olabildiği gibi karakter ya da string de olabilir.
3. Default durumunu istediğimiz yere yazabiliriz.
4. Bir switch bloğu içerisinde iki ya da daha fazla sayıda aynı case ifadesi bulunamaz.
5. Bir switch bloğunda default case olmak zorunda değildir.
6. Akış herhangi bir case ifadesine geldiğinde farklı bir case ifadesine yönlendirilmek istenirse goto anahtar sözcüğü kullanılır.

*/


using System;
 
public class Test
{
	public static void Main()
	{
		Console.WriteLine("Birinci Sayi: ");
		double sayi1 = Convert.ToDouble(Console.ReadLine());
		Console.WriteLine("Ikinci Sayi: ");
		double sayi2 = Convert.ToDouble(Console.ReadLine());
		Console.WriteLine("Toplama: 1, Cikarma: 2, Carpma: 3, Bolme: 4, Cikis: -1");
		int islem = Convert.ToInt32(Console.ReadLine());
		double sonuc = 0;
		if(islem == 1) {
			sonuc = sayi1 + sayi2;
		} else if(islem == 2) {
			sonuc = sayi1 - sayi2;
		} else if(islem == 3) {
			sonuc = sayi1 * sayi2;
		} else if(islem == 4) {
			if(sayi2 == 0) {
				Console.WriteLine("Bir sayi 0 ile bolunemez!");
			} else {
				sonuc = sayi1 / sayi2;
			}
		} else if(islem == -1) {
			Console.WriteLine("Cikis yapiliyor");
		}
		// Console.WriteLine(sonuc);
		Console.WriteLine("Sonuc: {0}", sonuc);
	}
}