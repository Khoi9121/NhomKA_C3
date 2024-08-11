#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Khai báo trước các hàm
void xoaKhoangTrangThua(char* str);
void timKiemTen(char* str, char* ten);
void chenTu(char* str, char* tu, int viTri);
void lietKeKyTuXuatHien(char* str);

// Định nghĩa hàm xoaKhoangTrangThua
void xoaKhoangTrangThua(char* str) {
    int i = 0, j = 0;
    int len = strlen(str);
    int coKhoangTrang = 0;

    // Xóa khoảng trắng đầu chuỗi
    while (isspace(str[i])) {
        i++;
    }

    for (; i < len; i++) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
            coKhoangTrang = 0;
        }
        else if (coKhoangTrang == 0) {
            str[j++] = ' ';
            coKhoangTrang = 1;
        }
    }

    // Xóa khoảng trắng cuối chuỗi
    if (j > 0 && str[j - 1] == ' ') {
        j--;
    }

    str[j] = '\0';
}

// Định nghĩa hàm tìm kiếm tên trong chuỗi họ tên
void timKiemTen(char* str, char* ten) {
    if (strstr(str, ten) != NULL) {
        printf("Tên '%s' đã được nhập đúng.\n", ten);
    }
    else {
        printf("Tên '%s' không có trong chuỗi.\n", ten);
    }
}

// Định nghĩa hàm chèn từ vào vị trí bất kỳ
void chenTu(char* str, char* tu, int viTri) {
    char ketQua[200] = ""; // Chuỗi kết quả

    // Sao chép phần đầu chuỗi gốc vào chuỗi kết quả
    strncpy_s(ketQua, str, viTri);
    ketQua[viTri] = '\0';

    // Thêm từ cần chèn vào chuỗi kết quả
    strcat_s(ketQua, tu);

    // Thêm phần còn lại của chuỗi gốc sau vị trí chèn
    strcat_s(ketQua, &str[viTri]);

    printf("Chuỗi sau khi chèn: '%s'\n", ketQua);
}

// Định nghĩa hàm liệt kê số lần xuất hiện của mỗi ký tự
void lietKeKyTuXuatHien(char* str) {
    int dem[256] = { 0 }; // Mảng đếm ký tự

    for (int i = 0; str[i] != '\0'; i++) {
        dem[(unsigned char)str[i]]++;
    }

    printf("Số lần xuất hiện của mỗi ký tự:\n");
    for (int i = 0; i < 256; i++) {
        if (dem[i] > 0) {
            printf("'%c' xuất hiện %d lần\n", i, dem[i]);
        }
    }
}

int main() {
    char chuoi[100];
    char tu[50];
    int viTri;
    int luaChon;

    do {
        printf("\nMenu:\n");
        printf("1. Nhập chuỗi và xóa khoảng trắng thừa\n");
        printf("2. Tìm kiếm tên trong chuỗi họ tên\n");
        printf("3. Chèn một từ vào vị trí bất kỳ\n");
        printf("4. Liệt kê số lần xuất hiện của mỗi ký tự\n");
        printf("5. Thoát\n");
        printf("Nhập lựa chọn của bạn: ");
        scanf_s("%d", &luaChon);
        getchar(); // Xóa ký tự newline trong bộ đệm

        switch (luaChon) {
        case 1:
            printf("Nhập vào chuỗi: ");
            fgets(chuoi, sizeof(chuoi), stdin);
            chuoi[strcspn(chuoi, "\n")] = '\0'; // Xóa ký tự newline
            xoaKhoangTrangThua(chuoi);
            printf("Chuỗi sau khi xóa khoảng trắng thừa: '%s'\n", chuoi);
            break;

        case 2:
            printf("Nhập vào tên cần tìm: ");
            fgets(tu, sizeof(tu), stdin);
            tu[strcspn(tu, "\n")] = '\0'; // Xóa ký tự newline
            timKiemTen(chuoi, tu);
            break;

        case 3:
            printf("Nhập vào từ cần chèn: ");
            fgets(tu, sizeof(tu), stdin);
            tu[strcspn(tu, "\n")] = '\0'; // Xóa ký tự newline

            printf("Nhập vào vị trí cần chèn (0-based): ");
            scanf_s("%d", &viTri);

            chenTu(chuoi, tu, viTri);
            break;

        case 4:
            printf("Nhập vào chuỗi để liệt kê số lần xuất hiện của mỗi ký tự: ");
            fgets(chuoi, sizeof(chuoi), stdin);
            chuoi[strcspn(chuoi, "\n")] = '\0'; // Xóa ký tự newline

            lietKeKyTuXuatHien(chuoi);
            break;

        case 5:
            printf("Thoát chương trình.\n");
            break;

        default:
            printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (luaChon != 5);

    return 0;
}
