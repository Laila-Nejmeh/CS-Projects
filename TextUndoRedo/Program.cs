using System;
using System.Collections.Generic;
class Program
{
static void Main()
    {
        Stack<string> undoStack = new Stack<string>();
        Stack<string> redoStack = new Stack<string>();
        string currentText = "";
        while (true)
        {
            Console.Clear();
            Console.WriteLine("SIMPLE TEXT EDITOR");
            Console.WriteLine("Current Text:");
            Console.WriteLine(currentText);
            Console.WriteLine("");
            Console.WriteLine("1.Add Text");
            Console.WriteLine("2.Undo");
            Console.WriteLine("3.Redo");
            Console.WriteLine("4.Delete Last Word");
            Console.WriteLine("5.Exit");
            Console.Write("\nChoose:");
            string choice = Console.ReadLine();
            switch (choice)
            {
                case "1":
                    undoStack.Push(currentText);
                    Console.Write("Enter Text:");
                    string newText = Console.ReadLine();
                    currentText += newText;
                    redoStack.Clear();
                    break;
                case "2":
                    if (undoStack.Count > 0)
                    {

                        redoStack.Push(currentText);

                        currentText = undoStack.Pop();
                    }
                    else
                    {
                        Console.WriteLine("Nothing to Undo!");
                        Console.ReadKey();
                    }
                    break;
                case "3":
                    if (redoStack.Count > 0)
                    {
                        undoStack.Push(currentText);
                        currentText = redoStack.Pop();

                    }
                    else
                    {
                        Console.WriteLine("Nothing ro Redo!");
                        Console.ReadKey();
                    }
                    break;
                case "4":
                    if (string.IsNullOrWhiteSpace(currentText))
                    {
                        Console.WriteLine("No text to delete!");
                           Console.ReadKey();
                        break;
                    }
                    undoStack.Push(currentText);
                    redoStack.Clear();
;                       currentText = currentText.Trim();
                    int LastSpace = currentText.LastIndexOf(' ');
                    if (LastSpace == -1)
                        currentText = "";
                    else { currentText=currentText.Substring(0,LastSpace); }
                    break;


                case "5":
                            return;
                        default:
                            Console.WriteLine("Invalid Choice!");
                            Console.ReadKey();
                            break;
                        }
        }      }
}
