//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//
 
#include "string.hpp"
#include "logentry.hpp"
#include <iostream>
#include <vector>

// REQUIRES:
// ENSURES:
LogEntry::LogEntry(const String& line) {
    //Use split to create LogEntry
    //std::vector<String> logEntryParts = line.split(' ');
    std::vector<String> logEntryParts = line.split(' ');

    if (logEntryParts.size() < 10) {
        // Handle invalid or incomplete log entries
        number_of_bytes = 0;
        return;
    }

    host = logEntryParts[0];

    // Parse date from the format: [18/Sep/2002:12:05:25 -0400]
    String dateTime = logEntryParts[3];
    dateTime = dateTime.substr(1, dateTime.length() - 1); // Remove '['
    std::vector<String> dateParts = dateTime.split('/');
    date.setDay(dateParts[0]);
    date.setMonth(dateParts[1]);
    std::vector<String> yearAndTime = dateParts[2].split(':');
    date.setYear(yearAndTime[0]);

    // Parse time
    time.setHour(yearAndTime[1]);
    time.setMinute(yearAndTime[2]);
    time.setSecond(yearAndTime[3]);

    // Request is enclosed in double quotes
    request = logEntryParts[5] + " " + logEntryParts[6] + " " + logEntryParts[7];

    // Parse status and bytes
    status = logEntryParts[8];
    number_of_bytes = (logEntryParts[9] == "-") ? 0 : stringToInt(logEntryParts[9]);
}

std::ostream& operator<<(std::ostream& out, const LogEntry& log) {
    out << "Host: " << log.getHost() << " | "
        << "Date: [" << log.getDate().getDay() << "/" 
        << log.getDate().getMonth() << "/" 
        << log.getDate().getYear() << "] "
        << "Time: " << log.getTime().getHour() << ":" 
        << log.getTime().getMinute() << ":" 
        << log.getTime().getSecond() << " | "
        << "Request: \"" << log.getRequest() << "\" | "
        << "Status: " << log.getStatus() << " | "
        << "Bytes: " << log.getNumberOfBytes();
    
    return out;
}



// REQUIRES:
// ENSURES:
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    String line;

    while (getline(in, line)) {
        if (!line.empty()) {
            result.push_back(LogEntry(line));
        }
    }
    return result;
}

// REQUIRES:
// ENSURES:
void output_all(std::ostream& out, const std::vector<LogEntry>& logs) {
    for (const auto& log : logs) {
        out << log << std::endl;
    }
}

// REQUIRES:
// ENSURES:
void by_host(std::ostream& out, const std::vector<LogEntry>& logs) {
    for (const auto& log : logs) {
        out << log.getHost() << std::endl;
    }

}

// REQUIRES:
// ENSURES:
int byte_count(const std::vector<LogEntry>& logs) {
    
    int total = 0;
    for (const auto& log : logs) {
        total += log.getNumberOfBytes();
    }
    return total;
}

int stringToInt(const String& str) {
    int result = 0;
    bool isValid = true;

    for (int i = 0; i < str.length(); ++i) {
        char c = str[i];
        if (c >= '0' && c <= '9') {  
            result = result * 10 + (c - '0');  // Convert character to digit and accumulate
        } else {
            isValid = false;
            break;  // Invalid character detected
        }
    }

    return isValid ? result : 0;  // Return 0 if the string contains invalid characters
}
