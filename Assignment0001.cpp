//Contact Manager Application

#include<iostream>
using namespace std;
#include<string>
#include<cctype>
#include<fstream>

enum RelationType { LESS, GREATER, EQUAL };          //enumeration used for searches and comparisons
const int MAX_ITEMS = 100;      //max number of contacts


class ItemType           //ADT
{
private:
	string name;
	string phone;
	string address;
public:
	ItemType();
	ItemType(string);
	void Print(ofstream&) const;
	void Initialize(string, string, string);
	RelationType ComparedTo(ItemType) const;
	void display()const;

};

void ItemType::display()const          //used to display info on console 
{
	cout << "Name: " << name << endl;
	cout << "Phone: " << phone << endl;
	cout << "Address: " << address << endl;
}

ItemType::ItemType()
{
	name = "";
	phone = "";
	address = "";
}

ItemType::ItemType(string n)
{
	name = n;
	phone = "";
	address = "";
}

void ItemType::Print(ofstream& out) const       //write name,phone and address into the file
{
	out << name << "," << phone << "," << address << endl;
}

RelationType ItemType::ComparedTo(ItemType item) const    //compares the item passed to the value stored in the list
{
	if (name < item.name)           
		return LESS;
	else if (name > item.name)
		return GREATER;
	else
		return EQUAL;
}

void ItemType::Initialize(string n, string p, string adr)
{
	name = n;
	phone = p;
	address = adr;
}

class SortedType
{
private:
	int length;          //length of the list
	int currentPos;         
	ItemType contacts[MAX_ITEMS];

public:
	SortedType();
	void AddContact(ItemType item);
	void DeleteContact(ItemType& item);
	void SearchContact(ItemType& item, bool& found);
	void ResetList();
	void MakeEmpty();
	int LengthIs();
	bool IsFull();
	void GetNextItem(ItemType&);

};

bool validName(const string& name)               //checks if the name entered while storing a contact is valid
{
	if (name.empty())               // if input is empty then it is not valid
		return false;
	for (char c : name)           //for loop stores the name in c characterwise and checks using isalpha() function of c++ whether it is an alphabet or not
	{
		if (!isalpha(c) && c != ' ')         //if any character is not a space or alphabet the input name becomes invalid
			return false; 
	}
	return true;
}

bool validPhone(const string& phone)         
{
	if (phone.size() != 11)          //the size() function of c++ checks that the phone number the user inputs is of size 11
		return false; 
	for (char c : phone)     
	{
		if (!isdigit(c))         //the isdigit() function checks that each of the 11 characters are digits
			return false;
	}
	return true;
}

bool validAddress(const string& address) 
{
	return !address.empty();        //if address passed by user is not empty it becomes valid
}

void InputContact(ItemType& item)
{
	string n, p, a;
	do
	{                                            //while adding the contact info
		cout << "Enter Name: " << endl;           //the user is asked to enter name, phone and address again if it is invalid
		getline(cin, n);
		if (!validName(n))
		{
			cout << "Invalid Name." << endl;
		}
	} while (!validName(n));

	do
	{
		cout << "Enter phone: " << endl;
		getline(cin, p);
		if (!validPhone(p))
		{
			cout << "Invalid Phone Number." << endl;
		}
	} while (!validPhone(p));

	do
	{
		cout << "Enter address: " << endl;
		getline(cin, a);
		if (!validAddress(a))
		{
			cout << "Invalid Address." << endl;
		}

	} while (!validAddress(a));
	item.Initialize(n, p, a);
}

void SortedType::GetNextItem(ItemType& item)
{
	currentPos++;                               //function gets next item in list by incrementing the current position pointing to an index
	item = contacts[currentPos];
}

SortedType::SortedType()
{
	length = 0;
	currentPos = -1;
}

void SortedType::SearchContact(ItemType& item, bool& found)
{
	int location = 0;
	bool moreToSearch;
	moreToSearch = (location < length);
	found = false;
	while (moreToSearch && !found)
	{
		switch (item.ComparedTo(contacts[location]))
		{
		case LESS:                      //no need to search more if item becomes smaller than value in list as it is a sorted list
			moreToSearch = false;
			break;
		case GREATER:
			location++;
			moreToSearch = (location < length);
			break;
		case EQUAL:
			found = true;
			cout << "Contact Found! " << endl;
			contacts[location].display();
			item = contacts[location];
			break;
		}

	}

	if (!found)
		cout << "Contact not found!" << endl;
}

void SortedType::DeleteContact(ItemType& item)
{
	int location = 0;
	bool moreToSearch;
	moreToSearch = (location < length);
	bool found = false;
	while (moreToSearch && !found)
	{
		switch (item.ComparedTo(contacts[location]))
		{
		case LESS:
			moreToSearch = false;
			break;
		case GREATER:
			location++;
			moreToSearch = (location < length);
			break;
		case EQUAL:
			found = true;
			break;
		}
	}
	if (found)
	{
		for (int index = location + 1; index < length; index++)
		{
			contacts[index - 1] = contacts[index];
		}
		length--;
		cout << "Contact Deleted." << endl;
	}
	else
		cout << "Contact does not exist." << endl;
}

void SortedType::ResetList()
{
	currentPos = -1;
}

void SortedType::MakeEmpty()
{
	length = 0;
	currentPos = -1;
}

int SortedType::LengthIs()
{
	return length;
}

bool SortedType::IsFull()
{
	return (LengthIs() == MAX_ITEMS);
}

void SortedType::AddContact(ItemType item)
{
	int location = 0;
	bool moreToSearch = false;
	moreToSearch = (location < length);
	if (IsFull())
	{   
		cout << "The list is full." << endl;
		return;
	}
	while (moreToSearch)
	{
		switch (item.ComparedTo(contacts[location]))
		{
		case LESS:
			moreToSearch = false;
			break;
		case GREATER:
			location++;
			moreToSearch = (location < length);
			break;
		}
	}
	for (int index = length; index > location; index--)
	{
		contacts[index] = contacts[index - 1];
	}
	contacts[location] = item;
	length++;
}

void PrintFile(const string& file, SortedType& list)
{                                        //file created in this function
	ofstream file1(file, ios::trunc);  //trunc used as app causes issues while adding and deleting elements
	int length;
	length = list.LengthIs();           
	list.ResetList();
	ItemType item;
	for (int index = 0; index < length; index++)
	{
		list.GetNextItem(item);          //loops and prints all list elemnts in the file
		item.Print(file1);
	}

}

void InputDel(ItemType& item)
{
	string n;
	cout << "Enter contact name to delete: " << endl;
	getline(cin, n); 
	item.Initialize(n, "", "");
}

void DisplayContacts(string file)
{
	ifstream file1(file);
	if (!file1)
	{
		cout << "File not opened." << file << endl;
		return ;
	}
	string line;
	while (getline(file1,line))
	{
		cout << line << endl;         //prints all lines from file to console
	}
	file1.close();
}

void LoadContacts(const string& file, SortedType& list) //reads every line from file into the SortedType object
{
	ifstream file1(file);
	if (!file1)
	{
		cout << "File not opened." << endl;
		return;
	}

	ItemType item;
	string n, p, a;
	while (getline(file1, n, ',') && getline(file1, p, ',') && getline(file1, a)) 
	{
		item.Initialize(n, p, a);
		list.AddContact(item);
	}
	file1.close();
}

int main()
{
	SortedType cont;
	LoadContacts("structures.txt", cont);
	
	ItemType item;
    int choice;
    string n;
	while (true)
	{
		cout << "1.Add Contact" << endl;
		cout << "2.Search Contact" << endl;
		cout << "3.Delete Contact" << endl;
		cout << "4.Display Contacts" << endl;
		cout << "5.Exit" << endl;
		cout << "Enter choice: " << endl;
		cin >> choice;
		cin.ignore();
		if (choice == 5)
		{
			break;
		}
		switch (choice)
		{
		case 1:       //Add Contact
		{
			InputContact(item);
			cont.AddContact(item);
			PrintFile("structures.txt", cont);
			break;
		}
		case 2:              //Search Contact
		{
			bool found;
			cout << "Enter name:" << endl;
			getline(cin, n);
			ItemType item1(n);
			cont.SearchContact(item1, found);
			break;
		}
		case 3:          //Delete Contact
		{
			InputDel(item);
			cont.DeleteContact(item);
			PrintFile("structures.txt", cont);
			break;
		}
		case 4:      //Displays Contacts on console
		{
			DisplayContacts("structures.txt");
			break;
		}
		default:
			cout << "Invalid Choice!" << endl;
		}
	
	}
	return 0;
}






