/*
 Course: Fundamentals of Computing II
 Student Name: Ismail ElDahshan
 Student ID: 900221719
 Professor: Dr. Amr Goneid
 Section: 3
 */

#include "deck.h"
#include "implementation.cpp"
#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
int cardConversion(char card) {// converting the given string into integer values that are in the given table to compare to see the winner.
    if (card == 'T')
    return 10;//converting the T value to be 10
  else if (card == 'J')
    return 11;// converting the J value to be 11
  else if (card == 'Q')
    return 12;// converting the Q value to be 12
  else if (card == 'K')
    return 13;// converting the K value to 13
  else if (card == 'A')
    return 14;// converting the A value to 14
  else
    return card - '0';// else if it is a number return a normal number
}

int main() {
    // Game Setup
    int NP = 4;// Declare the Number of Players NP (4 players)
    string v = "23456789TJQKA";// A string v of card ranks = "23456789TJQKA"
    Deck cdeck;// The card deck cdeck of type Deck
    
    Deck Hand[NP];// Hand[NP]: Hands of each player, an array of Decks, one for each player
    Deck::cardType c;// A card c of type cardType
    
    Deck::cardType cards[NP];// cards[NP]: Array of type cardtype for cards put on the table by each player
    int score[NP];// score[NP] An int array for the score of each player
    
    int N;// int N : used for next player
    int p;// int p: player number
    int wp;// int wp: winning player in a given round
    int win;// int win: the amount of win in that round
    // Prepare Deck
    cdeck.Create_Fresh_Deck();// Create a fresh deck (cdeck)
    cdeck.Shuffle_Deck();//Shuffle the whole deck
    cdeck.Cut_Deck();//Cut the deck
    cdeck.Display_Deck();// Display the deck
    
    // Distribute all cards to NP players
    N = 0;
    while (!cdeck.EmptyDeck()) // While there are still cards left
    {
        p = N % NP; // select player (0,1,2,3,0,1,2,3, etc)
        c = cdeck.RemoveCard();//pick a card from top of deck
        Hand[p].AddCard(c);//Distribute card to hand of player (p)
        N++; // next player
    }

    for (int i = 0; i < NP; i++) {
        score[i] = 0;    // Set scores of all players to zero
    }
    cout<<"The hands are:"<<endl;
    for (int i = 0; i < NP; i++) {
        Hand[i].Display_Deck();// Display the hands
        cout << endl;
    }
    
    // Game starts here
    
    while (!Hand[0].EmptyDeck()) {// while first player still has a card
        for (p = 0; p < NP; p++) {// Start a round. Each player puts a card face down on table
            cards[p] = Hand[p].RemoveCard();
        }
        
        wp = 0;// Cards are turned and winner player is defined (wp)
        for (int i = 1; i < NP; i++) {// loop through all players' cards and determine the winner
            int cardrank1 = cardConversion(cards[wp].rank);// convert the rank of the cards to an integer for comparison
            int cardrank2 = cardConversion(cards[i].rank);// convert the rank of the cards to an integer for comparison
            if (cardrank1 <cardrank2) {// if the current card's rank is higher, set wp to the current player's index
                wp = i;
            } else if (cardrank1 == cardrank2 && cards[i].suit > cards[wp].suit) {// if the ranks are equal, compare the suits to determine the winner
                wp = i;
            }
        }
        // display cards on table and winner card
        cout << " Cards are : " << endl;
        for (int i = 0; i < NP; i++) {
            
            cout << "Player "<< i+1 <<" : " <<cards[i].suit << " and " << cards[i].rank << endl;
        }
        cout << "Winning Card is : " << cards[wp].suit << " and " << cards[wp].rank
        << endl;
        
        score[wp]++; // increment the score of the winning player
        
        win=score[wp];
        for (int i = 0; i < NP; i++) {
            
            cout << "Player  " << i + 1 <<" : "<< " has a score " << score[i] << endl;// display each players scores
        }
        cout << "Round winner: Player " << wp + 1 << " with a score of " << win << endl; // display the winner of the round
    }//displaying the final scores
    cout << "Final Scores:" << endl;
    for (int i = 0; i < NP; i++) {
        cout << "Player " << i + 1 << ": " << score[i] << endl;//display the final scores of each player
    }
    int highscore = score[0]; // initialize the maximum score to the first player's score
    int winner = 0;
    for (int i = 1; i < NP; i++) {// loop through the rest of the players scores
        if (score[i] > highscore) {// if a player has a higher score than the current maximum score
            highscore = score[i];// update the maximum score to the player's score
            winner = i;// update the winner to the player's index
        }
    }

    // Display the winner
    cout << "The winner is player " << winner + 1 << " with a score of " << highscore << endl;
    return 0;

}
