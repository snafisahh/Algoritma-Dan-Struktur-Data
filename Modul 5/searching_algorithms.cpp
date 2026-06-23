#include "searching_algorithms.h"
#include <chrono>

using Clock = std::chrono::high_resolution_clock;

// Algoritma Linear Search
void linear_search(const std::vector<int>& data, int target, Metrics& m) {
    auto start = Clock::now();

    m.comparisons = 0;
    m.found_index = -1;

    int n = (int)data.size();
    for (int i = 0; i < n; ++i) {
        m.comparisons++;
        if (data[i] == target) {
            m.found_index = i;
            break;
        }
    }

    m.time_us = std::chrono::duration<double, std::micro>(Clock::now() - start).count();
}

// Algoritma Binary Search
void binary_search(const std::vector<int>& data, int target, Metrics& m) {
    auto start = Clock::now();

    m.comparisons = 0;
    m.found_index = -1;

    int left = 0;
    int right = (int)data.size() - 1;

    while (left <= right) {
        m.comparisons++;

        int mid = left + (right - left) / 2;

        if (data[mid] == target) {
            m.found_index = mid;
            break;
        } else if (data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    m.time_us = std::chrono::duration<double, std::micro>(Clock::now() - start).count();
} 