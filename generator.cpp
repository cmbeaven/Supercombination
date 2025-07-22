/*
    generator.cpp

    Holds the class methods for generating combinations
*/


#include "generator.h"
#include <string>
#include <vector>
#include <iostream>

generator::generator(std::string elements_){
    elements = elements_;
}


std::vector<std::string> generator::generateOutcomes(){
    // location to store combinations
    std::vector<std::string> results_vector;

    // empty string to pass into helper
    std::string starter = "";

    generateHelper(results_vector,starter,elements);

    return results_vector;
}

void generator::generateHelper(std::vector<std::string>& results, std::string combination, std::string elements_left){

    // if no elements left, add combination to final results
    if(elements_left.size() == 0){
 #ifdef DEBUG
        std::cout << combination << "\n";
 #endif
        results.push_back(combination);
        return;
    }

    // for each element left
    for(int i = 0; i < elements_left.size(); i++){
        // Adds given element to end of combination
        std::string tempCombination = combination + elements_left[i];

        // erases added element from a temporary elements left
        std::string tempElements_left = elements_left;
        tempElements_left.erase(tempElements_left.begin()+i);

        // recalls self
        generateHelper(results,tempCombination,tempElements_left);
    }
    return;
}