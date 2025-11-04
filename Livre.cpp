#include <iostream>
#include "Livre.h"

Livre::Livre(const std::string& titre, const std::string& auteur, const std::string& categorie, int prix)
    : titre(titre), auteur(auteur), categorie(categorie), prix(prix) {}


    std::string Livre::getTitre() const {
        return titre;
    }

    std::string Livre::getAuteur() const {
        return auteur;
    }

    std::string Livre::getCategorie() const {
        return categorie;
    }

    int Livre::getPrix() const {
        return prix;
    }





    void Livre::setTitre(const std::string& t){
        titre = t;
    }
    
    void Livre::setAuteur(const std::string& a){
        auteur = a;
    }
    
    void Livre::setCategorie(const std::string& c){
        categorie = c;
    }
    
    void Livre::setPrix(int p){
        prix = p;
    }
    
    
    


    std::string Livre::toString() const {
        return "Titre: " + titre + ", Auteur: " + auteur + ", Categorie: " + categorie + ", Prix: " + std::to_string(prix);
    }

    
    void afficherLivre(const Livre& livre) {
        std::cout << livre.toString() << std::endl;
    }


    