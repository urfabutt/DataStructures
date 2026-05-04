#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class ItemType
{
private:
	string ID;
	string destination;
	string departure;
	string duration;
	string status;
	int delay;
public:
	ItemType();
	void Initialize(string, string, string, string, string);
	string getID()const;
	string getDestination()const;
	string getDeparture()const;
	string getDuration()const;
	string getStatus()const;
	void getAll()const;
	void displayETA()const;
	int getDelay();
	void setStatus(string);
	bool operator>(const ItemType&);
	bool operator<(const ItemType&);
	bool operator==(const ItemType&);
	bool operator!=(const ItemType&);

};
void ItemType::setStatus(string s)
{
	status = s;
}
int ItemType::getDelay()
{
	cout << "What is the delay of flight right now(in hours): ";
	cin >> delay;
	return delay;
}
bool ItemType::operator!=(const ItemType& other)
{
	return ID != other.ID;
}
bool ItemType::operator==(const ItemType&other)
{
	return ID == other.ID;
}
bool ItemType::operator<(const ItemType& other)
{
	return ID < other.ID;
}
bool ItemType::operator>(const ItemType& other)
{
	return ID > other.ID;
}
ItemType::ItemType()
{
	delay = 0;
	ID = "";
	destination = "";
	departure = "";
	duration = "";
	status = "";
}
void ItemType::Initialize(string id, string des, string dep, string dur, string s)
{
	ID = id;
	destination = des;
	departure = dep;
	duration = dur;
	status = s;
}
string ItemType::getID()const
{
	return ID;
}
string ItemType::getDestination()const
{
	return destination;
}
string ItemType::getDeparture()const
{
	return departure;
}
string ItemType::getDuration()const
{
	return duration;
}
string ItemType::getStatus()const
{
	return status;
}
void ItemType::getAll() const
{
	cout << "Flight ID: " << ID << endl;
	cout << "Destination: " << destination << endl;
	cout << "Departure: " << departure << endl;
	cout << "Duration: " << duration << " hrs" << endl;
	cout << "Status: " << status << endl;
}

void ItemType::displayETA() const 
{
	int eta = stoi(departure) + stoi(duration);
	if (eta >= 24) 
		eta = eta - 24;  

	string mark;
	if (status == "Delayed") 
		mark = "Delayed";
	else mark = "On-Time";
	cout << left << setw(10) << "ID"
		<< setw(15) << "Destination"
		<< setw(12) << "Departure"
		<< setw(12) << "Duration"
		<< setw(12) << "Status"
		<< setw(10) << "ETA"
		<< setw(12) << "Time" << endl;
	cout << left << setw(10) << ID
		<< setw(15) << destination
		<< setw(12) << departure
		<< setw(12) << duration
		<< setw(12) << status
		<< setw(10) << eta
		<< setw(12) << mark << endl;
}

struct Node
{
	ItemType key;
	Node* left;
	Node* right;
	Node* parent;
	Node(ItemType);
};
Node::Node(ItemType k)
{
	key = k;
	left = nullptr;
	right = nullptr;
	parent = nullptr;

}
class BST
{
private:
	Node* root = nullptr;
	void Transplant(Node*,Node*);
	void InOrder(Node*);
	void groupByDestination(Node*, string);
	void groupByStatus(Node*, string);
	void HeadingByDestinationHelper(Node*);
	void HeadingByStatusHelper(Node*,string);
	bool CancelFlightHelper(Node*);
public:
	void displayByDestination(string);
	void displayByStatus(string);
	void display();
	void display2();
	Node* minimum(Node*);
	Node* Search(ItemType);
	void Insert(ItemType);
	void Delete(ItemType);
	void displayETAs(Node* node);
	void HeadingByDestination();
	void HeadingByStatus();
	void CancelFlight();
	
};
void BST::displayETAs(Node* node) 
{
	if (node == nullptr) return;
	displayETAs(node->left);
	node->key.displayETA();
	displayETAs(node->right);
}
Node* BST::Search(ItemType k)
{
	Node* x = root;
	while (x!=nullptr && x->key!=k)
	{
		if (k<x->key)
		{
			x = x->left;
		}
		else x = x->right;
	}
	return x;
}
void BST::Insert(ItemType k)
{
	Node* z = new Node(k);
	Node* y = nullptr;
	Node* x = root;
	while (x != nullptr)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else x = x->right;
	}
	z->parent = y;
	if (y == nullptr)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else y->right = z;
}
void BST::InOrder(Node* x)
{
	if (x != nullptr)
	{
		InOrder(x->left);
		x->key.getAll();
		InOrder(x->right);
	}
}

void BST::groupByDestination(Node* x, string dest) 
{
	if (x==nullptr) 
		return;
	groupByDestination(x->left, dest);
	if (x->key.getDestination() == dest)
		x->key.getAll();
	groupByDestination(x->right, dest);
}

void BST::groupByStatus(Node* x, string s) 
{
	if (x==nullptr) 
		return;
	groupByStatus(x->left, s);
	if (x->key.getStatus() == s)
		x->key.getAll();
	groupByStatus(x->right, s);
}

void BST::Transplant(Node* u, Node* v)
{
	if (u->parent == nullptr)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else u->parent->right = v;
	if (v != nullptr)
		v->parent = u->parent;
}
Node* BST::minimum(Node* x)
{
	while (x->left != nullptr)
		x = x->left;
	return x;
}
void BST::Delete(ItemType k)
{
	Node* z = Search(k);
	if (z == nullptr)
	{
		cout << "Flight does not exist." << endl;
		return;
	}
	if (z->left == nullptr)
		Transplant(z, z->right);
	else if (z->right == nullptr)
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
}
void BST::displayByDestination(string dest) 
{
	cout << "Flights to " << dest << endl;
	groupByDestination(root, dest);
}

void BST::displayByStatus(string s) 
{
	cout << "Flights with status " << s << endl;
	groupByStatus(root, s);
}
void BST::display()
{
	InOrder(root);
	cout << endl;
}
void BST::display2()
{
	displayETAs(root);
	cout << endl;
}

void BST::HeadingByDestinationHelper(Node* node) 
{ 
	if (node == nullptr)
		return;
	HeadingByDestinationHelper(node->left);
	static string lastDest = "";
	string currentDest = node->key.getDestination();
	if (currentDest != lastDest)
	{ cout << " Destination: " << currentDest << endl;
      cout << endl;
	  lastDest = currentDest;
	} 
	node->key.getAll();
	cout << endl;
	HeadingByDestinationHelper(node->right);
}
void BST::HeadingByDestination() 
{
	cout << "Destination-Based Flight Overview\n";
	HeadingByDestinationHelper(root);
}


void BST::HeadingByStatusHelper(Node* node, string status)
{
	if (node == nullptr)
		return;

	HeadingByStatusHelper(node->left, status);

	if (node->key.getStatus() == status)
		node->key.getAll();

	HeadingByStatusHelper(node->right, status);
}

void BST::HeadingByStatus()
{
	cout << "Departed Flights\n";
	HeadingByStatusHelper(root, "Departed");

	cout << "Landed Flights\n";
	HeadingByStatusHelper(root, "Landed");

	cout << "Delayed Flights\n";
	HeadingByStatusHelper(root, "Delayed");
}


bool BST::CancelFlightHelper(Node* node)
{
	if (node == nullptr)
		return false;

	bool leftCancelled = CancelFlightHelper(node->left);
	bool rightCancelled = CancelFlightHelper(node->right);
	bool cancelledHere = false;

	string status = node->key.getStatus();

	if (status == "Delayed")
	{
		int delayHours = node->key.getDelay(); 

		if (delayHours > 6)
		{
			node->key.setStatus("Cancelled");
			cout << "Flight " << node->key.getID()<< " has been cancelled due to delay of "<< delayHours << " hours.\n";
			cancelledHere = true;
		}
	}

	return leftCancelled || cancelledHere || rightCancelled;
}
void BST::CancelFlight()
{
	cout << "Checking for flights delayed more than 6 hours\n";
	bool cancelled = CancelFlightHelper(root);
	if (!cancelled)
		cout << "No flights were cancelled.\n";
}


int main()
{
	BST bst;
	int choice;

	do {
		cout << "Flight Reservation Directory\n";
		cout << "1. Insert new flight record\n";
		cout << "2. Delete a flight record\n";
		cout << "3. Search for a flight\n";
		cout << "4. Display all flights (sorted by Flight ID)\n";
		cout << "5. Display flights by destination\n";
		cout << "6. Display flights by status\n";
		cout << "7. Display All ETAs\n";
		cout << "8. Display All flights by destination\n";
		cout << "9. Display All flights by status\n";
		cout << "10. Check Long Delays\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) 
		{
			string id,dest, depTime, dur, stat;
			cout << "Enter Flight ID: ";
			cin >> id;
			cin.ignore();
			cout << "Enter Destination: ";
			getline(cin, dest);
			cout << "Enter Departure Time: ";
			getline(cin, depTime);
			cout << "Enter Duration (hours): ";
			cin >> dur;
			cin.ignore();
			cout << "Enter Status (Departed/Landed/Delayed): ";
			getline(cin, stat);

			ItemType item;
			item.Initialize(id, dest, depTime, dur, stat);
			bst.Insert(item);

		}
		else if (choice == 2) 
		{
			string id;
			cout << "Enter Flight ID to delete: ";
			cin >> id;
			ItemType temp;
			temp.Initialize(id, "", "", "", "");
			bst.Delete(temp);
		}
		else if (choice == 3) 
		{
			string id;
			cout << "Enter Flight ID to search: ";
			cin >> id;
			ItemType temp;
			temp.Initialize(id, "", "", "", "");
			Node* result = bst.Search(temp);
			if (result != nullptr)
				result->key.getAll();
			else
				cout << "Flight not found.\n";

		}
		else if (choice == 4) 
		{
			bst.display();
		}
		else if (choice == 5) 
		{
			string dest;
			cin.ignore();
			cout << "Enter destination: ";
			getline(cin, dest);
			bst.displayByDestination(dest);

		}
		else if (choice == 6) 
		{
			string stat;
			cin.ignore();
			cout << "Enter status (Departed/Landed/Delayed): ";
			getline(cin, stat);
			bst.displayByStatus(stat);
		}
		else if (choice == 7)
		{
			bst.display2();
		}
		else if (choice == 8)
		{
			bst.HeadingByDestination();
		}
		else if (choice == 9)
		{
			bst.HeadingByStatus();
		}
		else if (choice == 10)
		{
			bst.CancelFlight();
		}
	} while (choice != 0);

	cout << "Exiting program.\n";
	return 0;
}

