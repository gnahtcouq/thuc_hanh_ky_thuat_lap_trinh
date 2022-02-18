#include <iostream>
using namespace std;
#define MAX 100

struct NhanVien {
  int ma;
  char hoTen[30];
  int luongCB;
  float heSoLuong;
};
typedef struct NhanVien NHANVIEN;

struct CongTy {
  NHANVIEN ds[100];
  int soLuong;
};
typedef struct CongTy CONGTY;

void nhapNhanVien(NHANVIEN &nv);
void xuatNhanVien(NHANVIEN nv);
void nhapDanhSachNhanVien(CONGTY &dsnv);
void xuatDanhSachNhanVien(CONGTY dsnv);
bool ghiDanhSachNhanVien(CONGTY dsnv, char *tenFile);
bool docDanhSachNhanVien(CONGTY &dsnv, char *tenFile);
int tinhTongLuong(CONGTY dsnv);
bool xuatThongTinNhanVienTheoMa(CONGTY dsnv);
void menu();
int chonMenu();
void xuLyMenu();
void sapXepNhanVien(CONGTY dsnv);
void timNhanVienCoLuongCaoNhat(CONGTY dsnv);
void timNhanVienCoLuongCaoNhat(CONGTY dsnv);
void xoaNhanVienCoHeSoLuongThapNhat(CONGTY &dsnv);

int main() {
  // NHANVIEN nv;
  // CONGTY ds;

  // // nhapDanhSachNhanVien(ds);
  // // if (ghiDanhSachNhanVien(ds, "danhsachnhanvien.dat"))
  // //   cout << "\nGhi file thanh cong" << endl;
  // // else
  // //   cout << "\nGhi file khong duoc";
  // // xuatDanhSachNhanVien(ds);

  // if (docDanhSachNhanVien(ds, "danhsachnhanvien.dat")) {
  //   cout << "\nThong tin cua cac nhan vien vua doc la: " << endl;
  //   xuatDanhSachNhanVien(ds);
  //   cout << "\nTong luong cua cac nhan vien trong cong ty la: " << tinhTongLuong(ds) << endl;
  //   if (!xuatThongTinNhanVienTheoMa(ds))
  //     cout << "Khong tim thay";
  // }
  // else {
  //   cout << "\nDoc khong duoc";
  //   exit;
  // }

	menu();
	while (true)
	{	
		xuLyMenu();
	}


  cout << endl;
  system("pause");
  return 0;
}


void nhapNhanVien(NHANVIEN &nv) {
  cout << "Nhap ma nhan vien: ";
  cin >> nv.ma;
  cin.ignore();
  cout << "Nhap ten nhan vien: ";
  cin.getline(nv.hoTen, 30);
  cout << "Nhap luong can ban: ";
  cin >> nv.luongCB;
  cout << "Nhap he so luong: ";
  cin >> nv.heSoLuong;
  cout << endl;
  cin.ignore();
}

void xuatNhanVien(NHANVIEN nv) {
  cout << nv.ma << "\t" << nv.hoTen << "\t" << nv.luongCB << "\t" << nv.heSoLuong << endl;
}

void nhapDanhSachNhanVien(CONGTY &dsnv) {
  do {
    cout << "\nNhap so luong nhan vien: ";
    cin >> dsnv.soLuong;
  } while (dsnv.soLuong <= 0 || dsnv.soLuong > MAX);
  cin.ignore();
  for (int i = 0; i < dsnv.soLuong; i++) {
    nhapNhanVien(dsnv.ds[i]);
  }
}

void xuatDanhSachNhanVien(CONGTY dsnv) {
  for (int i = 0; i < dsnv.soLuong; i++) {
    xuatNhanVien(dsnv.ds[i]);
  }
}

bool ghiDanhSachNhanVien(CONGTY dsnv, char *tenFile) {
  FILE *f;
  f = fopen(tenFile, "wb");
  if (f == NULL)
    return false;
  fwrite(&dsnv.soLuong, sizeof(int), 1, f);
  fwrite(&dsnv.ds, sizeof(NHANVIEN), dsnv.soLuong, f);
  fclose(f);
  return true;
}

bool docDanhSachNhanVien(CONGTY &dsnv, char *tenFile) {
  FILE *f;
  f = fopen(tenFile, "rb");
  if (f == NULL)
    return false;
  fread(&dsnv.soLuong, sizeof(int), 1, f);
  fread(&dsnv.ds, sizeof(NHANVIEN), dsnv.soLuong, f);
  fclose(f);
  return true;
}

// Cau 5
int tinhTongLuong(CONGTY dsnv) {
  float tongLuong = 0;
  for (int i = 0; i < dsnv.soLuong; i++) {
    tongLuong += dsnv.ds[i].heSoLuong * dsnv.ds[i].luongCB;
  }
  return tongLuong;
}

// Cau 6
bool xuatThongTinNhanVienTheoMa(CONGTY dsnv) {
  int x;
  cout << "Nhap ma nhan vien can tim: ";
  cin >> x;
  for (int i = 0; i <= dsnv.soLuong; i++) {
    if (x == dsnv.ds[i].ma) {
      xuatNhanVien(dsnv.ds[i]);
      return true;
    }
  }
  return false;
}

// Cau 7
void menu() {
  cout << "*----------------------------MENU----------------------------*\n";
  cout << "|1. Nhap nhan vien\n";
  cout << "|2. Xuat nhan vien\n";
  cout << "|3. Nhap cong ty\n";
  cout << "|4. Xuat cong ty\n";
  cout << "|5. Tong luong cua cac nhan vien trong cong ty\n";
  cout << "|6. Xuat thong tin nhan vien theo ma\n";
  cout << "|8. Sap xep nhan vien theo he so luong\n";
  cout << "|9. Danh sach nhan vien co luong cao nhat\n";
  cout << "|10. Xoa nhan vien co he so luong thap nhat\n";
  cout << "|0. Thoat.\n";
  cout << "*-------------------------------------------------------------*\n";
}

int chonMenu() {
  int n = 0;
  cout << "\n\nNhap lua chon cua ban: ";
  cin >> n;
  if (n > 0 || n < 6)
    return n;
  else return chonMenu();
}

void xuLyMenu() {
  NHANVIEN nv;
  CONGTY ds;
  int x;
  int chon = chonMenu();
  switch (chon) {
  case 1:
    cout << "1. Nhap nhan vien\n";
    nhapNhanVien(nv);
    break;
  case 2:
    cout << "2. Xuat nhan vien\n";
    xuatNhanVien(nv);
    break;
  case 3:
    cout << "3. Nhap cong ty\n";
    nhapDanhSachNhanVien(ds);
    break;
  case 4:
    cout << "4. Xuat cong ty\n";
    xuatDanhSachNhanVien(ds);
    break;
  case 5:
    cout << "5. Tong luong cua cac nhan vien trong cong ty\n";
    cout << "Tong luong cua cac nhan vien trong cong ty la: " << tinhTongLuong(ds) << endl;
    break;
  case 6:
    cout << "6. Xuat thong tin nhan vien theo ma\n";
    if (!xuatThongTinNhanVienTheoMa(ds))
      cout << "Khong tim thay";
    break;
  case 8:
    cout << "8. Sap xep nhan vien theo he so luong\n";
    sapXepNhanVien(ds);
    break;
  case 9:
    cout << "9. Danh sach nhan vien co luong cao nhat\n";
    timNhanVienCoLuongCaoNhat(ds);
    break;
  case 10:
    cout << "10. Xoa nhan vien co he so luong thap nhat\n";
    xoaNhanVienCoHeSoLuongThapNhat(ds);
    xuatDanhSachNhanVien(ds);
    break;
  case 0:
    cout << "Thoat.\n";
    exit(1);
    break;
  }
}


// Cau 8
void sapXepNhanVien(CONGTY dsnv) {
  for (int i = 0; i < dsnv.soLuong; i++)
    for (int j = i + 1; j < dsnv.soLuong; j++)
      if (dsnv.ds[i].heSoLuong > dsnv.ds[j].heSoLuong)
        swap(dsnv.ds[i], dsnv.ds[j]);
  xuatDanhSachNhanVien(dsnv);
}

// Cau 9
void timNhanVienCoLuongCaoNhat(CONGTY dsnv) {
  float max = dsnv.ds[0].luongCB * dsnv.ds[0].heSoLuong;
  for (int i = 1; i < dsnv.soLuong; i++)
    if (dsnv.ds[i].luongCB * dsnv.ds[i].heSoLuong > max)
      max = dsnv.ds[i].luongCB * dsnv.ds[i].heSoLuong;
  for (int i = 0; i < dsnv.soLuong; i++)
    if (dsnv.ds[i].luongCB * dsnv.ds[i].heSoLuong == max)
      xuatNhanVien(dsnv.ds[i]);
}

// Cau 10
void xoaNhanVien(CONGTY &dsnv, int vitrixoa) {
  for(int i = vitrixoa; i < dsnv.soLuong - 1; i++)
    dsnv.ds[i] = dsnv.ds[i - 1];
  dsnv.soLuong--;
}

void xoaNhanVienCoHeSoLuongThapNhat(CONGTY &dsnv) {
  int min = dsnv.ds[0].heSoLuong;
  for (int i = 1; i < dsnv.soLuong; i++)
    if (dsnv.ds[i].heSoLuong < min)
      min = dsnv.ds[i].heSoLuong;
  for (int i = 0; i < dsnv.soLuong; i++)
    if (dsnv.ds[i].heSoLuong == min) {
      xoaNhanVien(dsnv, i);
      i--;
    }
}