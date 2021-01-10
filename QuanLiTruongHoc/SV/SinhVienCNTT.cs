using System;
using System.Collections.Generic;
using System.Text;

namespace QuanLiTruongHoc.SV
{
    public class SinhVienCNTT:SinhVien
    {
        private string doAn;

        public string DoAn { get => doAn; set => doAn = value; }
        public override void Input()
        {
            base.Input();
            Console.Write("->Do an: ");
            this.DoAn = Console.ReadLine();
        }
        public override void ShowInfo()
        {
            base.ShowInfo();
            Console.WriteLine("Do an: "+this.DoAn);
        }
    }
}
