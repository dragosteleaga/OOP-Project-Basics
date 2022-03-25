#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
// Detalii despre o banca anume gen ING ,BT va avea metoda sa afiseze cati ani
// vechime are banca
//
class Banca {
private:
  string numeBanca;
  int numarAngajati;
  char *locatieSediu;
  int anInfiintare;

public:
  Banca();
  Banca(string numeBanca, int anInfiintare);
  Banca(int numarAngajati, char *locatieSediu);
  Banca(string numeBanca, int numarAngajati, char *locatieSediu,
        int anInfiintare);
  Banca(const Banca &bank);

  Banca operator=(const Banca &bank);
  friend ostream &operator<<(ostream &out, const Banca &ob);
  friend istream &operator>>(istream &in, Banca &ob);

  void aniVechime();

  string getNumeBanca();
  float getNumarAngajati();
  char *getLocatieSediu() const;
  int getAnInfiintare();

  void setNumeBanca(string numeBanca);
  void setNumarAngajati(int numarAngajati);
  void setLocatieSediu(const char *locatieSediu);
  void setAnInfiintare(int anInfiintare);
  char operator[](char index);
  Banca operator+(Banca ob);
  Banca operator+=(int x);
  Banca operator+(int x);
  friend Banca operator+(int x, Banca b);
  Banca operator-(Banca ob);
  Banca operator-=(int x);
  Banca operator-(int x);
  friend Banca operator-(int x, Banca b);
  Banca operator++();
  Banca operator++(int);
  bool operator==(const Banca &ob);
  bool operator<(const Banca &ob);
  explicit operator int();

  ~Banca();
};
// operatorul << si >>
istream &operator>>(istream &in, Banca &ob) {
  cout << "\nNume banca: ";
  in >> ob.numeBanca;
  cout << "\nNumar angajati: ";
  in >> ob.numarAngajati;
  cout << "\nLocatie sediu: ";

  char aux[100];
  in >> aux;
  if (ob.locatieSediu != NULL)
    delete[] ob.locatieSediu;
  ob.locatieSediu = new char[strlen(aux) + 1];
  strcpy(ob.locatieSediu, aux);

  cout << "\nAn infiintare: ";
  in >> ob.anInfiintare;
  return in;
}
ostream &operator<<(ostream &out, const Banca &ob) {
  cout << "\nNume banca: ";
  out << ob.numeBanca;
  cout << "\nNumar angajati: ";
  out << ob.numarAngajati;
  cout << "\nLocatie sediu: ";
  out << ob.locatieSediu;
  cout << "\nAn infiintare: ";
  out << ob.anInfiintare;
  return out;
}

// constructor cu toti parametrii
Banca ::Banca(string numeBanca, int numarAngajati, char *locatieSediu,
              int anInfiintare) {
  this->numeBanca = numeBanca;
  this->numarAngajati = numarAngajati;
  this->locatieSediu = new char[strlen(locatieSediu) + 1];
  strcpy(this->locatieSediu, locatieSediu);
  this->anInfiintare = anInfiintare;
}
Banca ::Banca() {
  this->numeBanca = "noName";
  this->numarAngajati = 0;
  this->locatieSediu = new char[strlen("noName") + 1];
  strcpy(this->locatieSediu, "noName");
  this->anInfiintare = 0;
}

// constructor de copiere
Banca ::Banca(const Banca &bank) {

  this->numeBanca = bank.numeBanca;
  this->numarAngajati = bank.numarAngajati;
  this->locatieSediu = new char[strlen(bank.locatieSediu) + 1];
  strcpy(this->locatieSediu, bank.locatieSediu);
  this->anInfiintare = bank.anInfiintare;
}

// 2 constructori cu 2 parametrii fiecare

Banca ::Banca(string numeBanca, int anInfiintare) {
  this->numeBanca = numeBanca;
  this->anInfiintare = anInfiintare;
  new char[strlen("noName") + 1];
  strcpy(this->locatieSediu, "noName");
  this->numarAngajati = numarAngajati;
}

Banca ::Banca(int numarAngajati, char *locatieSediu) {
  this->numarAngajati = numarAngajati;
  this->locatieSediu = new char[strlen(locatieSediu) + 1];
  strcpy(this->locatieSediu, locatieSediu);
  this->numeBanca = "Anonim";
  this->anInfiintare = 0;
}
// Setters si getters pentru toti parametrii

string Banca::getNumeBanca() { return this->numeBanca; }

void Banca ::setNumeBanca(string numeBanca) { this->numeBanca = numeBanca; }

float Banca ::getNumarAngajati() { return this->numarAngajati; }

void Banca ::setNumarAngajati(int numarAngajati) {
  this->numarAngajati = numarAngajati;
}

void Banca ::setLocatieSediu(const char *locatieSediu) {
  if (this->locatieSediu != NULL) {
    delete[] this->locatieSediu;
  }
  this->locatieSediu = new char[strlen(locatieSediu)];
  strcpy(this->locatieSediu, locatieSediu);
}
char *Banca ::getLocatieSediu() const { return this->locatieSediu; }
int Banca ::getAnInfiintare() { return this->anInfiintare; }

void Banca ::setAnInfiintare(int anInfiintare) {
  this->anInfiintare = anInfiintare;
}

// operatorul =
Banca Banca ::operator=(const Banca &bank) {
  if (this != &bank) {
    if (this->locatieSediu != NULL)
      delete[] this->locatieSediu;
    this->numeBanca = bank.numeBanca;
    this->numarAngajati = bank.numarAngajati;
    this->locatieSediu = new char[strlen(bank.locatieSediu) + 1];
    strcpy(this->locatieSediu, bank.locatieSediu);
    this->anInfiintare = bank.anInfiintare;
  }
  return *this;
}
Banca ::~Banca() {
  if (this->locatieSediu != NULL)
    delete[] this->locatieSediu;
}
// metoda
void Banca ::aniVechime() {
  cout << "Banca " << numeBanca << " are " << 2022 - anInfiintare
       << " ani vechime!";
}
// operatorul ++ () si ()++
Banca Banca ::operator++() {
  // prefix
  ++this->numarAngajati;
  return Banca(this->numeBanca, this->anInfiintare, this->locatieSediu,
               this->anInfiintare);
}
Banca Banca ::operator++(int) {
  // sufix
  Banca copy(this->numeBanca, this->numarAngajati, this->locatieSediu,
             this->anInfiintare);
  this->numarAngajati++;
  return copy;
}
// operatorul []
char Banca::operator[](char index) {
  if (0 <= index && index < strlen(locatieSediu))
    return this->locatieSediu[index];
  cout << "Index introdus gresit!\n";
}

// operatorul + si operatorul -
Banca Banca ::operator+(Banca ob) {
  ob.numarAngajati = this->numarAngajati + ob.numarAngajati;
  ob.anInfiintare = this->anInfiintare + ob.anInfiintare;
  return ob;
}
Banca Banca ::operator+=(int x) {
  this->numarAngajati += x;
  return *this;
}
Banca Banca ::operator+(int x) {
  Banca aux(*this);
  aux.numarAngajati = aux.numarAngajati + x;
  return aux;
}
Banca operator+(int x, Banca b) {
  b.numarAngajati = b.numarAngajati + x;
  return b;
}

Banca Banca ::operator-(Banca ob) {
  ob.numarAngajati = this->numarAngajati - ob.numarAngajati;
  return ob;
}
Banca Banca ::operator-=(int x) {
  this->numarAngajati += x;
  return *this;
}
Banca Banca ::operator-(int x) {
  Banca aux(*this);
  aux.numarAngajati = aux.numarAngajati - x;
  return aux;
}
Banca operator-(int x, Banca b) {
  b.numarAngajati = b.numarAngajati - x;
  return b;
}
// operatorul cast
Banca ::operator int() { return (long)this->numarAngajati; }
// operator conditional
bool Banca ::operator<(const Banca &ob) {
  if (this->numarAngajati < ob.numarAngajati)
    return true;
  return false;
}
// operatorul ==
bool Banca ::operator==(const Banca &ob) {
  if (this->numarAngajati == ob.numarAngajati &&
      strcmp(this->locatieSediu, ob.locatieSediu) == 0 &&
      this->anInfiintare == ob.anInfiintare && this->numeBanca == ob.numeBanca)
    return true;
  return false;
}

// Detalii despre card , fiecare card e la o banca , va avea metoda sa spuna cat
// timp mai e valabil cardul
class Card {
private:
  long long numarCard;
  string IBAN;
  string numeCard;
  int codCVC;
  bool contactLess;
  Banca banca;

public:
  Card();
  Card(long long numarCard, string IBAN);
  Card(Banca banca, int codCVC);
  Card(long long numarCard, string IBAN, string numeCard, int codCVC,
       bool contactLess, Banca banca);
  Card(const Card &card1);

  Card operator=(const Card &card1);

  friend ostream &operator<<(ostream &out, const Card &ob);
  friend istream &operator>>(istream &in, Card &ob);
  // metoda
  void schimbareContactlessCard();
  // setters
  void setNumarCard(long long numarCard);
  void setIBAN(string IBAN);
  void setNumeCard(string numeCard);
  void setCodCVC(int codCVC);
  void setContactLess(bool contactLess);
  void setBanca(Banca banca);
  // getters
  long long getNumarCard();
  string getIBAN();
  string getNumeCard();
  int getCodCVC();
  bool getContactLess();
  Banca getBanca();
  // operatori
  friend Card operator+(Banca b, Card c);
  friend Card operator+(Card c, Banca b);
  Card operator++();
  Card operator++(int);
  Card operator+=(int x);
  Card operator+(int x);
  Card operator+(Card card);
  Card operator-=(int x);
  friend Card operator+(int x, Card card);
  Card operator-(int x);
  Card operator-(Card card);
  friend Card operator-(int x, Card card);
  explicit operator int();
  bool operator<(const Card &ob);
  bool operator==(const Card &ob);

  ~Card();
};
istream &operator>>(istream &in, Card &ob) {
  cout << "\nNumar card: ";
  in >> ob.numarCard;
  cout << "\nIBAN: ";
  in >> ob.IBAN;
  cout << "\nNume card (ex: teleagaDragos) : ";
  in >> ob.numeCard;
  cout << "\nCod CVC: ";
  in >> ob.codCVC;
  cout << "\nContactless [0-flase/1-true] : ";
  in >> ob.contactLess;
  cout << "\nDate despre banca: ";
  in >> ob.banca;
  return in;
}
ostream &operator<<(ostream &out, const Card &ob) {
  cout << "\nNumar card: ";
  out << ob.numarCard;
  cout << "\nIBAN: ";
  out << ob.IBAN;
  cout << "\nNume card:  ";
  out << ob.numeCard;
  cout << "\nCod CVC: ";
  out << ob.codCVC;
  if (ob.contactLess)
    cout << "\nContactless : Da";
  else
    cout << "\nContactless : Nu";
  cout << "\nDate despre banca: ";
  out << ob.banca;
  return out;
}

Card::Card(long long numarCard, string IBAN, string numeCard, int codCVC,
           bool contactLess, Banca banca) {
  this->numarCard = numarCard;
  this->IBAN = IBAN;
  this->numeCard = numeCard;
  this->codCVC = codCVC;
  this->contactLess = contactLess;
  this->banca = banca;
}
// constructor fara parametrii
Card::Card() {
  this->numarCard = 0;
  this->IBAN = "null";
  this->numeCard = "Anonim";
  this->codCVC = 0;
  this->contactLess = 0;
  this->banca = Banca();
}
// copy constructor
Card::Card(const Card &card1) {
  this->numarCard = card1.numarCard;
  this->IBAN = card1.IBAN;
  this->numeCard = card1.numeCard;
  this->codCVC = card1.codCVC;
  this->contactLess = card1.contactLess;
  this->banca = Banca(card1.banca);
}
// 2 constructor cu 2 parametrii
Card::Card(long long numarCard, string IBAN) {
  this->numarCard = numarCard;
  this->IBAN = IBAN;
  this->numeCard = "Anonim";
  this->codCVC = 0;
  this->contactLess = 0;
  this->banca = Banca();
}
Card::Card(Banca banca, int codCVC) {
  this->banca = Banca(banca);
  this->codCVC = codCVC;
  this->contactLess = 0;
  this->numeCard = "Anonim";
  this->numarCard = 0;
  this->IBAN = "noIBAN";
}
// setters
void Card::setNumarCard(long long numarCard) { this->numeCard = numeCard; }
void Card::setIBAN(string IBAN) { this->IBAN = IBAN; }
void Card::setNumeCard(string numeCard) { this->numeCard = numeCard; }
void Card::setCodCVC(int codCVC) { this->codCVC = codCVC; }
void Card::setContactLess(bool contactLess) { this->contactLess = contactLess; }
void Card::setBanca(Banca banca) { this->banca = banca; }
// getters
long long Card::getNumarCard() { return this->numarCard; }
string Card::getIBAN() { return this->IBAN; }
string Card::getNumeCard() { return this->numeCard; }
int Card::getCodCVC() { return this->codCVC; }
bool Card::getContactLess() { return this->contactLess; }
Banca Card::getBanca() { return this->banca; }
// operatorul =
Card Card::operator=(const Card &card1) {
  if (this != &card1) {
    this->numarCard = card1.numarCard;
    this->IBAN = card1.IBAN;
    this->numeCard = card1.numeCard;
    this->codCVC = card1.codCVC;
    this->contactLess = card1.contactLess;
    this->banca = Banca(card1.banca);
  }
  return *this;
}
// op + pt 2 clase
Card operator+(Banca b, Card c) {
  Banca b1;
  b1 = c.getBanca();
  b.setNumarAngajati(b.getNumarAngajati() + b1.getNumarAngajati());
  c.setBanca(b);
  return c;
}
Card operator+(Card c, Banca b) {
  Banca b1;
  b1 = c.getBanca();
  b.setNumarAngajati(b.getNumarAngajati() + b1.getNumarAngajati());
  c.setBanca(b);
  return c;
}

// deconstrucot
Card::~Card() {}
// metoda
void Card::schimbareContactlessCard() {
  if (this->contactLess == 1) {
    cout << "Cardul dumneavostra este contactless!" << endl;
    cout << "Schimbare in proces..." << endl;
    this->contactLess = 0;
    cout << "Cardul dumneavostra nu mai este contactless!" << endl;
  } else {
    cout << "Cardul nu este contactless!" << endl;
    cout << "Scchimbare in proces..." << endl;
    this->contactLess = 1;
    cout << "Cardul a devenit contactless!" << endl;
  }
}
// operatorul ++ () si ()++
Card Card::operator++() {
  // prefix
  ++this->numarCard;
  return Card(this->numarCard, this->IBAN, this->numeCard, this->codCVC,
              this->contactLess, this->banca);
}
Card Card::operator++(int) {
  // sufix
  Card copy(this->numarCard, this->IBAN, this->numeCard, this->codCVC,
            this->contactLess, this->banca);
  this->numarCard++;
  return copy;
}
// operatorul + si operatorul -
Card Card::operator+=(int x) {

  this->numarCard += x;
  return *this;
}
Card Card::operator+(int x) {

  Card aux(*this);
  aux.numarCard = aux.numarCard + x;
  return aux;
}
Card Card::operator+(Card card) {
  card.numarCard = this->numarCard + card.numarCard;
  return card;
}
Card Card::operator-=(int x) {

  this->numarCard += x;
  return *this;
}

Card operator+(int x, Card card) {
  card.numarCard = card.numarCard + x;
  return card;
}
Card Card::operator-(int x) {

  Card aux(*this);
  aux.numarCard = aux.numarCard - x;
  return aux;
}
Card Card::operator-(Card card) {
  card.numarCard = this->numarCard - card.numarCard;
  return card;
}
Card operator-(int x, Card card) {

  card.numarCard = card.numarCard - x;
  return card;
}
// operatorul cast
Card::operator int() { return (double)this->numarCard; }
// operator conditional
bool Card::operator<(const Card &ob) {
  if (this->numarCard < ob.numarCard)
    return true;
  return false;
}
// operatorul ==
bool Card::operator==(const Card &ob) {
  if (this->numarCard == ob.numarCard && this->contactLess == ob.contactLess &&
      this->numeCard == ob.numeCard && this->codCVC == ob.codCVC &&
      this->IBAN == ob.IBAN && this->banca == ob.banca)
    return true;
  return false;
}
// Detalii despre user  ,fiecare user are un card, are metoda sa adauge o suma
// la cheltuieli
class User {
  string nume;
  string prenume;
  float sold;
  int varsta;
  string valuta;
  bool angajat;
  char initialaTata;
  Card card;
  const int idUser;
  static int contorId;
  float *cheltuieliLunaTrecuta;
  int numarCheltuieli;

public:
  // construcotir
  User();
  User(string nume, string prenume);
  User(char initialaTata, float sold);
  User(string nume, string prenume, float sold, int varsta, string valuta,
       bool angajat, char initialaTata, Card card, float *cheltuieliLunaTrecuta,
       int numarCheltuieli);
  User(const User &user1);
  // op =
  User operator=(const User &user1);
  // operatori << >>
  friend ostream &operator<<(ostream &os, const User &ob);
  friend istream &operator>>(istream &os, User &ob);

  void adaugareCheltuialaLunaTrecuta(float cheltuialaNouaLunaTrecuta);

  // Setters
  void setNume(string nume);
  void setPreume(string prenume);
  void setSold(float sold);
  void setVarsta(int varsta);
  void setValuta(string valuta);
  void setAngajat(bool angajat);
  void setInitialaTata(char initialaTata);
  void setCard(Card card);
  void setNumarCheltuieli(int numarCheltuieli);
  void setCheltuieliLunaTrecuta(int *cheltuieliLunaTrecuta);
  // getters
  string getNume();
  string getPrenume();
  float getSold();
  int getVarsta();
  string getValuta();
  bool getAngajat();
  char getInitialaTata();
  Card getCard() const;
  float *getCheltuieliLunaTrecuta() const;
  int getNumarCheltuieli() const;
  // operatori
  float operator[](int index);
  User operator+=(int x);
  User operator++();
  User operator++(int);
  User operator+(int x);
  User operator+(User prod);
  friend User operator+(int x, User prod);
  User operator-=(int x);
  User operator-(int x);
  User operator-(User prod);
  friend User operator-(int x, User prod);
  explicit operator int();
  bool operator==(const User &ob);
  bool operator<(const User &ob);
  ~User();
};
istream &operator>>(istream &in, User &ob) {
  cout << "\nNume: ";
  in >> ob.nume;
  cout << "\nPrenume: ";
  in >> ob.prenume;
  cout << "\nSold: ";
  in >> ob.sold;
  cout << "\nVarsta: ";
  in >> ob.varsta;
  cout << "\nValuta: ";
  in >> ob.valuta;
  cout << "\nAngajat [1-True/0-False] : ";
  in >> ob.angajat;
  cout << "\nInitiala tatalui: ";
  in >> ob.initialaTata;
  cout << "\nNumar cheltuieli luna trecuta: ";
  in >> ob.numarCheltuieli;
  cout << "\nCheltuielile de luna trecuta: ";
  if (ob.cheltuieliLunaTrecuta != NULL)
    delete[] ob.cheltuieliLunaTrecuta;
  ob.cheltuieliLunaTrecuta = new float[ob.numarCheltuieli];
  for (int i = 0; i < ob.numarCheltuieli; i++)
    in >> ob.cheltuieliLunaTrecuta[i];
  cout << "\nDate despre card: ";
  in >> ob.card;
  return in;
}
ostream &operator<<(ostream &out, const User &ob) {
  cout << "\nNume: ";
  out << ob.nume;
  cout << "\nPrenume: ";
  out << ob.prenume;
  cout << "\nSold: ";
  out << ob.sold;
  cout << "\nVarsta: ";
  out << ob.varsta;
  cout << "\nValuta: ";
  out << ob.valuta;
  if (ob.angajat)
    cout << "\nAngajat: DA ";
  else
    cout << "\nAngajat: NU";
  cout << "\nInitiala tatalui: ";
  out << ob.initialaTata;
  cout << "\nNumar cheltuieli luna trecuta: ";
  out << ob.numarCheltuieli;
  cout << "\nCheltuielile de luna trecuta: ";
  for (int i = 0; i < ob.numarCheltuieli; i++)
    out << ob.cheltuieliLunaTrecuta[i] << " ";
  cout << "\nDate despre card: ";
  out << ob.card;
  return out;
}
User::User() : idUser(contorId++) {
  this->nume = "Anonim";
  this->prenume = "Anonim";
  this->sold = 0;
  this->varsta = 0;
  this->valuta = "Nespecificat";
  this->angajat = 0;
  this->initialaTata = 'X';
  this->card = Card();
  this->cheltuieliLunaTrecuta = NULL;
  this->numarCheltuieli = 0;
}
// constructor cu parametrii
User::User(string nume, string prenume, float sold, int varsta, string valuta,
           bool angajat, char initialaTata, Card card,
           float *cheltuieliLunaTrecuta, int numarCheltuieli)
    : idUser(contorId++) {
  this->nume = nume;
  this->prenume = prenume;
  this->sold = sold;
  this->varsta = varsta;
  this->valuta = valuta;
  this->angajat = angajat;
  this->initialaTata = initialaTata;
  this->card = card;
  this->numarCheltuieli = numarCheltuieli;
  this->cheltuieliLunaTrecuta = new float[numarCheltuieli];
  for (int i = 0; i <= this->numarCheltuieli; i++)
    this->cheltuieliLunaTrecuta[i] = cheltuieliLunaTrecuta[i];
}

// constructor de copiere
User::User(const User &user1) : idUser(contorId++) {
  this->nume = user1.nume;
  this->prenume = user1.prenume;
  this->sold = user1.sold;
  this->varsta = user1.varsta;
  this->valuta = user1.valuta;
  this->angajat = user1.angajat;
  this->initialaTata = user1.initialaTata;
  this->card = user1.card;
  this->numarCheltuieli = user1.numarCheltuieli;
  this->cheltuieliLunaTrecuta = new float[numarCheltuieli];
  for (int i = 0; i < this->numarCheltuieli; i++)
    this->cheltuieliLunaTrecuta[i] = user1.cheltuieliLunaTrecuta[i];
}
// constructori cu 2 parametrii
User::User(string nume, string prenume) : idUser(contorId++) {
  this->nume = nume;
  this->prenume = prenume;
  this->sold = 0;
  this->varsta = 0;
  this->valuta = "Nespecificat";
  this->angajat = 0;
  this->initialaTata = 'X';
  this->card = Card();
  this->numarCheltuieli = 0;
  this->cheltuieliLunaTrecuta = NULL;
}

User::User(char initialaTata, float sold) : idUser(contorId++) {
  this->nume = "Anonim";
  this->prenume = "Anonim";
  this->sold = sold;
  this->varsta = 0;
  this->valuta = "Nespecificat";
  this->angajat = 0;
  this->initialaTata = initialaTata;
  this->card = Card();
  this->cheltuieliLunaTrecuta = NULL;
  this->numarCheltuieli = 0;
}
// Setters
void User::setNume(string nume) { this->nume = nume; }
void User::setPreume(string prenume) { this->prenume = prenume; }
void User::setSold(float sold) { this->sold = sold; }
void User::setVarsta(int varsta) { this->varsta = varsta; }
void User::setValuta(string valuta) { this->valuta = valuta; }
void User::setAngajat(bool angajat) { this->angajat = angajat; }
void User::setInitialaTata(char initialaTata) {
  this->initialaTata = initialaTata;
}
void User::setCard(Card card) { this->card = card; }
void User::setNumarCheltuieli(int numarCheltuieli) {
  this->numarCheltuieli = numarCheltuieli;
}
void User::setCheltuieliLunaTrecuta(int *cheltuieliLunaTrecuta) {
  if (cheltuieliLunaTrecuta != NULL)
    delete[] cheltuieliLunaTrecuta;
  for (int i = 0; i < this->numarCheltuieli; i++)
    this->cheltuieliLunaTrecuta[i] = cheltuieliLunaTrecuta[i];
}
// getters
string User::getNume() { return this->nume; }
string User::getPrenume() { return this->prenume; }
float User::getSold() { return this->sold; }
int User::getVarsta() { return this->varsta; }
string User::getValuta() { return this->valuta; }
bool User::getAngajat() { return this->angajat; }
char User::getInitialaTata() { return this->initialaTata; }
Card User::getCard() const { return this->card; }

float *User::getCheltuieliLunaTrecuta() const {
  return this->cheltuieliLunaTrecuta;
}

int User::getNumarCheltuieli() const { return numarCheltuieli; }

User::~User() {
  if (this->cheltuieliLunaTrecuta != NULL)
    delete[] this->cheltuieliLunaTrecuta;
}
// operatorul =
User User::operator=(const User &user1) {
  if (this != NULL) {
    if (this->cheltuieliLunaTrecuta != NULL)
      delete[] this->cheltuieliLunaTrecuta;
    this->nume = user1.nume;
    this->prenume = user1.prenume;
    this->sold = user1.sold;
    this->varsta = user1.varsta;
    this->valuta = user1.valuta;
    this->angajat = user1.angajat;
    this->initialaTata = user1.initialaTata;
    this->card = user1.card;
    this->numarCheltuieli = user1.numarCheltuieli;
    this->cheltuieliLunaTrecuta = new float[numarCheltuieli];
    for (int i = 0; i < this->numarCheltuieli; i++)
      this->cheltuieliLunaTrecuta[i] = user1.cheltuieliLunaTrecuta[i];
  }
  return *this;
}
void User::adaugareCheltuialaLunaTrecuta(float cheltuialaNouaLunaTrecuta) {
  cheltuieliLunaTrecuta[getNumarCheltuieli()] = cheltuialaNouaLunaTrecuta;
  this->numarCheltuieli++;
}
// op + intre 2 clase

// operatorul ++ () si ()++
User User::operator++() {
  // prefix
  ++this->sold;
  return User(this->nume, this->prenume, this->sold, this->varsta, this->valuta,
              this->angajat, this->initialaTata, this->card,
              this->cheltuieliLunaTrecuta, this->numarCheltuieli);
}
User User::operator++(int) {
  // sufix
  User copy(this->nume, this->prenume, this->sold, this->varsta, this->valuta,
            this->angajat, this->initialaTata, this->card,
            this->cheltuieliLunaTrecuta, this->numarCheltuieli);
  this->sold++;
  return copy;
}
// operatorul + si operatorul -
User User::operator+=(int x) {
  this->sold += x;
  return *this;
}

User User::operator+(int x) {

  User aux(*this);
  aux.sold = aux.sold + x;
  return aux;
}
User User::operator+(User prod) {
  prod.sold = this->sold + prod.sold;
  return prod;
}
User operator+(int x, User prod) {

  prod.sold = prod.sold + x;
  return prod;
}
User User::operator-=(int x) {

  this->sold -= x;
  return *this;
}

User User::operator-(int x) {

  User aux(*this);
  aux.sold = aux.sold - x;
  return aux;
}
User User::operator-(User prod) {
  prod.sold = this->sold - prod.sold;
  return prod;
}
User operator-(int x, User prod) {

  prod.sold = prod.sold - x;
  return prod;
}
// operatorul cast
User::operator int() { return (int)this->sold; }
// operator conditional
bool User::operator<(const User &ob) {
  if (this->sold < ob.sold)
    return true;
  return false;
}
// operatorul ==
bool User::operator==(const User &ob) {
  for (int i = 0; i < this->numarCheltuieli; i++)
    if (this->cheltuieliLunaTrecuta[i] != ob.cheltuieliLunaTrecuta[i])
      return false;
  if (this->sold == ob.sold && this->angajat == ob.angajat &&
      this->numarCheltuieli == ob.numarCheltuieli &&
      this->initialaTata == ob.initialaTata && this->valuta == ob.valuta &&
      this->varsta == ob.varsta && this->prenume == ob.prenume &&
      this->nume == ob.nume && this->card == ob.card)
    return true;
  return false;
}
// operatorul []
float User ::operator[](int index) {
  if (0 <= index && index < this->numarCheltuieli)
    return this->cheltuieliLunaTrecuta[index];
  cout << "Index introdus gresit !\n";
}
// detalii despre o plata a unui user , va avea metoda sa trazactioneze bani
// catre cineva
class Plata {
private:
  double sumaPlatita;
  string dataEfectuariiPlatii;
  string destinatar;
  User user;
  long codTranzactie;

public:
  Plata();
  Plata(double sumaPlatita, string dataEfectuariiPlatii);
  Plata(long codTranzactie, string destinatar);
  Plata(double sumaPlatita, string dataEfectuariiPlatii, string destinatar,
        User user, long codTranzactie);
  Plata(const Plata &plata1);

  Plata operator=(const Plata &plata1);
  friend ostream &operator<<(ostream &os, const Plata &ob);
  friend istream &operator>>(istream &os, Plata &ob);

  void plataDirecta(User &destinatar, User &user);

  double getSumaPlatita();
  string &getDataEfectuariiPlatii();
  string &getDestinatar();
  User getUser() const;
  long getCodTranzactie();

  void setSumaPlatita(double sumaPlatita);
  void setDataEfectuariiPlatii(const string &dataEfectuariiPlatii);
  void setDestinatar(const string &destinatar);
  void setUser(User user);
  void setCodTranzactie(long codTranzactie);
  // operatori
  friend Plata operator+(Plata p, User u);
  friend Plata operator+(User u, Plata p);

  bool operator==(const Plata &ob);
  Plata operator+=(int x);
  Plata operator+(int x);
  Plata operator+(Plata prod);
  friend Plata operator+(int x, Plata prod);
  Plata operator-=(int x);
  Plata operator-(int x);
  Plata operator-(Plata prod);
  friend Plata operator-(int x, Plata prod);
  Plata operator++();
  Plata operator++(int);
  explicit operator int();
  bool operator<(const Plata &ob);

  ~Plata();
};
istream &operator>>(istream &in, Plata &ob) {
  cout << "\nSuma platita: ";
  in >> ob.sumaPlatita;
  cout << "\nData efectuarii platii  (ex : 12/03/2022 ) : ";
  in >> ob.dataEfectuariiPlatii;
  cout << "\nNume destinatar: ";
  in >> ob.destinatar;
  cout << "\nCod numeric de tranzactie: ";
  in >> ob.codTranzactie;
  cout << "\nDate user : ";
  in >> ob.user;
  return in;
}
ostream &operator<<(ostream &out, const Plata &ob) {
  cout << "\nSuma platita: ";
  out << ob.sumaPlatita;
  cout << "\nData efectuarii platii: ";
  out << ob.dataEfectuariiPlatii;
  cout << "\nNume destinatar: ";
  out << ob.destinatar;
  cout << "\nCod tranzactie: ";
  out << ob.codTranzactie;
  cout << "\nDate despre user: ";
  out << ob.user;
  return out;
}
Plata::Plata() {
  this->sumaPlatita = 0;
  this->dataEfectuariiPlatii = "Anonima";
  this->destinatar = "Anonim";
  this->user = User();
  this->codTranzactie = 0;
}
// constructor cu parametrii
Plata::Plata(double sumaPlatita, string dataEfectuariiPlatii, string destinatar,
             User user, long codTranzactie) {
  this->sumaPlatita = sumaPlatita;
  this->dataEfectuariiPlatii = dataEfectuariiPlatii;
  this->destinatar = destinatar;
  this->user = User(user);
  this->codTranzactie = codTranzactie;
}
Plata::Plata(double sumaPlatita, string dataEfectuariiPlatii) {
  this->sumaPlatita = sumaPlatita;
  this->dataEfectuariiPlatii = dataEfectuariiPlatii;
  this->user = User();
  this->destinatar = "Anonim";
  this->codTranzactie = 0;
}
Plata::Plata(long codTranzactie, string destinatar) {
  this->sumaPlatita = 0;
  this->dataEfectuariiPlatii = "Anonima";
  this->user = User();
  this->destinatar = destinatar;
  this->codTranzactie = codTranzactie;
}

// constructor de copiere
Plata::Plata(const Plata &plata1) {
  this->sumaPlatita = plata1.sumaPlatita;
  this->dataEfectuariiPlatii = plata1.dataEfectuariiPlatii;
  this->destinatar = plata1.destinatar;
  this->user = plata1.user;
  this->codTranzactie = plata1.codTranzactie;
}
// setters
void Plata::setSumaPlatita(double sumaPlatita) {
  this->sumaPlatita = sumaPlatita;
}
void Plata::setDataEfectuariiPlatii(const string &dataEfectuariiPlatii) {
  this->dataEfectuariiPlatii = dataEfectuariiPlatii;
}
void Plata::setDestinatar(const string &destinatar) {
  this->destinatar = destinatar;
}
void Plata::setUser(User user) { this->user = user; }
void Plata::setCodTranzactie(long codTranzactie) {
  this->codTranzactie = codTranzactie;
}
// getters
double Plata::getSumaPlatita() { return sumaPlatita; }
string &Plata::getDataEfectuariiPlatii() { return dataEfectuariiPlatii; }
string &Plata::getDestinatar() { return destinatar; }
User Plata::getUser() const { return this->user; }
long Plata::getCodTranzactie() { return codTranzactie; }

// operatorul =
Plata Plata::operator=(const Plata &plata1) {
  if (this != &plata1) {
    this->sumaPlatita = plata1.sumaPlatita;
    this->dataEfectuariiPlatii = plata1.dataEfectuariiPlatii;
    this->destinatar = plata1.destinatar;
    this->user = plata1.user;
    this->codTranzactie = plata1.codTranzactie;
  }
  return *this;
}
// deconstructor
Plata::~Plata() {}
void Plata::plataDirecta(User &destinatar, User &user) {
  if (this->sumaPlatita <= user.getSold()) {
    destinatar.setSold(destinatar.getSold() + sumaPlatita);
    user.setSold(user.getSold() - sumaPlatita);
  } else
    cout << "Introduceti o suma mai mica de " << this->user.getSold()
         << " pentru a valida plata dorita .\n";
}
// op+intre 2 clase
Plata operator+(Plata p, User u) {
  p.sumaPlatita = p.sumaPlatita + u.getSold() * 0, 1;
  return p;
}
Plata operator+(User u, Plata p) {
  p.sumaPlatita = p.sumaPlatita + u.getSold() * 0, 1;
  return p;
}
// operatorul ++ () si ()++
Plata Plata::operator++() {
  // prefix
  ++this->sumaPlatita;
  return Plata(this->sumaPlatita, this->dataEfectuariiPlatii, this->destinatar,
               this->user, this->codTranzactie);
}
Plata Plata::operator++(int) {
  // sufix
  Plata copy(this->sumaPlatita, this->dataEfectuariiPlatii, this->destinatar,
             this->user, this->codTranzactie);
  this->sumaPlatita++;
  return copy;
}
// operatorul + si operatorul -
Plata Plata::operator+=(int x) {

  this->sumaPlatita += x;
  return *this;
}
Plata Plata::operator+(int x) {

  Plata aux(*this);
  aux.sumaPlatita = aux.sumaPlatita + x;
  return aux;
}
Plata Plata::operator+(Plata prod) {

  prod.sumaPlatita = this->sumaPlatita + prod.sumaPlatita;
  return prod;
}
Plata operator+(int x, Plata prod) {

  prod.sumaPlatita = prod.sumaPlatita + x;
  return prod;
}
Plata Plata::operator-=(int x) {

  this->sumaPlatita -= x;
  return *this;
}
Plata Plata::operator-(int x) {

  Plata aux(*this);
  aux.sumaPlatita = aux.sumaPlatita - x;
  return aux;
}
Plata Plata::operator-(Plata prod) {

  prod.sumaPlatita = this->sumaPlatita - prod.sumaPlatita;
  return prod;
}
Plata operator-(int x, Plata prod) {

  prod.sumaPlatita = prod.sumaPlatita - x;
  return prod;
}
// operatorul cast
Plata::operator int() { return (int)this->sumaPlatita; }
// operator conditional
bool Plata::operator<(const Plata &ob) {
  if (this->sumaPlatita < ob.sumaPlatita)
    return true;
  return false;
}
// operatorul ==
bool Plata::operator==(const Plata &ob) {
  if (this->sumaPlatita == ob.sumaPlatita && this->getUser() == ob.getUser() &&
      this->codTranzactie == ob.codTranzactie &&
      this->destinatar == ob.destinatar &&
      this->dataEfectuariiPlatii == ob.dataEfectuariiPlatii)
    return true;
  return false;
}
int User::contorId = 10;
int main() {

  vector<Banca> lista_banci;
  vector<Card> lista_carduri;
  vector<User> lista_user;
  vector<Plata> lista_plata;
  vector<Banca> deletable_bank;
  vector<Card> deletable_card;
  vector<User> deletable_user;
  vector<Plata> deletable_plata;

  int k = 1, comanda, comanda1, comanda2;
  while (k == 1) {
    cout << endl
         << "1. Pentru adaugare\n2. Pentru afisare\n3. Pentru actualizare "
            "date\n4. Pentru stergerea datelor \n5. "
            "Pentru transfer bancar intre 2 useri \n6. Vechimea unei banci\n7. "
            "Pentru iesire.\n";
    cin >> comanda;
    switch (comanda) {
    // adaugare
    case 1: {
      cout << endl
           << "\nCe doriti sa adaugati?\n1. Pentru Banca\n2. Pentru "
              "Card\n3. Pentru User\n4. Pentru Plata\n5. Pentru intoarcere "
              "meniu "
              "principal: \n";
      cin >> comanda1;
      switch (comanda1) {
      case 1: {
        cout << endl
             << "Doriti sa adaugati:\n1. O banca cu toate datele\n2. O banca "
                "cu numarul de angajati si cu locatia sediului\n3. O banca cu "
                "numele ei si anul infiintarii\n4. Pentru intoarcere meniu "
                "principal:\n";
        cin >> comanda2;
        switch (comanda2) {
        case 1: {
          Banca b1;
          cin >> b1;
          lista_banci.push_back(b1);
          deletable_bank.push_back(b1);
          break;
        }
        case 2: {
          int numarAngajati;
          char *locatieSediu = new char[100];
          cout << "Numarul de angajati : \n";
          cin >> numarAngajati;
          cout << "Locatia sediului este : \n";
          cin >> locatieSediu;

          Banca b1(numarAngajati, locatieSediu);
          lista_banci.push_back(b1);
          deletable_bank.push_back(b1);

          break;
        }
        case 3: {
          string numeBanca;
          int anulInfiintare;
          cout << "Numele bancii : \n";
          cin >> numeBanca;
          cout << "Anul infiintarii : \n";
          cin >> anulInfiintare;
          Banca b1(numeBanca, anulInfiintare);
          lista_banci.push_back(b1);
          deletable_bank.push_back(b1);

          break;
        }
        case 4: {
          break;
        }
        default: {
          cout << "Ati introdus o varianta gresita\n Va rugam sa incercati din "
                  "nou!\n";
          break;
        }
        }
      } break;
      case 2: {
        cout << "Doriti sa adaugati :\n1. Card cu toate datele\n2. Card doar "
                "cu numarul cardului si IBAN\n3. Card cu banca si cod-ul CVC  "
                "\n4. Intoarcere la meniul precedent\n";
        cin >> comanda2;
        switch (comanda2) {
        case 1: {
          Card c;
          cin >> c;
          Banca b;
          b = c.getBanca();
          lista_banci.push_back(b);
          lista_carduri.push_back(c);
          deletable_card.push_back(c);
          break;
        }
        case 2: {
          cout << "Numar card :\n";
          long long numarCard;
          string IBAN;
          cin >> numarCard;
          cout << "IBAN :\n";
          cin >> IBAN;
          Card c(numarCard, IBAN);
          Banca b;
          b = c.getBanca();
          lista_banci.push_back(b);
          lista_carduri.push_back(c);
          deletable_card.push_back(c);

          break;
        }
        case 3: {
          cout << "Banca ce corespunde cu cardul : \n";
          cout << "Va rugam sa alegeti din bancile :\n";
          for (int i = 0; i < lista_banci.size(); i++)
            cout << i + 1 << ". Pentru " << lista_banci[i] << "\n";
          int i;
          cin >> i;
          cout << "Cod CVC :\n";
          int codCVC;
          cin >> codCVC;
          Card c(lista_banci[i - 1], codCVC);
          Banca b;
          b = c.getBanca();
          lista_banci.push_back(b);
          lista_carduri.push_back(c);
          deletable_card.push_back(c);

          cout << "Cardul a fost adaugat cu succes !\n";
          break;
        }
        case 4: {
          break;
        }
        default: {
          cout << "Ati introdus o varianta gresita\n";
          break;
        } break;
        }
        break;
      }
      case 3: {
        cout << "Ati ales sa adaugati user !\nDoriti sa adaugati :\n1. User cu "
                "toate datele\n2. User cu nume si prenume\n3. User cu initiala "
                "tatalui si cu sold  \n4. Intoarcere la meniul precedent\n";
        cin >> comanda2;
        switch (comanda2) {
        case 1: {
          User u1;
          cin >> u1;
          cout << "User adaugat cu succes ! \n";
          lista_user.push_back(u1);
          Card c;
          c = u1.getCard();
          Banca b;
          b = c.getBanca();
          lista_banci.push_back(b);
          lista_carduri.push_back(c);
          deletable_user.push_back(u1);

          break;
        }
        case 2: {
          cout << "Nume :\n";
          string nume, prenume;
          cin >> nume;
          cout << "Prenume :\n";
          cin >> prenume;
          User u1(nume, prenume);
          Card c;
          c = u1.getCard();
          Banca b;
          b = c.getBanca();
          lista_user.push_back(u1);
          lista_banci.push_back(b);
          lista_carduri.push_back(c);
          deletable_user.push_back(u1);

          cout << "User adaugat cu succes ! \n";
          break;
        }
        case 3: {
          char initialaTata;
          float sold;
          cout << "Initiata tatalui : \n";
          cin >> initialaTata;
          cout << "Sold : \n";
          cin >> sold;
          User u1(initialaTata, sold);
          lista_user.push_back(u1);
          Card c;
          c = u1.getCard();
          Banca b;
          b = c.getBanca();
          lista_banci.push_back(b);
          lista_carduri.push_back(c);
          deletable_user.push_back(u1);
          cout << "User adaugat cu succes ! \n";
          break;
        }
        case 4: {
          break;
        }
        default: {
          cout << "Ati introdus o varianta gresita\n";
          break;
        } break;
        }
      } break;
      case 4: {
        cout << "Ati ales sa adaugati o plata noua !\nDoriti sa adaugati o "
                "plata cu :\n1. Toate datele\n2. Suma platita si data "
                "efectuarii platii\n3. Cod tranzactie si "
                "destinatar\n4. Intoarcere la meniu principal\n";
        cin >> comanda2;
        switch (comanda2) {
        case 1: {
          Plata p;
          cin >> p;
          lista_plata.push_back(p);
          User u = p.getUser();
          Card c;
          c = u.getCard();
          Banca b;
          b = c.getBanca();
          lista_banci.push_back(b);
          lista_carduri.push_back(c);
          lista_user.push_back(u);
          deletable_plata.push_back(p);

          cout << "Plata a fost creata ! \n";
          break;
        }
        case 2: {
          double sumaPlatita;
          string dataEfectuariiPlatii;
          cout << "Suma platita este : \n";
          cin >> sumaPlatita;
          cout << "Data efectuarii platii  (ex : 12/03/2022 ) : \n";
          cin >> dataEfectuariiPlatii;
          Plata p(sumaPlatita, dataEfectuariiPlatii);
          lista_plata.push_back(p);
          User u = p.getUser();
          Card c;
          c = u.getCard();
          Banca b;
          b = c.getBanca();
          lista_banci.push_back(b);
          lista_carduri.push_back(c);
          lista_user.push_back(u);
          deletable_plata.push_back(p);

          cout << "Plata a fost creata ! \n";
          break;
        }
        case 3: {
          string destinatar;
          long codTranzactie;
          cout << "Nume destinatar :\n";
          cin >> destinatar;
          cout << "Cod tranzitie : \n";
          cin >> codTranzactie;
          Plata p(codTranzactie, destinatar);
          User u = p.getUser();
          Card c;
          c = u.getCard();
          Banca b;
          b = c.getBanca();
          lista_banci.push_back(b);
          lista_carduri.push_back(c);
          lista_user.push_back(u);
          lista_plata.push_back(p);
          deletable_plata.push_back(p);
        }
        case 4: {
          break;
        }
        default: {
          cout << "Ati introdus o varianta gresita\n";
          break;
        } break;
        }
      }
      }

      break;
    }
      // afisare
    case 2: {
      cout << "Ce doriti sa afisat ?\n1. Date despre o banca\n2. Date despre "
              "un Card\n3. Date despre un user\n4. Date despre o plata\n5. "
              "Intoarcere la meniul principal\n";
      cin >> comanda1;
      switch (comanda1) {
      case 1: {
        if (lista_banci.size() != NULL) {
          for (int i = 0; i < lista_banci.size(); i++)
            cout << "Tastati " << i + 1 << " pentru banca :\n"
                 << lista_banci[i].getNumeBanca() << "\n";
          int i;
          cin >> i;
          cout << "\n" << lista_banci[i - 1];
        } else
          cout << "Pentru a afisa o banca este nevoie sa adaugati una ! \n";
        break;
      }
      case 2: {
        if (lista_carduri.size() != NULL) {
          for (int i = 0; i < lista_carduri.size(); i++)
            cout << "\n"
                 << "Tastati " << i + 1 << " pentru cardul cu numele:\n"
                 << lista_carduri[i].getNumeCard() << "\n";
          int i;
          cin >> i;
          cout << lista_carduri[i - 1];
        } else
          cout << "Pentru a afisa un card este nevoie sa adaugati unul inainte "
                  "! \n";
        break;
      }
      case 3: {
        if (lista_user.size() != NULL) {
          for (int i = 0; i < lista_user.size(); i++)
            cout << "\n"
                 << "Tastati " << i + 1 << " pentru userul  :\n"
                 << lista_user[i].getNume() << "\n";
          int i;
          cin >> i;
          cout << lista_user[i - 1];
        } else
          cout << "Pentru a afisa un user este nevoie sa adaugati unul inainte "
                  "! \n";
        break;
      }
      case 4: {
        if (lista_plata.size() != NULL) {
          for (int i = 0; i < lista_plata.size(); i++)
            cout << "\n"
                 << "Tastati " << i + 1
                 << " pentru plata cu codul de tranzactie :\n"
                 << lista_plata[i].getCodTranzactie() << "\n";
          int i;
          cin >> i;
          cout << lista_plata[i - 1];
        } else
          cout << "Pentru a afisa o plata este nevoie sa adaugati una inainte "
                  "! \n";
        break;
      }
      case 5: {
        break;
      }
      default: {
        cout << "Ati introdus o varianta gresita\n";
        break;
      }
      }
      break;
    }

    // actualizare
    case 3: {
      cout << "Ce doriti sa actualizari ?\n1. O banca\n2. Un card\n3. Un "
              "user\n4. O plata\n5. Inapoi la meniul principal\n";
      cin >> comanda1;
      switch (comanda1) {
      case 1: {
        if (lista_banci.size() != NULL) {
          cout << "Ce banca doriti sa actualizati ?\n";
          for (int i = 0; i < lista_banci.size(); i++)
            cout << "Pentru banca cu numele " << lista_banci[i].getNumeBanca()
                 << " introduceti " << i + 1 << " .\n";
          int i;
          cin >> i;
          cout << "Ati selectat banca cu numele "
               << lista_banci[i - 1].getNumeBanca()
               << " !\nCe doriti sa actualizati :\n1. Numele bancii\n2. "
                  "Numarul de angajati\n3. Locatia sediului central\n4. Anul "
                  "de infiintare a bancii\n5.Inapoi la meniul principal\n ";
          cin >> comanda2;
          switch (comanda2) {
          case 1: {
            string numeBanca;
            cout << "Numele bancii doriti sa fie : \n";
            cin >> numeBanca;
            lista_banci[i - 1].setNumeBanca(numeBanca);
            cout << "Numele a fost actualizat !\n";
            break;
          }
          case 2: {
            int numarAngajati;
            cout << "Doriti sa adaugati doar un angajat? \n1. Da\n2. Nu\n";
            int j;
            cin >> j;
            if (j == 1) {
              lista_banci[i - 1]++;
              cout << "La banca cu numele " << lista_banci[i - 1].getNumeBanca()
                   << " s-a adaugat un angajat !\n";
            } else {
              cout << "Cati angajati doriti sa aiba banca in total ? \n";
              cin >> numarAngajati;
              lista_banci[i - 1].setNumarAngajati(numarAngajati);
              cout << "Numar de angajati actualizat !\n";
            }
            break;
          } break;
          case 3: {
            char *locatieSediu = new char[1000];
            cout << "Care doriti sa fie noua locatie a sediului central ? \n";
            cin >> locatieSediu;
            lista_banci[i - 1].setLocatieSediu(locatieSediu);
            cout << "Locatia a fost actualizata !\n";
            break;
          }
          case 4: {
            int anInfiintare;
            cout << "Care doriti sa fie noul an de infiintare a bancii ?\n";
            cin >> anInfiintare;
            lista_banci[i - 1].setAnInfiintare(anInfiintare);
            cout << "Anul de infiintare a bancii a fost acutualizat !\n";
            break;
          }
          case 5: {
            break;
          }
          default: {
            cout << "Ati introdus o varianta gresita ! \n";
            break;
          }
          }
        } else {
          cout << "Pentru a putea actualiza o banca este nevoie sa adaugati "
                  "una !\n";
          break;
        }
        break;

      } break;
      case 2: {
        if (lista_carduri.size() != NULL) {
          cout << "Ce card doriti sa actualizati ?\n";
          for (int i = 0; i < lista_carduri.size(); i++)
            cout << "Pentru cardul cu numele " << lista_carduri[i].getNumeCard()
                 << " introduceti " << i + 1 << " .\n";
          int i;
          cin >> i;
          cout << "Ati ales cardul cu numele "
               << lista_carduri[i - 1].getNumeCard()
               << " .\nCe doriti sa actualizati?\n1. Numarul cardului\n2. "
                  "IBAN-ul\n3. Numele cardului\n4. Codul CVC\n5. Optinunea "
                  "contactless\n6. Banca\n7. Intoarcere meniul principal\n";
          cin >> comanda2;
          switch (comanda2) {
          case 1: {
            long long numarCard;
            cout << "Numar card nou:\n";
            cin >> numarCard;
            lista_carduri[i - 1].setNumarCard(numarCard);
            cout << "Numarul a fost actualizat !\n";
            break;
          }
          case 2: {
            string IBAN;
            cout << "IBAN nou :\n";
            cin >> IBAN;
            lista_carduri[i - 1].setIBAN(IBAN);
            cout << "IBAN-ul a fost actualizat !\n";
            break;
          }
          case 3: {
            string numeCard;
            cout << "Nume card nou :\n";
            cin >> numeCard;
            lista_carduri[i - 1].setNumeCard(numeCard);
            cout << "Numele cardului a fost actualizat !\n";
            break;
          }
          case 4: {
            int codCVC;
            cout << "Cod CVC nou :\n";
            cin >> codCVC;
            lista_carduri[i - 1].setCodCVC(codCVC);
            cout << "Codul CVC a fost acutalizat ! \n";
            break;
          }
          case 5: {
            lista_carduri[i - 1].schimbareContactlessCard();
            break;
          }
          case 6: {

            cout << "Dorit sa :\n1. Schimbati banca actuala cu una deja "
                    "existenta\n2. Schimbati banca actuala cu una ce urmeaza "
                    "sa o creati \n3. Inapoi la meniul principal\n";
            int h;
            cin >> h;
            switch (h) {
            case 1: {
              for (int y = 0; y < lista_banci.size(); y++)
                cout << y + 1 << ". pentru banca cu numele "
                     << lista_banci[y].getNumeBanca() << "\n";
              int y;
              cin >> y;
              Banca b = lista_banci[y - 1];
              lista_carduri[i - 1].setBanca(b);
              cout << "Banca a fost actualizata !\n";
              break;
            }
            case 2: {
              Banca b;
              cin >> b;
              lista_carduri[i - 1].setBanca(b);
              lista_banci.push_back(b);
              cout << "Banca a fost actualizata !\n";
              break;
            }
            case 3: {
              break;
            }
            default: {
              cout << "Ati introdus o varianta gresita !\n";
              break;
            }
            }
          }
          }
        } else {
          cout << "Pentru a putea actualiza un card este nevoie sa adaugati "
                  "unul !\n";
          break;
        }
      } break;
      case 3: {
        if (lista_user.size() != NULL) {
          cout << "Ce user doriti sa actualizati ?\n";
          for (int i = 0; i < lista_user.size(); i++)
            cout << "Pentru userul cu numele " << lista_user[i].getNume()
                 << " introduceti " << i + 1 << " .\n";
          int i;
          cin >> i;
          cout << "Ati ales user cu numele " << lista_user[i - 1].getNume()
               << ".\nCe doriti sa actualizari ?\n1. Numele \n2. Prenumele"
                  "\n3. Soldul\n4. Varsta\n5. Valuta\n6. Daca este angajat sau "
                  "nu\n7.Initiala tatalui\n8. Cardul asociat userului\n9. "
                  "Adauga o cheltuiala la luna trecuta\n10. Inapoi la meniul "
                  "principal\n";
          int comanda4;
          cin >> comanda4;
          switch (comanda4) {
          case 1: {
            string nume;
            cout << "Nume utilizator nou :\n";
            cin >> nume;
            lista_user[i - 1].setNume(nume);
            cout << "Numele a fost actualizat !\n";
            break;
          }
          case 2: {
            string prenume;
            cout << "Preume utilizator nou :\n";
            cin >> prenume;
            lista_user[i - 1].setPreume(prenume);
            cout << "Preumele a fost actualizat !\n";
            break;
          }
          case 3: {
            float sold;
            cout << "Sold nou :\n";
            cin >> sold;
            lista_user[i - 1].setSold(sold);
            cout << "Soldul a fost actualizat !\n";
            break;
          }
          case 5: {
            string valuta;
            cout << "Valuta :\n";
            cin >> valuta;
            lista_user[i - 1].setValuta(valuta);
            cout << "Valut a fost actualizata !\n";
            break;
          }
          case 4: {
            int varsta;
            cout << "Varsta noua :\n";
            cin >> varsta;
            lista_user[i - 1].setVarsta(varsta);
            cout << "Varsta a fost actualizata !\n";
            break;
          }
          case 6: {
            bool angajat;
            cout << "Schimba in :\n1. Angajat\n2. Liber profesionist\n";
            int imp;
            cin >> imp;
            switch (imp) {
            case 1: {
              lista_user[i - 1].setAngajat(1);
              cout << "Statusul userului a fost actualizat cu succes !\n";
              break;
            }
            case 2: {
              lista_user[i - 1].setAngajat(0);
              cout << "Statusul userului a fost actualizat cu succes !\n";

              break;
            }
            default: {
              cout << "Ati introdus o varianta gresita !\n";
              break;
            }
            }
            break;
          }
          case 7: {
            char initialaTata;
            cout << "Initiala tatalui :\n";
            cin >> initialaTata;
            lista_user[i - 1].setInitialaTata(initialaTata);
            cout << "Initiala tatalui a fost actualizata cu succes !\n";
            break;
          }
          case 8: {
            cout << "Doriti sa:\n1. Schimbati cardul cu unul deja existent\n2. "
                    "Schimba cardul cu unul ce urmeaza sa-l creati !\n3. "
                    "Inapoi la meniul principal\n";
            int k;
            cin >> k;
            switch (k) {
            case 1: {
              for (int i = 0; i < lista_carduri.size(); i++)
                cout << "Pentru a schimba cardul curent cu cardul cu numele "
                     << lista_carduri[i].getNumeCard() << " introduceti "
                     << i + 1 << " .\n";
              int y;
              cin >> y;
              lista_user[i - 1].setCard(lista_carduri[y - 1]);
              cout << "Card schimbat cu succes !\n";
              break;
            } break;
            case 2: {
              Card c;
              cin >> c;
              lista_user[i - 1].setCard(c);
              cout << "Cardul a fost actualizat !\n";
              break;
            } break;
            case 3: {
              break;
            } break;
            default: {
              cout << "Ati introdus o varianta gresita !\n";
            } break;
            }
            break;
          }
          case 9: {
            cout << "Ce suna are chetuiala :";
            float cheltuialaNoua;
            cin >> cheltuialaNoua;
            lista_user[i - 1].adaugareCheltuialaLunaTrecuta(cheltuialaNoua);
            cout << "Cheltuiala a fost adaugata !";
            break;
          }
          case 10: {
            break;
          }
          default: {
            cout << "Ati introdus o varianta gresita !\n";
            break;
          }
          }

        } else {
          cout << "Pentru a actualiza un user este nevoie sa adaugati unul !\n";
          break;
        }

      } break;
      case 4: {
        if (lista_plata.size() != NULL) {
          cout << "Ce plata doriti sa actualizati ?\n";
          for (int i = 0; i < lista_plata.size(); i++)
            cout << "Pentru userul cu numele "
                 << lista_plata[i].getUser().getNume() << " introduceti "
                 << i + 1 << " .\n";
          int i;
          cin >> i;
          cout << "Ati ales plata cu numele "
               << lista_plata[i - 1].getUser().getNume()
               << " .\nCe doriti sa actualizati ?\n1. Suma platita\n2. Data "
                  "efectuarii platii\n3. Numele destinatarului\n4. Userul care "
                  "face plata\n5. Codul tranzitiei \n6. Intoarcere la meniul "
                  "principal\n";
          int comanda4;
          cin >> comanda4;
          // double sumaPlatita;
          //   string dataEfectuariiPlatii;
          //   string destinatar;
          //   User user;
          //   long codTranzactie;
          switch (comanda4) {
          case 1: {
            cout << "Suma noua platita \n";
            double sumaPlata;
            cin >> sumaPlata;
            lista_plata[i - 1].setSumaPlatita(sumaPlata);
            cout << "Suma a fost actualizata ! \n";
            break;
          } break;
          case 2: {
            cout << "Noua data a efectuarii platii \n";
            string dataEfectuariiPlatii;
            cin >> dataEfectuariiPlatii;
            lista_plata[i - 1].setDataEfectuariiPlatii(dataEfectuariiPlatii);
            cout << "Data a fost actualizata !\n";
            break;
          } break;
          case 3: {
            cout << "Noul nume al destinatarului \n";
            string numeDestinatar;
            cin >> numeDestinatar;
            lista_plata[i - 1].setDestinatar(numeDestinatar);
            cout << "Numele a fost actualizat! \n";
            break;
          } break;
          case 4: {
            cout << "Doriti sa creati un user nou sau actualizati cu unul deja "
                    "existent?\n1. User nou\n2. Unul deja existent \n3. "
                    "Intoarcere la meniul principal \n";
            int comanda5;
            cin >> comanda5;
            switch (comanda5) {
            case 1: {
              cout << "Noul user \n";
              User u;
              cin >> u;
              lista_plata[i - 1].setUser(u);
              cout << "Userul a fost actualizat !\n";
              break;
            } break;
            case 2: {
              for (int i = 0; i < lista_user.size(); i++)
                cout << "Pentru a schimba userul curent cu userul cu numele "
                     << lista_user[i].getNume() << " introduceti " << i + 1
                     << " .\n";
              int y;
              cin >> y;
              lista_plata[i - 1].setUser(lista_user[y - 1]);
              cout << "Userul a fost actualizat !\n";
              break;

            } break;
            case 3: {
              break;
            } break;
            default: {
              cout << "Ati introdus o varianta gresita !";
              break;
            } break;
            }

          } break;
          case 5: {
            cout << "Noul cod al tranzactiei \n";
            long codTranzactie;
            cin >> codTranzactie;
            lista_plata[i - 1].setCodTranzactie(codTranzactie);
            cout << "Codul a fost actualizat !\n";
            break;
          } break;
          }
        } else {
          cout << "Pentru a actualiza o plata este nevoie sa adaugati una !\n";
          break;
        }
      } break;
      }
    } break;
      // stergere
    case 4: {
      cout << "Ce doriti sa stergeti?\n1. O banca \n2. Un card\n3. Un user\n4. "
              "O plata\n5. Inapoi la meniul principal \n";
      cin >> comanda2;
      switch (comanda2) {
      case 1: {
        if (deletable_bank.size() != NULL) {
          cout << "Ce banca doriti sa stergeti ?\n";
          for (int i = 0; i < deletable_bank.size(); i++)
            cout << "Pentru banca cu numele "
                 << deletable_bank[i].getNumeBanca() << " introduceti " << i + 1
                 << " .\n";
          int y;
          cin >> y;
          int k;
          for (int i = 0; i < lista_banci.size(); i++)
            if (lista_banci[i] == deletable_bank[y - 1])
              k = i;
          lista_banci.erase(lista_banci.begin() + k);
          deletable_card.erase(deletable_card.begin() + y - 1);
          cout << "Banca a fost stearsa cu succes !\n";
          break;
        } else {
          cout << "Pentru a putea sterge o banca mai intai trebuie adaugata "
                  "una !\n";
          break;
        }
      } break;
      case 2: {
        if (deletable_card.size()) {
          cout << "Ce card doriti sa stergeti?\n";
          for (int i = 0; i < deletable_card.size(); i++)
            cout << "Pentru a sterge cardul cu numele "
                 << deletable_card[i].getNumeCard() << " introduceti " << i + 1
                 << " .\n";
          int y;
          cin >> y;
          int k;
          for (int i = 0; i < lista_carduri.size(); i++)
            if (lista_carduri[i] == deletable_card[y - 1])
              k = i;
          lista_carduri.erase(lista_carduri.begin() + k);
          deletable_card.erase(deletable_card.begin() + y - 1);
          cout << "Cardul a fost sters cu succes !\n";
          break;

        } else {
          cout << "Pentru a putea sterge un card mai intai trebuie adaugat "
                  "unul !\n";
          break;
        }
      }
      case 3: {
        if (deletable_user.size()) {
          cout << "Ce user doriti sa stergeti ?\n";
          for (int i = 0; i < deletable_user.size(); i++)
            cout << "Pentru a sterge user cu numele "
                 << deletable_user[i].getNume() << " introduceti " << i + 1
                 << " .\n";
          int y;
          cin >> y;
          int k;
          for (int i = 0; i < lista_user.size(); i++)
            if (lista_user[i] == deletable_user[y - 1])
              k = i;
          lista_user.erase(lista_user.begin() + k);
          deletable_user.erase(deletable_user.begin() + y - 1);
          cout << "Userul a fost sters cu succes !\n";
          break;
        } else {
          cout << "Pentru a putea sterge un user mai intai trebuie sa adaugati "
                  "unul !\n";
          break;
        }
      }
      case 4: {
        if (deletable_plata.size()) {
          cout << "Ce plata doriti sa stergeti ?\n";
          for (int i = 0; i < deletable_plata.size(); i++)
            cout << "Pentru a alege plata cu numele de utilizator "
                 << deletable_plata[i].getUser().getNume() << " introduceti "
                 << i + 1 << " .\n";
          int y, k;
          cin >> y;
          for (int i = 0; i < lista_plata.size(); i++)
            if (lista_plata[i] == deletable_plata[y - 1])
              k = i;
          lista_plata.erase(lista_plata.begin() + k);
          deletable_plata.erase(deletable_plata.begin() + y - 1);
          cout << "Plata a fost stearsa cu succes !\n";
          break;
        } else {
          cout << "Pentru a putea sterge o plata mai intai trebuie sa adaugati "
                  "una !\n";
          break;
        }
      }
      }
    } break;
      // plata user catre user
    case 5: {
      if (lista_user.size() >= 2) {
        cout << "Alegeti un user care sa faca plata ! \n";
        for (int i = 0; i < lista_plata.size(); i++)
          cout << endl
               << "Tastati " << i + 1 << " pentru \n"
               << lista_plata[i].getUser().getNume() << " "
               << lista_plata[i].getUser().getPrenume() << " trimite "
               << lista_plata[i].getSumaPlatita() << " de "
               << lista_plata[i].getUser().getValuta() << " ! \n";
        int i;
        cin >> i;
        cout << "Alegeti un user care sa primeasca banii\n";

        for (int j = 0; j < lista_user.size(); j++)
          cout << endl
               << "\nTastati " << j + 1 << " pentru \n"
               << lista_user[j].getNume() << " " << lista_user[j].getPrenume()
               << "\n";
        int j;
        cin >> j;
        User u1, u2;
        u1 = lista_plata[i - 1].getUser();
        u2 = lista_user[j - 1];
        lista_plata[i - 1].plataDirecta(u2, u1);
        for (int k = 0; k < lista_user.size(); k++)
          if (lista_user[k] == lista_plata[i - 1].getUser()) {
            lista_user[k] = u1;
            break;
          }
        lista_plata[i - 1].setUser(u1);
        lista_user[j - 1] = u2;
        cout << "Doriti sa vedeti "
                "datele "
                "utilizatorilor ?\n1. Da , doresc !\n2. Nu, doresc sa ma "
                "intorc la meniul principal\n";
        int commanda4;
        cin >> commanda4;

        switch (commanda4) {
        case 1: {
          cout << lista_user[j - 1] << endl;
          cout << lista_plata[i - 1].getUser() << endl;
          break;
        }
        default: {
          cout << "Ati introdus o varianta gresita !\n";
          break;
        } break;
        }

      } else
        cout << "Este nevoie de minim 2 user pentru a putea face un "
                "transfer "
                "intre useri ! \n";
      break;
    }
    case 6: {
      cout << "Pentru ce banca doriti sa aflati vechimea ?\n";
      for (int i = 0; i < lista_banci.size(); i++)
        cout << "Pentru banca cu numele " << lista_banci[i].getNumeBanca()
             << " introduceti " << i + 1 << " .\n";
      int y;
      cin >> y;
      lista_banci[y - 1].aniVechime();
      break;
    } break;
    case 7: {
      k = 0;
      break;
    }
    default: {
      cout << "Ati introdus o varianta gresita\n";
      break;
    }
    }
  }

  return 0;
}