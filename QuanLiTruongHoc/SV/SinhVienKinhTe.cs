using System;
using System.Collections.Generic;
using System.Text;

namespace QuanLiTruongHoc.SV
{
    public class SinhVienKinhTe:SinhVien
    {
        private string khoaLuan;

        public string KhoaLuan { get => khoaLuan; set => khoaLuan = value; }
        public override void Input()
        {
            base.Input();
            Console.Write("->Khoa luan: ");
            this.KhoaLuan = Console.ReadLine();
        }
        public override void ShowInfo()
        {
            base.ShowInfo();
            Console.WriteLine("Khoa luan: " + this.KhoaLuan);
        }
    }
}
