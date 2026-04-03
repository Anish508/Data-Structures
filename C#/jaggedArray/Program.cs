using System;   // 📦 Library (required for Console)

namespace MyApp   // (optional but recommended)
{
      class Program   // Class
      {
            static void Main(string[] args)   // Entry point 🚀
            {

                  Console.WriteLine("Enter total number of customers:");
                  int k = int.Parse(Console.ReadLine());

                  double[][] cust = new double[k][];

                  for (int i = 0; i < k; i++)
                  {
                        Console.WriteLine("Enter total item purchased by customer {0}:", i + 1);
                        int item = int.Parse(Console.ReadLine());
                        cust[i] = new double[item];

                        for (int j = 0; j < item; j++)
                        {
                              Console.WriteLine("Enter cost of the item {0}:", j + 1);
                              double cost = double.Parse(Console.ReadLine());
                              cust[i][j] = cost;
                        }
                  }

                  Console.WriteLine("_______________________________________________");
                  for (int i = 0; i < cust.Length; i++)
                  {
                        double s = 0;
                        Console.WriteLine("Bill for customer {0}:", i + 1);

                        for (int j = 0; j < cust[i].Length; j++)
                        {
                              Console.WriteLine("Item {0} cost is {1}", j + 1, cust[i][j]);
                              s += cust[i][j];
                        }

                        Console.WriteLine("Total amount to pay:{0}", s);
                        Console.WriteLine("_______________________________________________");
                  }
                  Console.ReadLine();
            }
      }
}