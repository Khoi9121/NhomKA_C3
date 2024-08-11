#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Khai báo trước các hàm
int demKhoangTrang(const char* str);
void chuanHoaChuoi(char* str);
void catHoTen(const char* ho_ten, char* ho_lot, char* ten);
void xoaTu(char* str, const char* tu);
char timKyTuXuatHienNhieuNhat(const char* str);

// Hàm đếm số khoảng trắng
int demKhoangTrang(const char* str) {
	int dem = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ') {
			dem++;
		}
	}
	return dem;
}

// Hàm chuẩn hóa chuỗi
void chuanHoaChuoi(char* str) {
	int dau_cau = 1;
	for (int i = 0; str[i] != '\0'; i++) {
		if (isalpha(str[i])) {
			if (dau_cau) {
				str[i] = toupper(str[i]);
				dau_cau = 0;
			}
			else {
				str[i] = tolower(str[i]);
			}
		}
		else if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
			dau_cau = 1;
		}
	}
}

// Hàm cắt họ tên
void catHoTen(const char* ho_ten, char* ho_lot, char* ten) {
	int len = strlen(ho_ten);
	int vi_tri_ten = len - 1;

	while (vi_tri_ten >= 0 && ho_ten[vi_tri_ten] != ' ') {
		vi_tri_ten--;
	}

	strncpy(ho_lot, ho_ten, vi_tri_ten);
	ho_lot[vi_tri_ten] = '\0';

	strcpy(ten, &ho_ten[vi_tri_ten + 1]);
}

// Hàm xóa từ
void xoaTu(char* str, const char* tu) {
	char* vi_tri = strstr(str, tu);
	if (vi_tri != NULL) {
		memmove(vi_tri, vi_tri + strlen(tu), strlen(vi_tri + strlen(tu)) + 1);
	}
}

// Hàm tìm ký tự xuất hiện nhiều nhất
char timKyTuXuatHienNhieuNhat(const char* str) {
	int dem[256] = { 0 };
	int max_dem = 0;
	char ky_tu_max = '\0';

	for (int i = 0; str[i] != '\0'; i++) {
		dem[(unsigned char)str[i]]++;
		if (dem[(unsigned char)str[i]] > max_dem) {
			max_dem = dem[(unsigned char)str[i]];
			ky_tu_max = str[i];
		}
	}

	return ky_tu_max;
}

int main() {
	char chuoi[100];
	char tu[50];
	int luaChon;
	do {
		printf("\nMenu:\n");
		printf("2. Dem so khoang trang trong chuoi\n");
		printf("4. Chuan hoa chuoi\n");
		printf("6. Cat ho ten thanh ho lot va ten\n");
		printf("8. Xoa mot tu trong chuoi\n");
		printf("10. Tim ky tu xuat hien nhieu nhat\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf_s("%d", &luaChon);
		getchar(); // Xóa ký tự newline trong bộ đệm

		switch (luaChon) {
		case 2:
			printf("Nhap vao chuoi de dem khoang trang: ");
			fgets(chuoi, sizeof(chuoi), stdin);
			chuoi[strcspn(chuoi, "\n")] = '\0'; // Xóa ký tự newline
			printf("So khoang trang trong chuoi: %d\n", demKhoangTrang(chuoi));
			break;
		case 4:
			printf("Nhap vao chuoi de chuan hoa: ");
			fgets(chuoi, sizeof(chuoi), stdin);
			chuoi[strcspn(chuoi, "\n")] = '\0'; // Xóa ký tự newline
			chuanHoaChuoi(chuoi);
			printf("Chuoi sau khi chuan hoa: %s\n", chuoi);
			break;
		case 6:
		{
			char ho_lot[50], ten[50];
			printf("Nhap vao ho ten: ");
			fgets(chuoi, sizeof(chuoi), stdin);
			chuoi[strcspn(chuoi, "\n")] = '\0'; // Xóa ký tự newline
			catHoTen(chuoi, ho_lot, ten);
			printf("Ho lot: %s\nTen: %s\n", ho_lot, ten);
		}
		break;
		case 8:
			printf("Nhap vao chuoi: ");
			fgets(chuoi, sizeof(chuoi), stdin);
			chuoi[strcspn(chuoi, "\n")] = '\0'; // Xóa ký tự newline
			printf("Nhap vao tu can xoa: ");
			fgets(tu, sizeof(tu), stdin);
			tu[strcspn(tu, "\n")] = '\0'; // Xóa ký tự newline
			xoaTu(chuoi, tu);
			printf("Chuoi sau khi xoa tu: %s\n", chuoi);
			break;
		case 10:
			printf("Nhap vao chuoi: ");
			fgets(chuoi, sizeof(chuoi), stdin);
			chuoi[strcspn(chuoi, "\n")] = '\0'; // Xóa ký tự newline
			printf("Ky tu xuat hien nhieu nhat: '%c'\n", timKyTuXuatHienNhieuNhat(chuoi));
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	} while (luaChon != 0);

	return 0;
}