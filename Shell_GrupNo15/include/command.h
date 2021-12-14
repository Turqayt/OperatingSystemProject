#include <prompt.h>


#define clear() printf("\033[H\033[J")



char* StringOku();
int cdKomutCalistir(char**);
int showpidKomutCalistir(char**);
int exitKomutCalistir(char**);
int kabukCalistir(char**);
char** ParametreleriAyir(char*);
int komutCalistir(char**);
int siraliCalistir(char**,int);
void girisYonlendirme(char**, char*);
void sig_child(int);

static char* konum;
char* dosya;
