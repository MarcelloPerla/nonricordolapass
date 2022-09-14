#include <iostream>
#include<ctime>
#include <string>

using namespace std;

const int tentativi_max = 5;
int riempiLettere(char, string, string&);

int main(){

  string nome;
  string si_o_no;
  char lettera;
  int tentativiSbagliati = 0;
  string consiglio;

  string parola;
  string parole[] =
  {
    "messico",
    "francia",
    "italia",
    "southafrica",
    "giappone",
    "australia",
    "egitto",
    "singapore",
    "cina",
    "turchia"
  };
  
  srand(time(NULL));
  int n = rand() % 10; 
  parola = parole[n];

  switch (n){
  	
	  case 0:
	    consiglio = "Consiglio: Condivide i confini con l'America'";
	    break;
	
	  case 1: 
	    consiglio = "Consiglio: Torre Eiffel ";
	    break;
	
	  case 2: 
	    consiglio = "Consiglio: Capitale Roma";
	    break;
	
	  case 3: 
	    consiglio = "Consiglio: Nato Nelson Mandela";
	    break;
	
	  case 4:
	    consiglio = "Consiglio: Gli anime sono stati creati";
	    break;
	
	  case 5: 
	    consiglio = "Consiglio: Vivono i canguri";
	      break;
	
	  case 6:   
		consiglio = "Consiglio: Grandi piramidi";
	    break;
	
	
	  case 7: 
	    consiglio = "Consiglio: Aereoporto chiamato Chaengi Airport";
	    break;
	
	  case 8: 
	    consiglio = "Consiglio: Risiede Beijing";
	    break;
	
	  case 9: 
	    consiglio = "Consiglio: Istanbul";
	    break;
  }

  string qualcosa(parola.lunghezza(), ('_')); 

  cout << "\n\nIndovina il nome di uno stato;
  cout << "\n\nOgni lettera e' un asterisco";
  cout << "\n\nDevi inserire solo una lettera alla volta"; 
  cout << "\n\nHai " << tentativi_max << " tentativi per indovinare";  
  cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; 
  
  while (tentativiSbagliati < tentativi_max){
    cout << endl << hint << endl;
    cout << "\n\n" << qualcosa;     
    cout << "\n\nIndovina una lettera: ";    
    cin >> si_o_no;                      
    if (riempiLettere(si_o_no, parola, qualcosa) == 0){
      cout << endl << "\n\Lettera non presente" << endl;
      tentativiSbagliati++;
    }
    else{
      cout << endl << "\n\Lettera trovata" << endl; 
    }
    cout << "\n\Hai ancora" << tentativi_max - tentativiSbagliati;
    cout << " tentativi rimasti" << endl;
    if (parola == qualcosa){
      cout << parola << endl;
      cout << "\n\Hai indovinato << endl;
      cout << "\n\WVuoi giocare un altro turno?" << endl;
      cout << "\n\Inserisci si o no" << endl; 

      cin >> si_o_no;

      if (si_o_no == "si"){
        main(); 
      }

      if (si_o_no == "no") {
        cout << "Chiusura programma..." << endl;
        return 0;
      }
      break;
    }
  }
  if (tentativiSbagliati == tentativi_max) {
    cout << "\n\Hai perso" << endl;
    cout << "\n\La parola era " << parola << endl;
    cout << "\n\Vuoi giocare un altro turno?" << endl;
    cout << "\n\Inserisci si o no" << endl;
    cin >> si_o_no;
    if (si_o_no == "si"){
      main();
    }
    if (si_o_no == "no")
    {
      cout << "Chiusura programma..." << endl;
        return 0; 
    }
  }
  return 0; 

}

int riempiLettere(char indovina, string parolasegreta, string& indovinaparola)
{
  int i;
  int turni = 0;
  int lun = parolasegreta.lunghezza();
  for (i = 0; i < lun; i++)
  {
    if (indovina == indovinaparola[i])
      return 0;
    if (indovina == indovinaparola[i])
    {
      indovinaparola[i] = indovina;
      turni++;
    }
  }
  return turni;
}

