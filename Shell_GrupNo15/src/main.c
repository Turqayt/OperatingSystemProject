#include "prompt.h"
#include "command.h"


int main()
{
    


	int durum = 1;
    	char* ekrandanOkunan;
    	char** parametreler;
    	
	while(durum) 
    	{
        Prompt();
        ekrandanOkunan = StringOku();
        
        parametreler = ParametreleriAyir(ekrandanOkunan);
        durum = kabukCalistir(parametreler);
    	};
  


    return 0;
}
