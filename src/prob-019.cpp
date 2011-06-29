#include <iostream>

bool isLeapYear(int year) {
    return year % 4 == 0 && (year % 100 > 0 || year % 400 == 0);
}

int whatDate(int day, int month, int year) {
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int numberOfDays = day;

    for (int m = 1; m < month; ++m) numberOfDays += daysInMonth[m];
    if (month > 2 && isLeapYear(year)) ++numberOfDays;

    for (int y = 1900; y < year; ++y) 
	numberOfDays += isLeapYear(y)? 366: 365;

    return numberOfDays % 7;
}

int main() {
    int numberOfSundays = 0;
    for (int y = 1901; y <= 2000; ++y)
	for (int m = 1; m <= 12; ++m)
	    if (whatDate(1, m, y) == 0) ++numberOfSundays;

    std::cout << numberOfSundays << "\n";
    return 0;
}
