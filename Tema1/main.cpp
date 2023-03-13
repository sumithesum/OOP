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
     joc (int pret , char *name,float rating,int cantititate){
        this->pret = pret;
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
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
    void setRating(const float rating){
        this->pret = pret;
    }
    void setCantitiate(const int cantitate){
        this->pret = pret;
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
};

int main(){
    return 0;
}