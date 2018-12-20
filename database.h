#pragma once

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <typeinfo>

#include "date.h"

using namespace std;

class Database
{
public:
  Database();

  void Add(const Date &date, const string &event);
  pair<Date, string> Last(const Date &date) const;
  void Print(ostream& os) const;

  template <typename Predicate>
  int RemoveIf(const Predicate predicate)
  {

    int removed_count = 0;
    vector<Date> erase_dates;

    for (auto &item : storage)
    {
      const Date &current_date = item.first;
      auto condition = [=](const string &event) { return predicate(current_date, event); };
      auto border = stable_partition(item.second.second.begin(), item.second.second.end(), condition);
      removed_count += border - item.second.second.begin();

      for (auto i = item.second.second.begin(); i != border; ++i)
      {
        item.second.first.erase(*i); // Deleting from set
      }

      item.second.second.erase(item.second.second.begin(), border); // Deleting items from vector
      if (item.second.second.empty())
      {
        erase_dates.push_back(item.first);
      }
    }
    for (const Date &d : erase_dates)
    {
      storage.erase(d);
    }
    erase_dates.clear();

    return removed_count;
  }

  template <typename Predicate>
  vector<pair<Date, string>> FindIf(const Predicate predicate) const
  {

    vector<pair<Date, string>> founds;

    for (const auto &item : storage)
    {
      for (const auto &event : item.second.second)
      {
        if (predicate(item.first, event))
        {
          founds.push_back(pair<Date,string>(item.first, event));
        }
      }
    }
    return founds;
  }

private:
  map<Date, pair<set<string>, vector<string>>> storage;
};