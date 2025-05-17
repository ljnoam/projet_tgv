# 🚄 Application de Réservation de Billets TGV (C++)

Projet développé dans le cadre d’un travail de groupe en 2ème année de Bachelor Informatique.  
L’objectif était de concevoir une application console en C++ pour gérer la réservation de billets de TGV, avec une interface simple et une structure orientée objet solide.

---

## 📌 Fonctionnalités principales

✅ Réserver un billet en fonction des places disponibles  
✅ Annuler une réservation existante  
✅ Afficher les réservations en cours et l’historique des billets  
✅ Parcourir un calendrier de trains  
✅ Gestion complète des données via des fichiers texte

---

## 🛠️ Technologies utilisées

- **Langage :** C++
- **Architecture :** Programmation orientée objet (POO)
- **Build system :** CMake
- **Environnement :** CLion / CMake compatible IDE
- **Persistance des données :** Fichiers `.txt` (pas de base de données)
- **Interface :** Application console (CLI)

---

## 🧱 Structure du projet

```
ProjetCPP/
├── src/                    # Fichiers source principaux
│   ├── billet.cpp / .h
│   ├── passager.cpp / .h
│   ├── reservation.cpp / .h
│   ├── train.cpp / .h
│   └── main.cpp
├── docs/                   # Documentation du projet
│   └── rapport-projet-tgv.pdf
├── CMakeLists.txt          # Configuration du build
├── .gitignore              # Fichiers ignorés par Git
└── README.md               # Ce fichier
```

---

## 🧠 Organisation des classes

- **Train** : contient les infos sur les lignes, les horaires, les places dispo.
- **Billet** : objet représentant un ticket, avec ses caractéristiques.
- **Passager** : profil de l’utilisateur (nom, ID...).
- **Réservation** : gère la logique de réservation / annulation.
- **Main** : point d’entrée avec logique utilisateur + interface console.

---

## 🎯 Objectifs pédagogiques atteints

- Application complète en C++ avec persistance de données
- Pratique poussée de la programmation orientée objet
- Collaboration en équipe sur un projet structuré
- Utilisation de `CMake` pour la compilation multiplateforme

---

## 🧪 Comment compiler et exécuter

### 🔧 Prérequis
- Un compilateur C++ (GCC, Clang, MSVC...)
- `CMake` installé
- Un terminal ou IDE compatible (ex : CLion, VSCode...)

### ▶️ Étapes

```bash
# Cloner le repo
git clone https://github.com/ton-user/reservation-tgv-cpp.git
cd reservation-tgv-cpp

# Créer un dossier de build
mkdir build && cd build

# Générer les fichiers de compilation
cmake ..

# Compiler
cmake --build .

# Lancer l'exécutable
./ProjetCPP   # ou ProjetCPP.exe sur Windows
```

---

## 📄 Rapport de projet

👉 [Lire le rapport PDF ici](https://github.com/ton-user/reservation-tgv-cpp/raw/main/docs/rapport-projet-tgv.pdf)

---

## 🚀 Améliorations possibles (TODO)

- Passer à une interface graphique (Qt, SDL, etc.)
- Ajouter un système de fidélité (points pour passagers réguliers)
- Remplacer les fichiers `.txt` par une base de données (ex: SQLite)
- Intégrer des tests unitaires avec GoogleTest ou Catch2
- Meilleure gestion des erreurs / exceptions

---

## 👨‍💻 Auteurs

- Noam – Développement classes principales, persistance
- Charles – Historique & calendrier, debug
- Elias – Implémentation logique TGV
- Matteo – Interface console, expérience utilisateur

---

## 📝 Licence

Ce projet est un exercice académique.  
Vous pouvez l'utiliser et le modifier à des fins pédagogiques ou personnelles.
