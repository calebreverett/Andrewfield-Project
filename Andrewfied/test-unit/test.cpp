#include "../src/cop3530_7_2.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
	To check output (At the andrewfied_maze_escape directory):
		g++ -std=c++14 -Werror -Wuninitialized -o test test-unit/test.cpp && ./test
*/

TEST_CASE("Function: Test 1", "[given]") 
{
	std::vector<std::string> graph = {
		"s#.#.",   
        ".#...",  
        "...#t"
	};

	REQUIRE(traverse(graph) == 8);
}

TEST_CASE("Function: Test 2", "[given]") 
{
	std::vector<std::string> graph = {
		"s....",   
        ".....",  
        "....t"
	};

	REQUIRE(traverse(graph) == 6);
}

TEST_CASE("Function: Test 3", "[given]")
{
    std::vector<std::string> graph = {
            "s#.#.",
            "##...",
            "...#t"
    };

    REQUIRE(traverse(graph) == -1);
}

TEST_CASE("Function: Test 4", "[given]")
{
    std::vector<std::string> graph = {
            "s###..........",
            ".....########.",
            "#############t"
    };

    REQUIRE(traverse(graph) == 17);
}

TEST_CASE("Function: Test 5", "[given]")
{
    std::vector<std::string> graph = {
            "s#.#.",
            ".....",
            ".####",
            ".....",
            "....#",
            "....t"
    };

    REQUIRE(traverse(graph) == 9);
}

TEST_CASE("Function: Test 6", "[given]")
{
    std::vector<std::string> graph = {
            "s####",
            ".####",
            "....t"
    };

    REQUIRE(traverse(graph) == 6);
}

TEST_CASE("Function: Test 7", "[given]")
{
    std::vector<std::string> graph = {
            "s#.#.....................",
            ".#.......................",
            "...#####################t"
    };

    REQUIRE(traverse(graph) == 28);
}

TEST_CASE("Function: Test 8", "[given]")
{
    std::vector<std::string> graph = {
            "s",
            ".",
            ".",
            ".",
            ".",
            ".",
            ".",
            "t"
    };

    REQUIRE(traverse(graph) == 7);
}

TEST_CASE("Function: Test 10", "[given]")
{
    std::vector<std::string> graph = {
            "s............",
            "#......#....#",
            "#############",
            ".............",
            ".............",
            ".............",
            ".............",
            "............t"
    };

    REQUIRE(traverse(graph) == -1);
}

TEST_CASE("Function: Test 9", "[given]")
{
    std::vector<std::string> graph;
    for(int i = 0; i < 100; i++){
        graph.push_back(".");
        for(int j = 0; j < 100; j++){
            graph[i] += '.';
        }
    }

    graph.at(0).at(0) = 's';
    graph.at(graph.size() - 1).at(graph.size()) = 't';

    int val = traverse(graph);
    REQUIRE(val == 199);
}
