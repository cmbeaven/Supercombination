
#include "generator.h"
#include "graph.h"
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <chrono>

int main(int argc, char** argv){

    auto t_start = std::chrono::high_resolution_clock::now();

    if(argc != 2){
        return 1;
    }

    std::string elements = argv[1];

    generator gen(elements);

    std::vector<std::string> combinations = gen.generateOutcomes();
    
    // for(auto x : combinations){
    //     std::cout << x << std::endl;
    // }

    graph combination_map(combinations);

    std::vector<int> supercombination = combination_map.getRoute();

    // for(auto x : supercombination){
    //     std::cout << combinations[x] << "\n";
    // }

    std::cout << combination_map.buildString(combinations) << "\n";

    auto diff = std::chrono::high_resolution_clock::now() - t_start;

    std::cout << "Time passed: " << std::dec << diff.count()/1000000 << "ms.\n";

    return 0;
}
