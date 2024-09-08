
#include "graph.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

graph::graph(std::vector<std::string>& combinations){

    string_size = combinations[0].size();
    map_size = combinations.size();
    distance_map = new int*[map_size];
    for(int n = 0; n < map_size; n++){
        distance_map[n] = new int[map_size];
    }
    // Now we need to look at the combination of all different combinations and figure out where the first place they line up is.


    for(int j = 0; j < map_size; j++){
        for(int k = 0; k < map_size; k++){  
            int x;
            for(x = 0; x < string_size; x++){

                if(combinations[j].substr(x,string_size) == combinations[k].substr(0,string_size-x))
                    break;
            }
            distance_map[j][k] = x;
            printf("From: %s To: %s | d = %d\n",combinations[j].c_str(),combinations[k].c_str(),x);
        }
    }


}

graph::~graph(){
    for(int n = 0; n < map_size; n++){
        delete[] distance_map[n];
    }
    delete[] distance_map;
}

std::vector<int> graph::getRoute(){
    if(smallest_route.size() != map_size){
        
        std::vector<int> possible_route;

        possible_route.push_back(0);

        size_t min_size = std::numeric_limits<size_t>::max();

        getRouteHelper(possible_route,string_size,min_size);

        std::cout << min_size << "\n";
    
    }
    return smallest_route;
}

void graph::getRouteHelper(std::vector<int>& route, size_t size, size_t& min_size){

    if(size > min_size){
        return;
    }
    else if(route.size() == map_size && min_size > size){
        min_size = size;
        smallest_route = route;
        return;
    }
    else{
        int from = *(route.end() - 1);

        for(int n = 0; n < map_size; n++){
            if(n == from) continue;
            if(std::find(route.begin(),route.end(),n) == route.end()){
                route.push_back(n);
                getRouteHelper(route, size + distance_map[from][n], min_size);
                route.pop_back();
            }
        }
    }

}

