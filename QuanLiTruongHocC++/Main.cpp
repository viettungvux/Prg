#include <iostream>
#include <string>
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
static class CanBo :public Person {
private:
	string khoa;
public:
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
	double virtual TinhLuong() {
		return 1;
	}
};
class DayHoc {
public:
	double virtual ChamDiem(double mark, double chuyenCan) {
		return mark * 1 + chuyenCan * 1;
	}
	void virtual KiemTraGiuaKi() {

	}
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
		return this->heSoLuong * 5000000 + 200000;
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
		return this->soTietDay*250000;
	}
	double ChamDiem(double mark, double chuyenCan) {
		return mark * 0.7 + chuyenCan * 0.3;
	}
	void KiemTraGiuaKi() {
		cout << "Kiem tra khi da hoc duoc 2/3 chuong trinh" << endl;
	}
};
int main() {
	return 0;
}