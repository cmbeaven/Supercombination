
#pragma once
#include <vector>
#include <string>

class graph{
    private:

        // distance map is a 2d array of numbers formatted
        // [from][to]
        // size = to map_size
        int** distance_map;

        int map_size;
        int string_size;

        std::vector<int> smallest_route;

        void getRouteHelper(std::vector<int>&, size_t current_size, size_t& min_size);

    public:
        graph(std::vector<std::string>& nodes);
        ~graph();

        std::vector<int> getRoute();

};


