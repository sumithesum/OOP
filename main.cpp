#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

ifstream  fin("tastatura.txt");

class joc {
private:
    unsigned  int cantitate;
    float rating;
    int pret;
    char *name;
public :
    joc (const int pret ,const char *name,float rating, const int cantitate){
        this->pret = pret;
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
        if (rating > 10)
            rating = 10;
        if (rating < 0)
            rating = 0;
        this->rating = rating;
        this->cantitate = cantitate;
    }
    ~joc(){
        delete[] name;
    }
    joc(){
        this->name = new char[1];
        strcpy(this->name,"");
        this->pret = 0;
        this->cantitate = 0;
        this->rating =0.0;
    }

    joc (const joc &a){
        this->pret = a.pret;
        this->name = new char[strlen(a.name)+1];
        strcpy(this->name,a.name);
        this->rating = a.rating;
        this->cantitate = a.cantitate;
    }
    char *getName() const{
        return this->name;
    }
    int getPret() const{
        return pret;
    }
    int getCantitate() const{
        return cantitate;
    }
    float getRating() const{
        return rating;
    }
    void setName( const char *name_){
        delete[] name;

        int len = strlen(name_);
        name = new char[len+1];
        strcpy(name,name_);
    }
    void setPret(const int pretu){
        this->pret = pretu;
    }
    void setRating(float ratingu){
        if (ratingu > 10.0)
            ratingu = 10.0;
        if (ratingu < 0.0)
            ratingu = 0.0;
        this->rating = ratingu;
    }
    void setCantitate(const unsigned int cantitatea){
        this->cantitate = cantitatea;
    }

    joc& operator= (const joc &s) {
        delete[] name;

        int len = strlen(s.name);
        name = new char[len+1];
        strcpy(name,s.name);

        this->pret = s.pret;
        this->rating = s.rating;
        this->cantitate = s.cantitate;
        return *this;
    }
    bool operator== (const joc &s) const {
        if (s.pret == this->pret && strcmp(this->name, s.name) == 0 && this->rating == s.rating && this->cantitate == s.cantitate)
            return true;
        return false;
    }
    bool operator!= (const joc &s) const {
        if (!(s.pret == this->pret && strcmp(this->name, s.name) == 0 && this->rating == s.rating && this->cantitate == s.cantitate))
            return true;
        return false;
    }
    friend std::istream& operator>>(std::istream &is, joc &j) {
        cout << "Numele Jocului:";
        char buf[100];
        is >> buf;
        j.setName(buf);
        cout<<endl<<"pret:";is >> j.pret;cout <<endl <<"cantitate:";is>>j.cantitate;cout<<endl;cout<<"rating(intre [0-10]):";is>>j.rating;cout<<endl<<"";
        if (j.getRating() > 10.0)
            j.setRating(10.0);
        if (j.getRating() < 0.0)
            j.rating =0.0;
        return is;
    }
    friend std::ostream& operator<<(std::ostream &os,const joc &s) {

        if (!s.name) {
            os << "Not initialized\n";
            return os;
        }

        os << "Numele Jocului: " << s.name << "; pret: " << s.pret <<"; cantitate:" <<s.cantitate << "; rating: " << s.rating  <<  '\n';


        return os;
    }
    friend class Magazin;

};

class Magazin{
private:
    char *name;
    int nrJocuri;
    joc *listaJocuri ;
public:
    Magazin(const Magazin &s){
        this->nrJocuri = s.nrJocuri;
        this->name = new char[strlen(s.name)+1];
        strcpy(this->name,s.name);
        delete[] this->listaJocuri;
        this->listaJocuri = new joc[nrJocuri * sizeof(joc)];
        for (int i = 0; i < this->nrJocuri; i++)
            this->listaJocuri[i] = s.listaJocuri[i];

    }
    Magazin() {
        this->name = new char[1];
        strcpy(this->name, "");
        this->nrJocuri =0;
        this->listaJocuri = new joc[0];
    }

    Magazin(const char *name,const int nrJocuri, const joc *listaJocuri){
        this->nrJocuri = nrJocuri;
        this->listaJocuri = new joc[nrJocuri* sizeof(joc)];
        for(int i = 0;i <nrJocuri ;i++)
            this->listaJocuri[i] = listaJocuri[i];
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
    }
    ~Magazin(){
        delete[] listaJocuri;
        delete[] name;
    }
    Magazin& operator= (const Magazin &s) {
        delete[] name;
        delete[] listaJocuri;

        int len = strlen(s.name);
        name = new char[len+1];
        strcpy(name,s.name);

        this->nrJocuri = s.nrJocuri;
        this->listaJocuri = new joc[nrJocuri * sizeof(joc)];
        for (int i = 0; i < this->nrJocuri; i++)
            this->listaJocuri[i] = s.listaJocuri[i];
        return *this;

    }
    void setName( const char *name_){
        delete[] name;

        int len = strlen(name_);
        name = new char[len+1];
        strcpy(name,name_);

    }

    void setListaJocuri(const joc *listaJocurii){
        delete[] this->listaJocuri;
        this->listaJocuri = new joc[nrJocuri * sizeof(joc)];
        for (int i = 0; i < this->nrJocuri; i++)
            this->listaJocuri[i] = listaJocurii[i];
    }
    void setNrJocuri(const int nrJocurii){
        this->nrJocuri = nrJocurii;
    }
    joc *getListaJocuri()const{
        return listaJocuri;
    }
    char *getName()const{
        return name;
    }
    int getNrJocuri()const{
        return nrJocuri;
    }
    friend std::istream& operator>>(std::istream &is, Magazin &j) {
        cout << "Numele Mgazinului:";
        char buf[255];
        is >> buf;
        j.setName(buf);
        cout<<endl<<"nrJocuri:";is >> j.nrJocuri;cout <<endl ;
        joc *lista = new joc[j.nrJocuri *sizeof(joc)];
        for (int i =0;i<j.nrJocuri;i++){
            cout << "Jocul cu nr "<<i+1<<" " <<endl;
            is >> lista[i];
        }
        cout <<endl<<endl ;
        j.setListaJocuri(lista);
        delete[] lista;
        return is;
    }
    friend std::ostream& operator<<(std::ostream &os,const Magazin &s) {

        if (!s.name) {
            os << "Not initialized\n";
            return os;
        }

        cout << "Numele Magazinului: "<<s.name<<"; numar de jocuri: "<<s.nrJocuri<<endl<<"Lista jocuri: "<<endl;
        for (int i = 0; i < s.nrJocuri;i++) {
            os << "Jocul nr " << i+1 << ':' << s.listaJocuri[i] << endl;
        }

        return os;
    }


};

void degeaba(){
    joc x;
    x.setPret(1);
    x.setCantitate(1);
    x.setRating(2.0);
    x.getRating();
    x.getName();
    x.getCantitate();
    x.getPret();
    Magazin y;
    y.setNrJocuri(1);
    y.getName();
    y.getListaJocuri();
    y.getNrJocuri();

}

void adaugareMagazin(){
    Magazin j1;
    cout <<"Adaugare Magazin " << endl;
    fin >> j1;
    cout << "Afisare Magazin " <<endl << j1 <<endl <<endl;

    cout << "Asta e tot , intoarcere la meniul principal" <<endl<<endl<<endl;
}


void adaugare1Joc(){
    joc joc1;
    fin >> joc1;
    cout << joc1;
    cout << "Asta e tot , intoarcere la meniul principal" <<endl<<endl<<endl;
}
void adaugareNJocuri(){
    cout <<endl<<"Cate jocuri doriti sa adaugati?"<<'\n';
    int nrJocuri; fin >> nrJocuri;
    joc * listaJocuri = new joc[nrJocuri * sizeof(joc)];
    for (int i = 0;i < nrJocuri ;i++)
    {

        fin >> listaJocuri[i];

    }
    cout << endl<<endl;
    for (int i = 0;i < nrJocuri ;i++)
    {

        cout  << listaJocuri[i] <<endl;

    }
    cout << "Asta e tot , intoarcere la meniul principal" <<endl<<endl<<endl;


}
int meniuPrincipal(){
    int optiune;
    cout<<"Alegeti optiunea pe care o doriti:" <<endl;
    cout<<" 1.Adaugati si afisati un nou  joc."<<endl;
    cout<<" 2.Adaugati si afisati n jocuri."<<endl;
    cout<<" 3.Adaugare magazin si afisare date."<<endl;
    cout<<" 4.Oprire"<<endl;
    cout << "Alegeti ce optiune va doriti:";fin >> optiune;
    switch(optiune){
        case 1:
            adaugare1Joc();
            break;
        case 2:
            adaugareNJocuri();
            break;
        case 3:
            adaugareMagazin();
            break;
        case 4:
            degeaba();
            cout << endl;
            cout << "Paaaaaaaaaaaaaaaaaaaa";
            return 0;

    }
    return 1;
}



int main() {
    while (meniuPrincipal());
    return 0;
}