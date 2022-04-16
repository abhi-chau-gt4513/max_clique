#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include "../graph_models/graphs.h"
using namespace std;

map <vector <char>, unsigned_int> edges;

Graph getGraph();

void clique_search();

void build_edge_map(Graph *graph);

