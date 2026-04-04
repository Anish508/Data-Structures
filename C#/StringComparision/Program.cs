using System;
using System.ComponentModel;   // 📦 Library (required for Console)

namespace MyApp   // (optional but recommended)
{
      class Program   // Class
      {
            static void Main(string[] args)   // Entry point 🚀
            {
                  Console.WriteLine("Enter first string:");
                  string s1 = Console.ReadLine();

                  Console.WriteLine("Enter first string:");
                  string s2 = Console.ReadLine();

                  int l1, l2;
                  l1 = l2 = 0;

                  foreach (char c in s1)
                  {
                        l1++;
                  }
                  foreach (char c in s2)
                  {
                        l2++;
                  }

                  if (l1 < l2)
                  {
                        Console.WriteLine("First string smaller then second string");
                  }
                  else if (l1 > l2)
                  {
                        Console.WriteLine("second string smaller then first string");
                  }
                  else
                  {
                        Console.WriteLine("Strings are equal");
                        Console.WriteLine("Comparing ascii vise:");
                        int r = 0, position = -1;
                        for (int i = 0; i < l1; i++)
                        {
                              if (s1[i] != s2[i])
                              {
                                    r = s1[i] - s2[i];
                                    position = i;
                                    break;
                              }
                        }
                        if (r == 0)
                        {
                              Console.WriteLine("Strings are equal");
                        }
                        else if (r < 0)
                        {
                              Console.WriteLine("First string is samller in the postion {0} and returning {1}", position + 1, r);
                        }
                        else
                        {
                              Console.WriteLine("second string is samller in the postion {0} and returning {1}", position + 1, r);
                        }

                        char ch1, ch2;
                        r = 0;
                        position = -1;
                        Console.WriteLine("Comparing text based vise:");
                        for (int i = 0; i < l1; i++)
                        {
                              ch1 = (s1[i] >= 'a' && s1[i] <= 'z') ? (char)(s1[i] - 32) : s1[i];
                              ch2 = (s2[i] >= 'a' && s2[i] <= 'z') ? (char)(s2[i] - 32) : s2[i];
                              if (ch1 != ch2)
                              {
                                    r = ch1 - ch2;
                              }
                        }
                        if (r == 0)
                        {
                              Console.WriteLine("Strings are equal");
                        }
                        else if (r < 0)
                        {
                              Console.WriteLine("First string is samller in the postion {0} and returning {1}", position + 1, r);
                        }
                        else
                        {
                              Console.WriteLine("second string is samller in the postion {0} and returning {1}", position + 1, r);
                        }
                  }

                  Console.Read();
            }
      }
}