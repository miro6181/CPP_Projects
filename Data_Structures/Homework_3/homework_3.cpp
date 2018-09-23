// ==========================================
// File: Assignment 3 starter code
// Author: Matt Bubernak
// Date: 1/29/2018
// Modified: Fall 2016 E.S.Boese, Fall 2018 Alex Curtiss
// Fall 2018 S. Gupta
// Description: Linked List Fun
// ==========================================
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

// DO NOT MODIFY THIS STRUCT
struct city
{
  string name; // name of the city
  city *next; // pointer to the next city
  int numberMessages; // how many messages passed through this city
  string message; // message we are sending accross
};

/* Function prototypes */
city* addCity(city *head, city *previous, string cityName );
city* deleteCity(city *head, string cityName);
city* deleteEntireNetwork(city *head);
city* searchNetwork(city *head, string cityName);
city* loadDefaultSetup(city *head);
void transmitMsg(city *head, string receiver, string message);
void printPath(city *head);
void displayMenu();
city* handleUserInput(city *head);

/* Do NOT modify main function */
int main(int argc, char* argv[])
{
  // pointer to the head of our network of cities
  city *head = NULL;

  head = handleUserInput(head);
  printPath(head);
  head = deleteEntireNetwork(head);
  if (head == NULL)
  cout << "Path cleaned" << endl;
  else
  printPath(head);
  cout << "Goodbye!" << endl;
  return 0;
}

/*
 * Purpose: handle the interaction with the user
 * @param head: the start of the linked list
 * @return: the start of the linked list
 *
 * DO NOT MODIFY THIS FUNCTION
 */
city* handleUserInput(city *head)
{
  bool quit = false;
  string s_input;
  int input;
  // loop until the user quits
  while (!quit)
  {
    displayMenu();
    // read in input, assuming a number comes in
    getline(cin, s_input);
    input = stoi(s_input);
    switch (input)
    {
      // print all nodes
      case 1: //rebuild network
        head = loadDefaultSetup(head);
        printPath(head);
        break;

      case 2: // print path
        printPath(head);
        break;

      case 3: //message is read in from file
        {
          string cityReceiver;

          cout << "Enter name of the city to receive the message: "
          << endl;
          getline(cin, cityReceiver);
          cout << "Enter the message to send: " << endl;
          string message;
          getline(cin, message);

          transmitMsg(head, cityReceiver, message);
        }
        break;

      case 4:
        {
          string newCityName;
          string prevCityName;
          cout << "Enter a new city name: " << endl;
          getline(cin, newCityName);
          cout << "Enter the previous city name (or First): " << endl;
          getline(cin, prevCityName);
          // find the node containing prevCity
          city *tmp = NULL;
          if(prevCityName !="First")
          tmp = searchNetwork(head, prevCityName);
          // add the new node
          head = addCity(head, tmp, newCityName);
          printPath(head);
        }
        break;

      case 5: // delete city
        {
          string city;
          cout << "Enter a city name: " << endl;
          getline(cin, city);
          head = deleteCity(head, city);
          printPath(head);

        }
        break;

      case 6: // delete network
        head = deleteEntireNetwork(head);
        break;

      case 7: // quit
        quit = true;
        cout << "Quitting... cleaning up path: " << endl;
        break;

      default: // invalid input
        cout << "Invalid Input" << endl;
        break;
    }
  }
  return head;
}

/*
 * Purpose: Add a new city to the network
 * between the city *previous and the city that follows it in the network.
 * Prints: `prev: <city name> new: <city name>` when a city is added,
 * prints _nothing_ if the city is being added to the _first_ position in
 * the list.
 * @param head: pointer to start of the list
 * @param previous: name of the city that comes before the new city, or null if
 *    the city is being added to the first position
 * @param cityName: name of the new city
 * @return: pointer to first node in list
 */
 // DONE - Works on Moodle
city* addCity(city *head, city *previous, string cityName)
{
  city* newNode = new city;
  newNode->name = cityName;
  city* temp = new city;
  temp=head;
  if(previous == NULL)
  {
    newNode->next = head;
    head = newNode;
  }
  while(temp != NULL && previous != temp)
  {
    temp = temp->next;
  }
  if(temp == NULL)
  {
    if(head == NULL)// if the head is null then it creates a node for the head
    {
      head = newNode;
      newNode->next = NULL;
    }
    return head;
  }
  else
  {
    newNode->next = temp->next; //the pointer for the new node will be the next of the prev node
    temp->next = newNode; // the prev node will now point to the new node
  }

  cout << "prev: " << previous->name << "  new: " << cityName << endl;
  return head;
}

/*
 * Purpose: Search the network for the specified city and return a pointer
 * to that node
 * @param head: head of the list
 * @param cityName: name of the city to look for in network
 * @return: pointer to node of cityName, or NULL if not found
 * @see addCity, deleteCity
 */
 // DONE - Works in Moodle
city *searchNetwork(city *head, string cityName)
{
  city *temp = new city;
  temp = head;
  while(temp != NULL && temp->name != cityName)
  {
     temp = temp->next;
  }
  return temp;
  return head;
}

/*
 * Purpose: deletes all cities in the network starting at the head city.
 * @param head: head of list
 * @return: NULL as the list is empty
 */
 // DONE - Works on Moodle
 city* deleteEntireNetwork(city *head)
 {
   if(head == NULL)
   {
       return 0;
   }
   //Temp pointer to the node to be deleted
   city *temp;
   while(head != NULL)
   {
     cout << "deleting: " << head->name << endl;
     temp = head;
     //Move head to next node while temp stays behind to be deleted
     head = head->next;
     delete temp;
   }

   cout << "Deleted network" << endl;
   // Return head, which should be NULL
   return head;
 }

/*
 * Purpose: transmit a message from city to city
 * @param head: pointer to head of the list
 * @param receiver: the name of the City to receive the message
 * @param message: the message to transmit*/
 // DONE - Works on Moodle
void transmitMsg(city *head, string receiver, string message)
{
  if(head == NULL)
  {
    cout << "Empty list" << endl;
    return;
  }
  city* recip = searchNetwork(head, receiver);
  city* sender = head;
  while (sender != recip->next)
  {
    sender->numberMessages = sender->numberMessages +1;
    sender->message = message;
    // Use the following output statements to print each node of the linked list:
    cout << sender->name << " [# messages passed: " <<
    sender->numberMessages << "] received: " <<
    sender->message << endl;
    sender = sender->next;
   }
 }

/*
 * Purpose: delete the city in the network with the specified name.
 * @param head: first node in list
 * @param cityName: name of the city to delete in the network
 * @return: head node of list
 */
 // DONE - Works on Moodle
city* deleteCity(city *head, string cityName)
{
  city* toDelete = searchNetwork(head, cityName);
  int i = 0;
  if (toDelete == head)
  {
    city* temp = head;
    head = head->next;
    free(temp);
    return head;
  }
  if ((toDelete != NULL) and (toDelete->next != NULL))
  {
    while((toDelete != head) and (i >= 1))
    {
      head = head->next;
    }
    //cout << head->next->name << endl;
    //cout << toDelete->next->name << endl;
    head->next = toDelete->next;
    i++;
   }
   else
   {
     cout << "City does not exist." << endl;
     return head;
   }
   free(toDelete);
   return head;;
}

/*
 * Purpose: prints the current list nicely
 * @param head: head of list
 */
 // NOT DONE - Has erros in output
void printPath(city *head)
{
  cout << "== CURRENT PATH ==" << endl;
  if (head == NULL)
  {
    cout << "nothing in path" << endl;
  }
  while(head)
  {
    if(head != NULL)
    {
      cout << head->name << " " << "->";
      head = head->next;
    }
    else
    {
      cout << "NULL" << endl;
      break;
    }
  }
  cout << "NULL" << endl;
  // Add code here to print the network path.
  cout << "===" << endl;
}

/*
 * Purpose: populates the network with the predetermined cities
 * @param head: start of list
 * @return: head of list
 */
 // DONE - Works on Moodle
city* loadDefaultSetup(city *head)
{
  // Add code here to populate the LinkedList with the default values
  head = deleteEntireNetwork(head);
  head = addCity(head,NULL,"Los Angeles");
  addCity(head,head,"Phoenix");
  addCity(head,head->next,"Denver");
  addCity(head,head->next->next,"Dallas");
  addCity(head,head->next->next->next,"Atlanta");
  addCity(head,head->next->next->next->next,"New York");

  return head;
  printPath(head);
}

/* Purpose: displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu()
{
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Build Network" << endl;
  cout << "2. Print Network Path" << endl;
  cout << "3. Transmit Message" << endl;
  cout << "4. Add City" << endl;
  cout << "5. Delete City" << endl;
  cout << "6. Clear Network" << endl;
  cout << "7. Quit" << endl;
}
