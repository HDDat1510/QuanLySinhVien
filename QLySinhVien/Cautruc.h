#pragma once
typedef struct MonHoc {
	char tenMonHoc[50];
	int soTinChi;
	float diem;
	struct MonHoc* next;
}MonHoc;
typedef struct HocKy {
	char tenHocKy[50];
	MonHoc* dsMonHoc;
	struct HocKy* next;
}HocKy;
typedef struct NgaySinh {
	char ngay[3], thang[3], nam[5];
} Ngay;
typedef struct SinhVien {
	char MSSV[15], Name[30], GT[5], Lop[20];
	Ngay Sinh;
	float GPA;
	HocKy* dsHocKy;
	struct SinhVien* next;
} SV;

