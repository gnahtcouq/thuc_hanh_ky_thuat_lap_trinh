#include <iostream>
using namespace std;
const int MAX = 50;

struct DAYSO {
  int n;
  int list[MAX];
};

int fibonaci(int n);
int giaiThua(int n);
int binarySearch(int a[], int l, int r, int x);
// void khoiTao(DAYSO& a);
// void nhapDaySo(DAYSO& a);
void xuatDaySo(DAYSO a);
void xuatMang(int a[], int n);
void mergeSort_Tang(int a[], int l, int r);
void mergeSort_Giam(int a[], int l, int r);
void merge_Tang(int a[], int l, int m, int r);
void merge_Giam(int a[], int l, int m, int r);
void quickSort_Tang(int a[], int l, int h);
int partition(int a[], int low, int high);
void hoanVi(int& a, int& b);

// // Bai tap tong hop
// struct SinhVien {
//   char mssv[5];
//   char hoLot[30];
//   char ten[10];
//   float dtb;
// };

// struct DSSV {
//   int siSo;
//   SinhVien list[MAX];
// };

// DSSV taoDuLieu();
// void inSinhVien(SinhVien sv);
// void inDSSV(DSSV dssv);
// void mergeSort(SinhVien a[], int l, int r);
// void quickSort(SinhVien[], int l, int h);
// int binarySearch(SinhVien a[], int l, int r, char* mssv);

int main() {
  // DAYSO ds;
  // khoiTao(ds);
  int n;
  do {
    cout << "\nNhap n nguyen duong: ";
    cin >> n;
    if (n <= 0)
      cout << "\nNhap sai. Hay nhap lai";
  } while (n <= 0);

  cout << "\n" << n << " giai thua = " << giaiThua(n) << endl;

  cout << "\nPhan tu thu " << n << " cua day Fibonaci = " << fibonaci(n) << endl;

  // nhapDaySo(ds);
  int a[] = { 4, 23, 5, 8, 7, 9, 12, 16, 11, 17 };
  int a_size = sizeof(a) / sizeof(a[0]);

  int b[] = { 2, 9, 5, 15, 41, 32, 7, 3, 8, 17 };
  int b_size = sizeof(b) / sizeof(b[0]);

  cout << "\nMang a ban dau: ";
  xuatMang(a, a_size);
  mergeSort_Tang(a, 0, a_size - 1);
  cout << "\nSap xep day A = thuat toan MergeSort tang" << endl;
  xuatMang(a, a_size);
  mergeSort_Giam(a, 0, a_size - 1);
  cout << "\nSap xep day A = thuat toan MergeSort giam" << endl;
  xuatMang(a, a_size);

  cout << "\n\nMang b ban dau: ";
  xuatMang(b, a_size);
  quickSort_Tang(b, 0, b_size - 1);
  cout << "\nSap xep day B = thuat toan QuickSort tang" << endl;
  xuatMang(b, b_size);

  // xuatDaySo(ds);


  system("pause");
  return 0;
}

int fibonaci(int n) {
  if (n < 3)
    return 1;
  return fibonaci(n - 1) + fibonaci(n - 2);
}

int giaiThua(int n) {
  if (n == 0 || n == 1)
    return 1;
  return n * giaiThua(n - 1);
}

// Ham tim kiem nhi phan su dung giai thuat de quy
int binarySearch(int a[], int l, int r, int x) {
  if (r >= l) {
    int mid = (l + r) / 2;

    // Neu a[mid] == x; tra ve chi so va ket thuc
    if (a[mid] == x)
      return mid;

    // Neu a[mid] > x, thuc hien tim kiem nua trai cua mang
    if (a[mid] > x)
      return binarySearch(a, l, mid - 1, x);
    // Neu a[mid] < x, thuc hien tim kiem nua phai cua mang
    if (a[mid] < x)
      return binarySearch(a, mid + 1, r, x);
  }

  // Neu khong tim thay
  return -1;
}

// void khoiTao(DAYSO& a) {
//   a.n = 0;
// }

// void nhapDaySo(DAYSO& a) {
//   cout << "\nNhap so luong phan tu: ";
//   cin >> a.n;
//   for (int i = 0; i < a.n; i++) {
//     cout << "Nhap phan tu thu " << i + 1 << " la: ";
//     cin >> a.list[i];
//   }
// }

void xuatDaySo(DAYSO a) {
  for (int i = 0; i < a.n; i++) {
    cout << a.list[i] << " ";
  }
}

void xuatMang(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

// l la chi so trai va r la chi so phai cua mang can duoc sap xep
void mergeSort_Tang(int a[], int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    mergeSort_Tang(a, l, m);
    mergeSort_Tang(a, m + 1, r);

    merge_Tang(a, l, m, r);
  }
}

// Gop hai mang con a[l...m] va a[m+1...r]
void merge_Tang(int a[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  // Tao cac mang tam
  int* L, * R;
  L = new int[n1];
  R = new int[n2];

  // Copy du lieu sang cac mang tam
  for (i = 0; i < n1; i++)
    L[i] = a[l + i];
  for (j = 0; j < n2; j++)
    R[j] = a[m + 1 + j];

  // Gop 2 mang tam vua roi vao mang a
  i = 0; // Khoi tao chi so bat dau cua mang con dau tien
  j = 0; // Khoi tao chi so bat dau cua mang con thu hai
  k = l; // Khoi tao chi so bat dau cua mang luu ket qua

  // chung nao con co cap o mang L[i] va mang R[j] ma lay ra so sanh thi moi so sanh. Con neu 1 mang da ket thuc roi thi do la mang cac phan tu nho hon thi chi can cho mang co phan tu lon hon vao mang tong hop 
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) { // Trong truong hop bang nhau thi cho L[i] di truoc
      a[k] = L[i];
      i++; // De dich sang phai cua mang dau tien la mang L
    }
    else {
      a[k] = R[j];
      j++;
    }
    k++;
  }
  // Copy cac phan tu con lai cua mang L vao a neu co
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }
  // Copy cac phan tu con lai cua mang R vao a neu co
  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }

  delete L;
  delete R;
}

void mergeSort_Giam(int a[], int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    mergeSort_Giam(a, l, m);
    mergeSort_Giam(a, m + 1, r);

    merge_Giam(a, l, m, r);
  }
}

// Gop hai mang con a[l...m] va a[m+1...r]
void merge_Giam(int a[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  // Tao cac mang tam
  int* L, * R;
  L = new int[n1];
  R = new int[n2];

  // Copy du lieu sang cac mang tam
  for (i = 0; i < n1; i++)
    L[i] = a[l + i];
  for (j = 0; j < n2; j++)
    R[j] = a[m + 1 + j];

  // Gop 2 mang tam vua roi vao mang a
  i = 0; // Khoi tao chi so bat dau cua mang con dau tien
  j = 0; // Khoi tao chi so bat dau cua mang con thu hai
  k = l; // Khoi tao chi so bat dau cua mang luu ket qua

  // chung nao con co cap o mang L[i] va mang R[j] ma lay ra so sanh thi moi so sanh. Con neu 1 mang da ket thuc roi thi do la mang cac phan tu nho hon thi chi can cho mang co phan tu lon hon vao mang tong hop 
  while (i < n1 && j < n2) {
    if (L[i] > R[j]) { // Trong truong hop bang nhau thi cho L[i] di truoc
      a[k] = L[i];
      i++; // De dich sang phai cua mang dau tien la mang L
    }
    else {
      a[k] = R[j];
      j++;
    }
    k++;
  }
  // Copy cac phan tu con lai cua mang L vao a neu co
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }
  // Copy cac phan tu con lai cua mang R vao a neu co
  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }

  delete L;
  delete R;
}

void quickSort_Tang(int a[], int low, int high) {
  if (low < high) {
    /* pi la chi so noi phan tu nay da dung dung vi tri va la phan tu chia mang lam 2 mang con trai & phai */
    int pi = partition(a, low, high);

    // Goi de quy sap xep 2 mang con trai va phai
    quickSort_Tang(a, low, pi - 1);
    quickSort_Tang(a, pi + 1, high);
  }
}

int partition(int a[], int low, int high) {
  int pivot = a[high];
  int left = low;
  int right = high - 1;
  while (1) {
    while (left <= right && a[left] < pivot)
      left++;
    while (right >= left && a[right] > pivot)
      right--;
    if (left >= right)
      break;
    hoanVi(a[left], a[right]);
    left++;
    right--;
  }
  hoanVi(a[left], a[high]);
  return left;
}

void hoanVi(int& a, int& b) {
  int t = a;
  a = b;
  b = t;
}

// // Bai tap tong hop
// DSSV taoDuLieu() {
//   DSSV dssv = { 10, {
//       {"SV01", "Le Thi", "Be", 7.7 },
//       {"SV10", "Tran Van", "An", 6.5 },
//       {"SV03", "Nguyen Ngoc", "Ti", 4.5 },
//       {"SV06", "Le Van", "Phuoc", 8.0 },
//       {"SV04", "Tran Thi", "Binh", 6.0 },
//       {"SV05", "Ngo Bao", "Chau", 7.0 },
//       {"SV07", "Le Thanh", "Tam", 9.0 },
//       {"SV09", "Mac Thi", "Buoi", 10.0 },
//       {"SV02", "Le Thi Hong", "Gam", 3.5 },
//       {"SV08", "Nguyen Duy", "An", 8.5 }
//     }
//   };
//   return dssv;
// }

// void inSinhVien(SinhVien sv) {
//   cout << endl << sv.mssv << "\t";
//   cout << sv.hoLot << " ";
//   cout << sv.ten << "\t";
//   cout << sv.dtb;
// }

// void inDSSV(DSSV dssv) {
//   cout << endl;
//   for (int i = 0; i < dssv.siSo; i++) {
//     inSinhVien(dssv.list[i]);
//     cout << endl;
//   }
// }

// void mergeSort(SinhVien a[], int l, int r) {

// }

// void quickSort(SinhVien[], int l, int h) {

// }

// int binarySearch(SinhVien a[], int l, int r, char* mssv) {
//   return -1;
// }