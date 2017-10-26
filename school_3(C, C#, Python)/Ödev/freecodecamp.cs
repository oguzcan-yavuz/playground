using System;
using System.Xml;
using HtmlAgilityPack;

public class Program
{
	public static void Main()
	{
	    string username = "yavuzovski";

		var html = @"http://www.freecodecamp.com/" + username;

        HtmlWeb web = new HtmlWeb();

        var htmlDoc = web.Load(html);

        var node = htmlDoc.DocumentNode.SelectSingleNode("//head/title");

        Console.WriteLine("Node Name: " + node.Name + "\n" + node.OuterHtml);
	}
}
