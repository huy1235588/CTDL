#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef enum Status
{
    CON_HOC,
    TAM_NGHI
} Status;

struct SinhVien
{
    char *ho_ten;
    float diem_toan;
    float diem_van;
    float diem_tb;
    Status trang_thai;
};
typedef struct SinhVien SinhVien;

// Hàm nhập thông tin cho biến cấu trúc SinhVien
void inputInformation(SinhVien *sv, int n)
{
    for (int i = 0; i < n; i++)
    {
        char name[100];

        printf("Nhập thông tin sinh viên thứ %d: \n", i + 1);
        printf("Nhập họ tên: ");

        // Xóa bộ nhớ đệm đầu vào
        while ((getchar()) != '\n');
        fgets(name, sizeof(name), stdin);

        // Loại bỏ ký tự '\n' ở cuối chuỗi
        name[strcspn(name, "\n")] = '\0';

        // Cấp phát bộ nhớ động cho chuỗi ký tự
        sv[i].ho_ten = (char *)malloc(strlen(name) + 1);
        // Sao chép name vào ho_ten
        strcpy(sv[i].ho_ten, name);

        printf("Nhập điểm toán: ");
        scanf("%f", &sv[i].diem_toan);
        printf("Nhập điểm văn: ");
        scanf("%f", &sv[i].diem_van);

        sv[i].diem_tb = (sv[i].diem_toan + sv[i].diem_van) / 2;

        printf("Nhập trạng thái (0 - Còn học, 1 - Tạm nghỉ): ");
        scanf("%d", &sv[i].trang_thai);
        printf("\n");
    }
}

// Hàm in thông tin cho biến cấu trúc SinhVien
void printInputInformation(SinhVien *sv, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nThông tin của sinh viên thứ %d: \n", i + 1);
        printf("Họ tên: %s\n", sv[i].ho_ten);
        printf("Điểm toán: %.2f\n", sv[i].diem_toan);
        printf("Điểm văn: %.2f\n", sv[i].diem_van);
        printf("Điểm trung bình: %.2f\n", sv[i].diem_tb);
        printf("Trạng thái : %s\n", (sv[i].trang_thai == 0) ? "Còn học" : "Tạm nghỉ");
        printf("\n");
    }
}

void printHighestAverageStudent(SinhVien *sv, int n)
{
    int index = 0;
    float max_diem_tb = sv[0].diem_tb;
    for (int i = 1; i < n; i++)
    {
        if (sv[i].diem_tb > max_diem_tb)
        {
            max_diem_tb = sv[i].diem_tb;
            index = i;
        }
    }
    printf("\nSinh viên có diem trung binh cao nhat la:\n");
    printf("Họ tên: %s\n", sv[index].ho_ten);
    printf("Điểm toán: %.2f\n", sv[index].diem_toan);
    printf("Điểm văn: %.2f\n", sv[index].diem_van);
    printf("Điểm trung bình: %.2f\n", sv[index].diem_tb);
    printf("Trạng thái: %s\n", (sv[index].trang_thai == CON_HOC) ? "CON_HOC" : "TAM_NGHI");
}

int main()
{
    int n;
    printf("Nhập số lượng sinh viên: ");
    scanf("%d", &n);

    // Cấp phát động cho danh sách sinh viên
    SinhVien *sv = (SinhVien *)malloc(n * sizeof(SinhVien));
    if (sv == nullptr)
    {
        cout << "Không thể cấp phát bộ nhớ";
        return 1;
    }

    // Nhập thông tin cho biến cấu trúc SinhVien
    inputInformation(sv, n);
    // In thông tin cho biến cấu trúc SinhVien
    printInputInformation(sv, n);
    // Tìm và in ra thông tin sinh viên có điểm trung bình cao nhất.
    printHighestAverageStudent(sv, n);

    // Giải phóng bộ nhớ đã cấp phát
    for (int i = 0; i < n; i++)
    {
        free(sv[i].ho_ten);
    }
    free(sv);
    return 0;
}