using System;

public class DrawObject {
    public virtual void Draw() {
        Console.WriteLine("Virtual method of DrawObject class");
    }
}

public class Line : DrawObject {
    public override void Draw() {
        Console.WriteLine("Override method of Line class");
    }
}

public class Circle : Line {
    public override void Draw() {
        Console.WriteLine("Override method of Circle class");
    }
}

class MainClass {
    public static void Main(string[] args) {
        Circle circ = new Circle();
        circ.Draw();
        ((Line)circ).Draw();        // prints Circle class's Draw method because Line class's Draw method is overriden.
        Line line = new Line();
        line.Draw();

        // making an object and storing instances in that object array
        DrawObject[] DO = new DrawObject[3];
        DO[0] = new Line();
        DO[1] = new Circle();
        DO[2] = new DrawObject();
        foreach(DrawObject obj in DO) {
            obj.Draw();
        }

    }
}
