#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int calculateSeekTime(int head, vector<int>& requests, string direction, int max_cylinder) {
    int total_seek_time = 0;
    sort(requests.begin(), requests.end());
    int index = find(requests.begin(), requests.end(), head) - requests.begin();
    vector<int> left_requests(requests.begin(), requests.begin() + index);
    vector<int> right_requests(requests.begin() + index + 1, requests.end());

    if (direction == "left") {
        reverse(left_requests.begin(), left_requests.end());
        total_seek_time += head + max_cylinder;
    } else {
        total_seek_time += max_cylinder - head;
    }

    for (const auto& request : right_requests) {
        total_seek_time += abs(request - head);
        head = request;
    }

    if (direction == "left") {
        total_seek_time += head + max_cylinder;
        head = 0;
    } else {
        total_seek_time += max_cylinder - head;
        head = max_cylinder;
    }

    for (const auto& request : left_requests) {
        total_seek_time += abs(request - head);
        head = request;
    }

    return total_seek_time;
}

int main() {
    int head, max_cylinder, num_requests;
    string direction;
    cout << "Enter the initial head position: ";
    cin >> head;
    cout << "Enter the maximum cylinder number: ";
    cin >> max_cylinder;
    cout << "Enter the direction (left/right): ";
    cin >> direction;
    cout << "Enter the number of disk requests: ";
    cin >> num_requests;
    vector<int> requests(num_requests);
    cout << "Enter the disk requests: ";
    for (int i = 0; i < num_requests; i++) {
        cin >> requests[i];
    }

    cout << "FCFS Total Seek Time: " << calculateSeekTime(head, requests, direction, max_cylinder) << endl;

    int scan_seek_time = calculateSeekTime(head, requests, direction, max_cylinder);
    cout << "SCAN Total Seek Time: " << scan_seek_time << endl;

    int cscan_seek_time = calculateSeekTime(head, requests, direction, max_cylinder);
    cout << "C-SCAN Total Seek Time: " << cscan_seek_time << endl;

    int look_seek_time = calculateSeekTime(head, requests, direction, max_cylinder);
    cout << "LOOK Total Seek Time: " << look_seek_time << endl;

    return 0;
}
