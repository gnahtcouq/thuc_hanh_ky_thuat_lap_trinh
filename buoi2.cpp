#include <iostream>
#include <math.h>
using namespace std;
const int MAX = 50;

struct DAYSO{
    int list[MAX];
    int n;
};
void nhapDS(DAYSO &a);
void xuatDS(DAYSO a);
int tongDS(DAYSO a);
int tichDS(DAYSO a);
int demDuong(DAYSO a);
int tongChan(DAYSO a);
int tichPTChiSoChan(DAYSO a);
int demPTChiaHet3Va5(DAYSO a);
int kt_SoNguyenTo(int n);
int tong_SoNguyenTo(DAYSO a);
void xuatSLAmDuongBangKhong(DAYSO a);
bool kiemtra_HoanThien(int n);
int dem_HoanThien(DAYSO a);
void kiemtra_TangDan(DAYSO a);
void thaythe_XY(DAYSO &a, int x, int y);
void dem_KhongTrung(DAYSO a);

int main(){
    int x,y;
    DAYSO d;
    nhapDS(d);
    xuatDS(d);
    cout << "\nCau 1. Tong cac phan tu cua day so = " << tongDS(d);
    cout << "\nCau 1. Tich cac phan tu cua day so = " << tichDS(d);
    cout << "\nCau 1. So phan tu duong co trong day so = " << demDuong(d);
    cout << "\nCau 2. Tong so phan tu chan co trong day so = " << tongChan(d);
    cout << "\nCau 2. Tich so phan tu co chi so chan co trong day so = " << tichPTChiSoChan(d);
    cout << "\nCau 2. So phan tu chia het cho 3 va 5 co trong day so = " << demPTChiaHet3Va5(d);
    cout << "\nCau 3. Tong phan tu la so nguyen to co trong day so = " << tong_SoNguyenTo(d);
    xuatSLAmDuongBangKhong(d);
    cout << "\nCau 4. So luong so hoan thien co trong day so = " << dem_HoanThien(d);
    kiemtra_TangDan(d);
    cout << "\nCau 4. Nhap x = ";
    cin >> x;
    cout << "\nCau 4. Nhap y = ";
    cin >> y;
    thaythe_XY(d,x,y);
    dem_KhongTrung(d);
    return 0;
}

// Cau 1
void nhapDS(DAYSO &a){
    do{
        cout << "\nNhap so phan tu cua danh sach: ";
        cin >> a.n;
        if(a.n<0)
            cout << "\nBan nhap khong hop le";
    }while(a.n<0);
    for (int i = 0; i < a.n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a.list[i];
    }
}
void xuatDS(DAYSO a){
    for (int i = 0; i < a.n; i++)
        cout << a.list[i] << " ";
}
int tongDS(DAYSO a){
    int tong = 0;
    for (int i = 0; i < a.n; i++)
        tong += a.list[i];
    return tong;
}
int tichDS(DAYSO a){
    int tich = 1;
    for(int i=0;i<a.n;i++)
        tich *= a.list[i];
    return tich;
}
int demDuong(DAYSO a){
    int dem = 0;
    for(int i=0;i<a.n;i++){
        if(a.list[i]>0)
            dem++;
    }
    return dem;
}
// Cau 2
int tongChan(DAYSO a){
    int tong = 0;
    for (int i = 0; i < a.n; i++){
        if(a.list[i]%2==0)
            tong+=a.list[i];
    }
    return tong;
}
int tichPTChiSoChan(DAYSO a){
    int tich = 1;
    for (int i = 0; i < a.n; i++){
        if(i%2==0)
            tich*=a.list[i];
    }
    return tich;
}
int demPTChiaHet3Va5(DAYSO a){
    int dem = 0;
    for (int i = 0; i < a.n; i++){
        if(a.list[i]%3==0 && a.list[i]%5==0)
            dem++;
    }
    return dem;
}
// Cau 3
int kt_SoNguyenTo(int n) {
	if (n < 2) return 0;
	else {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n%i == 0) {
				return 0;
			}
		}
		return 1;
	}
}
int tong_SoNguyenTo(DAYSO a){
    int tong=0;
    for(int i=0;i<a.n;i++){
        if(kt_SoNguyenTo(a.list[i])){
            tong+=a.list[i];
        }
    }
    return tong;
}
void xuatSLAmDuongBangKhong(DAYSO a){
    int demAm=0;
    int demDuong=0;
    int demBangKhong=0;
    for(int i=0;i<a.n;i++){
        if((a.list[i])<0)
            demAm++;
        else if((a.list[i])>0)
            demDuong++;
        else if((a.list[i])==0)
            demBangKhong++;
    }
    cout << "\nCau 3. So luong phan tu am co trong day so la: " << demAm;
    cout << "\nCau 3. So luong phan tu duong co trong day so la: " << demDuong;
    cout << "\nCau 3. So luong phan tu bang khong co trong day so la: " << demBangKhong;
}
// Cau 4
bool kiemtra_HoanThien(int n){
    int tong = 0;
    for(int i=1;i<=n/2;i++){
        if(n%i==0) 
            tong+=i;
    }
    if(tong==n) return true;
    return false;
}
int dem_HoanThien(DAYSO a){
    int dem = 0;
    for (int i = 0; i < a.n; i++){
        if(kiemtra_HoanThien(a.list[i]))
            dem++;
    }
    return dem;
}
void kiemtra_TangDan(DAYSO a){
    int flag = 1;
    for(int i = 0; i < a.n-1; i++){
        if(a.list[i] > a.list[i+1]){
            flag = 0;
            break;
        }
    }
    if (flag == 0)
        cout << "\nCau 4. Day khong phai day so tang dan";
    else
        cout << "\nCau 4. Day la day so tang dan";
}

void thaythe_XY(DAYSO &a, int x, int y){
    for(int i = 0;i < a.n;++i){
        if(a.list[i] == x) a.list[i] = y;
    }
    cout <<"\nMang sau khi da thay la: ";
    xuatDS(a);
}

void dem_KhongTrung(DAYSO a){
    for (int i = 0; i < a.n - 1; i++){
        for (int j = i + 1; j < a.n; j++){
            if (a.list[i] < a.list[j]){
                int tam = a.list[i];
                a.list[i] = a.list[j];
                a.list[j] = tam;
            }
        }
    }
    int dem = 1;
    for (int i = 1; i < a.n; i++){
        if (a.list[i] != a.list[i - 1])
            dem++;
    }
    cout << "\nSo phan tu (khong trung nhau) trong day so la: " << dem;
}