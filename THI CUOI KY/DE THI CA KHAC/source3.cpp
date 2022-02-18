#include <iostream>
using namespace std;
const int MAX = 50;
struct DAYSO {
  int list[MAX];
  int n;
};

void nhapMang(DAYSO& a);
void xuatMang(DAYSO a);
int demKeChan(DAYSO a);

struct matran {
  float mt[MAX][MAX];
  int dong;
  int  cot;
};
void nhapmt(matran& m);
void xuatmt(matran m);
void fullAm(matran m);

struct Ngay {
  int ngay, thang, nam;
};

struct PET {
  char maPet[10];
  char loaiPet[50];
  Ngay ngaySinhPet;
  int giaPet;
};
struct PETLIST {
  int slpet;
  PET DSPET[MAX];
};
void nhapPet(PET& p);
void xuatPet(PET& p);
void nhapDSPet(PETLIST& P);
void xuatDSPet(PETLIST& P);
int petGiaMax(PETLIST P);
void xuatDSpetGiaMax(PETLIST P);
void sapXepGiamDanTheoNgaySinh(PETLIST& P);

int main() {

  DAYSO a;
  matran m;
  PETLIST P;
  int menu;
  do {
    cout << "\n--------------------------------";
    cout << "\n 0: Thoat!!! ";
    cout << "\n 1: Dem so luong phan tu ke nhau ma ca hai deu chan!!!";
    cout << "\n 2: Liet ke cac dong toan am trong ma tran cac so thuc!!!";
    cout << "\n 3: Nhap DS thu cung!!!";
    cout << "\n 4: Xuat DS thu cung!!!";
    cout << "\n 5: Xuat DS thu cung gia cao nhat";
    cout << "\n 6: Sap xep DS thu cung giam dan theo ngay sinh";
    cout << endl;
    cin >> menu;
    switch (menu) {
    case 0:break;
    case 1: {
      nhapMang(a);
      xuatMang(a);
      cout << "\nSo Luong phan tu ke nhau ma ca hai deu chan la: " << demKeChan(a);
      break;
    }
    case 2: {
      nhapmt(m);
      xuatmt(m);
      cout << "\nCac dong toan am trong ma tran: ";
      fullAm(m);
      break;
    }
    case 3: {
      nhapDSPet(P);
      break;
    }
    case 4: {
      xuatDSPet(P);
      break;
    }
    case 5: {
      cout << "\nDanh sach pet gia max" << endl;
      xuatDSpetGiaMax(P);
      break;
    }
    case 6: {
      cout << "\nSap xep giam dan theo ngay sinh" << endl;
      sapXepGiamDanTheoNgaySinh(P);
      break;
    }
    default: {
      cout << "\n Chuc nang ban chon KHONG ton tai!!!!";
      break;
    }
    }
  } while (menu != 0);

  system("pause");
}


//1.     Hãy xác định số lượng các phần tử kề nhau mà cả hai đều chẵn.
void nhapMang(DAYSO& a) {
  cout << "\nNhap so phan tu : ";
  cin >> a.n;
  for (int i = 0; i < a.n; i++) {
    cout << "a[" << i << "] = ";
    cin >> a.list[i];
  }
}

void xuatMang(DAYSO a) {
  for (int i = 0; i < a.n - 1; i++)
    cout << " " << a.list[i];
}

int demKeChan(DAYSO a) {
  int dem = 0;
  for (int i = 0; i < a.n; i++) {
    if (i == 1)
      if (a.list[1] % 2 == 0 && a.list[0] % 2 == 0)
        dem++; 
    if (i == a.list[a.n - 1])
      if (a.list[a.n - 1] % 2 ==0 && a.list[a.n - 2] % 2 == 0)
        dem++;
    if (i > 1 && i < a.list[a.n - 1])
      if (a.list[i] % 2 == 0 && a.list[i + 1] % 2 == 0)
        dem++;
  }
  return dem;
}
//2.     Liệt kê các dòng toàn âm trong ma trận các số thực.

void nhapmt(matran& m) {
  cout << "\nnhap so dong: ";
  cin >> m.dong;
  cout << "\nnhap so cot:";
  cin >> m.cot;
  for (int i = 0; i < m.dong; i++) {
    for (int j = 0; j < m.cot; j++) {
      cout << "ma[" << i << "][" << j << "]=";
      cin >> m.mt[i][j];
    }
  }

}
void xuatmt(matran m) {
  for (int i = 0; i < m.dong; i++) {
    cout << endl;
    for (int j = 0; j < m.cot; j++)
      cout << m.mt[i][j] << "\t";
  }
}

void fullAm(matran m) {
  int flag = 0;
  for (int i = 0; i < m.dong; i++) {
    for (int j = 0; j < m.cot; j++) {
      if (m.mt[i][j] >= 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      cout << "\ndong " << i + 1 << " toan am\n";
  }
}

//3.     Viết hàm cho phép chuẩn hóa chuỗi.(xóa khoảng trắng đầu và cuối chuỗi, xóa những khoảng trắng dư thừa giữa các từ)
//em khong hieu yeu cau de!!!
//4.      Viết chương trình thực hiện các yêu cầu sau :
//a.Nhập mảng 1 chiều các thú cưng.Biết rằng thông tin một thú cưng gồm những thành phần sau :
//-Mã thú : chuỗi tối đa 10 ký tự
//- Loại thú : chuỗi tối đa 50 ký tự
//- Ngày sinh : kiểu ngày(ngày, tháng, năm: kiểu nguyên)
//- Giá : kiểu nguyên
//b.Xuất mảng
//c.Liệt kê danh sách các thú cưng có giá cao nhất.
//d.Thống kê số lượng khách thú cưng theo loại thú.
//e.Sắp xếp các phần tử trong mảng giảm dần theo ngày sinh.
void nhapPet(PET& p) {
  cin.ignore();
  cout << "\nMa thu cung: ";
  cin.getline(p.maPet, 10 + 1);
  cout << "Loai thu cung: ";
  cin.getline(p.loaiPet, 50 + 1);
  cout << "Ngay sinh cua thu cung: ";
  cin >> p.ngaySinhPet.ngay;
  cout << "Thang sinh cua thu cung: ";
  cin >> p.ngaySinhPet.thang;
  cout << "Nam sinh cua thu cung: ";
  cin >> p.ngaySinhPet.nam;
  cout << "Gia ban cua thu cung: ";
  cin >> p.giaPet;
  cout << endl;
}
void xuatPet(PET& p) {
  cout << "\n Ma thu cung: " << p.maPet;
  cout << "\n Loai thu cung: " << p.loaiPet;
  cout << "\n Ngay sinh thu cung: " << p.ngaySinhPet.ngay << "-" << p.ngaySinhPet.thang << "-" << p.ngaySinhPet.nam;
  cout << "\n Gia thu cung: " << p.giaPet;
  cout << endl;
}
void nhapDSPet(PETLIST& P) {
  cout << "\n Nhap so luong thu cung: ";
  cin >> P.slpet;
  for (int i = 0; i < P.slpet; i++) {
    cout << "\n Thu cung thu " << i + 1;
    nhapPet(P.DSPET[i]);
  }
}
void xuatDSPet(PETLIST& P) {
  for (int i = 0; i < P.slpet; i++) {
    xuatPet(P.DSPET[i]);
  }
}
int petGiaMax(PETLIST P) {
  int max = 0;
  for (int i = 0; i < P.slpet; ++i)
    if (P.DSPET[i].giaPet > max)
      max = P.DSPET[i].giaPet;
  return max;
}

void xuatDSpetGiaMax(PETLIST P) {
  int max = petGiaMax(P);
  for (int i = 0; i < P.slpet; ++i)
    if (P.DSPET[i].giaPet == max)
      xuatPet(P.DSPET[i]);
}

void hoanVi(PET& a, PET& b) {
  PET tam = a;
  a = b;
  b = tam;
}

void sapXepGiamDanTheoNgaySinh(PETLIST& P) {
  for (int i = 0; i < P.slpet; i++)
    for (int j = i + 1; j < P.slpet; j++) {
      if (P.DSPET[i].ngaySinhPet.nam < P.DSPET[j].ngaySinhPet.nam)
        hoanVi(P.DSPET[i], P.DSPET[j]);
      if (P.DSPET[i].ngaySinhPet.nam == P.DSPET[j].ngaySinhPet.nam) {
        if (P.DSPET[i].ngaySinhPet.thang < P.DSPET[j].ngaySinhPet.thang)
          hoanVi(P.DSPET[i], P.DSPET[j]);
        if (P.DSPET[i].ngaySinhPet.thang == P.DSPET[j].ngaySinhPet.thang)
          if (P.DSPET[i].ngaySinhPet.ngay < P.DSPET[j].ngaySinhPet.ngay)
            hoanVi(P.DSPET[i], P.DSPET[j]);
      }
    }
}