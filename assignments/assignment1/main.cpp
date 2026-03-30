/*
 * CS106L Assignment 1: SimpleEnroll
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 *
 * Welcome to Assignment 1 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";

struct Course {
    std::string title;
    std::string number_of_units;
    std::string quarter;
};

#include "utils.cpp"

void parse_csv(std::string filename, std::vector<Course>& courses) {
    std::ifstream in(filename);
    
    int i = 1;
    std::string str;
    // fliter line one
    std::getline(in, str);
    while (std::getline(in, str)) {
        std::vector<std::string> tokens = split(str, ',');
        courses.push_back({tokens[0], tokens[1], tokens[2]});
    }

    in.close();
}

void write_courses_offered(std::vector<Course>& all_courses) {
    std::string filename = "./student_output/courses_offered.csv";
    std::ofstream out(filename);
    
    out << "Title,Number of Units,Quarter" << std::endl;
    std::vector<Course> courses_offered;
    for (const auto& course : all_courses) {
        if (course.quarter != "null") {
            courses_offered.push_back(course);
        }
    }
    
    for (const auto& course : courses_offered) {
        out << course.title << "," << course.number_of_units << "," << course.quarter << std::endl;
        delete_elem_from_vector(all_courses, course);
    }

    out.close();
}

void write_courses_not_offered(std::vector<Course>& unlisted_courses) {
    std::string filename = "./student_output/courses_not_offered.csv";
    std::ofstream out(filename);
    
    out << "Title,Number of Units,Quarter" << std::endl;
    for (const auto& course : unlisted_courses) {
        out << course.title << "," << course.number_of_units << "," << course.quarter << std::endl;
    }

    out.close();
}

int main() {
  static_assert(is_valid_course<Course>, "Course struct is not correctly defined!");

  std::vector<Course> courses;
  parse_csv("courses.csv", courses);

  write_courses_offered(courses);
  write_courses_not_offered(courses);

  return run_autograder();
}
