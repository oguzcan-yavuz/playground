using System;

interface IParentInterface {
    void ParentInterfaceMethod();
}

interface IMyInterface : IParentInterface {
    void MethodToImplement();
}

class InterfaceImplementer : IMyInterface {
    static void Main() {
        InterfaceImplementer iImp = new InterfaceImplementer();
        iImp.ParentInterfaceMethod();
        iImp.MethodToImplement();
    }

    public void ParentInterfaceMethod() {
        Console.WriteLine("Parent interface method");
    }

    public void MethodToImplement() {
        Console.WriteLine("Method to implement");
    }
}
