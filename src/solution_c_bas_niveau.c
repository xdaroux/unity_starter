/*

Exercice C bas niveau

Vous travaillez en C pour un système aux ressources très limitées.
Vous ne pouvez vous permettre d'utiliser une librairie standard C complète.
Vous devrez donc implémenter vous-mêmes certains fonctions indispensables 
pour votre application.

Pour l'instant, seule la fonction putchar() est disponible. 
Cette fonction est chargée d'envoyer un charactère vers la console.

int putchar(int c);

Pour votre application vous devez coder les fonctions suivantes, 
ainsi qu'un programme main.c permettant de les tester.

vous devez inclure stdint.h et stddef.h pour avoir accès aux types, 
et stdio.h pour putchar().

En C, les chaînes de caractères sont des tableaux de char terminées par 
le caractère nul, '\0' (code ASCII 0x00)
*/

/* affiche une chaine sur la console, passe la dernière valeur de retour de putchar */
int puts(const char* cs);


/* retourne la longueur d'une chaine, sans compter le '\0' final
	size_t est defini dans stddef.h, c'est un entier non signé.
 */
size_t strlen(const char* cs)
{
    size_t i = 0;
    while(cs[i++] != '\0');
    return i-1;
}


/*
	effectue une copie profonde de la chaîne cs dans le tableau de char désigné par s
	retourne s (permet une utilisation plus flexible que void)
*/
char* strcpy(char* s, const char* ct)
{
    int i = 0;
    do {
        s[i] = ct[i];
    } while (ct[i++] != '\0');
    return s;
}


/* inverse une chaîne en place */
char* strreverse(char *s)
{
    size_t i, j;
    char k;

    for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
        k = s[i];
        s[i] = s[j];
        s[j] = k;
    }
    return s;
}


/* convertie un entier non signé en chaine de caractère.
   s est un tampon existant pouvant recevoir la chaîne (il faut au max 13 cases) */
char* longtodec(unsigned int l, char* s);
{
    unsigned char i = 0;
    while(l > 0) {
        s[i++] = l % 10 + '0';
        l /= 10;
    }
    s[i] = '\0';
    return strreverse(s);
}


/* converti un nombre entier non signé d'un nombre de bits donné (8, 16, 32)
	en chaîne de caractère représentant le nombre en hexadécimal */
char* hexstr(uint32_t l, char* s, uint8_t bits)
{
    int8_t i, j;
    int32_t c;

    for(i = bits-4, j = 0; i >= 0; i -= 4) {
        c = ((l >> i) & 0x0f) + 0x30;
        if (c > 0x39) c+= 7;
        s[j++] = c;
    }

    s[j] = '\0';
    return s;
}
