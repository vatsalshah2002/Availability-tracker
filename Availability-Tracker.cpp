#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TimeInterval {
    int start_time;
    int end_time;
};

pair<int, int> findOptimalMeetingTime(const unordered_map<string, vector<TimeInterval>>& availability) {
    unordered_map<int, int> availabilitycount;

    // Count availability periods
    for (const auto& entry : availability) {
        for (const auto& interval : entry.second) {
            for (int i = interval.start_time; i < interval.end_time; ++i) {
                availabilitycount[i]++;
            }
        }
    }

    // Find the most common availability period
    auto mostCommonPeriod = max_element(availabilitycount.begin(), availabilitycount.end(),[](const auto& a, const auto& b) {
            return a.second < b.second;
        });

    // Check if there is a common availability
    if (mostCommonPeriod->second == 0) {
        // No common availability
        return { -1, -1 };
    }

    // Check for multiple equally common optimal meeting times
    auto equalRange = equal_range(availabilitycount.begin(), availabilitycount.end(), *mostCommonPeriod,  [](const auto& a, const auto& b) {
            return a.second == b.second;
        });

    // Return the first optimal meeting time
    return { equalRange.first->first, equalRange.first->first + 1 }; // Assume intervals are 1 hour
}

int main() {
    // Sample availability data
    unordered_map<string, vector<TimeInterval>> teamAvailability1 = {
        {"John", {{9, 11}, {14, 17}, {20, 22}}},
        {"Jane", {{8, 10}, {13, 15}, {18, 21}}},
        {"Bob", {{10, 12}, {15, 18}, {21, 23}}},
    };

    unordered_map<string, vector<TimeInterval>> teamAvailability2 = {
        {"John", {{9, 11}, {14, 17}}},
        {"Jane", {{8, 10}, {13, 15}, {18, 21}}},
        {"Bob", {{10, 12}, {15, 18}, {21, 23}}},
    };

    unordered_map<string, vector<TimeInterval>> teamAvailability3 = {
        {"John", {{9, 11}, {14, 17}}},
        {"Jane", {{8, 10}, {13, 15}, {18, 21}}},
        {"Bob", {{10, 12}, {15, 18}, {21, 23}}},
        {"Alice", {{12, 14}, {19, 20}}},
    };

    unordered_map<string, vector<TimeInterval>> teamAvailability4 = {
        {"John", {{9, 11}, {14, 17}, {18, 20}}},
        {"Jane", {{8, 10}, {13, 15}, {18, 21}}},
        {"Bob", {{10, 12}, {15, 18}, {21, 23}}},
    };

    unordered_map<string, vector<TimeInterval>> teamAvailability5 = {
        {"John", {{9, 11}, {14, 17}, {18, 20}}},
        {"Jane", {{8, 10}, {13, 15}, {18, 21}}},
        {"Bob", {{10, 12}, {15, 18}, {21, 23}}},
        {"Alice", {{12, 14}, {19, 20}}},
    };

    // Find optimal meeting time
    auto optimalMeetingTime1 = findOptimalMeetingTime(teamAvailability1);
    auto optimalMeetingTime2 = findOptimalMeetingTime(teamAvailability2);
    auto optimalMeetingTime3 = findOptimalMeetingTime(teamAvailability3);
    auto optimalMeetingTime4 = findOptimalMeetingTime(teamAvailability4);
    auto optimalMeetingTime5 = findOptimalMeetingTime(teamAvailability5);

    cout << "Optimal meeting time 1: " << optimalMeetingTime1.first << ":00 - " << optimalMeetingTime1.second << ":00\n";
    cout << "Optimal meeting time 2: " << optimalMeetingTime2.first << ":00 - " << optimalMeetingTime2.second << ":00\n";
    cout << "Optimal meeting time 3: " << optimalMeetingTime3.first << ":00 - " << optimalMeetingTime3.second << ":00\n";
    cout << "Optimal meeting time 4: " << optimalMeetingTime4.first << ":00 - " << optimalMeetingTime4.second << ":00\n";
    cout << "Optimal meeting time 5: " << optimalMeetingTime5.first << ":00 - " << optimalMeetingTime5.second << ":00\n";

    return 0;
}

