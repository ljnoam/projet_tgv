#ifndef TRAIN_H
#define TRAIN_H

#include <string>

using namespace std;

class Train {
private:
    int numeroTrain;
    string villeDepart;
    string villeArrivee;
    string horaireDepart;
    string horaireArrivee;
    int capacite;
    int placesLibres;

public:
    Train(int num, const string& depart, const string& arrivee,
          const string& horaireD, const string& horaireA, int cap);

    bool verifierDisponibilite() const;
    bool reserverPlace();
    bool annulerReservation();
    void afficherInfosTrain() const;

    int getNumeroTrain() const { return numeroTrain; }
};

#endif
