#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <vector>
#include "Livre.h"

class Bibliotheque {
public:
    void ajouterLivre(const Livre& livre);
    void supprimerLivre(const std::string& titre);
    Livre chercherLivre(const std::string& titre);
    void afficherLivres() const;
    void sauvegarderDansFichier(const std::string& nomFichier) const;
    int getNbLivres() const { return livres.size(); };
    void chargerDepuisFichier(const std::string& nomFichier);

private:
    std::vector<Livre> livres;
};

#endif // BIBLIOTHEQUE_H