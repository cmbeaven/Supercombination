
#include "generator.h"
#include "graph.h"
#include <string>
#include <vector>
#include <iostream>

int main(int argc, char** argv){

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

    return 0;
}
