#ifndef BTREEINDEX_H
#define BTREEINDEX_H
#include "BPlusTree.h"
#include <string>
#include <vector>

using namespace std;

using PrimTree = BPlusTree<int, vector<string>>;
class BTreeIndex {
private:
    PrimTree tree;
    vector<string> headers; 

public:
    void insert(const string& key, const vector<string>& attrs);
    vector<string> search(const string& key);
    vector<vector<string>> rangeQuery(const string& lowKey, const string& highKey);
    void update(const string& key, const vector<string>& attrs);
    bool contains(int key) const;
    void remove(const string& key);
    void clear();
    void print();
    PrimTree& raw() { return tree; }
    size_t size() const { return tree.size(); }
    void setHeaders(const vector<string>& h) { headers = h; }
    const vector<string>& getHeaders() const { return headers; }
    int getColumnIndex(const string& columnName) const; 
};

#endif