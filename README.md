# TP_Synthese_TFTP
J'utilise le serveur de moodle et l'active avec la commande ./go.sh.
On envoie quatres arguments dans notre fonction : 
- Le nom de la fonction (gettftp)
- Le nom de la machine utilisée (localhost)
- Le port (1069)
- Le fichier envoyé

Après avoir codé le sendto on obtient les lignes suivantes dans le terminal :
![Capture d'écran 2025-01-08 145405](https://github.com/user-attachments/assets/7e63bb68-c70e-42a5-8065-ca9bc66a2a07)

Sur Wireshark on voit que le sendto a bien fonctionné : 
![Capture d'écrannnnn](https://github.com/user-attachments/assets/24e47dd1-f896-4e30-a416-20253533f1b1)
