#include <iostream>
#include <cstring>
using namespace std;

class joc {
private:
    unsigned  int cantitate;
    float rating;
    int pret;
    char *name;
public :
     joc (int pret , char *name,float rating,int cantitate){
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

    joc (const joc &a){
        this->pret = a.pret;
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
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
    char *setName( const char *name_){
        delete[] name;

        int len = strlen(name_);
        name = new char[len+1];
        strcpy(name,name_);
}
    void setPret(const int pret){
        this->pret = pret;
}
    void setRating(float rating){
        if (rating > 10.0)
            rating = 10.0;
        if (rating < 0.0)
            rating = 0.0;
        this->rating = rating;
    }
    void setCantitiate(const unsigned int cantitate){
        this->cantitate = cantitate;
    }

    void operator= (const joc &s) {
        delete[] name;

        int len = strlen(s.name);
        name = new char[len+1];
        strcpy(name,s.name);

        this->pret = s.pret;
        this->rating = s.rating;
        this->cantitate = s.cantitate;
}
    bool operator== (const joc &s) const {
        if (s.pret == this->pret && strcmp(this->name, s.name) == 0 && this->rating == s.rating && this->cantitate == s.cantitate)
            return 1;
        return 0;
}
    bool operator!= (const joc &s) const {
        if (!(s.pret == this->pret && strcmp(this->name, s.name) == 0 && this->rating == s.rating && this->cantitate == s.cantitate))
            return 1;
        return 0;
    }
    friend std::istream& operator>>(std::istream &is, joc &j) {

        char buf[100];
        is >> buf;
        j.setName(buf);

        is >> j.pret>>j.cantitate>>j.rating>>j.cantitate;

        return is;
    }
    friend std::ostream& operator<<(std::ostream &os, joc &s) {

        if (!s.name) {
            os << "Not initialized\n";
            return os;
        }

        os << "Student: name: " << s.name << " pret: " << s.pret << " rating: " << s.rating <<" cantitate:" <<s.cantitate <<  '\n';

        return os;
    }
    friend class magazin;

};

class Magazin{
private:
     unsigned  int nrJocuri;
     joc** listaJocuri = new joc*[nrJocuri*sizeof(joc*)];
public:
    Magazin(unsigned  int nrJocuri, joc **listaJocuri){
            this->nrJocuri = nrJocuri;
            for(int i = 0;i <nrJocuri;i++)
                this->listaJocuri[i] = listaJocuri[i];
    }
    ~Magazin(){
        delete[] listaJocuri;
    }
};

int main(){
    return 0;
}