#include<iostream>
#include<math.h>
using namespace std;

void nhap_NguyenDuong(int &n);
void kt_SoNguyenTo(int n);
void kt_SoHoanThien(int n);
void kt_SoChinhPhuong(int n);
int kt_SoNguyenTo6(int n);
void xuat_SoNguyenTo(int n);
int dem_SoChinhPhuong(int n);
void xuat_SoChinhPhuong(int n);
bool kt_HoanThien(int &h);
int dem_HoanThien(int n);
void xuat_HoanThien(int n);
int tong_HoanThien(int n);

int main(){
    int n;
    nhap_NguyenDuong(n);
    kt_SoNguyenTo(n);
    kt_SoHoanThien(n);
    kt_SoChinhPhuong(n);
    xuat_SoNguyenTo(n);
    cout << "\nCau 7. " << " Co " << dem_SoChinhPhuong(n) << " so chinh phuong la ";
    xuat_SoChinhPhuong(n);
    cout << "\nCau 8. " << " Co " << dem_HoanThien(n) << " so hoan thien la ";
    xuat_HoanThien(n);
    cout << "Tong cac so hoan thien da liet ke la " << tong_HoanThien(n);
    return 0;
}


//Cau 1
void nhap_NguyenDuong(int &n){
    do{
        cout << "\nCau 1. Nhap n: ";
        cin >> n;
    }while(n<=0); //Cau 2 sua thanh while(n<10 || n>100);
}

//Cau 3
void kt_SoNguyenTo(int n) {
	int dem=0;
    for(int i=1;i<=n;i++)
        if(n%i==0)
            dem++;
    if(dem==2)
        cout << "Cau 3. " << n << " La so nguyen to";
    else
        cout << "Cau 3. " << n << " Khong phai la so nguyen to";
}

// Cau 4
void kt_SoHoanThien(int n){
    int sum=0;
    for(int i=1;i<n;i++)
        if(n%i==0)
            sum+=i;
    if(sum==n)
        cout << "\nCau 4. " << n << " La so hoan thien";
    else
        cout << "\nCau 4. " << n << " Khong la so hoan thien";
}

//Cau 5
void kt_SoChinhPhuong(int n){
    int flag =0;
    for(int i=1;i<=n;i++)
        if(i*i==n){
            flag = 1;
            break;
        }
    if (flag==1)
        cout << "\nCau 5. " <<n << " La so chinh phuong";
    else
        cout << "\nCau 5. " << n << " Khong phai la so chinh phuong";
}

//Cau 6
int kt_SoNguyenTo6(int n){
	if (n < 2) return 0;
	else {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n%i == 0){
				return 0;
			}
		}
		return 1;
	}
}
void xuat_SoNguyenTo(int n){
    cout << "\nCau 6. So nguyen to cuoi cung nho hon n: ";
    for(int i=n;i>0;i--){
        if(kt_SoNguyenTo6(i)){
            cout << i << " ";
            break;
        }
    }
}

// Cau 7
int dem_SoChinhPhuong(int n){
    int dem=0;
    for(int i=1;i<=n;i++){
        if (sqrt(i)*sqrt(i)==i)
            dem++;
    }
    return dem;
}
void xuat_SoChinhPhuong(int n){
    for(int i=1;i<=n;i++){
        if (sqrt(i)*sqrt(i)==i)
            cout << i << " ";
    }
}

//Cau 8
bool kt_HoanThien(int &h){
	int tong = 0;
	for (int i = 1; i <= h / 2; i++){
		if (h%i == 0){
			tong += i;
		}
	}
	if (tong == h){
		return true;
	}
	return false;
}
int dem_HoanThien(int n){
    int dem=0;
    for(int i=1;i<=n;i++){
        if(kt_HoanThien(i)==true)
            dem++;
    }
    return dem;
}
void xuat_HoanThien(int n){
    for(int i=1;i<=n;i++){
        if(kt_HoanThien(i)==true)
            cout << i << " ";
    }
}
int tong_HoanThien(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(kt_HoanThien(i)==true)
            sum+=i;
    }
    return sum;
}