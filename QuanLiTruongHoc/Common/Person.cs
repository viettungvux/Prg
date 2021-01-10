using System;
using System.Collections.Generic;
using System.Text;

namespace QuanLiTruongHoc.Common
{
    public abstract class Person
    {
        private string name;
        private int age;
        public string Name { get => name; set => name = value; }
        public int Age { get => age; set => age = value; }
        
        public void Input()
        {
            Console.Write("->Name: ");
            this.name = Console.ReadLine();
            Console.Write("->Age: ");
            this.Age = int.Parse(Console.ReadLine());
        }
        public void ShowInfo()
        {
            Console.WriteLine("Name: "+this.Name);
            Console.WriteLine("Age: "+this.Age);
        }
    }
}
