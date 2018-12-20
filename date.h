#pragma once

#include <iostream>
#include <sstream>

using namespace std;

class Date
{
public:

  Date(int new_year, int new_month, int new_day);


  int GetYear() const;
  int GetMonth() const;
  int GetDay() const;

private:
  int year;
  int month;
  int day;
};

ostream &operator<<(ostream &stream, const Date &date);

bool operator!=(const Date &d1, const Date &d2);
bool operator==(const Date &d1, const Date &d2);
bool operator>=(const Date &d1, const Date &d2);
bool operator<(const Date &d1, const Date &d2);
bool operator>(const Date &d1, const Date &d2);
bool operator<=(const Date &d1, const Date &d2);

  Date ParseDate(istream &date_stream);
