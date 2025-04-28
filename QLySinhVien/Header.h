#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Cautruc.h"
#include <stdbool.h>
void themSinhVien(SV** head);
void themHocKy(HocKy** head);
void themHocKyChoSinhVien(SV** head, HocKy** dsHK);
void nhapDiemMotSinhVien(SV** head);
void nhapDiemDSSV(SV** head);
void tinhGPA(SV** head);
void sapXepDSSVTheoGPA(SV** head);
void inDSSV(SV* head);
void xuatDSSVTheoFileTXT(SV* head, const char* tenFile);
void xuatDSSVTheoFileCSV(SV* head, const char* tenFile);
void xoaSinhVien(SV **head);
void giaiPhongBoNho(SV **head);
void themSinhVienTuFile(SV **head);
void luuDanhSachSinhVien(SV *head);
void sapXepDSSVTheoMSSV(SV **head);
