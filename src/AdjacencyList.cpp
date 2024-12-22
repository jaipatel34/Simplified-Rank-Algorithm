
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "AdjacencyList.h"

using namespace std;

//Constructor
AdjacencyList::AdjacencyList(){

}

//finds the edge and adds it
void AdjacencyList::addEdge(const string& fromEdge, const string& toEdge) {
    if (graph.find(toEdge) == graph.end()) {
        graph[toEdge] = {};
    }
    if (graph.find(fromEdge) == graph.end()) {
        graph[fromEdge] = {};
    }

    graph[fromEdge].push_back(toEdge);
    out_deg[fromEdge]++;
};

//finds the rank
void AdjacencyList::GetRank() {
    double firstr = 1.0 / graph.size();
    for (const auto& ThePage : graph) {
        rank[ThePage.first] = firstr;
    }
};

//finds the PageRank
string AdjacencyList::PageRank(int n) {
    GetRank();

    if (n == 1) {
        stringstream newAnswer;

        //convert for sorting
        vector<pair<string, double>> FirstRank(rank.begin(), rank.end());
        sort(FirstRank.begin(), FirstRank.end());

        //get output
        for (const auto& ThePage : FirstRank) {
            newAnswer << ThePage.first << " " << fixed << setprecision(2) << ThePage.second<< "\n";
        }

        string answer = newAnswer.str();
        cout << answer;
        return answer;
    }

    //find the PageRank based of times it goes through
    for (int it = 1; it < n; it++) {
        unordered_map<string, double> newRank;

        for (const auto& ThePage: graph) {
            newRank[ThePage.first] = 0.0;
        }

        for (const auto& ThePage:graph) {
            double div = rank[ThePage.first] / out_deg[ThePage.first];

            for (const auto& ThePages: ThePage.second) {
                newRank[ThePages] += div;
            }
        }

        rank = newRank;
    }
    stringstream NewAnswer;

    //sort url
    vector<pair<string, double>> sorte(rank.begin(), rank.end());
    sort(sorte.begin(), sorte.end());

    //for output
    for (const auto& ThePage : sorte) {
        NewAnswer << ThePage.first << " " << fixed << setprecision(2) << ThePage.second << "\n";
    }

    string answers = NewAnswer.str();
    cout << answers;
    return answers;
};

//Destructor
AdjacencyList::~AdjacencyList() {

};
