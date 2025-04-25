#include "include/header.hpp"
#include <algorithm>
#include <numeric>

void SortByName(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), 
        [](const Student& a, const Student& b) {
            return a.Name < b.Name;
        });
}

double CalculateAverageRating(const Student& student) {
    if (student.Ratings.empty()) return 0.0;
    double sum = std::accumulate(student.Ratings.begin(), student.Ratings.end(), 0.0);
    return sum / student.Ratings.size();
}

void SortByRating(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return CalculateAverageRating(a) < CalculateAverageRating(b);
        });
}

size_t CountTwoness(const std::vector<Student>& students) {
    return std::count_if(students.begin(), students.end(),
        [](const Student& student) {
            return std::find(student.Ratings.begin(), student.Ratings.end(), 2) != student.Ratings.end();
        });
}

size_t CountExcellent(const std::vector<Student>& students) {
    return std::count_if(students.begin(), students.end(),
        [](const Student& student) {
            if (student.Ratings.empty()) return false;
            return std::all_of(student.Ratings.begin(), student.Ratings.end(),
                [](unsigned rating) { return rating == 5; });
        });
}

std::vector<Student> VectorMathExcellent(const std::vector<Student>& students) {
    std::vector<Student> result;
    for (const auto& student : students) {
        for (size_t i = 0; i < student.Subjects.size(); ++i) {
            if (student.Subjects[i] == "Math" && i < student.Ratings.size() && student.Ratings[i] == 5) {
                result.push_back(student);
                break;
            }
        }
    }
    return result;
}
