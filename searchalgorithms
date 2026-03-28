// file to implement sorting algorithm (Quick Sort by GPA only)

#include <iostream>
#include <vector>
#include <algorithm>

// ─────────────────────────────────────────────
//  Quick Sort  —  sorted by GPA
//  Time: O(n log n) average
// ─────────────────────────────────────────────
int partitionGPA(std::vector<Student>& students, int low, int high) {
    float pivot = students[high].gpa;
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (students[j].gpa < pivot) {
            ++i;
            std::swap(students[i], students[j]);
        }
    }

    std::swap(students[i + 1], students[high]);
    return i + 1;
}

void quickSortByGPA(std::vector<Student>& students, int low, int high) {
    if (low < high) {
        int pi = partitionGPA(students, low, high);

        quickSortByGPA(students, low, pi - 1);
        quickSortByGPA(students, pi + 1, high);
    }
}

// ─────────────────────────────────────────────
//  Helper Function (for  debugging)
// ─────────────────────────────────────────────
void printByGPA(const std::vector<Student>& students) {
    std::cout << "\nStudents sorted by GPA:\n";
    for (const auto& s : students) {
        std::cout << "  " << s.name << " | GPA: " << s.gpa << "\n";
    }
}
