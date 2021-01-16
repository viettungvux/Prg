using System;
using System.Collections.Generic;
using System.Text;

namespace QuanLiTruongHoc.GV
{
    public class GiangVienBienChe:CanBo, IDayHoc
    {
        private double heSoLuong;

        public double HeSoLuong { get => heSoLuong; set => heSoLuong = value; }
        public new void Input()
        {
            base.Input();
            Console.Write("->He so luong: ");
            this.HeSoLuong = double.Parse(Console.ReadLine());
        }
        public new void ShowInfo()
        {
            base.ShowInfo();
            Console.WriteLine("He so luong: "+this.HeSoLuong);
        }
        public double ChamDiem(double mark, double chuyen_can)
        {
            return chuyen_can * 0.4 + mark * 0.6;
        }
        public void KiemTraGiuaKi()
        {
            Console.WriteLine("Kiem tra khi da hoc het chuong trinh");
        }

        public override double TinhLuong()
        {
            return HeSoLuong * 5000000 + 100000;
        }
    }
}
