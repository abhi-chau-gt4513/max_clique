#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef uint16_t unsigned_int;

const unsigned_int graph_size = 8;

int counter = 0;

typedef struct Structure {
    vector<char> vertices;
    map <char, vector<char> > edges;
    unsigned_int size;
    unsigned_int numEdges;
} Graph;

Graph graph1;
Graph graph2;
Graph graph3;
Graph graph4;

map < vector <char>, vector <char> > max_common_edges;

vector<char> getSubVerts(vector<char> verts, unsigned_int start, unsigned_int end);

Graph getClique(vector<char> *verts, unsigned_int size);

Graph getGraph1(void);

Graph getGraph2(void);

Graph getGraph3(void);

Graph getGraph4(void);

unsigned_int getArrLength(unsigned_int arr_size, unsigned_int data_size);

unsigned_int *factorial(unsigned_int num);