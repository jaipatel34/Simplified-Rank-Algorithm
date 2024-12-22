
//header file
#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unordered_map>


using namespace std;

class AdjacencyList {
private:
    unordered_map<string, double> rank;
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> out_deg;

public:
    AdjacencyList();
    void addEdge(const string& fromEdge, const string& toEdge);
    void GetRank();
    string PageRank(int n);
    ~AdjacencyList();
};

