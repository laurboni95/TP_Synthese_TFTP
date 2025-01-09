# TP_Synthese_TFTP
Dans cette fonction nous devons envoiyer quatres arguments : 
- Le nom de la fonction (gettftp)
- Le nom de la machine utilisée (localhost)
- Le port (1069)
- Le fichier envoyé

J ai appris à configurer les paramètres de la strucuture hints pour utiliser IPv4 et le protocol UDP.
Pour la requête en lecture (RRQ) j'ai appris à correctement les coder en respectant le formatage imposé.
Avec l'utilisation des fonctions sendto et recvfrom j'ai appris à stocker l'adresse source lors de la réception d'un paquet.
Lors de la réception des données j'ai appris que le paquet ACK était constitué de 4 octets.

Avec ce TP, j'ai pu voir sur Wireshark l'envoi et la réception des données transmises. Cela m'a permis de mieux comprendre le fonctionnement de Wireshark grâce à l'exemple concret du paquet créé.

Ce projet a permis de mieux comprendre les spécificités du protocole TFTP et de la communication réseau en UDP.

Après avoir codé le sendto on obtient les lignes suivantes dans le terminal :
![Capture d'écran 2025-01-08 145405](https://github.com/user-attachments/assets/7e63bb68-c70e-42a5-8065-ca9bc66a2a07)

Sur Wireshark on voit que le sendto a bien fonctionné : 
![Capture d'écrannnnn](https://github.com/user-attachments/assets/24e47dd1-f896-4e30-a416-20253533f1b1)

Après le codage de la fonction recvfrom :
![image](https://github.com/user-attachments/assets/84bcad74-2535-451a-b7c1-2d39353d88c2)
