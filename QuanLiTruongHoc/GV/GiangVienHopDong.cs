using QuanLiTruongHoc.Common;
using System;
using System.Collections.Generic;
using System.Text;

namespace QuanLiTruongHoc.GV
{
    public class GiangVienHopDong:CanBo, IDayHoc
    {
        private int soNgayCong;

        public int SoNgayCong { get => soNgayCong; set => soNgayCong = value; }
        public new void Input()
        {
            base.Input();
            Console.Write("->So tiet day: ");
            this.SoNgayCong = int.Parse(Console.ReadLine());
        }
        public void ShowInfo()
        {
            base.ShowInfo();
            Console.Write("So tiet day: " + this.SoNgayCong);
        }
        public double ChamDiem(double mark, double chuyen_can)
        {
            return chuyen_can * 0.3 + mark * 0.7;
        }

        public void KiemTraGiuaKi()
        {
            Console.WriteLine("Kiem tra khi da hoc 2/3 chuong trinh");
        }

        public override double TinhLuong()
        {
            return SoNgayCong * 300000;
        }
    }
}
