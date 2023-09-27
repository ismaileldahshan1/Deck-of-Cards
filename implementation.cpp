/*
 Course: Fundamentals of Computing II
 Student Name: Ismail ElDahshan
 Student ID: 900221719
 Professor: Dr. Amr Goneid
 Section: 3
 */
#include "deck.h"
#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
Deck::Deck()//constructor
{
   top = -1;//set top to -1
   
}

Deck::~Deck() {}//destructor


bool Deck::EmptyDeck()const// return True if Deck is empty
{
   //return true if top is -1 else return false
  if (top == -1) {
    return true;
  } else {
    return false;
  }
}

void Deck::AddCard(const cardType &c) // Add a card (c) to top of deck
{
   //increment top then store card c in D[top]
    top++;
    D[top] = c;
  
}

Deck::cardType Deck::RemoveCard()// Remove and return top card
{
   //Get top card , decrement top then return the card
  cardType c = D[top];
  top--;
  return c;
}

void Deck::Create_Fresh_Deck() // Create a fresh Deck
{
  cardType c; // Declare an object c of type cardType
   
  string v = "23456789TJQKA";//string v contains the card values
  top = -1;//set top to -1
  for (int i = 0; i < 4; i++) {// loop over the four suits
    for (int j = 0; j < 13; j++) {// loop over the thirteen card values
    
      c.suit = char(i+3);// Card Suit: ASCII values of 3,4,5 or 6
       c.rank = v[j]; // Card rank
      AddCard(c);           // Add card to deck
    }
  }
}
void Deck::swap(int i, int k)// Swap cards (i) and (k)
{
   //Swap D[i] with D[k]
  cardType temp = D[i];
  D[i] = D[k];
  D[k] = temp;
}
void Deck::Shuffle_Deck() {// Shuffle Deck.

  srand(time(NULL)); // Initialize Random Number Generator

  for (int i = 51; i >= 1; i--) { // For i from 51 down to 1 generate a random integer k whose value is from 0 to i.
    int k = rand() % (i + 1); // Random integer from 0 to i
    swap(i, k);   // Then swap cards (i) and (k).
  }
}

void Deck::Cut_Deck()// Cut Deck: Exchange upper half with lower half
{
  for (int i = 0; i <= 25; i++) {//Swap cards in locations 0 to 25 with those in locations 26 to 51
    swap(i, i + 26);
  }
}

void Deck::Display_Deck() const {
  if (!EmptyDeck()) {//If Deck is not empty
    for (int i = 0; i <=top; i++) {
      
       cout << D[i].suit<<" " << D[i].rank << endl;//display suit and rank of each card in the Deck
  
    }
  }
}

