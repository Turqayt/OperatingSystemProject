#include "command.h"


char *Komutlar[] = {
    "cd",
    "showpid",
    "exit"
};

int cdKomutCalistir(char** komut)
{
    if(komut[1] == NULL)
    {
        fprintf(stderr, "lkabuk: eksik erguman \"cd\"\n");
    }
    else
    {
        int durum = chdir(komut[1]); //Komut calistiriliyor.
        if(durum != 0)
            perror("lkabuk");
    }
    
    return 1; //İslem tamamlandi, program sonlandirilmadi.
}

int showpidKomutCalistir(char** komut)
{
 
  int dongu=4;

for(;dongu>1;dongu--){
      int p_id;
      p_id = fork();
    
     /* call fork() from parent process*/
if (0 == p_id)
{
   p_id = getpid(); 
   printf(" %d\n", p_id);
   
}

else
{
  /*parent fork*/
}
}

  return 1;     
    
}

int exitKomutCalistir(char** komut)
{
    return 0;
}



void** Calistir(char** parametreler)
{
	kabukCalistir(parametreler);
}

void Batch()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    Prompt();
    fp = fopen(dosya, "r");
    if (fp == NULL)
    {
	printf("Batch dosyası mevcut değil veya açılamıyor.\n");
	exit(EXIT_FAILURE);
    }
        

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("%s", line);
	int durum = 1;
    	char* ekrandanOkunan;
    	char** parametreler;
    	
	
        parametreler = ParametreleriAyir(line);
	durum = kabukCalistir(parametreler);
	if(!strcmp(line, "exit")) exit(EXIT_SUCCESS);
        
    }
	
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
	
}

char* StringOku()
{
    char* ekrandanOkunan = malloc(sizeof(char*) * 1024);
    
    int i = 0;
    int karakter = 0;

    //Bellek alanı ayrılamadı ise çıkış yapılıyor.
    if (!ekrandanOkunan)
    {
        fprintf(stderr, "lkabuk: Bellek alani ayrilamadi\n");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        karakter = getchar();

        if(karakter == EOF)
        {
            exit(EXIT_SUCCESS);
        }
        else if(karakter == '\n')
        {
            ekrandanOkunan[i] == '\0';
            return ekrandanOkunan;
        }
        else
        {
            ekrandanOkunan[i] = karakter;
        }
        
        i++;
    }
}

char** ParametreleriAyir(char* ekrandanOkunan)
{
    const char* sinir = " \t\r\n\a";
    
    int i = 0;
    
    char** parametreler = malloc(sizeof(char*) * 80); //80 karakter siniri
    char* parametre;

    //Bellek alanı ayrılamadı ise çıkış yapılıyor.
    if(!parametreler)
    {
        fprintf(stderr, "lkabuk: allocation error\n");
        exit(EXIT_FAILURE);
    }

    parametre = strtok(ekrandanOkunan, sinir);
    
    while(parametre != NULL)
    {
        parametreler[i] = parametre;
        i++;
        parametre = strtok(NULL, sinir);
    }
    
    parametreler[i] = NULL;
    return parametreler;
}
void girisYonlendirme(char** komut, char* dosya)
{
    pid_t pid;
    
    int dosyaTanimlayici;
    
    if (!(access (dosya,F_OK) != -1))
    {
        printf("lkabuk: %s adinda bir dosya bulunamadi\n",dosya);
        return;
    }
    if((pid = fork()) == -1)
    {
        printf("Cocuk proses olusturulamadi\n");
        return;
    }
    if (pid==0)
    {
        dosyaTanimlayici = open(dosya, O_RDONLY, 0600);
        dup2(dosyaTanimlayici, STDIN_FILENO);
        close(dosyaTanimlayici);

        if (execvp(komut[0],komut) == -1)
        {
            printf("lkabuk: Basarısız oldu");
            kill(getpid(),SIGTERM);
        }
    }
    
    waitpid(pid,NULL,0);
}


void sig_child(int signo)
{
    int durum;
    int child_val;
    int chid;
    
    chid = waitpid(-1, &durum, WNOHANG);
    
    if (chid > 0) //Arkaplanda çalışmayan processler için bu değer -1
    {
        if (WIFEXITED(durum))
        {
            child_val = WEXITSTATUS(durum);
            printf("[%d] retval : %d \n",chid, child_val);
            Prompt();
        }
    }
}

int komutCalistir(char** komut)
{
    pid_t pid;
    int durum;
    
    pid = fork();
    
    if(pid == 0) //Cocuk proses
    {
        int sonuc = execvp(komut[0], komut); //komut dizisinin ilk elemanı komutu içerir.

        if(sonuc == -1)
        {
            perror("lkabuk");
            kill(getpid(),SIGTERM);
        } //komut calistirilmadi.
    }
    else if(pid > 0) //Ebeveyn proses
    {
        waitpid(pid,NULL,0); //Cocuk prosesi bekle.
    }
    else
    {
        perror("lkabuk"); //Fork hatasi
    }
    
    return 1;
}
int siraliCalistir(char** komut, int count)
{
    pid_t pid;
    
    for(int i = 0; i < count; i=i+2)
    {
        if((pid = fork()) == -1)
        {
            printf("Cocuk proses olusturulamadi\n");
            return 1;
        }
        if (pid == 0)
        {
            if (execlp(komut[i], komut[i], komut[i+1], NULL) == -1)
            {
                printf("lkabuk: Basarısız oldu");
                kill(getpid(),SIGTERM);
            }
        }
        
        waitpid(pid, NULL, 0);
    }
    
    return 1;
}


int kabukCalistir(char** komut)
{
    int builtInKomutKontrol = -1;
    
    char* komut_tempSirali[80];

    if(komut[0] == NULL) //Komut bos
    {
        return 1;
    }
    
    //Gelen komut builtin komutu olup olmadigi bulunuyor.
    for(int i = 0; i < 3; i++)
    {
        /* 
       0 == cd, 
       1 == showpid,
       2 == exit
    */
    
        if (strcmp(komut[0], Komutlar[i]) == 0)
        {
            builtInKomutKontrol = i;
            break;
        }
        else
        {
            builtInKomutKontrol = -1;
        }
    }

    if(builtInKomutKontrol >= 0)
    {
        if(builtInKomutKontrol == 0){
            return cdKomutCalistir(komut);
        }
        else if(builtInKomutKontrol == 1){
            return showpidKomutCalistir(komut);
        }
        else if(builtInKomutKontrol == 2){
            return exitKomutCalistir(komut);
        }
        else {
            perror("lkabuk");
        }
    }
    else
    {
        int siraliKomutKontrol = 0;
        int k = 0;

        while(komut[k] != NULL)
        {
            if(!strcmp(komut[k], ";"))
            {
                siraliKomutKontrol = 1;
            }
            k++;
        }

        if(siraliKomutKontrol == 1)
        {
            int i = 0;
            int ekle = 0;
            
            while(komut[i] != NULL)
            {
                if(!strcmp(komut[i], ";"))
                {

                }
                else
                {
                    komut_tempSirali[ekle] = komut[i];
                    ekle++;
                }
                i++;
            }
            
            komut_tempSirali[i] = NULL;

            siraliCalistir(komut_tempSirali, ekle);
            return 1;
        }
    else
    {
      komutCalistir(komut);
      return 1;
    }
    }
}



