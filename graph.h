/*
    graph.h

    Holds graph class which has a 2d array holding distances between any two combinations
    Graph class also traverses this array to create a superpermutation
*/
#pragma once
#include <vector>
#include <string>

class graph{
    private:

        // distance map is a 2d array of numbers formatted
        // [from][to]
        // size = to map_size
        int** distance_map;

        // holds size of map array indices
        int map_size;

        // holds current size of smallest superpermutation
        int string_size;
        // holds current smallest superpermutation route (vector of ints that correspond to their location in the combination vector)
        std::vector<int> smallest_route;

        // helper for recursion of getRoute
        void getRouteHelper(std::vector<int>&, size_t current_size, size_t& min_size);

    public:
        // creates a graph with combinations passed in
        graph(std::vector<std::string>& nodes);
        ~graph();

        // builds superpermutation string
        std::string buildString(std::vector<std::string>& nodes);

        // generates smallest route
        std::vector<int> getRoute();

};


