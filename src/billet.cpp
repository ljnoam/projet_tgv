#include "billet.h"
#include <iostream>

using namespace std;

Billet::Billet(int num, const std::string& classe, double prix, int train, const std::string& date)
        : numeroBillet(num), typeClasse(classe), prix(prix), numeroTrain(train), dateVoyage(date), _estAnnule(false) {}


void Billet::afficherDetailsBillet() const {
    cout << "Billet #" << numeroBillet << " - " << typeClasse
         << " - Prix: " << prix << " EUR - Train: " << numeroTrain
         << " - Date: " << dateVoyage;
    cout << "\n";
}


double Billet::calculerPrix(const string& classe, double distance) {
    double basePrix = 0.2 * distance;
    return (classe == "Première Classe") ? basePrix * 1.5 : basePrix;
}
