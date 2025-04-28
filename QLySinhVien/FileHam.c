#include "Header.h"
void xoaNewLine(char* A) {
	int doDai = strlen(A);
	if (doDai > 0 && A[doDai - 1] == '\n') {
		A[doDai - 1] = '\0';
	}
}
void themSinhVien(SV** head) {
	SV* newSV = (SV*)malloc(sizeof(SV));
	if (newSV == NULL) {
		printf("Khong du bo nho de cap phat!\n");
		return;
	}
	printf("Nhap ma so sinh vien : ");
	fgets(newSV->MSSV, sizeof(newSV->MSSV), stdin);
	xoaNewLine(newSV->MSSV);
	printf("Nhap ho ten sinh vien : ");
	fgets(newSV->Name, sizeof(newSV->Name), stdin);
	xoaNewLine(newSV->Name);
	printf("Nhap gioi tinh(Nam/Nu): ");
	fgets(newSV->GT, sizeof(newSV->GT), stdin);
	xoaNewLine(newSV->GT);
	printf("Nhap lop : ");
	fgets(newSV->Lop, sizeof(newSV->Lop), stdin);
	xoaNewLine(newSV->Lop);
	printf("Nhap ngay sinh (dd mm yyyy): ");
	scanf("%2s %2s %4s", newSV->Sinh.ngay, newSV->Sinh.thang, newSV->Sinh.nam);
	getchar();
	newSV->GPA=0;
	newSV->next = *head;
	*head = newSV;
}
void themSinhVienTuFile(SV **head) {
    FILE *DSSV = fopen("DSSVMau.txt", "r");
    if (DSSV == NULL) {
        printf("Khong mo duoc file DSSV.txt!\n");
        return;
    }
    while (1) {
        SV *newSV = (SV *)malloc(sizeof(SV));
        if (newSV == NULL) {
            printf("Khong du bo nho de cap phat!\n");
            fclose(DSSV);
            return;
        }
        if (fgets(newSV->MSSV, sizeof(newSV->MSSV), DSSV) == NULL){
            free(newSV);
            break; 
        }
        xoaNewLine(newSV->MSSV);
        if (fgets(newSV->Name, sizeof(newSV->Name), DSSV) == NULL || fgets(newSV->GT, sizeof(newSV->GT), DSSV) == NULL ||
            fgets(newSV->Lop, sizeof(newSV->Lop), DSSV) == NULL) {
            printf("File bi thieu du lieu!\n");
            free(newSV);
            break;
        }
        xoaNewLine(newSV->Name);
        xoaNewLine(newSV->GT);
        xoaNewLine(newSV->Lop);
        if (fscanf(DSSV, "%2s %2s %4s", newSV->Sinh.ngay, newSV->Sinh.thang, newSV->Sinh.nam) != 3) {
            printf("File bi sai dinh dang ngay sinh!\n");
            free(newSV);
            break;
        }
        fgetc(DSSV); 
        newSV->GPA = 0;
        newSV->next = *head;
        *head = newSV;
    }
    fclose(DSSV);
}
void inDSSV(SV* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    printf("%-5s %-15s %-20s %-12s %-12s %-5s\n", 
           "STT", "MSSV", "Ho va ten", "Gioi tinh", "Lop", "GPA");
    int stt = 1; 
    while (head != NULL) {
        printf("%-5d %-15s %-20s %-12s %-12s %.2f\n",stt++,head->MSSV,head->Name,head->GT,head->Lop,head->GPA);
        head = head->next;
    }
}
void xuatDSSVTheoFileTXT(SV* head, const char* tenFile) {
    FILE* file = fopen(tenFile, "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi!\n");
        return;
    }
    fprintf(file, "%-5s %-15s %-20s %-12s %-12s %-5s\n","STT", "MSSV", "Ho va ten", "Gioi tinh", "Lop", "GPA");
    int stt = 1;
    while (head != NULL) {
        fprintf(file, "%-5d %-15s %-20s %-12s %-12s %.2f\n", 
                stt++,head->MSSV,head->Name,head->GT,head->Lop,head->GPA);
        head = head->next;
    }
    fclose(file);
    printf("Da xuat danh sach ra file %s thanh cong!\n", tenFile);
}
void luuDanhSachSinhVien(SV *head) {
    FILE *file = fopen("DSSVMau.txt", "w");
    if (file == NULL) {
        printf("Khong mo duoc file DSSVMau.txt de ghi!\n");
        return;
    }
    SV *sv = head;
    while (sv != NULL) {
        fprintf(file, "%s\n", sv->MSSV);
        fprintf(file, "%s\n", sv->Name);
        fprintf(file, "%s\n", sv->GT);
        fprintf(file, "%s\n", sv->Lop);
        fprintf(file, "%s %s %s\n", sv->Sinh.ngay, sv->Sinh.thang, sv->Sinh.nam);
        sv = sv->next;
    }
    fclose(file);
    printf("Da luu danh sach sinh vien vao DSSVMau.txt!\n");
}
void xuatDSSVTheoFileCSV(SV* head, const char* tenFile) {
    FILE* file = fopen(tenFile, "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi!\n");
        return;
    }
    fprintf(file, "STT,MSSV,Ho va ten,Gioi tinh,Lop,GPA\n");
    int stt = 1;
    while (head != NULL) {
        fprintf(file, "%d,%s,%s,%s,%s,%.2f\n",stt++, head->MSSV, head->Name, head->GT, head->Lop, head->GPA);
        head = head->next;
    }
    fclose(file);
    printf("Da xuat danh sach ra file %s thanh cong!\n", tenFile);
}

void xoaSinhVien(SV **head) {
    if(*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    char MSSV[15];
    printf("Nhap vao ma so cua sinh vien can xoa: ");
    fgets(MSSV, sizeof(MSSV), stdin);
    xoaNewLine(MSSV);
    SV *svHienTai = *head;
    SV *svTruocDo = NULL;
    while(svHienTai != NULL) {
        if(strcmp(svHienTai->MSSV, MSSV) == 0) {
            HocKy *hk = svHienTai->dsHocKy;
            while(hk != NULL) {
                HocKy *tempHK = hk;
                hk = hk->next;
                MonHoc *mh = tempHK->dsMonHoc;
                while(mh != NULL) {
                    MonHoc *tempMH = mh;
                    mh = mh->next;
                    free(tempMH);
                }
                free(tempHK);
            }
            if(svTruocDo == NULL) {
                *head = svHienTai->next;
            } else {
                svTruocDo->next = svHienTai->next;
            }
            SV *temp = svHienTai;
            svHienTai = svHienTai->next;
            free(temp);
            printf("Da xoa sinh vien co MSSV: %s\n", MSSV);
            return;
        } else {
            svTruocDo = svHienTai;
            svHienTai = svHienTai->next;
        }
    }
	printf("Khong co sinh vien mang ma so %s trong danh sach!\n",MSSV);
	return;    
}
void giaiPhongBoNho(SV **head) {
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    SV *tmp = *head;
    while (tmp != NULL) {
        HocKy *tmpHK = tmp->dsHocKy;
        while (tmpHK != NULL) {
            MonHoc *tmpMH = tmpHK->dsMonHoc;
            while (tmpMH != NULL) {
                MonHoc *nextMH = tmpMH->next;  
                free(tmpMH);  
                tmpMH = nextMH; 
            }
            HocKy *nextHK = tmpHK->next;  
            free(tmpHK);  
            tmpHK = nextHK; 
        }
        SV *nextSV = tmp->next; 
        free(tmp);  
        tmp = nextSV;  
    }
    *head = NULL; 
}
void nhapDiemMotSinhVien(SV** head) {
	if (*head == NULL) {
		printf("Danh sach rong!\n");
		return;
	}
	char MSSV[15];
	printf("Vui long nhap MSSV cua sinh vien can nhap diem: ");
	fgets(MSSV, sizeof(MSSV), stdin);
	xoaNewLine(MSSV);
	SV* svHienTai = *head;
	int timSV = 0;
	while (svHienTai != NULL) {
		if (strcmp(svHienTai->MSSV, MSSV) == 0) {
			timSV = 1;
			HocKy* hocKyHienTai = svHienTai->dsHocKy;
			while (hocKyHienTai != NULL) {
				MonHoc* monHocHienTai = hocKyHienTai->dsMonHoc;
				while (monHocHienTai != NULL) {
					printf("Nhap diem cho mon hoc %s\n: ", monHocHienTai->tenMonHoc);
					scanf("%f", &monHocHienTai->diem);
					monHocHienTai = monHocHienTai->next;
				}
				hocKyHienTai = hocKyHienTai->next;
			}
			break;
		}
		svHienTai = svHienTai->next;
	}
	if (!timSV) {
		printf("Khong tim thay sinh vien co MSSV: %s\n", MSSV);
		return;
	}
}
void nhapDiemDSSV(SV** head) {
	if (*head == NULL) {
		printf("Danh sach rong!\n");
		return;
	}
	SV* tmp = *head;
	while (tmp != NULL) {
		printf("\nNhap cho sinh vien co ma so: %s\n", tmp->MSSV);
		HocKy* tmpHK = tmp->dsHocKy;
		while (tmpHK != NULL) {
			printf("- Hoc ky: %s\n", tmpHK->tenHocKy);
			MonHoc* tmpMH = tmpHK->dsMonHoc;
			while (tmpMH != NULL) {
				printf("Nhap diem cho mon hoc %s : ", tmpMH->tenMonHoc);
				do {
					scanf("%f", &tmpMH->diem);
					getchar();
				} while (tmpMH->diem < 0 || tmpMH->diem>10);
				while (getchar() != '\n');
				tmpMH = tmpMH->next;
			}
			tmpHK = tmpHK->next;
		}
		tmp = tmp->next;
	}
	printf("\nHoan thanh nhap diem!\n");
}
void tinhGPA(SV** head) {
	if (*head == NULL) {
		printf("Danh sach rong!\n");
		return;
	}
	SV* svHienTai = *head;
	while (svHienTai != NULL) {
		HocKy* hocKyHienTai = svHienTai->dsHocKy;
		float tongDiem = 0;
		int tongTC = 0;
		while (hocKyHienTai != NULL) {
			MonHoc* monHocHienTai = hocKyHienTai->dsMonHoc;
			while (monHocHienTai != NULL) {
				tongDiem += monHocHienTai->diem * monHocHienTai->soTinChi;
				tongTC += monHocHienTai->soTinChi;
				monHocHienTai = monHocHienTai->next;
			}
			hocKyHienTai = hocKyHienTai->next;
		}
		svHienTai->GPA = tongTC > 0 ? tongDiem / tongTC : 0;
		svHienTai = svHienTai->next;
	}
}
void themMonHoc(MonHoc** head, const char* tenMon, int tinChi) {
	MonHoc* newMon = (MonHoc*)malloc(sizeof(MonHoc));
	if (newMon == NULL) {
		printf("Khong du bo nho de cap phat!\n");
		return;
	}
	strncpy(newMon->tenMonHoc, tenMon, sizeof(newMon->tenMonHoc) - 1);
	newMon->tenMonHoc[sizeof(newMon->tenMonHoc) - 1] = '\0';
	newMon->soTinChi = tinChi;
	newMon->next = *head;
	*head = newMon;
}
void themHocKy(HocKy** head) {
	HocKy* newHK = (HocKy*)malloc(sizeof(HocKy));
	if (newHK == NULL) {
		printf("Khong du bo nho de cap phat!\n");
		return;
	}
	printf("Nhap vao ten hoc ky (VD: Hoc ky 1,2,3...): ");
	fgets(newHK->tenHocKy, sizeof(newHK->tenHocKy), stdin);
	xoaNewLine(newHK->tenHocKy);
	newHK->dsMonHoc = NULL;
	if (strstr(newHK->tenHocKy, "1") != NULL) {
		themMonHoc(&(newHK->dsMonHoc), "Tin hoc dai cuong", 2);
		themMonHoc(&(newHK->dsMonHoc), "Triet hoc Mac-Lenin", 3);
		themMonHoc(&(newHK->dsMonHoc), "Bao tri he thong", 3);
		themMonHoc(&(newHK->dsMonHoc), "Giai tich 1", 2);
		themMonHoc(&(newHK->dsMonHoc), "Dai so tuyen tinh", 3);
		themMonHoc(&(newHK->dsMonHoc), "Nhap mon nganh CNTT", 3);
	}
	else if (strstr(newHK->tenHocKy, "2") != NULL) {
		themMonHoc(&(newHK->dsMonHoc), "Vat ly", 3);
		themMonHoc(&(newHK->dsMonHoc), "Chu nghia xa hoi khoa hoc", 2);
		themMonHoc(&(newHK->dsMonHoc), "Ky thuat lap trinh", 3);
		themMonHoc(&(newHK->dsMonHoc), "Kinh te chinh tri Mac-Lenin", 2);
		themMonHoc(&(newHK->dsMonHoc), "Giai tich 2", 2);
		themMonHoc(&(newHK->dsMonHoc), "Xac suat thong ke", 3);
	}
	else {
		char tenMonHoc[50];
		int tinChi;
		char luaChon;
		do {
			printf("\nNhap ten mon hoc muon them: ");
			fgets(tenMonHoc, sizeof(tenMonHoc), stdin);
			xoaNewLine(tenMonHoc);
			printf("Nhap so tin chi cho mon hoc '%s': ", tenMonHoc);
			scanf("%d", &tinChi);
			while (getchar() != '\n');
			themMonHoc(&(newHK->dsMonHoc), tenMonHoc, tinChi);
			printf("Ban co muon them mon hoc khac? (y/n): ");
			scanf("%c", &luaChon);
			while (getchar() != '\n');
		} while (luaChon == 'y' || luaChon == 'Y');
	}
	newHK->next = *head;
	*head = newHK;
	printf("Da them hoc ky thanh cong!\n");
	return;
}
void themHocKyChoSinhVien(SV** head, HocKy** dsHK) {
	char mssv[15];
	printf("Nhap MSSV can them hoc ky: ");
	fgets(mssv, sizeof(mssv), stdin);
	xoaNewLine(mssv);
	SV* sv = *head;
	while (sv != NULL && strcmp(sv->MSSV, mssv) != 0) {
		sv = sv->next;
	}
	if (sv == NULL) {
		printf("Khong tim thay SV co MSSV: %s\n", mssv);
		return;
	}
	printf("\nDanh sach hoc ky hien co:\n");
	HocKy* hk = *dsHK;
	int stt = 1;
	while (hk != NULL) {
		printf("%d. %s\n", stt++, hk->tenHocKy);
		hk = hk->next;
	}
	int luaChon;
	printf("Chon hoc ky can them (nhap so thu tu): ");
	scanf("%d", &luaChon);
	getchar();
	hk = *dsHK;
	stt = 1;
	while (hk != NULL && stt < luaChon) {
		hk = hk->next;
		stt++;
	}
	if (hk == NULL) {
		printf("Lua chon khong hop le!\n");
		return;
	}
	HocKy* newHK = (HocKy*)malloc(sizeof(HocKy));
	if (newHK == NULL) {
		printf("Khong du bo nho!\n");
		return;
	}
	strcpy(newHK->tenHocKy, hk->tenHocKy);
	newHK->dsMonHoc = NULL;
	newHK->next = sv->dsHocKy;
	MonHoc* mon = hk->dsMonHoc;
	while (mon != NULL) {
		themMonHoc(&(newHK->dsMonHoc), mon->tenMonHoc, mon->soTinChi);
		mon = mon->next;
	}
	sv->dsHocKy = newHK;
	printf("Da them hoc ky %s cho SV %s thanh cong!\n", hk->tenHocKy, sv->Name);
}
void sapXepDSSVTheoGPA(SV **head) {
    if(*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    int hoanDoi;
    SV *svTruocDo, *svHienTai, *svKeTiep;
    do {
        hoanDoi = 0;
        svTruocDo = NULL;
        svHienTai = *head;  
        while(svHienTai->next != NULL) {
            svKeTiep = svHienTai->next;
            if(svHienTai->GPA < svKeTiep->GPA) {
                if(svTruocDo != NULL) {
                    svTruocDo->next = svKeTiep;
                }
                else {
                    *head = svKeTiep;
                }
                svHienTai->next = svKeTiep->next;
                svKeTiep->next = svHienTai;
                svTruocDo = svKeTiep;
                hoanDoi = 1;
            }
            else {
                svTruocDo = svHienTai;
                svHienTai = svHienTai->next;
            }
        }
    } while(hoanDoi);
}
void sapXepDSSVTheoMSSV(SV **head) {
    if (*head == NULL) {
        printf("Danh sách rong!\n");
        return;
    }
	int hoanDoi;
    SV *svTruocDo, *svHienTai, *svKeTiep;
    do {
        hoanDoi = 0;
        svTruocDo = NULL;
        svHienTai = *head;
        while (svHienTai->next != NULL) {
            svKeTiep = svHienTai->next;
            if (strcmp(svHienTai->MSSV, svKeTiep->MSSV) > 0) {
                if (svTruocDo != NULL) {
                    svTruocDo->next = svKeTiep;
                } else {
                    *head = svKeTiep;
                }
                svHienTai->next = svKeTiep->next;
                svKeTiep->next = svHienTai;
                svTruocDo = svKeTiep;
                hoanDoi = 1;
            } else {
                svTruocDo = svHienTai;
                svHienTai = svHienTai->next;
            }
        }
    } while (hoanDoi);
}


