/*
	Author: Fabio Marchesi
			Contiene il codice che controlla se le due soluzioni corrispondono.
			Legge da "outputCorretto.txt" la soluzione corretta.
			Legge da "outputSbagliato.txt" la soluzione da confrontare.
			Scrive su "esito.txt" se la soluzione è corretta.
*/

/*
	Versione di Default:
		Controlla semplicemente che gli output stampati siano identici
	Commentare questa versione ed inserirne una nuova per controlli differenti.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream inCorretto("outputCorretto.txt");
	ifstream inSbagliato("outputSbagliato.txt");
	ofstream esito("esito.txt");
	vector<string> v1;
	while(!inCorretto.eof()){
		string next;
		inCorretto>>next;
		cout<<next<<" ";
		v1.push_back(next);
	}
	cout<<"\n";
	vector<string> v2;
	while(!inSbagliato.eof()){
		string next;
		inSbagliato>>next;
		v2.push_back(next);
	}
	//Output Malformato, numero differente di valori stampati
	if(v1.size()!=v2.size()){
		esito<<"Output_Malformato";
		inCorretto.close();
		inSbagliato.close();
		esito.close();
		return 0;
	}
	//Output erratto, numero corretto di valori stampati, ma non corrispondono i valori
	for(int i=0;i<v1.size();i++)
		if(v1[i]!=v2[i]){
			esito<<"Output_Errato";
			inCorretto.close();
			inSbagliato.close();
			esito.close();
			return 0;
		}
	// Output corretto, i due output corrispondono
	esito<<"Output_Corretto";
	inCorretto.close();
	inSbagliato.close();
	esito.close();
	return 0;
}
