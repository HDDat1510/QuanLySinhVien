#include "Header.h"

void menu() {
    printf("\n==================================================\n");
    printf("0.  Hien thi menu\n");
    printf("1.  Them sinh vien vao danh sach\n");
    printf("2.  Them hoc ky\n");
    printf("3.  Them hoc ky cho sinh vien\n");
    printf("4.  Nhap diem cho mot sinh vien\n");
    printf("5.  Nhap diem cho danh sach sinh vien\n");
    printf("6.  Tinh GPA cho danh sach sinh vien\n");
    printf("7.  In danh sach sinh vien\n");
    printf("8.  Sap xep danh sach sinh vien theo GPA (giam dan)\n");
    printf("9.  Sap xep danh sach sinh vien theo MSSV (tang dan)\n");
    printf("10. Xoa sinh vien\n");
    printf("11. Xuat danh sach sinh vien ra file CSV\n");
    printf("12. Xuat danh sach sinh vien ra file TXT\n");
    printf("13. Luu danh sach sinh vien\n");
    printf("14. Giai phong bo nho va thoat\n");
    printf("==================================================\n");
}

int main() {
    SV* head = NULL;
    HocKy* hk = NULL;
    MonHoc* mh = NULL;
    themSinhVienTuFile(&head);
    int luaChon, MENU = 1;
    menu();
    while (MENU) {
        printf("\nVui long nhap vao lua chon cua ban (0 de xem menu): ");
        scanf("%d", &luaChon);
        getchar();
        switch (luaChon) {
        case 0:
            menu();
            break;
        case 1:
            printf("\n==================================================\n");
            themSinhVien(&head);
            break;
        case 2:
            printf("\n==================================================\n");
            themHocKy(&hk);
            break;
        case 3:
            printf("\n==================================================\n");
            themHocKyChoSinhVien(&head, &hk);
            break;
        case 4:
            printf("\n==================================================\n");
            nhapDiemMotSinhVien(&head);
            break;
        case 5:
            printf("\n==================================================\n");
            nhapDiemDSSV(&head);
            break;
        case 6:
            printf("\n==================================================\n");
            tinhGPA(&head);
            break;
        case 7:
            printf("\n==================================================\n");
            inDSSV(head);
            break;
        case 8:
            printf("\n==================================================\n");
            sapXepDSSVTheoGPA(&head);
            printf("Da sap xep danh sach theo GPA (giam dan)!\n");
            break;
        case 9:
            printf("\n==================================================\n");
            sapXepDSSVTheoMSSV(&head);
            printf("Da sap xep danh sach theo MSSV (tang dan)!\n");
            break;
        case 10:
            printf("\n==================================================\n");
            xoaSinhVien(&head);
            break;
        case 11:
            printf("\n==================================================\n");
            xuatDSSVTheoFileCSV(head, "DSSV.csv");
            printf("Da xuat danh sach ra file DSSV.csv!\n");
            break;
        case 12:
            printf("\n==================================================\n");
            xuatDSSVTheoFileTXT(head, "DSSV.txt");
            printf("Da xuat danh sach ra file DSSV.txt!\n");
            break;
        case 13:
            printf("\n==================================================\n");
            luuDanhSachSinhVien(head);
            printf("Da luu danh sach sinh vien!\n");
            break;
        case 14:
            printf("\n==================================================\n");
            giaiPhongBoNho(&head);
            MENU = 0;
            printf("Da giai phong bo nho va thoat chuong trinh!\n");
            break;
        default:
            printf("\n==================================================\n");
            printf("Lua chon khong hop le! Vui long nhap lai.\n");
            break;
        }
    }
    return 0;
}
