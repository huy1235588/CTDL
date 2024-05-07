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