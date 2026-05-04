//#include <iostream>
//#include <string>
//#include <iomanip>
//#include "BST.h"
//#include "AVL.h"
//#include "BFS.h"
//using namespace std;
//
//// Helper function to extract integer from flight ID (for AVL)
//int extractNumber(const string& s) {
//    string numStr = "";
//    for (char c : s) {
//        if (isdigit(c))
//            numStr += c;
//    }
//    if (numStr.empty()) return 0;
//    return stoi(numStr);
//}
//
//void insertFlight(BST& bst, AVL& avl) {
//    string id, dest, dep, dur, status;
//    cout << "Enter Flight ID: "; cin >> id;
//    cout << "Enter Destination: "; cin >> dest;
//    cout << "Enter Departure (hh format): "; cin >> dep;
//    cout << "Enter Duration (hours): "; cin >> dur;
//    cout << "Enter Status (Departed/Landed/Delayed): "; cin >> status;
//
//    ItemType flight;
//    flight.Initialize(id, dest, dep, dur, status);
//    bst.Insert(flight);
//
//    // AVL stores numeric version of ID
//    int numID = extractNumber(id);
//    avl.insert(ItemType1(numID));
//
//    cout << "Flight inserted successfully!\n";
//}
//
//void deleteFlight(BST& bst) {
//    string id;
//    cout << "Enter Flight ID to delete: ";
//    cin >> id;
//    ItemType f;
//    f.Initialize(id, "", "", "", "");
//    bst.Delete(f);
//}
//
//void searchFlight(BST& bst) {
//    string id;
//    cout << "Enter Flight ID to search: ";
//    cin >> id;
//    ItemType f;
//    f.Initialize(id, "", "", "", "");
//    Node* res = bst.Search(f);
//    if (res)
//        res->key.getAll();
//    else
//        cout << "Flight not found.\n";
//}
//
//void cancelFlights(BST& bst) {
//    bst.CancelFlight();
//}
//
//void bstMenu(BST& bst) {
//    int choice;
//    do {
//        cout << "\n--- BST Flight Menu ---\n";
//        cout << "1. Display all flights\n";
//        cout << "2. Display flights by destination\n";
//        cout << "3. Display flights by status\n";
//        cout << "4. Display ETAs\n";
//        cout << "5. Cancel delayed flights (>6 hrs)\n";
//        cout << "0. Back to main menu\n";
//        cout << "Enter choice: "; cin >> choice;
//
//        string dest, status;
//        switch (choice) {
//        case 1: bst.display(); break;
//        case 2:
//            cout << "Enter destination: "; cin >> dest;
//            bst.displayByDestination(dest); break;
//        case 3:
//            cout << "Enter status: "; cin >> status;
//            bst.displayByStatus(status); break;
//        case 4: bst.displayETAs(bst.Search(ItemType())); break;
//        case 5: cancelFlights(bst); break;
//        case 0: break;
//        default: cout << "Invalid choice\n";
//        }
//    } while (choice != 0);
//}
//
//void avlMenu(AVL& avl) {
//    int choice;
//    do {
//        cout << "\n--- AVL Flight Menu ---\n";
//        cout << "1. Display inorder\n";
//        cout << "2. Search by numeric ID\n";
//        cout << "0. Back to main menu\n";
//        cout << "Enter choice: "; cin >> choice;
//        int id;
//        switch (choice) {
//        case 1: avl.printInorder(); break;
//        case 2:
//            cout << "Enter numeric ID: "; cin >> id;
//            if (avl.search(ItemType1(id)))
//                cout << "Flight exists in AVL.\n";
//            else
//                cout << "Flight not found in AVL.\n";
//            break;
//        case 0: break;
//        default: cout << "Invalid choice\n";
//        }
//    } while (choice != 0);
//}
//
//void bfsMenu() {
//    int n;
//    cout << "Enter number of airports (<=20): "; cin >> n;
//    string airportNames[20];
//    for (int i = 0; i < n; i++) {
//        cout << "Enter airport " << i << " name: ";
//        cin >> airportNames[i];
//    }
//
//    Graph g(n);
//
//    int edges;
//    cout << "Enter number of edges/routes: "; cin >> edges;
//    for (int i = 0; i < edges; i++) {
//        int u, v;
//        cout << "Enter edge (u v) as indices: ";
//        cin >> u >> v;
//        g.addEdge(u, v);
//    }
//
//    int src, dest;
//    cout << "Enter source airport index: "; cin >> src;
//    cout << "Enter destination airport index: "; cin >> dest;
//
//    g.BFS(src);
//    g.printRoute(src, dest, airportNames);
//}
//
//int main() {
//    BST bst;
//    AVL avl(); // root is nullptr initially
//    int choice;
//    do {
//        cout << "\n=== Main Menu ===\n";
//        cout << "1. Insert Flight\n";
//        cout << "2. Delete Flight\n";
//        cout << "3. Search Flight\n";
//        cout << "4. BST Menu\n";
//        cout << "5. AVL Menu\n";
//        cout << "6. BFS Menu\n";
//        cout << "0. Exit\n";
//        cout << "Enter choice: "; cin >> choice;
//
//        switch (choice) {
//        case 1: insertFlight(bst, avl); break;
//        case 2: deleteFlight(bst); break;
//        case 3: searchFlight(bst); break;
//        case 4: bstMenu(bst); break;
//        case 5: avlMenu(avl); break;
//        case 6: bfsMenu(); break;
//        case 0: cout << "Exiting...\n"; break;
//        default: cout << "Invalid choice\n";
//        }
//    } while (choice != 0);
//    return 0;
//}









//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <string>
//#include <chrono>
//#include "bst.h"
//#include "avl.h"
//#include "bfs.h"
//
//using namespace std;
//
//void loadFlights(BST& bst, const string& filename) {
//    ifstream fin(filename);
//    if (!fin) return;
//    string id, dep, dur, status;
//    while (fin >> id >> dep >> dur) {
//        getline(fin, status);
//        if (!status.empty() && status[0] == ' ') status = status.substr(1);
//        Flight f{ id, dep, dur, status };
//        bst.insert(f);
//    }
//    fin.close();
//}
//
//void saveFlights(BST& bst, const string& filename) {
//    ofstream fout(filename);
//    if (!fout) return;
//    bst.saveToFile(fout);
//    fout.close();
//}
//
//int main() {
//    BST bst;
//    AVL avl;
//    Graph graph;
//
//    loadFlights(bst, "flights.txt");
//    avl.loadFromBST(bst); // initialize AVL from BST nodes
//
//    graph.loadAirports("airports.txt");
//    graph.loadRoutes("routes.txt");
//
//    int choice;
//    do {
//        cout << "------------------------------\n";
//        cout << "Flight Management System\n";
//        cout << "------------------------------\n";
//        cout << "1. Add New Flight (BST)\n";
//        cout << "2. Search Flight (BST)\n";
//        cout << "3. Delete Flight (BST)\n";
//        cout << "4. Display All Flights (BST)\n";
//        cout << "5. Display Flights (AVL) + Rotation Info\n";
//        cout << "6. Compare Search Time (BST vs AVL)\n";
//        cout << "7. Plan Trip from Airport A to B\n";
//        cout << "8. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//        if (choice == 1) {
//            Flight f;
//            cout << "Enter Flight ID: "; cin >> f.id;
//            cout << "Enter Departure (HH:MM): "; cin >> f.departure;
//            cout << "Enter Duration (e.g. 2h): "; cin >> f.duration;
//            cout << "Enter Status (single-word or with dashes): "; cin.ignore(); getline(cin, f.status);
//            bst.insert(f);
//            avl.insert(f);
//            cout << "Inserted " << f.id << " into BST and AVL.\n";
//        }
//        else if (choice == 2) {
//            string id; cout << "Enter Flight ID to search: "; cin >> id;
//            BSTNode* bnode = bst.search(id);
//            if (bnode) {
//                cout << "Found (BST): "; bnode->data.print();
//            }
//            else cout << "Flight not found in BST.\n";
//        }
//        else if (choice == 3) {
//            string id; cout << "Enter Flight ID to delete: "; cin >> id;
//            if (bst.remove(id)) cout << "Deleted from BST.\n";
//            else cout << "Not found in BST.\n";
//            if (avl.remove(id)) cout << "Deleted from AVL.\n";
//        }
//        else if (choice == 4) {
//            cout << "BST Inorder Display:\n";
//            bst.inorderDisplay();
//        }
//        else if (choice == 5) {
//            cout << "AVL Inorder Display:\n";
//            avl.inorderDisplay();
//            cout << "Total rotations performed (AVL): " << avl.getRotationCount() << "\n";
//        }
//        else if (choice == 6) {
//            string id; cout << "Enter Flight ID to compare search times: "; cin >> id;
//            auto t1 = chrono::high_resolution_clock::now();
//            BSTNode* bnode = bst.search(id);
//            auto t2 = chrono::high_resolution_clock::now();
//            AVLNode* anode = avl.search(id);
//            auto t3 = chrono::high_resolution_clock::now();
//            auto bst_time = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
//            auto avl_time = chrono::duration_cast<chrono::nanoseconds>(t3 - t2).count();
//            cout << "BST search: " << (bnode ? "Found" : "Not found") << ", time = " << bst_time << " ns\n";
//            cout << "AVL search: " << (anode ? "Found" : "Not found") << ", time = " << avl_time << " ns\n";
//        }
//        else if (choice == 7) {
//            cout << "Airports list:\n";
//            graph.printAirports();
//            string src, dst; cout << "Enter source Airport ID: "; cin >> src;
//            cout << "Enter destination Airport ID: "; cin >> dst;
//            graph.planTrip(src, dst);
//        }
//        else if (choice == 8) {
//            saveFlights(bst, "flights.txt");
//            graph.saveAirports("airports_out.txt");
//            cout << "Saved data and exiting.\n";
//        }
//    } while (choice != 8);
//
//    return 0;
//}
//
//





/*
Sample files (place in same folder):

flights.txt
PK101 09:00 2h On-time
PK102 12:00 3h Delayed
PK103 18:30 1h Cancelled

airports.txt (semicolon-separated lines)
KHI;Karachi Intl;Karachi;Pakistan;1
LHE;Allama Iqbal;Lahore;Pakistan;1
KDU;Skardu;Skardu;Pakistan;0

routes.txt (pairs of airport IDs per line)
KHI LHE
LHE KDU
KHI KDU
*/


//#include <iostream>
//#include <fstream>
//#include <string>
//#include "BST.h"
//#include "AVL.h"
//#include "BFS.h"
//using namespace std;
//
//void showMenu() {
//    cout << "\n===== Flight Management System =====\n";
//    cout << "1. Add Flight (BST & AVL)\n";
//    cout << "2. Delete Flight (BST & AVL)\n";
//    cout << "3. Search Flight (BST)\n";
//    cout << "4. Display All Flights\n";
//    cout << "5. Display Flights by Destination\n";
//    cout << "6. Display Flights by Status\n";
//    cout << "7. Cancel Delayed Flights\n";
//    cout << "8. Display Flight ETAs (AVL)\n";
//    cout << "9. Load Flights from File\n";
//    cout << "10. Save Flights to File\n";
//    cout << "11. Airport BFS - Route & Distance\n";
//    cout << "0. Exit\n";
//    cout << "Enter your choice: ";
//}
//
//int main()
//{
//    BST bst;
//    AVL avl;
//    Graph airportGraph;
//
//    // Load airports and routes
//    airportGraph.loadAirports("airports.txt");
//    airportGraph.loadRoutes("routes.txt");
//
//    // Load flights from file
//    bst.loadFromFile("flights.txt");
//    avl.loadFromFile("flights.txt");
//
//    int choice;
//    do {
//        showMenu();
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            string id, dest, dep, dur, status;
//            cout << "Enter Flight ID: "; cin >> id;
//            cout << "Enter Destination: "; cin >> dest;
//            cout << "Enter Departure (hour 0-23): "; cin >> dep;
//            cout << "Enter Duration (hours): "; cin >> dur;
//            cout << "Enter Status (On-Time/Delayed/Departed/Landed): "; cin >> status;
//
//            ItemType flight;
//            flight.Initialize(id, dest, dep, dur, status);
//
//            bst.Insert(flight);
//            avl.insert(flight);
//            break;
//        }
//
//        case 2: {
//            string id;
//            cout << "Enter Flight ID to delete: "; cin >> id;
//            ItemType temp; temp.Initialize(id, "", "", "", "");
//            bst.Delete(temp);
//            avl.del(temp);
//            break;
//        }
//
//        case 3: {
//            string id;
//            cout << "Enter Flight ID to search: "; cin >> id;
//            ItemType temp; temp.Initialize(id, "", "", "", "");
//            Node* res = bst.Search(temp);
//            if (res) res->key.display();
//            else cout << "Flight not found.\n";
//            break;
//        }
//
//        case 4:
//            bst.display();
//            break;
//
//        case 5: {
//            string dest;
//            cout << "Enter destination: "; cin >> dest;
//            bst.displayByDestination(dest);
//            break;
//        }
//
//        case 6: {
//            string status;
//            cout << "Enter status: "; cin >> status;
//            bst.displayByStatus(status);
//            break;
//        }
//
//        case 7:
//            bst.CancelFlights();
//            break;
//
//        case 8:
//            avl.printETAs();
//            break;
//
//        case 9:
//            bst.loadFromFile("flights.txt");
//            avl.loadFromFile("flights.txt");
//            cout << "Flights loaded.\n";
//            break;
//
//        case 10:
//            bst.saveToFile("flights.txt");
//            avl.saveToFile("flights.txt");
//            cout << "Flights saved.\n";
//            break;
//
//        case 11: {
//            string src, dest;
//            cout << "Enter source airport ID: "; cin >> src;
//            cout << "Enter destination airport ID: "; cin >> dest;
//            airportGraph.printRoute(src, dest);
//            break;
//        }
//
//        case 0:
//            cout << "Exiting program.\n";
//            break;
//
//        default:
//            cout << "Invalid choice. Try again.\n";
//        }
//
//    } while (choice != 0);
//
//    return 0;
//}
