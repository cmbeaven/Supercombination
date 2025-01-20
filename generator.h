/*
    generator.h

    Class template for generator
    Generator Class creates all combinations of a given string of elements
*/
#pragma once

#include <string>
#include <vector>


class generator {
    private:

    // holds string where each character is an element to be included in the combinations.
    std::string elements;

    // helper function for recursion in generator
    // takes in current combination and a string of remaining elements
    // Puts any finished combinations into the results vector
    void generateHelper(std::vector<std::string>& result, std::string combination, std::string elements_left);

    public:

    // takes in string of elements when created
    generator(std::string elements_);

    // returns vector of strings that contains each combination of set elements
    std::vector<std::string>  generateOutcomes();
};