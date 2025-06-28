#include <iostream>
#include <vector>
using namespace std;

struct Course {
    string name;
    float grade;
    int credit;
};
    
float calculateCGPA(const vector<Course>& courses) {
    float totalGradePoints = 0;
    int totalCredits = 0;

    for (const auto& course : courses) {
        totalGradePoints += course.grade * course.credit;
        totalCredits += course.credit;
    }

    return (totalCredits == 0) ? 0 : totalGradePoints / totalCredits;
}

void displayCourses(const vector<Course>& courses) {
    cout << "\nCourse Details:\n";
    for (const auto& course : courses) {
        cout << "Course: " << course.name << " | Grade: " << course.grade << " | Credits: " << course.credit << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    vector<Course> courses(n);
    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << " name: ";
        cin >> courses[i].name;
        cout << "Grade: ";
        cin >> courses[i].grade;
        cout << "Credit Hours: ";
        cin >> courses[i].credit;
    }

    displayCourses(courses);
    cout << "\nFinal CGPA: " << calculateCGPA(courses) << endl;

    return 0;
}
