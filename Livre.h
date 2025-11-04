#ifndef LIVRE_H
#define LIVRE_H

#include <string>

class Livre {
public:
    Livre(const std::string& titre, const std::string& auteur, const std::string& categorie, int prix);

    std::string getTitre() const;
    std::string getAuteur() const;
    std::string getCategorie() const;
    int         getPrix() const;

    void setTitre(const std::string& t);
    void setAuteur(const std::string& a);
    void setCategorie(const std::string& c);
    void setPrix(int p);

    std::string toString() const;

private:
    std::string titre;
    std::string auteur;
    std::string categorie;
    int         prix;
};

#endif // LIVRE_H