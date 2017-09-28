using System;

namespace OopExample {
    // Base Class
    class ExampleClass {
        public int size;

        // Base Class constructor'a sahip oldugunda derived class da sahipse bir sorun cikiyor.

        // public ExampleClass(int s) {
        //     Console.WriteLine("Constructor worked!");
        //     size = s;
        // }
        public void SetSize(int s) {
            size = s;
        }
        public int SizeSquare() {
            return size * size;
        }
    }

    // Derived Class
    class Homework: ExampleClass {
        public int homeworks;
        public Homework(int s) {
            Console.WriteLine("Derived class's constructor is working!");
            homeworks = s;
        }
        public void SetHomeworks(int n) {
            homeworks = n;
        }
        public double RootHomework() {
            return Math.Sqrt(homeworks);
        }
    }

    class MainClass {
        public static void Main(string[] args) {

            // ExampleClass'in constructor'u oldugu ornek.

            // ExampleClass exmp = new ExampleClass(522);
            // Console.WriteLine("exmp size = {0}", exmp.size);
            // exmp.SetSize(50);
            // Console.WriteLine("New exmp size = {0}", exmp.size);
            // int sqr = exmp.SizeSquare();
            // Console.WriteLine("Square of the size = {0}", sqr);


            Homework hm = new Homework(21);
            Console.WriteLine("homeworks = {0}", hm.homeworks);
            hm.SetHomeworks(100);
            Console.WriteLine("new homeworks = {0}", hm.homeworks);
            double rt = hm.RootHomework();
            Console.WriteLine("square root of homeworks = {0}", rt);
            hm.SetSize(131);
            Console.WriteLine("size of homeworks = {0}", hm.size);
            int sqr = hm.SizeSquare();
            Console.WriteLine("Square of the size = {0}", sqr);
        }
    }
}
