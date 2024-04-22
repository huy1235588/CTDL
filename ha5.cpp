#include <iostream>
#include <ctime>
using namespace std;

#define HOURS 3600
#define MINUTES 60
#define SECONDS 1

typedef int TimeType;
struct TimeClock
{
    TimeType hours = 0;
    TimeType minutes = 0;
    TimeType seconds = 0;
};
typedef struct TimeClock Clock;

int generateRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int printTime(Clock *time)
{
    return printf("%d:%d:%d\n", time->hours, time->minutes, time->seconds);
}

Clock *timeDifference(Clock *time1, Clock *time2)
{
    //: huyển thời gian về giây
    int second1 = time1->hours * HOURS + time1->minutes * MINUTES + time1->seconds * SECONDS;
    int second2 = time2->hours * HOURS + time2->minutes * MINUTES + time2->seconds * SECONDS;
    // So sánh
    int compareTime = abs(second1 - second2);
    // Chuyển lại thời gian
    TimeType hours = compareTime / HOURS;
    TimeType minutes = compareTime % HOURS / MINUTES;
    TimeType seconds = compareTime % MINUTES;
    Clock clock = {hours, minutes, seconds};
    Clock *pClock = &clock;

    return pClock;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    // Giờ hiện tại dựa trên hệ thống
    time_t now = time(0);
    // Chuyển now sang dạng chuỗi
    tm *currentTime = localtime(&now);
    // In giờ hiện tại
    printf("The local time is: %d:%d:%d \n", currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec);

    Clock clock1 = {currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec};
    Clock clock2 = {generateRandom(0, 23), generateRandom(0, 59), generateRandom(0, 59)};

    // In ra các mốc thời gian
    cout << "Time 1: ";
    printTime(&clock1);
    cout << "Time 2: ";
    printTime(&clock2);
    // Tính và in ra độ chênh lệch giữa hai mốc thời gian
    cout << "Different: ";
    printTime(timeDifference(&clock1, &clock2));
    return 0;
}
