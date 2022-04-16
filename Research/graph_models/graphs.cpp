#include "graphs.h"

int main() {
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


    Graph graph1 = getClique(&vertices, arr_len);


    Graph graph2;

    unsigned_int l1 = arr_len / 2;
    vector<char> v1 = getSubVerts(vertices, 0, l1);
    Graph graph2a = getClique(&v1, l1);
    unsigned_int l2 = arr_len - l1;
    vector<char> v2 = getSubVerts(vertices, l1, arr_len);
    Graph graph2b = getClique(&v2, l2);

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
            adj_edgs.push_back(graph2a.vertices.at(j));
            graph2.numEdges++;
        }
        graph2.edges.insert(make_pair(graph2b.vertices.at(i), adj_edgs));
    }
    graph2.size = vertices.size();
    
    Graph graph3;
    graph3.vertices = vertices;
    graph3.size = vertices.size();
    for (unsigned_int i = 0; i < graph3.size; i++) {
        vector<char> adj_edgs;
        graph3.edges.insert(make_pair(graph3.vertices.at(i), adj_edgs));
    }
    graph3.numEdges = 0;


    // for (unsigned_int i = 0; i < fullClique.size; i++) {
        // std::cout << fullClique.edges->at(fullClique.vertices[i]) << std::endl;
    // }
    return 0;
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