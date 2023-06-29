#include<iostream>
#include<array>
#include<random>
#include<chrono>
#include<algorithm>
#include<bitset>

enum class CardSuit
{
    clubs,
    diamonds,
    hearts,
    spades,

    max_suits
};

enum class CardRank
{
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,

    max_ranks
};

struct Card
{
    CardSuit suit {};
    CardRank rank {};
};


void printCard(const Card& card)
{
    switch (card.rank) {
        case CardRank::rank_2: std::cout << '2'; break;
        case CardRank::rank_3: std::cout << '3'; break;
        case CardRank::rank_4: std::cout << '4'; break;
        case CardRank::rank_5: std::cout << '5'; break;
        case CardRank::rank_6: std::cout << '6'; break;
        case CardRank::rank_7: std::cout << '7'; break;
        case CardRank::rank_8: std::cout << '8'; break;
        case CardRank::rank_9: std::cout << '9'; break;
        case CardRank::rank_10: std::cout << "10"; break;
        case CardRank::rank_jack: std::cout << "11"; break;
        case CardRank::rank_queen: std::cout << "12"; break;
        case CardRank::rank_king: std::cout << 'K'; break;
        case CardRank::rank_ace: std::cout << 'A'; break;
        default: std::cout << '?'; break;
    }

    switch (card.suit) {
        case CardSuit::clubs: std::cout << 'C'; break;
        case CardSuit::diamonds: std::cout << 'D'; break;
        case CardSuit::hearts: std::cout << 'H'; break;
        case CardSuit::spades: std::cout << 'S'; break;
        default: std::cout << '?'; break;
    }
}


using Deck = std::array<Card, 52>;
using Index = Deck::size_type;


Deck createDeck(void)
{
    Deck deck {};
    for(std::size_t suit_no {0}; suit_no < static_cast<int>(CardSuit::max_suits); ++suit_no)
        for(std::size_t rank_no {0}; rank_no < static_cast<int>(CardRank::max_ranks); ++rank_no)
        {
            std::size_t index = (suit_no*13 + rank_no);
            deck[index].suit = static_cast<CardSuit>(suit_no);
            deck[index].rank = static_cast<CardRank>(rank_no);
        }
    return deck;
}

void printDeck(const Deck &deck)
{
    std::cout << "The current deck is: ";

    int index {0};
    for(const Card &card : deck)
    {
        printCard(card);
        std::cout << ' ';

        if( !(++index%13) )
        { std::cout << '\n'; }
    }
    std::cout << '\n';
}


void shuffleDeck(Deck &deck)
{
    static std::mt19937 mt{static_cast<std::mt19937::result_type>( std::chrono::steady_clock::now().time_since_epoch().count() ) };
    std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(Card &card)
{
    if(static_cast<int>(card.rank)<=8)
        { return static_cast<int>(card.rank)+2; }
    else if(static_cast<int>(card.rank)<=11)
        { return 10; }
    else
        { return 11; }
}

constexpr int threshold {21};
constexpr int dealer_threshold {17};

struct GameStatus{
    int user_score {};
    int dealer_score {};
    Deck deck { createDeck() };
    std::size_t next_card;
    int turn;
};

bool isScoreOverThreshold(GameStatus &game)
{
    return ( game.user_score>threshold || game.dealer_score>threshold);
}

// 0=nobody won, 1=user won, 2=dealer won
int calculateGameResult(GameStatus &game)
{
    if(isScoreOverThreshold(game)){
        return (game.dealer_score>threshold)? 1 : 2;
    }
    else{
        return (game.dealer_score < game.user_score)? 1 : ( (game.dealer_score = game.user_score)? 0 : 2);
    }
}

void userDrawsCard(GameStatus &game)
{
    if(game.next_card>=52)
    {
        std::cout << "Cannot not draw cards from an empty deck!\n";
        return;
    }
    std::cout << "The drawn card is: ";
    printCard(game.deck[game.next_card]);
    std::cout << '\n';
    game.user_score += getCardValue(game.deck[game.next_card++]);
}

void dealerDrawsCard(GameStatus &game)
{
    if(game.next_card>=52)
    {
        std::cout << "Cannot not draw cards from an empty deck!\n";
        return;
    }
    std::cout << "The drawn card is: ";
    printCard(game.deck[game.next_card]);
    std::cout << '\n';
    game.dealer_score += getCardValue(game.deck[game.next_card++]);
}

void userPlaysTurn(GameStatus &game)
{
    std::cout << "User plays.\n";
    char command {};
    do{
        std::cout << "Hits (h) or stands (s)? ";
        std::cin >> command;

        if(command!='h' && command!='s'){
            std::cout <<"Give please a valid command!\n";
            continue;
        }
        else if(command=='s'){
            break;
        }

        std::cout << "The user draws a card\n";
        userDrawsCard(game);
        std::cout << "User score: " << game.user_score << "\tDealer score: " << game.dealer_score << '\n';

        if(isScoreOverThreshold(game)){
            return;
        }
    } while (command!='s');
    
    std::cout<< "User turn finished\n\n";
}

void dealerPlaysTurn(GameStatus &game)
{
    std::cout << "Dealer plays.\n";
    while (game.dealer_score <= dealer_threshold){
        std::cout << "The dealer draws a card\n";
        dealerDrawsCard(game);
        std::cout << "User score: " << game.user_score << "\tDealer score: " << game.dealer_score << '\n';

        if(isScoreOverThreshold(game)){
            return;
        }
    }
    std::cout<< "Dealer turn finished\n\n";
}

// same symbols of the calculateGameResult
int playBlackjack(Deck &shuffled_deck)
{
    GameStatus game = {0, 0, shuffled_deck, 0, 0};
    std::cout << "The game starts!\n\nThe user draws two cards: \n";
    userDrawsCard(game);
    userDrawsCard(game);

    // if the score is over it must be the user who lost at this point
    if(isScoreOverThreshold(game))
        return calculateGameResult(game);

    std::cout << "The dealer draws a card\n";
    dealerDrawsCard(game);

    std::cout << "User score: " << game.user_score << "\tDealer score: " << game.dealer_score << '\n';

    userPlaysTurn(game);
    if(isScoreOverThreshold(game)){
        std::cout << "The user lost!\n";
        return calculateGameResult(game);
    }

    dealerPlaysTurn(game);
    if(isScoreOverThreshold(game)){
        std::cout << "The dealer lost!\n";
        return calculateGameResult(game);
    }

    userPlaysTurn(game);
    if(isScoreOverThreshold(game)){
        std::cout << "The user lost!\n";
        return calculateGameResult(game);
    }

    std::cout << "Nobody won!\n";
    return calculateGameResult(game);
}


int main(void)
{
    Deck deck { createDeck()};
    shuffleDeck(deck);
    playBlackjack(deck);
    return 0;
}

