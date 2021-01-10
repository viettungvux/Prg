using QuanLiTruongHoc.Common;
using System;
using System.Collections.Generic;
using System.Text;

namespace QuanLiTruongHoc.GV
{
    public abstract class CanBo:Person
    {
        private string khoa;

        public string Khoa { get => khoa; set => khoa = value; }
        public void Input()
        {
            base.Input();
            Console.WriteLine("->Khoa: ");
            this.Khoa = Console.ReadLine();
        }
        public void ShowInfo()
        {
            base.ShowInfo();
            Console.WriteLine("Khoa: "+this.Khoa);
        }
        public abstract double TinhLuong();
    }
}
