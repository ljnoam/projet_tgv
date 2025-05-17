#include "passager.h"
#include <iostream>
#include <algorithm>

using namespace std;

Passager::Passager(const string& nom, const string& prenom, int id)
        : nom(nom), prenom(prenom), identifiant(id) {}

void Passager::ajouterReservation(const Billet& billet) {
    reservations.push_back(billet);
    cout << "Réservation ajoutée pour le passager " << nom << " " << prenom << ".\n";
}

void Passager::annulerReservation(int numeroBillet) {
    auto it = find_if(reservations.begin(), reservations.end(),
                      [numeroBillet](const Billet& b) { return b.getNumeroTrain() == numeroBillet; });

    if (it != reservations.end()) {
        reservations.erase(it);  // Retirer le billet annulé de la liste
        cout << "Billet #" << numeroBillet << " supprimé des réservations du passager.\n";
    } else {
        cout << "Billet non trouvé dans les réservations.\n";
    }
}

void Passager::afficherReservations() const {
    cout << "Réservations pour " << nom << " " << prenom << ":\n";

    for (const auto& billet : reservations) {
        if (billet.estAnnule()) {  // Vérifie si le billet est annulé
            cout << "Billet #" << billet.getNumeroTrain() << " - Annulé\n";  // Affiche que le billet est annulé
        } else {
            billet.afficherDetailsBillet();  // Affiche les détails du billet si non annulé
        }
    }
}

