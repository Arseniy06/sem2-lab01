#include <vector>
#include <string>

struct Student
{
    std::string Name;
    std::string GroupId;
    std::vector<unsigned> Ratings;
    std::vector<std::string> Subjects;
};

void SortByName(std::vector<Student>& students);

void SortByRating(std::vector<Student>& students);

size_t CountTwoness(const std::vector<Student>& students);

size_t CountExcellent(const std::vector<Student>& students);

std::vector<Student> VectorMathExcellent(const std::vector<Student>& students);
