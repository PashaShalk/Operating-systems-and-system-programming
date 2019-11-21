using System;
using System.IO;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] symbols = new char[] {'1','2','\r','3','4','5','\r','a','b','c','d','\r','f','h','g','\r','j','r','t','\r'};

            try
            {
                using (StreamWriter writer =new StreamWriter("C://Users//vanya//Desktop//Osi//test1.txt"))
                {
                    for(int i = 0; i < (int)Math.Pow(2, 30); i++) {
                        writer.Write(symbols[new Random().Next(0,symbols.Length)]);
                        if(i==(int)(Math.Pow(2,5)) || i == (int)(Math.Pow(2, 25)) || i == (int)(Math.Pow(2, 28)))
                        {
                            Console.WriteLine(i);
                        }
                    }
                }
            }catch(IOException e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}
