using QuanLiTruongHoc.GV;
using QuanLiTruongHoc.SV;
using System;
using System.Collections;
using System.Collections.Generic;

namespace QuanLiTruongHoc
{
    class Program
    {
        static void Main(string[] args)
        {
			var lop = new List<SinhVien>();
			GiangVienBienChe gvbc = new GiangVienBienChe();
			GiangVienHopDong gvhd = new GiangVienHopDong();
			int flag=0;
			int key=0;
			do
			{
				Console.WriteLine("=====================&Manage School&=====================");
				Console.WriteLine("1. Nhap thong tin giao vien");
				Console.WriteLine("2. Xem thong tin giang vien");
				Console.WriteLine("3. Nhap thong tin sinh vien");
				Console.WriteLine("4. Xuat thong tin sinh vien cua lop");
				Console.WriteLine("5. Tim kiem sinh vien theo ten");
				Console.WriteLine("6. In diem trung binh cua cac sinh vine");
				Console.WriteLine("0. Thoat");
				Console.WriteLine("=====================&Manage School&=====================");
				Console.Write(" Chon chuc nang: ");
				key = int.Parse(Console.ReadLine());
				switch (key)
				{
					case 0:
						break;
					case 1:
						{
							int func = 0;
							do
							{
								Console.Clear();
								Console.WriteLine("==============&Quan li Giang vien&=============");
								Console.WriteLine("1. Giao vien bien che");
								Console.WriteLine("2. Giao vien hop dong");
								Console.WriteLine("0. Thoat");
								Console.WriteLine("==============&Quan li Giang vien&=============");
								Console.Write("Chon giao vien: ");
								func = int.Parse(Console.ReadLine());
								switch (func)
								{
									case 0:
										break;
									case 1:
										{
											flag = 0;
											gvbc.Input();
											break;
										}
									case 2:
										{
											flag = 1;
											gvhd.Input();
											break;
										}
									default:
										Console.WriteLine("Chuc nang khong hop le!");
										break;
								}
							} while (func != 0);
							Console.Clear();
							break;
						}
					case 2:
						if (flag == 0)
						{
							gvbc.ShowInfo();
							Console.WriteLine("Luong: "+ gvbc.TinhLuong());
						}
						else
						{
							gvhd.ShowInfo();
							Console.WriteLine( "Luong: "+ gvhd.TinhLuong());
						}
						break;
					case 3:
						{
							Console.Clear();
							int func = 0;
							do
							{
								Console.Clear();
								Console.WriteLine("==============&Quan li Sinh vien&=============");
								Console.WriteLine("1. Sinh vien kinh te");
								Console.WriteLine("2. Sinh vien cntt");
								Console.WriteLine("0. Thoat" );
								Console.WriteLine("==============&Quan li Sinh vien&=============");
								Console.Write( "Chon sinh vien: ");
								func = int.Parse(Console.ReadLine());
								switch (func)
								{
									case 0:
										break;
									case 1:
										var sv = new SinhVienKinhTe();
										sv.Input();
										lop.Add(sv);
										break;
									case 2:
										var sv1 = new SinhVienCNTT();
										sv1.Input();
										lop.Add(sv1);
										break;
									default:
										Console.WriteLine("Chuc nang khong hop le!");
										break;
								}
							} while (func != 0);
							Console.Clear();
							break;
						}
					case 4:
						Console.WriteLine("Thong tin cac sinh vien");
						foreach(SinhVien s in lop){
							s.ShowInfo();
                        }
						break;
					case 5:
						{
							string name;
							Console.Write("Nhap ten sinh vien muon tim: ");
							name = Console.ReadLine();
							int mark = 0;
							
							for (int i = 0; i < lop.Capacity; i++)
							{
                                if (lop[i].Name == name)
                                {
									lop[i].ShowInfo();
									mark = 1;
                                }
							}
							if (mark == 0)
							{
								Console.WriteLine("Khong tim thay sinh vien nao co ten "+name);
							}
							break;
						}
					case 6:
						{
							for (int i = 0; i < lop.Capacity; i++)
							{
								if (flag == 0)
								{
									Console.WriteLine("Ten: " + lop[i].Name + "----------Diem: " + gvbc.ChamDiem(lop[i].Mark, lop[i].ChuyenCan));
								}
								else
								{
									Console.WriteLine("Ten: " + lop[i].Name + "----------Diem: " + gvhd.ChamDiem(lop[i].Mark, lop[i].ChuyenCan));
								}
							}
							break;
						}
					default:
						Console.WriteLine("Chuc nang khong hop le");
						break;
				}
				//Console.Clear();
			} while (key != 0);
		}
    }
}
