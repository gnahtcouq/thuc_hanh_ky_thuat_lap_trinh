#include <iostream>
using namespace std;
const int MAX = 50;
struct DAYSO{
    int list[MAX];
    int n;
};
void nhapDS(DAYSO &a);
void xuatDS(DAYSO a);
int timMin(DAYSO a);
int hamA(DAYSO a);
int timSoChanNhoNhat(DAYSO a);
void BubbleSort(DAYSO &a);
void xoaPhanTuCuoiCung(DAYSO &a);
void xoaPhanTuBatKy(DAYSO &a);
void xoaPhanTuAm(DAYSO &a);
void themPhanTuCuoi(DAYSO &a, int x);
void themPhanTuBatKy(DAYSO &a);

int main(){
    DAYSO d;
    nhapDS(d);
    xuatDS(d);

    // Cau 2
    cout << "\nMin la: " << timMin(d);

    // Cau 3
    int kq = hamA(d);
    cout << "\nHamA la: " << kq;

    // Cau 4
    int kq2 = timSoChanNhoNhat(d);
    cout << "\nSo chan nho nhat la: " << kq2;

    // Cau 5
    BubbleSort(d);
    cout << "\nDay so sau khi sap xep tang dan la: ";
    xuatDS(d);

    // Cau 6
    xoaPhanTuCuoiCung(d);
    cout << "\nDay so sau khi xoa phan tu cuoi la: ";
    xuatDS(d);

    // Cau 7
    int vitrixoa;
    do{
        cout << "\nNhap vi tri can xoa: ";
        cin >> vitrixoa;
        if(vitrixoa<0 || vitrixoa>d.n)
            cout << "\nNhap sai. Hay nhap lai";
    }while(vitrixoa<0 || vitrixoa>d.n);
    xoaPhanTuBatKy(d);
    cout << "\nDay so sau khi xoa la: ";
    xuatDS(d);

    // Cau 8
    xoaPhanTuAm(d);
    cout << "\nDay so sau khi xoa phan tu am la: ";
    xuatDS(d);

    // Cau 9
    int x;
    cout << "\nNhap phan tu muon them: ";
    cin >> x;
    themPhanTuCuoi(d,x);
    cout << "\nDay so sau khi them la: ";
    xuatDS(d);
    
    // Cau 10
    themPhanTuBatKy(d);
    cout << "\nDay so sau khi them la: ";
    xuatDS(d);

    cout << endl;
    system("pause");
    return 0;
}

// Cau 1
void nhapDS(DAYSO &a){
    cout << "\nNhap so phan tu: ";
    cin >> a.n;
    for (int i = 0; i < a.n; i++){
        cout << "a[" << i << "] = ";
        cin >> a.list[i];
    }
}
void xuatDS(DAYSO a){
    for (int i = 0; i < a.n; i++)
        cout << a.list[i] << " ";
}

// Cau 2
int timMin(DAYSO a){
    int min = a.list[0];
    for (int i = 0; i < a.n; i++)
        if (a.list[i] < min)
            min = a.list[i];
    return min;
}

// Cau 3
int hamA(DAYSO a){ // hamA thuc hien cong viec la tim so lon nhat
    int flag = 0;
    int kq;
    for (int i = 0; i < a.n; i++)
        if (a.list[i] > 0)
            if (flag == 0){
                kq = a.list[i];
                flag = 1;
            }
            else if (a.list[i] > kq)
                kq = a.list[i];
    return kq;
}

// Cau 4
int timSoChanNhoNhat(DAYSO a){ // hamA la tim so lon nhat
    int flag = 0;
    int kq;
    for (int i = 0; i < a.n; i++)
        if (a.list[i] > 0  && a.list[i]%2 == 0)
            if (flag == 0){
                kq = a.list[i];
                flag = 1;
            }
            else if (a.list[i] < kq)
                kq = a.list[i];
    return kq;
}

// Cau 5
void BubbleSort(DAYSO &a){ // Sap xep tang dan
    int i, j, x;
    for (i = 0; i < a.n - 1; i++)
        for (j = a.n - 1; j > i; j--)
            if (a.list[j] < a.list[j - 1]){
                x = a.list[j];
                a.list[j] = a.list[j - 1];
                a.list[j - 1] = x;
            }
}

// Cau 6
void xoaPhanTuCuoiCung(DAYSO &a){
    a.n--;
}

// Cau 7
void xoaPhanTuBatKy(DAYSO &a){
    int vitrixoa;
    for(int i = vitrixoa+1; i<a.n; i++){
        a.list[i-1] = a.list[i];
    }
    a.n--;
}

// Cau 8
void xoaPhanTuAm(DAYSO &a){
    for(int i = 0;i<a.n;i++){
        if(a.list[i]<0){
            xoaPhanTuBatKy(a);
            i--;
        }
    }
}

// Cau 9
void themPhanTuCuoi(DAYSO &a, int x){
    a.n++;
    a.list[a.n-1] = x;
}

// Cau 10
void themPhanTuBatKy(DAYSO &a){
    int vitrithem, phantuthem;
    do{
        cout << "\nNhap vi tri can them: ";
        cin >> vitrithem;
        cout << "\nNhap phan tu them: ";
        cin >> phantuthem;
        if(vitrithem<0 || vitrithem>a.n)
            cout << "\nNhap sai. Hay nhap lai";
    }while(vitrithem<0 || vitrithem>a.n);

    for(int i=a.n-1; i>=vitrithem; i--){
        a.list[i+1] = a.list[i];
    }
    a.list[vitrithem] = phantuthem;
    a.n++;
}