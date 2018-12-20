#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <utility>

#include "database.h"
#include "date.h"

using namespace std;

Database::Database() {}

void Database::Add(const Date &date, const string &event)
{
    if (storage.count(date) > 0)
    {
        if (storage[date].first.count(event) > 0)
        {
            return;
        }
    }
    storage[date].first.insert(event);
    storage[date].second.push_back(event);
}

void Database::Print(ostream &os) const
{
    for (const auto &item : storage)
    {
        for (const auto &e : item.second.second)
        {
            //cout << item.first << " ";
            os << item.first << " ";
            //cout << e << endl;
            os << e << endl;
        }
    }
}

pair<Date, string> Database::Last(const Date &date) const
{
    pair<Date, string> result({2000, 1, 1}, "No events before this date");
    auto it = storage.upper_bound(date);
    if (it == storage.begin())
    {
        throw invalid_argument("No events before this date");
    }
    else
    {
        --it;
        result.first = it->first;
        result.second = it->second.second.back();
    }
    return result;
}
