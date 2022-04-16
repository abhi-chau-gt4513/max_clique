#include "algo.h";


// ***************** Build Graphs Logic *****************

void build_graphs() {
    vector<char> vertices;
    vertices.push_back('a');
    vertices.push_back('b');
    vertices.push_back('c');
    vertices.push_back('d');
    vertices.push_back('e');
    vertices.push_back('f');
    vertices.push_back('g');
    vertices.push_back('h');

    int arr_len = vertices.size();


    graph1 = getClique(&vertices, arr_len);


    unsigned_int l1 = arr_len / 2;
    vector<char> v1 = getSubVerts(vertices, 0, l1);
    Graph graph2a = getClique(&v1, l1);
    graph2a.vertices = v1;
    unsigned_int l2 = arr_len - l1;
    vector<char> v2 = getSubVerts(vertices, l1, arr_len);
    Graph graph2b = getClique(&v2, l2);
    graph2b.vertices = v2;

    graph2.vertices = vertices;
    graph2.numEdges = 0;
    for (unsigned_int i = 0; i < graph2a.size; i++) {
        vector<char> adj_edgs;
        for (unsigned_int j = i + 1; j < graph2a.size; j++) {
            adj_edgs.push_back(graph2a.vertices.at(j));
            graph2.numEdges++;
        }
        adj_edgs.push_back(graph2b.vertices.at(0));
        graph2.numEdges++;
        graph2.edges.insert(make_pair(graph2a.vertices.at(i), adj_edgs));
    }
    for (unsigned_int i = 0; i < graph2b.size; i++) {
        vector<char> adj_edgs;
        for (unsigned_int j = i + 1; j < graph2b.size; j++) {
            adj_edgs.push_back(graph2b.vertices.at(j));
            graph2.numEdges++;
        }
        graph2.edges.insert(make_pair(graph2b.vertices.at(i), adj_edgs));
    }
    graph2.size = vertices.size();
    
    graph3.vertices = vertices;
    graph3.size = vertices.size();
    for (unsigned_int i = 0; i < graph3.size; i++) {
        vector<char> adj_edgs;
        graph3.edges.insert(make_pair(graph3.vertices.at(i), adj_edgs));
    }
    graph3.numEdges = 0;

}

/**
 * @brief Get the Sub Verts object
 * 
 * @param verts 
 * @param start 
 * @param end 
 * @return vector<char> 
 * 
 * verts.begin() is the pointer to first element of vector
 * 
 * verts.end() is the pointer to last element of vector
 * 
 * Source: https://www.geeksforgeeks.org/vectorbegin-vectorend-c-stl/ 
 */
vector<char> getSubVerts(vector<char> verts, unsigned_int start, unsigned_int end) {
    if (start < 0 || end > verts.size()) return verts;
    auto first = verts.begin() + start;
    cout << *first << endl;
    auto last = verts.begin() + end;
    cout << *(last - 1) << endl;
    vector<char> v(first, last);
    return v;

}


Graph getClique(vector<char> *verts, unsigned_int size) {
    // ptrn i = 0;
    Graph clique;
    clique.size = size;
    unsigned_int val1 = * factorial(size);
    unsigned_int val2 = * factorial(2);
    unsigned_int val3 = * factorial(size - 2);
    clique.numEdges = (unsigned_int) (val1 / val2 / val3);

    for (unsigned_int i = 0; i < size; i++) {
        clique.vertices.push_back((* verts).at(i));
        vector<char> adj_edgs;
        for (unsigned_int j = i + 1; j < size; j++) {
            adj_edgs.push_back(verts->at(j));
            
        }
        clique.edges.insert(make_pair(verts->at(i), adj_edgs));
    }

    return clique;
}

Graph getGraph1(void) {
    return graph1;
}

Graph getGraph2(void) {
    return graph2;
}

Graph getGraph3(void) {
    return graph3;
}

unsigned_int getArrLength(unsigned_int arr_size, unsigned_int data_size) {
    return arr_size / data_size;
}

unsigned_int* factorial(unsigned_int num) {
    unsigned_int start = 1;
    unsigned_int *result = &start;
    while (num >= 1) {
        *result *= num;
        num --;
    }
    return result;
}

// ***************** Algorithm Logic *****************

void clique_search() {
    Graph graph = getGraph1();
    build_edge_map(&graph);
    map <char, char > maxEdges;
    unsigned_int numTrue = 0;
    unsigned_int numFalse = 0;
    for (int i = 0; i < graph.size; i++) {
        for (int j = i + 1; j < graph.size; j++) {
            vector <char> e;
            e.push_back(graph.vertices.at(i));
            e.push_back(graph.vertices.at(j));
            auto f = edges.find(e);
            unsigned_int second = f -> second;
            if (edges.at((f->first)) != 0) {
                cout << true << endl;
                numTrue++;
            } else {
                cout << false << endl;
                numFalse ++;
            }
            e.clear();

        }
    }
    cout << numTrue << endl;
    cout << numFalse << endl;
}

void build_edge_map(Graph *graph) {
    for (int i = 0; i < graph->vertices.size(); i++) {
        char c = graph->vertices.at(i);
        unsigned_int k = 0;
        for (int j = i + 1; j < graph->vertices.size(); j++) {
            vector <char> edg;
            edg.push_back(c);
            edg.push_back(graph->vertices.at(j));
            if (graph->edges.at(c).size() == 0 || k >= graph->edges.at(c).size() || graph->edges.at(c).at(k) != graph->vertices.at(j)) {
                edges.insert(make_pair(edg, 0));
            } else {
                edges.insert(make_pair(edg, 1));
                k++;
            }
        }
    }
    map <vector <char>, unsigned_int> test = edges;
    cout << test.size();
}

int main() {
    build_graphs();
    clique_search();
    return 0;
}