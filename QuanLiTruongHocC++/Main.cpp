#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Person {
private:
	string name;
	int age;
public:
	string Name() {
		return this->name;
	}
	int Age() {
		return this->age;
	}
	void Name(string name) {
		this->name = name;
	}
	void Age(int age) {
		this->age = age;
	}
	void virtual Input() {
		cout << "->Name: ";
		cin >> this->name;
		cout << "->Age: ";
		cin >> this->age;
	}
	void virtual ShowInfo() {
		cout << "Name: " << this->name << endl;
		cout << "Age: " << this->age << endl;
	}
};
class SinhVien : public Person {
private:
	string studentId;
	double mark;
	double chuyenCan;
public:
	string StudentId() {
		return this->studentId;
	}
	double Mark() {
		return this->mark;
	}
	double ChuyenCan() {
		return this->chuyenCan;
	}
	void StudentId(string studentId) {
		this->studentId = studentId;
	}
	void Mark(double mark) {
		this->mark = mark;
	}
	void ChuyenCan(double chuyenCan) {
		this->chuyenCan = chuyenCan;
	}
	void Input() {
		Person::Input();
		cout << "->Student ID: ";
		cin >> this->studentId;
		cout << "->Mark: ";
		cin >> this->mark;
		cin.ignore();
		cout << "->Chuyen can: ";
		cin >> this->chuyenCan;
	}
	void ShowInfo() {
		Person::ShowInfo();
		cout << "Student ID: " << this->studentId << endl;
		cout << "Mark: " << this->mark << endl;
		cout << "Chuyen can: " << this->chuyenCan << endl;
	}
	bool operator ==(SinhVien sv) {
		if (this->Name() == sv.Name() && this->Age() == sv.Age() && this->StudentId() == sv.StudentId() && this->Mark() == sv.Mark() && this->ChuyenCan() == sv.ChuyenCan()) {
			return true;
		}
		return false;
	}
	bool operator !=(SinhVien sv) {
		if (this->Name() != sv.Name() || this->Age() != sv.Age() || this->StudentId() != sv.StudentId() || this->Mark() != sv.Mark() || this->ChuyenCan() != sv.ChuyenCan()) {
			return true;
		}
		return false;
	}
};
class SinhVienCNTT :public SinhVien {
private:
	string doAn;
	string DoAn() {
		return this->doAn;
	}
	void DoAn(string doAn) {
		this->doAn = doAn;
	}
public:
	void Input() {
		SinhVien::Input();
		cin.ignore();
		cout << "->Do an: ";
		cin >> this->doAn;
	}
	void ShowInfo() {
		SinhVien::ShowInfo();
		cout << "Do an: " << this->doAn << endl;
	}
};
class SinhVienKinhTe :public SinhVien {
private:
	string khoaLuan;
public:
	string KhoaLuan() {
		return this->khoaLuan;
	}
	void KhoaLuan(string khoaLuan) {
		this->khoaLuan = khoaLuan;
	}
	void Input() {
		SinhVien::Input();
		cin.ignore();
		cout << "->Khoa luan: ";
		cin >> this->khoaLuan;
	}
	void ShowInfo() {
		SinhVien::ShowInfo();
		cout << "Khoa luan: " << this->khoaLuan << endl;
	}
};
class CanBo :public Person {
private:
	string khoa;
public:
	CanBo() {

	}
	string Khoa() {
		return this->khoa;
	}
	void Khoa(string khoa) {
		this->khoa = khoa;
	}
	void Input() {
		Person::Input();
		cout << "->Khoa: ";
		cin >> this->khoa;
	}
	void ShowInfo() {
		Person::ShowInfo();
		cout << "Khoa: " << this->khoa << endl;
	}
	double virtual TinhLuong() = 0;
};
class DayHoc {
public:
	double virtual ChamDiem(double mark, double chuyenCan) = 0;
	void virtual KiemTraGiuaKi() = 0;
};
class GiangVienBienChe :public CanBo, DayHoc {
private:
	double heSoLuong;
public:
	double HeSoLuong() {
		return this->heSoLuong;
	}
	void HeSoLuong(double heSoLuong) {
		this->heSoLuong = heSoLuong;
	}
	void Input() {
		CanBo::Input();
		cout << "->He so luong: ";
		cin >> this->heSoLuong;
	}
	void ShowInfo() {
		CanBo::ShowInfo();
		cout << "He so luong: " << this->heSoLuong << endl;
	}
	double TinhLuong() {
		return this->heSoLuong * 5000 + 200;
	}
	double ChamDiem(double mark, double chuyenCan) {
		return mark * 0.6 + chuyenCan * 0.4;
	}
	void KiemTraGiuaKi() {
		cout << "Kiem tra khi da hoc het chuong trinh" << endl;
	}
};
class GiangVienHopDong :public CanBo, DayHoc {
private:
	int soTietDay;
public:
	int SoTietDayHoc() {
		return this->soTietDay;
	}
	void HeSoLuong(int soTietDay) {
		this->soTietDay = soTietDay;
	}
	void Input() {
		CanBo::Input();
		cout << "->So tiet day: ";
		cin >> this->soTietDay;
	}
	void ShowInfo() {
		CanBo::ShowInfo();
		cout << "So tiet day: " << this->soTietDay << endl;

	}
	double TinhLuong() {
		return this->soTietDay * 1.0* 250;
	}
	double ChamDiem(double mark, double chuyenCan) {
		return mark * 0.7 + chuyenCan * 0.3;
	}
	void KiemTraGiuaKi() {
		cout << "Kiem tra khi da hoc duoc 2/3 chuong trinh" << endl;
	}
};
int main() {
	vector<SinhVien*> lop;
	GiangVienBienChe* gvbc = new GiangVienBienChe();
	GiangVienHopDong* gvhd = new GiangVienHopDong();
	int flag = 0;
	int key;
	do {
		cout << "=====================&Manage School&=====================" << endl;
		cout << "1. Nhap thong tin giao vien" << endl;
		cout << "2. Xem thong tin giang vien" << endl;
		cout << "3. Nhap thong tin sinh vien" << endl;
		cout << "4. Xuat thong tin sinh vien cua lop" << endl;
		cout << "5. Tim kiem sinh vien theo ten" << endl;
		cout << "6. In diem trung binh cua cac sinh vine" << endl;
		cout << "0. Thoat" << endl;
		cout << "=====================&Manage School&=====================" << endl;
		cout << "Chon chuc nang: ";
		cin >> key;
		switch (key) {
		case 0:
			break;
		case 1: {
			int func = 0;
			do {
				system("cls");
				cout << "==============&Quan li Giang vien&=============" << endl;
				cout << "1. Giao vien bien che" << endl;
				cout << "2. Giao vien hop dong" << endl;
				cout << "0. Thoat" << endl;
				cout << "==============&Quan li Giang vien&=============" << endl;
				cout << "Chon giao vien: ";
				cin >> func;
				switch (func) {
				case 0:
					break;
				case 1: {
					flag = 0;
					gvbc->Input();
					break;
				}
				case 2: {
					flag = 1;
					gvhd->Input();
					break;
				}
				default:
					cout << "Chuc nang khong hop le" << endl;
					break;
				}
			} while (func != 0);
			system("cls");
			break;
		}
		case 2:
			if (flag == 0) {
				gvbc->ShowInfo();
				cout << "Luong: " << gvbc->TinhLuong() << endl;
			}
			else {
				gvhd->ShowInfo();
				cout << "Luong: " << gvhd->TinhLuong() << endl;
			}
			break;
		case 3: {
			system("cls");
			int func = 0;
			SinhVien* sv;
			do {
				system("cls");
				cout << "==============&Quan li Sinh vien&=============" << endl;
				cout << "1. Sinh vien kinh te" << endl;
				cout << "2. Sinh vien cntt" << endl;
				cout << "0. Thoat" << endl;
				cout << "==============&Quan li Sinh vien&=============" << endl;
				cout << "Chon sinh vien: ";
				cin >> func;
				switch (func) {
				case 0:
					break;
				case 1:
					sv = new SinhVienKinhTe();
					sv->Input();
					lop.push_back(sv);
					break;
				case 2:
					sv = new SinhVienCNTT();
					sv->Input();
					lop.push_back(sv);
					break;
				default:
					cout << "Chuc nang khong hop le" << endl;
					break;
				}
			} while (func != 0);
			system("cls");
			break;
		}
		case 4:
			cout << "Thong tin cac sinh vien" << endl;
			for (int i = 0; i < lop.size(); i++) {
				lop.at(i)->ShowInfo();
			}
			break;
		case 5: {
			string name;
			cout << "Nhap ten sinh vien muon tim: ";
			cin.ignore();
			getline(cin, name);
			int mark = 0;
			for (int i = 0; i < lop.size(); i++) {
				if (lop.at(i)->Name() == name) {
					lop.at(i)->ShowInfo();
					mark = 1;
				}
			}
			if (mark == 0) {
				cout << "Khong tim thay sinh vien nao co ten " << name << endl;
			}
			break;
		}	
		case 6: {
			for (int i = 0; i < lop.size(); i++) {
				if (flag == 0) {
					cout << "Ten: " << lop.at(i)->Name() << "----------Diem: "<< gvbc->ChamDiem(lop.at(i)->Mark(), lop.at(i)->ChuyenCan()); 
					cout<< endl;
				}
				else {
					cout << "Ten: " << lop.at(i)->Name() << "----------Diem: "<<gvhd->ChamDiem(lop.at(i)->Mark(), lop.at(i)->ChuyenCan());
					cout<< endl;
				}
			}
			break;
		}
		default:
			cout << "Chuc nang khong hop le" << endl;
			break;
		}
		//system("cls");
	} while (key != 0);
	return 0;
}