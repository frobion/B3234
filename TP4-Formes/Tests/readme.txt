Programme de tests automatiques - mode d'emploi


-------------------------------------------------------------------------------
test.sh [ repertoire [ fichier.csv ] ]

- repertoire indique le rÃ©pertoire dans lequel se trouvent les fichiers de 
configuration du test
- fichier.csv indique un fichier dans lequel les rÃ©sultats du tests seront 
ajoutÃ©s

En l'absence d'arguments, le script traitera le rÃ©pertoire courant

Fichiers de configuration :
- run : fichier texte indiquant la ligne de commande Ã  Ã©xÃ©cuter (obligatoire)
- std.in : fichier texte indiquant une entrÃ©e clavier Ã  simuler (facultatif)
- std.out : fichier texte indiquant la sortie devant Ãªtre produite 
(facultatif/validation*)
- stderr.out : fichier texte indiquant la sortie d'erreur devant Ãªtre produite 
(facultatif/validation*)
- description : fichier texte donnant la description du test (facultatif)
- returncode : fichier texte contenant l'entier code retour attendu 
(facultatif/validation*)
- *.outfile : un ou plusieurs fichiers devant Ãªtre produits par le programme 
(facultatif/validation*)
  si le fichier s'appelle exemple.txt.outfile, il sera comparÃ© Ã  exemple.txt

*validation indique que le script va tester la conformitÃ©, si cette conformitÃ© 
n'est pas 
satisfaite, il l'indiquera

-------------------------------------------------------------------------------
mktest.sh

Fichier Ã  personnaliser. Dans l'Ã©tat, il cherche Ã  valider tous les tests 
contenus dans les rÃ©pertoires dont le nom commence par Test.

