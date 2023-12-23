# Availability-tracker
The Availability Tracker function is designed to determine the optimal meeting time for a team based on the availability of individual team members in various time zones. The function takes a list of team members along with their respective availability intervals, represented by start and end times.

The function utilizes an unordered hash-map to store team member's names as keys and vectors of Time-Interval structs as values. Each Time-Interval struct represents a specific availability interval.

Logic:
The function counts the availability of each hour across team members by incrementing a counter in the availabilitycount map.
It identifies the most common availability period by finding the maximum count using the max_element function.
In case of no common availability, the function returns {-1, -1}.
If there are multiple equally common optimal meeting times, it returns the first one found.
