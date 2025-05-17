#ifndef BILLET_H
#define BILLET_H

#include <string>

using namespace std;

class Billet {
private:
    int numeroBillet;
    string typeClasse;
    double prix;
    int numeroTrain;
    string dateVoyage;
    bool _estAnnule;

public:
    Billet(int num, const string& classe, double prix, int train, const string& date);

    void afficherDetailsBillet() const;
    double calculerPrix(const string& classe, double distance);

    int getNumeroTrain() const { return numeroTrain; }

    void annuler() { _estAnnule = true; }  // Modifie l'état de l'attribut
    bool estAnnule() const { return _estAnnule; }
};

#endif
