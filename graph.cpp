/*
    graph.cpp

    Holds graph methods that creates 2d graph between all combinations and traverses graph to find superpermutation
*/
#include "graph.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

// sets up graph class and generates distances between nodes
graph::graph(std::vector<std::string>& combinations){

    // allocates 2d array
    string_size = combinations[0].size();
    map_size = combinations.size();
    distance_map = new int*[map_size];
    for(int n = 0; n < map_size; n++){
        distance_map[n] = new int[map_size];
    }

    // runs algorithm on each combination
    for(int j = 0; j < map_size; j++){
        for(int k = 0; k < map_size; k++){  
            int x;
            // goes through each letter till one does not match
            for(x = 0; x < string_size; x++){
                
                if(combinations[j].substr(x,string_size-x) == combinations[k].substr(0,string_size-x))
                    break;
            }
            distance_map[j][k] = x;
            printf("From: %s To: %s | d = %d\n",combinations[j].c_str(),combinations[k].c_str(),x);
        }
    }


}

graph::~graph(){
    // deallocate array
    for(int n = 0; n < map_size; n++){
        delete[] distance_map[n];
    }
    delete[] distance_map;
}

// gets superpermutation route and assigns it to smallest_route
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
// recursion helper to get smallest route
void graph::getRouteHelper(std::vector<int>& route, size_t size, size_t& min_size){
    // if route is bigger than current minimum size, return and don't go further
    if(size > min_size){
        return;
    }
    // if route is smaller than current smallest, set as new smallest route
    else if(route.size() == map_size && min_size > size){
        min_size = size;
        smallest_route = route;
        return;
    }
    // recall function with a new and unique node appended to the route.
    else{
        int from = *(route.end() - 1);

        for(int n = 0; n < map_size; n++){
            if(n == from) continue;
            if(distance_map[from][n] > (string_size+1)/2) continue;
            if(std::find(route.begin(),route.end(),n) == route.end()){
                route.push_back(n);
                getRouteHelper(route, size + distance_map[from][n], min_size);
                route.pop_back();
            }
        }
    }

}

std::string graph::buildString(std::vector<std::string>& nodes){
    std::string supercombination = "";
    supercombination += nodes[0];

    for(int i = 1; i < nodes.size(); i++){
        supercombination += nodes[smallest_route[i]].substr(string_size - distance_map[smallest_route[i-1]][smallest_route[i]],string_size);
        printf("%s :%s\n", nodes[smallest_route[i]].substr(string_size - distance_map[smallest_route[i-1]][smallest_route[i]],string_size).c_str() ,supercombination.c_str());
    }

    return supercombination;
}