#include <iostream>
#include <ctime>

int diffDates(int year, int month, int day) {

    tm targetDate = {};
    targetDate.tm_year = year - 1900;
    targetDate.tm_mon = month - 1;
    targetDate.tm_mday = day;
    
    tm baseDate = {};
    baseDate.tm_year = 1990 - 1900;
    baseDate.tm_mon = 0;
    baseDate.tm_mday = 1;

    time_t target = mktime(&targetDate);
    time_t base = mktime(&baseDate);

    double difference  = difftime(target, base);
    return difference  / (60 * 60 * 24);
}

std::string checkAct(int startDay) {

    int dayLoop = startDay % 5;

    if (dayLoop == 0 || dayLoop == 4) {
        return "晒网";
    } else {
        return "打鱼";
    }
}

int main() {
    std::string inputDate;
    std::cout << "输入 ： ";
    std::cin >> inputDate;

    int year, month, day;
    sscanf(inputDate.c_str(), "%d-%d-%d", &year, &month, &day);

    int startDay = diffDates(year, month, day);
    std::string result = checkAct(startDay + 1);

    std::cout << "输出 ： " << result << std::endl;

    return 0;
}

//测试日期
//1990-01-02
//1990-01-04
//1990-01-06


https://drive.google.com/file/d/126tH07_GA70U7S9KgIz2Ri3MFJ5xq0j0/view?usp=drivesdk