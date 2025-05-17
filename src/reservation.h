#ifndef RESERVATION_H
#define RESERVATION_H

#include "passager.h"
#include "billet.h"

using namespace std;

class Reservation {
private:
    int numeroReservation;
    Passager passager;
    Billet billet;
    bool estAnnulee;

public:
    Reservation(int num, const Passager& p, const Billet& b);

    void confirmerReservation();
    void annulerReservation();
    void afficherDetailsReservation() const;

    const Billet& getBillet() const { return billet; }
    int getNumeroReservation() const { return numeroReservation; }
    bool estReservationAnnulee() const { return estAnnulee; }
    const int getNumeroBillet() const { return billet.getNumeroTrain(); }
};

#endif
