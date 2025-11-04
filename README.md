# 📚 Bibliothèque C++  

Bienvenue dans le projet **Bibliothèque C++** ! Ce programme simule une bibliothèque permettant de gérer des livres via un menu console interactif.  

---

## ✨ Fonctionnalités

- ➕ Ajouter un livre (titre, auteur, catégorie, prix)  
- ❌ Supprimer un livre par son titre  
- 🔍 Chercher un livre par son titre  
- 📖 Afficher tous les livres  
- 💾 Sauvegarder la bibliothèque dans un fichier texte  
- 📂 Charger la bibliothèque depuis un fichier texte  

---

## 🛠️ Technologies & Concepts
  
- Gestion de fichiers avec `fstream`  
- Conteneurs STL (`vector`)  
- Classes et objets (`Livre` et `Bibliotheque`)  
- Entrée/sortie console (`cin`, `cout`)  

---

## ⚠️ Remarques importantes

> ⚠️ **Attention :** Le fichier `bibliotheque.txt` doit respecter le format suivant pour que le programme puisse le charger correctement :  
> 
> ```
> Titre;Auteur;Categorie;Prix
> ```
> Chaque livre doit être sur une ligne distincte.

---

## 🖥️ Compilation et exécution

Pour compiler le projet sous **Linux/WSL** ou **Mac** :  

```bash
g++ -o Bibliotheque main.cpp Livre.cpp Bibliotheque.cpp
```
Après compilation, lancez le programme avec :

```bash
./Bibliotheque
```
