/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>

std::random_device rd;
std::mt19937 rng(rd());

std::string kYourName = "Tom Wang"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename) {
    std::ifstream in(filename);

    std::string name;
    std::unordered_set<std::string> applicants;

    while (std::getline(in, name)) {
        applicants.insert(name);
    }

    return applicants;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */

std::pair<char, char> initials_of_name(std::string name) {
    if (name.empty()) {
        return {' ', ' '};
    }
    char first = name[0], second = ' ';
    size_t space_pos = name.find(' ');
    if (space_pos != std::string::npos && space_pos + 1 < name.size()) {
        second = name[space_pos + 1];
    }
    return {first, second};
}

bool compare_initials_of_name(std::string name, std::string student) {
    return initials_of_name(name) == initials_of_name(student);
}

std::queue<const std::string*> find_matches(std::string name, std::unordered_set<std::string>& students) {
    std::queue<const std::string*> Q;
    for (const std::string& student : students) {
        if (compare_initials_of_name(name, student)) {
            Q.push(&student);
        }
    }
    return Q;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
    if (matches.empty() == true) {
        return "NO MATCHES FOUND.";
    }

    std::uniform_int_distribution<> dis(1, matches.size());
    int count = dis(rng);

    std::string match_name;
    while (count--) {
        const std::string* pointer = matches.front();
        matches.pop();
        match_name = *pointer; 
    }
    return match_name;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
