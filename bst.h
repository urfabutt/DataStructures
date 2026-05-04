// File: bst.h

//#ifndef BST_H
//#define BST_H
//
//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//struct Flight {
//    string id;
//    string departure;
//    string duration;
//    string status;
//    void print() const {
//        cout << id << " " << departure << " " << duration << " " << status << "\n";
//    }
//};
//
//struct BSTNode {
//    Flight data;
//    BSTNode* left, * right;
//    BSTNode(const Flight& f) : data(f), left(nullptr), right(nullptr) {}
//};
//
//class BST {
//public:
//    BST() : root(nullptr) {}
//    ~BST() { clear(root); }
//    void insert(const Flight& f) { root = insertRec(root, f); }
//    BSTNode* search(const string& id) { return searchRec(root, id); }
//    bool remove(const string& id) { bool removed = false; root = removeRec(root, id, removed); return removed; }
//    void inorderDisplay() { inorderRec(root); }
//    void saveToFile(ofstream& fout) { saveRec(root, fout); }
//    BSTNode* getRoot() { return root; }
//private:
//    BSTNode* root;
//    BSTNode* insertRec(BSTNode* node, const Flight& f) {
//        if (!node) return new BSTNode(f);
//        if (f.id < node->data.id) node->left = insertRec(node->left, f);
//        else if (f.id > node->data.id) node->right = insertRec(node->right, f);
//        else node->data = f; // replace
//        return node;
//    }
//    BSTNode* searchRec(BSTNode* node, const string& id) {
//        if (!node) return nullptr;
//        if (id == node->data.id) return node;
//        if (id < node->data.id) return searchRec(node->left, id);
//        return searchRec(node->right, id);
//    }
//    BSTNode* removeRec(BSTNode* node, const string& id, bool& removed) {
//        if (!node) return nullptr;
//        if (id < node->data.id) node->left = removeRec(node->left, id, removed);
//        else if (id > node->data.id) node->right = removeRec(node->right, id, removed);
//        else {
//            removed = true;
//            if (!node->left) { BSTNode* r = node->right; delete node; return r; }
//            if (!node->right) { BSTNode* l = node->left; delete node; return l; }
//            // two children: find inorder successor
//            BSTNode* succ = node->right;
//            while (succ->left) succ = succ->left;
//            node->data = succ->data;
//            node->right = removeRec(node->right, succ->data.id, removed);
//        }
//        return node;
//    }
//    void inorderRec(BSTNode* node) {
//        if (!node) return;
//        inorderRec(node->left);
//        node->data.print();
//        inorderRec(node->right);
//    }
//    void saveRec(BSTNode* node, ofstream& fout) {
//        if (!node) return;
//        saveRec(node->left, fout);
//        fout << node->data.id << " " << node->data.departure << " " << node->data.duration << " " << node->data.status << "\n";
//        saveRec(node->right, fout);
//    }
//    void clear(BSTNode* node) { if (!node) return; clear(node->left); clear(node->right); delete node; }
//};
//
//#endif#pragma once



//#ifndef BST_H
//#define BST_H
//
//#include <iostream>
//#include <string>
//#include <iomanip>
//using namespace std;
//
//class ItemType
//{
//private:
//    string ID;
//    string destination;
//    string departure;
//    string duration;
//    string status;
//    int delay;
//
//public:
//    ItemType();
//    void Initialize(string, string, string, string, string);
//    string getID() const;
//    string getDestination() const;
//    string getDeparture() const;
//    string getDuration() const;
//    string getStatus() const;
//    void getAll() const;
//    void displayETA() const;
//    int getDelay();
//    void setStatus(string);
//
//    bool operator>(const ItemType&);
//    bool operator<(const ItemType&);
//    bool operator==(const ItemType&);
//    bool operator!=(const ItemType&);
//};
//
//// ---------------- ItemType DEFINITIONS ----------------
//
//ItemType::ItemType()
//{
//    delay = 0;
//    ID = "";
//    destination = "";
//    departure = "";
//    duration = "";
//    status = "";
//}
//
//void ItemType::Initialize(string id, string des, string dep, string dur, string s)
//{
//    ID = id;
//    destination = des;
//    departure = dep;
//    duration = dur;
//    status = s;
//}
//
//string ItemType::getID() const { return ID; }
//string ItemType::getDestination() const { return destination; }
//string ItemType::getDeparture() const { return departure; }
//string ItemType::getDuration() const { return duration; }
//string ItemType::getStatus() const { return status; }
//
//int ItemType::getDelay()
//{
//    cout << "What is the delay of flight right now(in hours): ";
//    cin >> delay;
//    return delay;
//}
//
//void ItemType::setStatus(string s)
//{
//    status = s;
//}
//
//bool ItemType::operator!=(const ItemType& other) { return ID != other.ID; }
//bool ItemType::operator==(const ItemType& other) { return ID == other.ID; }
//bool ItemType::operator<(const ItemType& other) { return ID < other.ID; }
//bool ItemType::operator>(const ItemType& other) { return ID > other.ID; }
//
//void ItemType::getAll() const
//{
//    cout << "Flight ID: " << ID << endl;
//    cout << "Destination: " << destination << endl;
//    cout << "Departure: " << departure << endl;
//    cout << "Duration: " << duration << " hrs" << endl;
//    cout << "Status: " << status << endl;
//}
//
//void ItemType::displayETA() const
//{
//    int eta = stoi(departure) + stoi(duration);
//    string mark = (status == "Delayed" ? "Delayed" : "On-Time");
//
//    cout << left << setw(10) << "ID"
//        << setw(15) << "Destination"
//        << setw(12) << "Departure"
//        << setw(12) << "Duration"
//        << setw(12) << "Status"
//        << setw(14) << "ETA"
//        << setw(12) << "Time" << endl;
//
//    cout << left << setw(10) << ID
//        << setw(15) << destination
//        << setw(12) << departure
//        << setw(12) << duration
//        << setw(12) << status;
//
//    if (eta >= 24)
//    {
//        eta -= 24;
//        cout << setw(14) << ("1 day " + to_string(eta) + "h");
//    }
//    else
//    {
//        cout << setw(14) << (to_string(eta) + "h");
//    }
//
//    cout << setw(12) << mark << endl;
//}
//
//
//// ------------------- NODE -------------------
//
//struct Node
//{
//    ItemType key;
//    Node* left;
//    Node* right;
//    Node* parent;
//
//    Node(ItemType);
//};
//
//Node::Node(ItemType k)
//{
//    key = k;
//    left = nullptr;
//    right = nullptr;
//    parent = nullptr;
//}
//
//
//// ------------------- BST CLASS -------------------
//
//class BST
//{
//private:
//    Node* root = nullptr;
//
//    void Transplant(Node*, Node*);
//    void InOrder(Node*);
//    void groupByDestination(Node*, string);
//    void groupByStatus(Node*, string);
//    void HeadingByDestinationHelper(Node*);
//    void HeadingByStatusHelper(Node*, string);
//    bool CancelFlightHelper(Node*);
//
//public:
//    void Insert(ItemType);
//    Node* Search(ItemType);
//    void Delete(ItemType);
//    Node* minimum(Node*);
//    void display();
//    void displayETAs(Node*);
//    //void display2();
//    void displayByDestination(string);
//    void displayByStatus(string);
//    void HeadingByDestination();
//    void HeadingByStatus();
//    void CancelFlight();
//};
//
//
//// ---- Implementations below ---- (unchanged – your code)
//
//void BST::displayETAs(Node* node)
//{
//    if (!node) return;
//    displayETAs(node->left);
//    node->key.displayETA();
//    displayETAs(node->right);
//}
//
//Node* BST::Search(ItemType k)
//{
//    Node* x = root;
//    while (x && x->key != k)
//        x = (k < x->key) ? x->left : x->right;
//    return x;
//}
//
//void BST::Insert(ItemType k)
//{
//    Node* z = new Node(k);
//    Node* y = nullptr;
//    Node* x = root;
//
//    while (x)
//    {
//        y = x;
//        x = (z->key < x->key) ? x->left : x->right;
//    }
//
//    z->parent = y;
//
//    if (!y) root = z;
//    else if (z->key < y->key) y->left = z;
//    else y->right = z;
//}
//
//void BST::InOrder(Node* x)
//{
//    if (!x) return;
//    InOrder(x->left);
//    x->key.getAll();
//    InOrder(x->right);
//}
//
//void BST::display()
//{
//    InOrder(root);
//    cout << endl;
//}
//
//Node* BST::minimum(Node* x)
//{
//    while (x && x->left)
//        x = x->left;
//    return x;
//}
//
//void BST::Transplant(Node* u, Node* v)
//{
//    if (!u->parent) root = v;
//    else if (u == u->parent->left) u->parent->left = v;
//    else u->parent->right = v;
//
//    if (v) v->parent = u->parent;
//}
//
//void BST::Delete(ItemType k)
//{
//    Node* z = Search(k);
//    if (!z)
//    {
//        cout << "Flight does not exist.\n";
//        return;
//    }
//
//    if (!z->left)
//        Transplant(z, z->right);
//    else if (!z->right)
//        Transplant(z, z->left);
//    else
//    {
//        Node* y = minimum(z->right);
//        if (y->parent != z)
//        {
//            Transplant(y, y->right);
//            y->right = z->right;
//            y->right->parent = y;
//        }
//        Transplant(z, y);
//        y->left = z->left;
//        y->left->parent = y;
//    }
//}
//
//void BST::groupByDestination(Node* x, string dest)
//{
//    if (!x) return;
//    groupByDestination(x->left, dest);
//    if (x->key.getDestination() == dest)
//        x->key.getAll();
//    groupByDestination(x->right, dest);
//}
//
//void BST::displayByDestination(string d)
//{
//    cout << "Flights to " << d << endl;
//    groupByDestination(root, d);
//}
//
//void BST::groupByStatus(Node* x, string s)
//{
//    if (!x) return;
//    groupByStatus(x->left, s);
//    if (x->key.getStatus() == s)
//        x->key.getAll();
//    groupByStatus(x->right, s);
//}
//
//void BST::displayByStatus(string s)
//{
//    cout << "Flights with status " << s << endl;
//    groupByStatus(root, s);
//}
//
//void BST::HeadingByDestinationHelper(Node* node)
//{
//    if (!node) return;
//    HeadingByDestinationHelper(node->left);
//
//    static string lastDest = "";
//    string cur = node->key.getDestination();
//
//    if (cur != lastDest)
//    {
//        cout << "Destination: " << cur << "\n\n";
//        lastDest = cur;
//    }
//
//    node->key.getAll();
//    cout << endl;
//
//    HeadingByDestinationHelper(node->right);
//}
//
//void BST::HeadingByDestination()
//{
//    cout << "Destination-Based Overview\n";
//    HeadingByDestinationHelper(root);
//}
//
//void BST::HeadingByStatusHelper(Node* node, string status)
//{
//    if (!node) return;
//    HeadingByStatusHelper(node->left, status);
//    if (node->key.getStatus() == status)
//        node->key.getAll();
//    HeadingByStatusHelper(node->right, status);
//}
//
//void BST::HeadingByStatus()
//{
//    cout << "Departed Flights\n";
//    HeadingByStatusHelper(root, "Departed");
//
//    cout << "Landed Flights\n";
//    HeadingByStatusHelper(root, "Landed");
//
//    cout << "Delayed Flights\n";
//    HeadingByStatusHelper(root, "Delayed");
//}
//
//bool BST::CancelFlightHelper(Node* node)
//{
//    if (!node) return false;
//
//    bool left = CancelFlightHelper(node->left);
//    bool right = CancelFlightHelper(node->right);
//    bool here = false;
//
//    if (node->key.getStatus() == "Delayed")
//    {
//        int d = node->key.getDelay();
//        if (d > 6)
//        {
//            node->key.setStatus("Cancelled");
//            cout << "Flight " << node->key.getID()
//                << " cancelled due to " << d << " hours delay.\n";
//            here = true;
//        }
//    }
//
//    return left || here || right;
//}
//
//void BST::CancelFlight()
//{
//    cout << "Checking delays...\n";
//    if (!CancelFlightHelper(root))
//        cout << "No flights cancelled.\n";
//}
//
//#endif // BST_H


#ifndef BST_H
#define BST_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// ===============================
// ItemType Class
// ===============================

class ItemType
{
private:
    string ID;
    string destination;
    string departure;   // numeric string "14"
    string duration;    // numeric string "2"
    string status;

public:
    ItemType();

    void Initialize(string, string, string, string, string);

    string getID() const;
    string getDestination() const;
    string getDeparture() const;
    string getDuration() const;
    string getStatus() const;

    void setStatus(string);

    void display() const;
    void displayETA() const;

    // Comparison operators (BST sorted by Flight ID)
    bool operator>(const ItemType&) const;
    bool operator<(const ItemType&) const;
    bool operator==(const ItemType&) const;
    bool operator!=(const ItemType&) const;
};

// ---------- ItemType Implementation ----------

ItemType::ItemType()
{
    ID = destination = departure = duration = status = "";
}

void ItemType::Initialize(string id, string des, string dep, string dur, string s)
{
    ID = id;
    destination = des;
    departure = dep;
    duration = dur;
    status = s;
}

string ItemType::getID() const { return ID; }
string ItemType::getDestination() const { return destination; }
string ItemType::getDeparture() const { return departure; }
string ItemType::getDuration() const { return duration; }
string ItemType::getStatus() const { return status; }

void ItemType::setStatus(string s) { status = s; }

bool ItemType::operator==(const ItemType& other) const { return ID == other.ID; }
bool ItemType::operator!=(const ItemType& other) const { return ID != other.ID; }
bool ItemType::operator<(const ItemType& other) const { return ID < other.ID; }
bool ItemType::operator>(const ItemType& other) const { return ID > other.ID; }

void ItemType::display() const
{
    cout << "Flight ID: " << ID << "\n"
        << "Destination: " << destination << "\n"
        << "Departure: " << departure << "\n"
        << "Duration: " << duration << " hrs\n"
        << "Status: " << status << "\n\n";
}

void ItemType::displayETA() const
{
    int dep = stoi(departure);
    int dur = stoi(duration);
    int eta = dep + dur;

    cout << left << setw(12) << ID
        << setw(15) << destination
        << setw(10) << departure
        << setw(8) << duration
        << setw(12) << status;

    if (eta >= 24)
        cout << setw(12) << ("1 day " + to_string(eta - 24) + "h");
    else
        cout << setw(12) << (to_string(eta) + "h");

    cout << endl;
}

// ===============================
// Node Struct
// ===============================

struct Node
{
    ItemType key;
    Node* left;
    Node* right;
    Node* parent;

    Node(ItemType k)
    {
        key = k;
        left = right = parent = nullptr;
    }
};

// ===============================
// BST CLASS
// ===============================

class BST
{
private:
    Node* root = nullptr;

    void InOrder(Node*);
    Node* minimum(Node*);
    void Transplant(Node*, Node*);
    void displayETAHelper(Node*);
    void groupByDestination(Node*, string);
    void groupByStatus(Node*, string);
    void CancelHelper(Node*, bool&);
    void saveHelper(Node*, ofstream&);
public:
    void Insert(ItemType);
    Node* Search(ItemType);
    void Delete(ItemType);

    void display();
    void displayETAs();
    void displayByDestination(string);
    void displayByStatus(string);
    void CancelFlights();

    // File handling
    void loadFromFile(string filename);
    void saveToFile(string filename);
};

// ===============================
// BST IMPLEMENTATION
// ===============================

Node* BST::Search(ItemType k)
{
    Node* cur = root;
    while (cur && cur->key != k)
    {
        if (k < cur->key)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return cur;
}

void BST::Insert(ItemType k)
{
    if (Search(k))
    {
        cout << "Flight with ID " << k.getID() << " already exists!\n";
        return;
    }

    Node* z = new Node(k);
    Node* y = nullptr;
    Node* x = root;

    while (x)
    {
        y = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }

    z->parent = y;

    if (!y) root = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z;
}

void BST::InOrder(Node* x)
{
    if (!x) return;
    InOrder(x->left);
    x->key.display();
    InOrder(x->right);
}

void BST::display()
{
    InOrder(root);
}

Node* BST::minimum(Node* x)
{
    while (x && x->left)
        x = x->left;
    return x;
}

void BST::Transplant(Node* u, Node* v)
{
    if (!u->parent)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    if (v)
        v->parent = u->parent;
}

void BST::Delete(ItemType k)
{
    Node* z = Search(k);
    if (!z)
    {
        cout << "Flight not found.\n";
        return;
    }

    if (!z->left)
        Transplant(z, z->right);
    else if (!z->right)
        Transplant(z, z->left);
    else
    {
        Node* y = minimum(z->right);

        if (y->parent != z)
        {
            Transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        Transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
    }

    delete z;
}

void BST::displayETAHelper(Node* node)
{
    if (!node) return;
    displayETAHelper(node->left);
    node->key.displayETA();
    displayETAHelper(node->right);
}

void BST::displayETAs()
{
    cout << left << setw(12) << "ID"
        << setw(15) << "Destination"
        << setw(10) << "Dep"
        << setw(8) << "Dur"
        << setw(12) << "Status"
        << setw(12) << "ETA"
        << endl;
    displayETAHelper(root);
}

void BST::groupByDestination(Node* x, string d)
{
    if (!x) return;
    groupByDestination(x->left, d);
    if (x->key.getDestination() == d)
        x->key.display();
    groupByDestination(x->right, d);
}

void BST::displayByDestination(string d)
{
    cout << "Flights going to: " << d << "\n\n";
    groupByDestination(root, d);
}

void BST::groupByStatus(Node* x, string s)
{
    if (!x) return;
    groupByStatus(x->left, s);
    if (x->key.getStatus() == s)
        x->key.display();
    groupByStatus(x->right, s);
}

void BST::displayByStatus(string s)
{
    cout << "Flights with status: " << s << "\n\n";
    groupByStatus(root, s);
}

void BST::CancelHelper(Node* node, bool& cancelledAny)
{
    if (!node) return;

    CancelHelper(node->left, cancelledAny);

    if (node->key.getStatus() == "Delayed")
    {
        cout << "Enter delay in hours for flight " << node->key.getID() << ": ";
        int delay;
        cin >> delay;

        if (delay > 6)
        {
            node->key.setStatus("Cancelled");
            cout << "Flight " << node->key.getID() << " cancelled.\n";
            cancelledAny = true;
        }
    }

    CancelHelper(node->right, cancelledAny);
}

void BST::CancelFlights()
{
    bool cancelledAny = false;
    CancelHelper(root, cancelledAny);

    if (!cancelledAny)
        cout << "No flights were cancelled.\n";
}

// ===============================
// File Handling
// ===============================

void BST::loadFromFile(string filename)
{
    ifstream fin(filename);
    if (!fin)
    {
        cout << "Cannot open " << filename << ". Starting with empty database.\n";
        return;
    }

    string id, dest, dep, dur, status;
    while (fin >> id >> dest >> dep >> dur >> status)
    {
        ItemType item;
        item.Initialize(id, dest, dep, dur, status);
        Insert(item);
    }

    fin.close();
}

void BST::saveToFile(string filename)
{
    ofstream fout(filename);
    if (!fout)
    {
        cout << "Cannot write to " << filename << endl;
        return;
    }

    saveHelper(root, fout);
    fout.close();
}

void BST::saveHelper(Node* node, ofstream& fout)
{
    if (!node) return;
    saveHelper(node->left, fout);
    fout << node->key.getID() << " "
        << node->key.getDestination() << " "
        << node->key.getDeparture() << " "
        << node->key.getDuration() << " "
        << node->key.getStatus() << endl;
    saveHelper(node->right, fout);
}

#endif
