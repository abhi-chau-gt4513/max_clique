#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "../graph_models/graphs.h"
using namespace std;

map <vector <char>, unsigned_int> edges;
map <vector <char>, vector <char> > maxVerts;

int numVerts = 0;
int numEdges = 0;

Graph getGraph();

void clique_search();

vector <char> getMaxClique();

void build_edge_map(Graph *graph);