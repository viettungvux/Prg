using QuanLiTruongHoc.GV;
using QuanLiTruongHoc.SV;
using System;
using System.Collections;

namespace QuanLiTruongHoc
{
    class Program
    {
        static void Main(string[] args)
        {
            SinhVien[] lopHoc = new SinhVien[100];

            int key = 0;
            Console.WriteLine("Nhap thong tin giang vien chu nhiem");
            do
            {
                Console.WriteLine("1. GV hop dong");
                Console.WriteLine("2. GV bien che");
                Console.Write("Chon kieu giao vien: ");
                key = int.Parse(Console.ReadLine());
                switch (key)
                {
                    case 1:
                        GiangVienHopDong gvhd = new GiangVienHopDong();
                        gvhd.Input();

                        break;
                    case 2:
                        GiangVienBienChe gvbc = new GiangVienBienChe();
                        gvbc.Input();
                        break;
                    default:
                        Console.WriteLine("Giang vien khong hop le");
                        break;
                }
            } while (key != 1 && key != 2);
            Console.WriteLine("Nhap thong tin cac sinh vien");
            int i = 0;
            do
            {
                Console.WriteLine("=============================");
                Console.WriteLine("1. Sinh vien Kinh te");
                Console.WriteLine("2.Sinh vien CNTT");
                Console.WriteLine("0. Thoat");
                Console.WriteLine("=============================");
                Console.Write("Chon kieu sinh vien: ");
                key = int.Parse(Console.ReadLine());
                switch (key)
                {
                    case 1:
                        lopHoc[i] = new SinhVienKinhTe();
                        lopHoc[i].Input();
                        break;
                    case 2:
                        lopHoc[i] = new SinhVienCNTT();
                        lopHoc[i].Input();
                        break;
                    case 0:
                        Console.WriteLine("Dang thoat CT");
                        break;
                    default:
                        Console.WriteLine("Chuc nang khong hop le!");
                        break;
                }
                i++;
            } while (key != 0);

            ///In Danh sách sinh viên thuộc khoa CNTT
            foreach (SinhVien sv in lopHoc)
            {
                if (sv is SinhVienCNTT)
                {
                    sv.ShowInfo();
                }
            }
            SinhVien sv1 = new SinhVien();
            SinhVien sv2 = new SinhVienCNTT();
            sv1.Input();
            sv2.Input();
            if (sv1 == sv2)
            {

            }
        }
    }
}
