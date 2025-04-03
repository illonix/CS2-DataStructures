//
// File:        logentry.hpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class definition for a log entry.
//
//
//
 
#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>

//
class Date {
public:
            Date() {};
    void setDay(const String& d) { day = d; }
    void setMonth(const String& m) { month = m; }
    void setYear(const String& y) { year = y; }

    String getDay() const { return day; }
    String getMonth() const { return month; }
    String getYear() const { return year; }

private:
    String  day, month, year;
};

//
class Time {
  public:
            Time() {};
    void setHour(const String& h) { hour = h; }
    void setMinute(const String& m) { minute = m; }
    void setSecond(const String& s) { second = s; }

    String getHour() const { return hour; }
    String getMinute() const { return minute; }
    String getSecond() const { return second; }

  private:
    String  hour, minute, second;
};


// A single log entry
class LogEntry {
public:
            LogEntry() {};
            LogEntry(const String&);
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

    // Getter methods
    String getHost() const { return host; }
    Date getDate() const { return date; }
    Time getTime() const { return time; }
    String getRequest() const { return request; }
    String getStatus() const { return status; }
    int getNumberOfBytes() const { return number_of_bytes; }

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry>&);
void                    by_host     (std::ostream&, const std::vector<LogEntry>&);
int                     byte_count  (const std::vector<LogEntry>&);
int                     stringToInt (const String&);

#endif
