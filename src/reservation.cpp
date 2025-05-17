#include "reservation.h"
#include <iostream>

using namespace std;

Reservation::Reservation(int num, const Passager& p, const Billet& b)
        : numeroReservation(num), passager(p), billet(b), estAnnulee(false) {}

void Reservation::confirmerReservation() {
    cout << "Réservation confirmée pour " << passager.getNom() << ".\n";
}

void Reservation::annulerReservation() {
    estAnnulee = true;
    cout << "Réservation annulée pour le billet #" << billet.getNumeroTrain() << ".\n";
}

void Reservation::afficherDetailsReservation() const {
    if (!estAnnulee) {
        cout << "Détails de la réservation #" << numeroReservation << ":\n";
        passager.afficherReservations();
        billet.afficherDetailsBillet();
    } else {
        cout << "Cette réservation a été annulée.\n";
    }
}
