#include <iostream>
#include <string>
#include <limits>
#include "Bibliotheque.h"
#include "Livre.h"

int main() {
    Bibliotheque biblio;
    int choix;

    do {
        std::cout << "\nMenu Bibliotheque:\n";
        std::cout << "1. Ajouter un livre\n";
        std::cout << "2. Supprimer un livre\n";
        std::cout << "3. Chercher un livre\n";
        std::cout << "4. Afficher tous les livres\n";
        std::cout << "5. Sauvegarder dans un fichier\n";
        std::cout << "6. Charger depuis un fichier\n";
        std::cout << "0. Quitter\n";
        std::cout << "Choix: ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Nettoie le retour à la ligne

        switch(choix) {
            case 1: {
                std::string titre, auteur, categorie;
                int prix;
                std::cout << "Titre: "; std::getline(std::cin, titre);
                std::cout << "Auteur: "; std::getline(std::cin, auteur);
                std::cout << "Categorie: "; std::getline(std::cin, categorie);
                std::cout << "Prix: "; 
                while(!(std::cin >> prix)) { // Vérifie que l'utilisateur entre bien un entier
                    std::cout << "Veuillez entrer un nombre entier pour le prix: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Nettoie après cin >>
                biblio.ajouterLivre(Livre(titre, auteur, categorie, prix));
                std::cout << "Livre ajouté: " << titre << std::endl;
                break;
            }

            case 2: {
                std::string titre;
                std::cout << "Titre du livre à supprimer: ";
                std::getline(std::cin, titre);
                biblio.supprimerLivre(titre);
                std::cout << "Livre supprimé si trouvé." << std::endl;
                break;
            }

            case 3: {
                std::string titre;
                std::cout << "Titre du livre à chercher: ";
                std::getline(std::cin, titre);
                Livre livre = biblio.chercherLivre(titre);
                if(livre.getTitre() != "") {
                    std::cout << "Livre trouvé: " << livre.toString() << std::endl;
                } else {
                    std::cout << "Livre non trouvé." << std::endl;
                }
                std::cout << "Appuyez sur Entrée pour continuer...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

            case 4: {
                if(biblio.getNbLivres() == 0) {
                    std::cout << "La bibliothèque est vide." << std::endl;
                } else {
                    biblio.afficherLivres();
                }
                std::cout << "Appuyez sur Entrée pour continuer...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

            case 5: {
                std::string nomFichier;
                std::cout << "Nom du fichier pour sauvegarde: ";
                std::getline(std::cin, nomFichier);
                biblio.sauvegarderDansFichier(nomFichier);
                std::cout << "Bibliothèque sauvegardée dans " << nomFichier << std::endl;
                break;
            }

            case 6: {
                std::string nomFichier;
                std::cout << "Nom du fichier source pour charger la bibliotheque : ";
                std::getline(std::cin, nomFichier);
                biblio.chargerDepuisFichier(nomFichier);
                std::cout << "Bibliothèque chargée depuis " << nomFichier << std::endl;
                break;
            }

            case 0: {
                std::cout << "Au revoir!" << std::endl;
                break;
            }

            default: {
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
                break;
            }
        }
    } while(choix != 0);

return 0;


}
