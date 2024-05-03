#include <iostream>
#include <stdlib.h>
#include <string.h>
typedef enum Status
{
    CON_HOC,
    TAM_NGHI
} Status;

struct SinhVien
{
    char ho_ten[50];
    float diem_toan;
    float diem_van;
    float diem_tb;
    Status trang_thai;
};
typedef struct SinhVien SinhVien;

// Hàm cấp phát động cho danh sách sinh viên
SinhVien* generateList() {
    SinhVien *list = new SinhVien;
    if (list == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    return list;
}

// Hàm nhập thông tin cho biến cấu trúc SinhVien
void inputInformation(SinhVien *sv)
{
    printf("Nhập họ tên: ");
    scanf("%[^\n]s",sv->ho_ten);

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
    printf("Trạng thái: %s\n", (sv->trang_thai == 0) ? "Còn học" : "Tạm nghỉ");
}

int main()
{
    SinhVien *sv = generateList();

    // Nhập thông tin cho biến cấu trúc SinhVien
    inputInformation(&*sv);
    // In thông tin cho biến cấu trúc SinhVien
    printInputInformation(&*sv);

    // Giải phóng bộ nhớ đã cấp phát
    delete(sv);
    return 0;
}