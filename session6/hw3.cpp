/* 
 *  use the structure card defined in the poker program in 4.7, an example: Flusing, onpage 125, to wrute a hand-sorting routine.
 *
 *  In card games, most playser keep their cards sorted by pip value.  The routine places aces first, kings next and so forth, down to twos. A hand is five cards.
 */

#include <iostream>
#include <string>
using namespace std;

enum suit { clubs, diamonds, hearts, spades};

class pips {
  public:
    void assign(int n) { p=n % 13 + 1;}
    int getpip() { return p;}
    void print() { cout << p;}
  private:
    int p;
};

class card {
  public:
    suit s;
    pips p;
    void assign(int n) { cd=n; s = static_cast<suit>(n/13); p.assign(n);}
    void pr_card();
    void print() { int num = p.getpip(); cout << num << " of " << s << endl;}
  private:
    int cd;
};

class deck {
  public:
    void init_deck();
    void shuffle();
    void deal(int, int, card*);
    void pr_deck();
  private:
    card d[52];
};

void deck::init_deck()
{
  for(int i=0; i<52; ++i) {
    d[i].assign(i);
  }
}

void deck::shuffle()
{
  for(int i = 0; i<52; ++i){
    int k = i + (rand() % (52-i));
    card t = d[i];
    d[i] = d[k];
    d[k] = t;
  }
}

void deck::deal(int n, int pos, card* hand)
{
  for( int i = pos; i < pos + n; ++i) {
    hand[i-pos] = d[i];
  }
}

int main()
{
  card one_hand[5];
  deck dk;
  int i,k,j;
  int ndeal, nc,nhand;
  ndeal = 1;
  nc = 5;
  nhand = 52 / nc;

  dk.init_deck();

  for (k=0; k < ndeal; k+= nhand) {
    if((nhand + k ) > ndeal) {
      nhand = ndeal - k;
    }
    dk.shuffle();
    dk.shuffle();
    dk.deal(nc, i, one_hand);
  }

  

  for (i =0; i < nc; ++i) {
    one_hand[i].print();
  }

  


  return 0;
}
