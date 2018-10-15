/* Written by Michael Rogers*/
//Code doesn't work at this time.
#include <iostream>
#include "HW5-MovieTree.hpp"
#include <fstream>
#include <sstream>

using namespace std;

MovieTree::MovieTree() {
  root = NULL;
}

MovieTree::~MovieTree() {
  DeleteTree(root);
}

void MovieTree::search(string title) {
  if(node == NULL) {
      return NULL;
  }

  MovieNode *current = node;
  while(current != NULL) {
      if(current->title == value){
          return current;
      }
      else if (value < current->title) {
          current = current->leftChild;
      }
      else {
          current = current->rightChild;
      }
  }
  return NULL; //no matching title found in the tree
}

void MovieTree::findMovie(string title) {
  MovieNode *foundMovie=search(title);
  if(foundMovie!=NULL) {
      cout << "Movie Info:" << endl;
      cout << "===========" << endl;
      cout << "Ranking:" << foundMovie->ranking << endl;
      cout << "Title:" << foundMovie->title << endl;
      cout << "Year:" << foundMovie->year << endl;
      cout << "Quantity:" << foundMovie->quantity << endl;
  }
  else {
      cout << "Movie not found." << endl;
  }
}

void MovieTree::printMovieInventory() {
	MovieNode* current = root;

	while(current != NULL) {
		if(current->leftChild != NULL) {
			cout <<"Movie: " << current->leftChild->title << " " << current->leftChild->quantity << endl;
    }
		cout <<"Movie: " << current->title << " " << current->quantity << endl;

		if(current->rightChild != NULL) {
		 	cout <<"Movie: " << current->rightChild->title << " " << current->rightChild->quantity << endl;
		    current = current->leftChild;
		}

		else {
		    return;
		}
	}
}

void MovieTree::addMovieNode(int ranking, string title, int year, int quantity) {
    MovieNode *newMovie = new MovieNode(ranking,title,year,quantity);

    if(root == NULL) {
       root = newMovie; //If tree empty make newMovie the root
    }
    else {
        MovieNode *temp = root;
        while(true) {
            if(newMovie->title <= temp->title) { //If newMovie is less than, move to left subtree
                if(temp->leftChild == NULL) {
                    temp->leftChild = newMovie;
                    newMovie->parent = temp; //Set parent for new node
                    return;
                }
                else {
                    temp = temp->leftChild;
                }
            }
            else {
                if(temp->rightChild == NULL) { //Right subtree traversal
                    temp->rightChild = newMovie;
                    newMovie->parent = temp;//Set parent for new node
                    return;
                }
                else {
                    temp = temp->rightChild;
                }
            }
        }
    }
}

void MovieTree::findMovie(string title) {
    MovieNode* node = root;
    char letter = title[0];
    bool found = false;

	while(node != NULL) {
  		if(node->title == title) {
      		cout << "Movie Info:" << endl << "===========" << endl;
      		cout << "Ranking:" << node->ranking << endl;
      		cout << "Title:" << node->title << endl;
      		cout << "Year:" << node->year << endl;
      		cout << "Quantity:" << node->quantity << endl;
      		found = true;
      		return;
        }
    	else if((node->title[0] > letter) && (node->leftChild != NULL)) {
      		node = node->leftChild;
        }
    	else {
    	  	node = node->rightChild;
    	}
  	}
  	if (!found) {
  	    cout << "Movie not found." << endl;
  	}
 }

 void MovieTree::rentMovie(string title) {
     bool found = false;
     char letter = title[0];
     MovieNode* node = root;
     MovieNode* thisMovie = root;

     while(node != NULL) {
         if(node->title == title) {
             thisMovie = node;
       		found = true;
       		goto Line1;
         }
 	       else if((node->title[0] > letter) && (node->leftChild != NULL)) {
   		      node = node->leftChild;
         }
 	       else {
 	  	      node = node->rightChild;
 	       }
    }
 Line1:
     if((found) and (thisMovie->quantity > 0)) {
     	cout << "Movie has been rented." << endl;
     	thisMovie->quantity = thisMovie->quantity - 1;
         findMovie(title);
     }
     else if((found) and (thisMovie->quantity <= 0)) {
         cout << "Movie out of stock." << endl;
     }
     else {
         cout << "Movie not found." << endl;
     }
 }

void MovieTree::DeleteTree(MovieNode *node) {
    if(node==NULL){
      return;
    }
    DeleteTree(node->leftChild);
    DeleteTree(node->rightChild);
    delete node;
}

int main()
{
   ifstream file("movies.txt");
   ifstream docs("Documentaries.txt");

   /* if fopen( ) was not successful there was an error, so exit with error */
   if(!file.is_open() or !docs.is_open()) {
     cout << "Error opening input file";
     exit(1);
   }

   int choice = 4;
   MovieTree *tree = new MovieTree(); //our movie tree
   char buffer[100];
   int ranking,quantity,year;
   string title;

   //initially load all movies from file
   while(!file.eof() and !docs.eof()) {//while its not end of file
       file.getline(buffer,100,','); //read the ranking from file ,using comma delimiter
       ranking=atoi(buffer);
       file.getline(buffer,100,',');//get the title from file
       title=string(buffer);
       file.getline(buffer,100,',');
       year=atoi(buffer);
       file.getline(buffer,100,'\n');
       quantity=atoi(buffer);
       tree->addMovieNode(ranking,title,year,quantity);
   }

   file.close();

   //now repeatedly get user's choice and perform action accordingly
   do {
       cout<<"======Main Menu======" << endl;
       cout << "1. Find a movie" << endl;
       cout << "2. Rent a movie" << endl;
       cout << "3. Print the inventory" << endl;
       cout << "4. Quit" << endl;

       cin>>choice;
       switch(choice) { //based on command number call diffent functions
           case 1:
               //find a title
               cout << "Enter the movie title : " << endl;getchar();
               getline(cin,title);
               tree->findMovie(title);
               break;
           case 2:
               //rent a title
               cout << "Enter the movie title : " << endl;getchar();
               getline(cin,title);
               tree->rentMovie(title);
               break;
           case 3:
               //print inventory
               tree->printMovieInventory();
               break;
           case 4:
              cout << "Goodbye!" << endl;
              DeleteTree(root);
              break;
           default:
           ;

       }

   }while(choice!=4);


   return 0;
}
