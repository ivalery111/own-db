# Description
This simple database works with pairs(date,event). Also this database knows select and remove events by user condition.

# List of operations:

* **Add *date event*** - add pair(***date,event***) to database;
  - ***date*** has a format: *"year-month-day"*. After field ***date*** tthere must be a space that separates from the ***event***
* **Print** - dispay all data;
* **Find *condition*** - display all records that satisfy the ***condition***;
* **Del *condition*** - removes recors that satisfy the ***condition***;
* **Last *date*** - display a record with the latest event that happened not later that this ***date***

The conditions in the **Find** and **Del** commands impose certain restrictions on dates and events, for example:
* **Find date < 2017-11-06*** - find all events that happened before November 6, 2017;
* **Del event != "holiday"** - remove from the database all events except of **"holiday"**; 
* **Find date >= 2017-01-01 AND date < 2017-07-01 AND event == "sport event"** - find all events **"sport event"**, that occurred in the first half of 2017.
* **Del date < 2017-01-01 AND (event == "holiday" OR event == "sport event")** - remove from the database all events of **"holiday"** and **"sport event"** that happened before 2017;

In commands of both types, conditions can be empty: all events fall under such a confition.

# Input and Output format
Each line consists one command, for example:
**Add 2017-11-07 big sport event** - add pair(**2017-11-07,big sport event**) to the database;
