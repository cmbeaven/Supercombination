#pragma once

#include <string>
#include <vector>


class generator {
    private:

    std::string elements;

    void generateHelper(std::vector<std::string>& result, std::string combination, std::string elements_left);

    public:

    generator(std::string elements_);

    std::vector<std::string>  generateOutcomes();
};