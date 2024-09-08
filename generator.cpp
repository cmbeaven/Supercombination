
#include "generator.h"
#include <string>
#include <vector>
#include <iostream>

generator::generator(std::string elements_){
    elements = elements_;
}


std::vector<std::string> generator::generateOutcomes(){
    std::vector<std::string> results_vector;

    std::string starter = "";

    generateHelper(results_vector,starter,elements);

    return results_vector;
}

void generator::generateHelper(std::vector<std::string>& results, std::string combination, std::string elements_left){

    if(elements_left.size() == 0){
        results.push_back(combination);
        return;
    }

    for(int i = 0; i < elements_left.size(); i++){
        std::string tempCombination = combination + elements_left[i];
        std::string tempElements_left = elements_left;
        tempElements_left.erase(tempElements_left.begin()+i);
        generateHelper(results,tempCombination,tempElements_left);
    }
    return;
}