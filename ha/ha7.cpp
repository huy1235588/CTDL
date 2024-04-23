#include <iostream>
#include <stdlib.h>
#include <string.h>
typedef enum Status
{
    CON_HOC,
    TAM_NGHI
} Status;

typedef struct SinhVien
{
    char *ho_ten;
    float diem_toan;
    float diem_van;
    float diem_tb;
    Status trang_thai;
} SinhVien;

// Hàm cấp phát động cho danh sách sinh viên
SinhVien* capPhatDanhSach(int n) {
    SinhVien *danh_sach = (SinhVien*)malloc(n * sizeof(SinhVien));
    if (danh_sach == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    return danh_sach;
}

// Hàm nhập thông tin cho biến cấu trúc SinhVien
void inputInformation(SinhVien *sv)
{
    char name[100];

    printf("Nhập họ tên: ");
    fgets(name, sizeof(name), stdin);

    // Loại bỏ ký tự '\n' ở cuối chuỗi
    name[strcspn(name, "\n")] = '\0';

    // Cấp phát bộ nhớ động cho chuỗi ký tự
    sv->ho_ten = (char *)malloc(strlen(name) + 1);
    strcpy(sv->ho_ten, name);


    printf("Nhập điểm toán: ");
    scanf("%f", &sv->diem_toan);
    printf("Nhập điểm văn: ");
    scanf("%f", &sv->diem_van);

    sv->diem_tb = (sv->diem_toan + sv->diem_van) / 2;

    printf("Nhập trạng thái (0 - Còn học, 1 - Tạm nghỉ): ");
    scanf("%d", &sv->trang_thai);
}

// Hàm in thông tin cho biến cấu trúc SinhVien
void printInputInformation(SinhVien *sv)
{
    printf("\nThông tin của sinh viên:\n");
    printf("Họ tên: %s\n", sv->ho_ten);
    printf("Điểm toán: %.2f\n", sv->diem_toan);
    printf("Điểm văn: %.2f\n", sv->diem_van);
    printf("Điểm trung bình: %.2f\n", sv->diem_tb);
    printf("Trạng thái : %s\n", (sv->trang_thai == 0) ? "Còn học" : "Tạm nghỉ");
}

int main()
{
    SinhVien *sv;
    sv = (SinhVien *)malloc(sizeof(SinhVien));

    // Nhập thông tin cho biến cấu trúc SinhVien
    inputInformation(&*sv);
    // In thông tin cho biến cấu trúc SinhVien
    printInputInformation(&*sv);

    // Giải phóng bộ nhớ đã cấp phát
    free(sv->ho_ten);
    free(sv);
    return 0;
}