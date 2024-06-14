import random
from enum import Enum

class Suit(Enum):
    HEARTS = 1
    DIAMONDS = 2
    SPADES = 3
    CLUBS = 4

class CardValue(Enum):
    ACE = 1  
    TWO = 2
    THREE = 3
    FOUR = 4
    FIVE = 5
    SIX = 6 
    SEVEN = 7
    EIGHT = 8
    NINE = 9
    TEN = 10
    JACK = 11
    QUEEN = 12
    KING = 13
      

class Card:
    def __init__(self, suit: Suit, value: CardValue):
        self.suit = suit
        self.value = value

class Deck:
    def __init__(self):
        self.reset()
    
    def shuffle(self):
        random.shuffle(self.cards)
    
    def draw(self):
        return (self.cards.pop())
    
    def reset(self):
        self.cards = []
        for suit in Suit:
            for value in CardValue:
                self.cards.append(Card(suit, value))
        self.shuffle()
    
    def print_deck(self):
        for card in self.cards:
            print(f"{card.value.name} of {card.suit.name}")
    
class Player:
    def __init__(self, name):
        self.name = name
        self.reset()
    
    def draw(self, deck):
        self.hand.append(deck.draw())
    
    def show_hand(self):
        print(f"{self.name}'s hand: ")
        for card in self.hand:
            print(f"{card.value.name} of {card.suit.name} \n")
    
    def sort_hand(self):
        self.hand.sort(key=lambda card: card.value.value)
        
    def reset(self):
        self.hand = []

def reset_game(player1, player2, deck):
    player1.reset()
    player2.reset()
    deck.reset()

deck = Deck()
player1 = Player("Player 1")
player2 = Player("Player 2")
# deck.print_deck()
player1.draw(deck)
player2.draw(deck)
player1.show_hand()
player2.show_hand()
# deck.print_deck()

    