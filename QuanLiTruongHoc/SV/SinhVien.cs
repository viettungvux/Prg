using QuanLiTruongHoc.Common;
using System;
using System.Collections.Generic;
using System.Text;

namespace QuanLiTruongHoc.SV 
{ 
    public class SinhVien:Person
    {
        private string studentId;
        private double mark;
        private double chuyenCan;
        public string StudentId { get => studentId; set => studentId = value; }
        public double Mark { get => mark; set => mark = value; }
        public double ChuyenCan { get => chuyenCan; set => chuyenCan = value; }
        public virtual void Input()
        {
            base.Input();
            Console.Write("->Student ID: ");
            this.StudentId = Console.ReadLine();
            Console.Write("->Mark: ");
            this.Mark=double.Parse(Console.ReadLine());
            Console.Write("->Diem chuyen can: ");
            this.ChuyenCan = double.Parse(Console.ReadLine());
        }
        public virtual void ShowInfo()
        {
            base.ShowInfo();
            Console.WriteLine("Student ID: "+this.StudentId);
            Console.WriteLine("Mark: "+this.Mark);
            Console.WriteLine("Chuyen can: " + this.ChuyenCan);
            
        }
        public static bool operator ==(SinhVien sv1, SinhVien sv2)
        {
            if(sv1.Name==sv2.Name && sv1.Age==sv2.Age && sv1.Mark == sv2.Mark && sv1.ChuyenCan==sv2.ChuyenCan && sv1.StudentId==sv2.StudentId)
            {
                return true;
            }
            return false;
        }
        public static bool operator !=(SinhVien sv1, SinhVien sv2)
        {
            if (sv1.Name != sv2.Name || sv1.Age != sv2.Age || sv1.Mark != sv2.Mark && sv1.ChuyenCan != sv2.ChuyenCan || sv1.StudentId != sv2.StudentId)
            {
                return true;
            }
            return false;
        }
    }
}
