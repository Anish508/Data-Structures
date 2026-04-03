// Online C# Editor for free
// Write, Edit and Run your C# code using C# Online Compiler

using System;

public class HelloWorld
{
    class Distance{
        private int feet , inches;
        
        public Distance(int feet , int inches){
            this.feet = feet;
            this.inches = inches;
            normalize();
        }
        public void normalize(){
            if(inches>=12){
                feet += inches / 12;
                inches = inches % 12;
            }
            if(inches < 0){
                feet--;
                inches+=12;
            }
        }
        
        public static Distance operator +(Distance d1, Distance d2){
            return new Distance(d1.feet + d2.feet, d1.inches + d2.inches );
        }
         public static Distance operator -(Distance d1, Distance d2){
            int total1 = d1.feet*12 + d1.inches;
            int total2 = d2.feet*12 + d2.inches;
             
             int diff = total1 - total2;
             
             int f = diff / 12;
             int i = diff % 12;
             
             if(i<0){
                 f--;
                 i+=12;
             }
            return new Distance(f, i);
        }
        
        public void print(){
            Console.Write("{0} ' {1} ", feet, inches);
        }
    }
    public static void Main(string[] args)
    {
           
        Console.WriteLine("Enter d1 feet and inches:");
        int f =  int.Parse(Console.ReadLine());
        int i  = int.Parse(Console.ReadLine());
         Distance x = new Distance(f, i);
         
         Console.WriteLine("Enter d2 feet and inches:");
         f =  int.Parse(Console.ReadLine());
         i  = int.Parse(Console.ReadLine());
         Distance y = new Distance(f, i);
         
         
         Distance z;
         
         x.print();
         Console.Write("+");
         y.print();
         z = x+ y;
         Console.Write("=");
         z.print();
         
         Console.WriteLine();
         x.print();
         Console.Write("-");
         y.print();
         z = x- y;
         Console.Write("=");
         z.print();
         
         Console.Read();
         
         
    }
}