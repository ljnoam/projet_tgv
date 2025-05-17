#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "train.h"
#include "billet.h"
#include "passager.h"
#include "reservation.h"

using namespace std;

// Fonction pour afficher le menu principal
void afficherMenu() {
    cout << "\n--- Système de Réservation de Billets de Trains ---\n";
    cout << "1. Afficher les trains disponibles\n";
    cout << "2. Réserver un billet\n";
    cout << "3. Annuler une réservation\n";
    cout << "4. Afficher les réservations d'un passager\n";
    cout << "5. Quitter\n";
    cout << "Choisissez une option : ";
}

// Fonction principale
int main() {
    vector<Train> trains = {
            Train(101, "Paris", "Lille", "08:00", "10:00", 100),
            Train(102, "Bordeaux", "Toulon", "09:00", "11:30", 80),
            Train(103, "Nice", "Toulouse", "07:30", "09:45", 50)
    };

    vector<Passager> passagers;
    vector<Reservation> reservations;
    int choix;

    do {
        afficherMenu();
        cin >> choix;

        switch (choix) {
            case 1: {
                cout << "\n--- Trains Disponibles ---\n";
                for (const auto& train : trains) {
                    train.afficherInfosTrain();
                }
                break;
            }
            case 2: {
                int numeroTrain;
                string nom, prenom, typeClasse, dateVoyage;
                cout << "Entrez le numéro du train : ";
                cin >> numeroTrain;

                auto it = find_if(trains.begin(), trains.end(),
                                  [numeroTrain](const Train& t) { return t.getNumeroTrain() == numeroTrain; });

                if (it != trains.end() && it->verifierDisponibilite()) {
                    cout << "Entrez votre nom : ";
                    cin >> nom;
                    cout << "Entrez votre prénom : ";
                    cin >> prenom;
                    cout << "Entrez le type de classe (Deuxième/Première) : ";
                    cin >> typeClasse;
                    cout << "Entrez la date du voyage (AAAA-MM-JJ) : ";
                    cin >> dateVoyage;

                    auto passagerIt = find_if(passagers.begin(), passagers.end(),
                                              [&nom, &prenom](const Passager& p) {
                                                  return p.getNom() == nom && p.getPrenom() == prenom;
                                              });

                    Passager* passagerPtr = nullptr;

                    if (passagerIt != passagers.end()) {
                        passagerPtr = &(*passagerIt);
                    } else {
                        passagers.emplace_back(nom, prenom, passagers.size() + 1);
                        passagerPtr = &passagers.back();
                    }

                    Billet billet(reservations.size() + 1, typeClasse, 50.0, numeroTrain, dateVoyage);
                    Reservation reservation(reservations.size() + 1, *passagerPtr, billet);
                    reservations.push_back(reservation);

                    passagerPtr->ajouterReservation(billet);
                    it->reserverPlace();

                    cout << "Réservation confirmée ! Numéro de réservation : " << reservations.size() << "\n";
                } else {
                    cout << "Train indisponible ou complet.\n";
                }
                break;
            }

            case 3: {
                int numeroReservation;
                cout << "Entrez le numéro de la réservation à annuler : ";
                cin >> numeroReservation;

                auto it = find_if(reservations.begin(), reservations.end(),
                                  [numeroReservation](const Reservation& r) {
                                      return r.getNumeroReservation() == numeroReservation;
                                  });

                if (it != reservations.end()) {
                    it->annulerReservation();

                    auto trainIt = find_if(trains.begin(), trains.end(),
                                           [numeroTrain = it->getBillet().getNumeroTrain()](const Train& t) {
                                               return t.getNumeroTrain() == numeroTrain;
                                           });

                    if (trainIt != trains.end()) {
                        trainIt->annulerReservation();
                    }

                    if (it->estReservationAnnulee()) {
                        reservations.erase(it);
                    }

                    cout << "Réservation annulée avec succès.\n";
                } else {
                    cout << "Réservation introuvable.\n";
                }
                break;
            }
            case 4: {
                if (passagers.empty()) {
                    cout << "Aucun passager disponible.\n";
                    break;
                }

                cout << "Liste des passagers :\n";
                for (const auto& passager : passagers) {
                    cout << "ID: " << passager.getIdentifiant() << ", Nom: " << passager.getNom() << ", Prénom: " << passager.getPrenom() << "\n";
                }

                int idPassager;
                cout << "Entrez l'identifiant du passager : ";
                cin >> idPassager;

                auto it = find_if(passagers.begin(), passagers.end(),
                                  [idPassager](const Passager& p) { return p.getIdentifiant() == idPassager; });

                if (it != passagers.end()) {
                    it->afficherReservations();
                } else {
                    cout << "Passager introuvable.\n";
                }
                break;
            }
            case 5: {
                cout << "Merci d'avoir utilisé notre système. À bientôt !\n";
                break;
            }
            default:
                cout << "Option invalide. Veuillez réessayer.\n";
                break;
        }
    } while (choix != 5);

    return 0;
}
