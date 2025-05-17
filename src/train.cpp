#include "train.h"
#include <iostream>

using namespace std;

Train::Train(int num, const string& depart, const string& arrivee,
             const string& horaireD, const string& horaireA, int cap)
        : numeroTrain(num), villeDepart(depart), villeArrivee(arrivee),
          horaireDepart(horaireD), horaireArrivee(horaireA), capacite(cap), placesLibres(cap) {}

bool Train::verifierDisponibilite() const {
    return placesLibres > 0;
}

bool Train::reserverPlace() {
    if (placesLibres > 0) {
        --placesLibres;
        return true;
    }
    return false;
}

bool Train::annulerReservation() {
    if (placesLibres < capacite) {
        ++placesLibres;
        return true;
    }
    return false;
}

void Train::afficherInfosTrain() const {
    cout << "Train " << numeroTrain << " : " << villeDepart << " -> " << villeArrivee << "\n"
         << "Départ : " << horaireDepart << ", Arrivée : " << horaireArrivee << "\n"
         << "Places disponibles : " << placesLibres << "/" << capacite << "\n";
}
