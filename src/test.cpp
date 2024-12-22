
//uncomment to test this and then comment the main (do vice versa for opposite)
/*#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "AdjacencyList.h"


using namespace std;

TEST_CASE("PageRank Output Test 1", "Ex") {

    string input = R"(1 15
aman.com github.com
)";

    string expectedOutput = R"(aman.com 0.00
github.com 0.00
)";
    AdjacencyList g;
    istringstream stream(input);
    int num;
    int i;
    stream >> num;
    stream >> i;

    string fromEdge;
    string toEdge;
    for (int j = 0; j < num; j++){
        stream >> fromEdge;
        stream >> toEdge;
        g.addEdge(fromEdge, toEdge);
    }

    string actualOutput = g.PageRank(i);

    REQUIRE(actualOutput == expectedOutput);
}
TEST_CASE("PageRank Output Test 2", "Ex"){

    string input = R"(157 12
pcbuildinguf.com ufl.edu
samsung.com openai.com
roblox.com microsoft.com
apple.com python.org
aman.com samsung.com
openai.com disney.com
chase.com getbootstrap.com
mozilla.org apple.com
roblox.com openai.com
google.com reactjs.org
mozilla.org zoom.us
roblox.com instagram.com
apple.com pcbuildinguf.com
mozilla.org samsung.com
stackoverflow.com reactjs.org
disney.com getbootstrap.com
zoom.us roblox.com
samsung.com aman.com
ufl.edu github.com
facebook.com twitter.com
microsoft.com ufl.edu
python.org ufl.edu
chase.com reactjs.org
pcbuildinguf.com reactjs.org
twitter.com getbootstrap.com
instagram.com disney.com
getbootstrap.com facebook.com
wikipedia.org openai.com
facebook.com zoom.us
apple.com mozilla.org
aman.com instagram.com
github.com zoom.us
google.com instagram.com
reactjs.org mozilla.org
openai.com samsung.com
facebook.com apple.com
stackoverflow.com aman.com
zoom.us chase.com
github.com twitter.com
instagram.com pcbuildinguf.com
disney.com google.com
disney.com mozilla.org
twitter.com python.org
openai.com instagram.com
microsoft.com roblox.com
chase.com aman.com
ufl.edu instagram.com
getbootstrap.com google.com
openai.com zoom.us
reactjs.org openai.com
mozilla.org wikipedia.org
google.com ufl.edu
roblox.com python.org
mozilla.org ufl.edu
stackoverflow.com facebook.com
facebook.com samsung.com
github.com aman.com
facebook.com aman.com
disney.com reactjs.org
mozilla.org reactjs.org
apple.com roblox.com
disney.com instagram.com
python.org twitter.com
facebook.com python.org
zoom.us pcbuildinguf.com
facebook.com wikipedia.org
disney.com github.com
google.com stackoverflow.com
openai.com reactjs.org
samsung.com google.com
ufl.edu reactjs.org
pcbuildinguf.com google.com
aman.com python.org
zoom.us apple.com
twitter.com samsung.com
github.com instagram.com
twitter.com github.com
microsoft.com facebook.com
openai.com ufl.edu
stackoverflow.com roblox.com
chase.com mozilla.org
zoom.us google.com
getbootstrap.com reactjs.org
microsoft.com pcbuildinguf.com
openai.com facebook.com
mozilla.org instagram.com
instagram.com getbootstrap.com
ufl.edu twitter.com
mozilla.org chase.com
disney.com aman.com
instagram.com reactjs.org
getbootstrap.com roblox.com
zoom.us github.com
ufl.edu aman.com
twitter.com apple.com
microsoft.com openai.com
pcbuildinguf.com samsung.com
reactjs.org apple.com
microsoft.com getbootstrap.com
microsoft.com mozilla.org
wikipedia.org mozilla.org
python.org wikipedia.org
mozilla.org pcbuildinguf.com
wikipedia.org ufl.edu
mozilla.org google.com
instagram.com github.com
stackoverflow.com github.com
samsung.com mozilla.org
openai.com apple.com
pcbuildinguf.com twitter.com
aman.com reactjs.org
openai.com twitter.com
samsung.com chase.com
python.org google.com
facebook.com instagram.com
google.com pcbuildinguf.com
zoom.us wikipedia.org
github.com google.com
pcbuildinguf.com stackoverflow.com
twitter.com instagram.com
aman.com getbootstrap.com
disney.com chase.com
python.org instagram.com
microsoft.com aman.com
apple.com github.com
facebook.com roblox.com
ufl.edu stackoverflow.com
aman.com stackoverflow.com
chase.com facebook.com
facebook.com stackoverflow.com
samsung.com zoom.us
openai.com getbootstrap.com
aman.com chase.com
chase.com github.com
roblox.com facebook.com
aman.com pcbuildinguf.com
getbootstrap.com chase.com
aman.com mozilla.org
apple.com reactjs.org
wikipedia.org disney.com
openai.com pcbuildinguf.com
mozilla.org getbootstrap.com
github.com reactjs.org
getbootstrap.com zoom.us
aman.com apple.com
apple.com samsung.com
google.com getbootstrap.com
facebook.com google.com
microsoft.com stackoverflow.com
roblox.com aman.com
apple.com twitter.com
facebook.com reactjs.org
reactjs.org roblox.com
aman.com zoom.us
twitter.com facebook.com
samsung.com microsoft.com
microsoft.com disney.com)";

    string expectedOutput = R"(aman.com 0.05
apple.com 0.05
chase.com 0.03
disney.com 0.02
facebook.com 0.04
getbootstrap.com 0.05
github.com 0.05
google.com 0.06
instagram.com 0.07
microsoft.com 0.02
mozilla.org 0.06
openai.com 0.05
pcbuildinguf.com 0.05
python.org 0.03
reactjs.org 0.09
roblox.com 0.06
samsung.com 0.04
stackoverflow.com 0.03
twitter.com 0.04
ufl.edu 0.04
wikipedia.org 0.02
zoom.us 0.04
)";
    AdjacencyList g;
    istringstream stream(input);
    int num;
    int i;
    stream >> num;
    stream >> i;

    string fromEdge;
    string toEdge;
    for (int j = 0; j < num; j++){
        stream >> fromEdge;
        stream >> toEdge;
        g.addEdge(fromEdge, toEdge);
    }

    string actualOutput = g.PageRank(i);

    REQUIRE(actualOutput == expectedOutput);
}


TEST_CASE("PageRank Output Test 3", "Ex"){

    string input = R"(7 3
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com)";

    string expectedOutput = R"(facebook.com 0.30
gmail.com 0.15
google.com 0.10
maps.com 0.25
ufl.edu 0.20
)";
    AdjacencyList g;
    istringstream stream(input);
    int num;
    int i;
    stream >> num;
    stream >> i;

    string fromEdge;
    string toEdge;
    for (int j = 0; j < num; j++){
        stream >> fromEdge;
        stream >> toEdge;
        g.addEdge(fromEdge, toEdge);
    }

    string actualOutput = g.PageRank(i);

    REQUIRE(actualOutput == expectedOutput);
}
TEST_CASE("PageRank Output Test 4", "Ex") {

    string input = R"(14 100
mozilla.org youtube.com
pcbuildinguf.com mozilla.org
google.com zoom.us
google.com pcbuildinguf.com
youtube.com pcbuildinguf.com
zoom.us google.com
wikipedia.org youtube.com
zoom.us wikipedia.org
youtube.com mozilla.org
google.com wikipedia.org
youtube.com zoom.us
mozilla.org wikipedia.org
wikipedia.org google.com
wikipedia.org mozilla.org)";

    string expectedOutput = R"(google.com 0.13
mozilla.org 0.25
pcbuildinguf.com 0.11
wikipedia.org 0.22
youtube.com 0.20
zoom.us 0.11
)";
    AdjacencyList g;
    istringstream stream(input);
    int num;
    int i;
    stream >> num;
    stream >> i;

    string fromEdge;
    string toEdge;
    for (int j = 0; j < num; j++){
        stream >> fromEdge;
        stream >> toEdge;
        g.addEdge(fromEdge, toEdge);
    }

    string actualOutput = g.PageRank(i);

    REQUIRE(actualOutput == expectedOutput);
}
TEST_CASE("PageRank Output Test 5", "Ex") {

    string input = R"(140 510
disney.com twitter.com
mozilla.org wikipedia.org
pcbuildinguf.com instagram.com
wikipedia.org python.org
twitter.com wikipedia.org
disney.com zoom.us
samsung.com pcbuildinguf.com
google.com mozilla.org
zoom.us youtube.com
instagram.com openai.com
youtube.com twitter.com
stackoverflow.com zoom.us
reactjs.org python.org
python.org instagram.com
reactjs.org openai.com
instagram.com python.org
python.org facebook.com
zoom.us stackoverflow.com
facebook.com zoom.us
google.com pcbuildinguf.com
python.org openai.com
instagram.com reactjs.org
mozilla.org reactjs.org
instagram.com pcbuildinguf.com
aman.com zoom.us
stackoverflow.com reactjs.org
samsung.com google.com
samsung.com twitter.com
wikipedia.org zoom.us
samsung.com aman.com
zoom.us openai.com
pcbuildinguf.com stackoverflow.com
mozilla.org instagram.com
disney.com instagram.com
stackoverflow.com samsung.com
instagram.com wikipedia.org
twitter.com reactjs.org
pcbuildinguf.com github.com
google.com youtube.com
zoom.us github.com
aman.com stackoverflow.com
aman.com pcbuildinguf.com
twitter.com python.org
roblox.com reactjs.org
stackoverflow.com disney.com
stackoverflow.com youtube.com
disney.com mozilla.org
samsung.com stackoverflow.com
twitter.com github.com
python.org mozilla.org
twitter.com mozilla.org
samsung.com mozilla.org
facebook.com reactjs.org
aman.com github.com
youtube.com stackoverflow.com
github.com openai.com
pcbuildinguf.com python.org
twitter.com samsung.com
facebook.com twitter.com
zoom.us wikipedia.org
google.com instagram.com
zoom.us roblox.com
pcbuildinguf.com reactjs.org
openai.com aman.com
python.org disney.com
wikipedia.org reactjs.org
aman.com facebook.com
youtube.com python.org
instagram.com facebook.com
aman.com roblox.com
roblox.com python.org
roblox.com disney.com
pcbuildinguf.com twitter.com
facebook.com samsung.com
pcbuildinguf.com facebook.com
reactjs.org zoom.us
github.com samsung.com
samsung.com zoom.us
aman.com wikipedia.org
reactjs.org pcbuildinguf.com
disney.com reactjs.org
aman.com instagram.com
disney.com pcbuildinguf.com
reactjs.org instagram.com
zoom.us twitter.com
github.com twitter.com
google.com samsung.com
facebook.com instagram.com
instagram.com mozilla.org
stackoverflow.com twitter.com
youtube.com roblox.com
facebook.com roblox.com
facebook.com python.org
github.com youtube.com
samsung.com disney.com
openai.com stackoverflow.com
mozilla.org samsung.com
reactjs.org mozilla.org
reactjs.org github.com
samsung.com facebook.com
samsung.com instagram.com
youtube.com openai.com
github.com aman.com
stackoverflow.com aman.com
instagram.com zoom.us
aman.com samsung.com
stackoverflow.com instagram.com
disney.com samsung.com
wikipedia.org pcbuildinguf.com
openai.com disney.com
google.com python.org
openai.com youtube.com
disney.com facebook.com
google.com openai.com
twitter.com instagram.com
python.org twitter.com
disney.com stackoverflow.com
facebook.com wikipedia.org
pcbuildinguf.com aman.com
zoom.us facebook.com
pcbuildinguf.com wikipedia.org
roblox.com pcbuildinguf.com
mozilla.org google.com
python.org samsung.com
instagram.com stackoverflow.com
roblox.com stackoverflow.com
disney.com wikipedia.org
youtube.com disney.com
google.com github.com
aman.com disney.com
zoom.us disney.com
youtube.com instagram.com
pcbuildinguf.com disney.com
pcbuildinguf.com roblox.com
wikipedia.org aman.com
instagram.com twitter.com
github.com wikipedia.org
aman.com reactjs.org
zoom.us aman.com
reactjs.org aman.com

)";

    string expectedOutput = R"(aman.com 0.07
disney.com 0.06
facebook.com 0.05
github.com 0.04
google.com 0.02
instagram.com 0.08
mozilla.org 0.05
openai.com 0.05
pcbuildinguf.com 0.06
python.org 0.06
reactjs.org 0.08
roblox.com 0.03
samsung.com 0.06
stackoverflow.com 0.06
twitter.com 0.07
wikipedia.org 0.06
youtube.com 0.03
zoom.us 0.06
)";
    AdjacencyList g;
    istringstream stream(input);
    int num;
    int i;
    stream >> num;
    stream >> i;

    string fromEdge;
    string toEdge;
    for (int j = 0; j < num; j++){
        stream >> fromEdge;
        stream >> toEdge;
        g.addEdge(fromEdge, toEdge);
    }

    string actualOutput = g.PageRank(i);

    REQUIRE(actualOutput == expectedOutput);
}*/
