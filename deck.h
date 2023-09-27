
#ifndef deck_h
#define deck_h
#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Deck {
    //A small class cardType can be used to represent a single card and has public members suit and value.
public:
    class cardType {
    public:
      char suit;
      char rank;
    };

private:
    cardType D[52]; // Array containing the Deck of cards
  int top;        // Top of Deck
  void swap(int i, int k); // prototype for a utility function to swap cards (i) & (k)

public:

  Deck();// Constructor
  ~Deck();// Destructor
  void Create_Fresh_Deck(); // Create a fresh Deck
  bool EmptyDeck()const;// return True if Deck is empty
  cardType RemoveCard();// Remove and return top card
  void AddCard(const cardType &c);// Add a card (c) to top of deck
  void Shuffle_Deck();// Shuffle Deck.
  void Cut_Deck();//Cut Deck: Exchange upper half with lower half
  void Display_Deck() const;// Display Deck
};

#endif /* deck_h */
