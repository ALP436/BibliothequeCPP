#include "Bibliotheque.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void Bibliotheque::ajouterLivre(const Livre& livre) {
    livres.push_back(livre);
    std::cout << "DEBUG: nombre de livres = " << getNbLivres() << std::endl;
}

void Bibliotheque::supprimerLivre(const std::string& titre){
    for(auto it = livres.begin(); it != livres.end(); ++it) {
        if(it->getTitre() == titre) {
            livres.erase(it);
            return;
        }
    }
}

Livre Bibliotheque::chercherLivre(const std::string& titre) {
    for(const auto& livre : livres) {
        if(livre.getTitre() == titre) {
            return livre;
        }
    }
    return Livre("", "", "", 0); 
}

void Bibliotheque::afficherLivres() const {
    if(livres.empty()) {
        std::cout << "Aucun livre dans la bibliotheque." << std::endl;
        return;
    }

    for(const auto& livre : livres) {
        std::cout << livre.toString() << std::endl;
    }
}

void Bibliotheque::sauvegarderDansFichier(const std::string& nomFichier) const {
    std::ofstream fichier(nomFichier);
    if(!fichier.is_open()){
        std::cerr << "Erreur lors de l'ouverture du fichier pour sauvegarde." << std::endl;
        return;
    }

    for(const auto& livre: livres) {
        fichier << livre.getTitre() << ";"
                << livre.getAuteur() << ";"
                << livre.getCategorie() << ";"
                << livre.getPrix() << std::endl;
    }

    fichier.close();
}


void Bibliotheque::chargerDepuisFichier(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if(!fichier.is_open()){
        std::cerr << "Erreur lors de l'ouverture du fichier pour chargement." << std::endl;
        return;
    }

    livres.clear();
    std::string ligne;

    while(std::getline(fichier,ligne)){
        std::stringstream ss(ligne);
        std::string titre,auteur,categorie, prixStr;
        int prix;

        if(std::getline(ss,titre,';') &&
           std::getline(ss,auteur,';') &&
           std::getline(ss,categorie,';') &&
           std::getline(ss,prixStr)){
            prix = std::stoi(prixStr);
            Livre livre(titre, auteur, categorie, prix);
            livres.push_back(livre);
           }
    }
    fichier.close();
}
