/*
	Author: Fabio Marchesi
			Contiene il codice che esegue le due soluzioni fino a quando non trova un corner case.
			Utilizza le librerie di Windows per:
				_Eseguire il generatore
				_Eseguire la soluzione corretta
				_Spostare l'output in "outputCorretto.txt"
				_Eseguire la soluzione da correggere
				_spostare il risultato in "outputSbagliato.txt"
				_Eseguire il correttore
*/
#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;
int main(){
	int tc=100; //Numero di input che prova
	//La soluzione non può rimanere in esecusione per più di K secondi
	double k=1.0;																			
	for(int current=0;current<tc;current++)
	{
		cout<<"TestCase: "<<current<<" : ";
		//Generazione dell'Input
		HANDLE hProcess;
		STARTUPINFO si={0};
		PROCESS_INFORMATION pi={0};
		DWORD dwProcessoId=0;
		DWORD dwThreadId=0;
		CreateProcess("Generatore.exe", NULL, NULL, NULL, false, NULL ,NULL , NULL, &si , &pi);		
		WaitForSingleObject(pi.hProcess, INFINITE);														
		UINT uExitCode;		
		TerminateProcess(pi.hProcess, uExitCode);	
		
		//Esecuzione soluzione corretta
		si = {0};
		pi = {0};
		dwProcessoId=0;
		dwThreadId=0;
		CreateProcess("correctSolution.exe", NULL, NULL, NULL, false, NULL ,NULL , NULL, &si , &pi );				
		WaitForSingleObject(pi.hProcess, INFINITE);															
		TerminateProcess(pi.hProcess, uExitCode);	
		
		//Trascrizione dell'output
		ifstream inCorretto("output.txt");
		ofstream outCorretto("outputCorretto.txt");
		while(!inCorretto.eof()){
			string next;
			inCorretto>>next;
			outCorretto<<next<<" ";
		}
		inCorretto.close();
		outCorretto.close();
		
	//Esecuzione della soluzione da correggere
		si={0};
		pi={0};
		dwProcessoId=0;
		dwThreadId=0;
		CreateProcess("wrongSolution.exe", NULL, NULL, NULL, false, NULL ,NULL , NULL, &si , &pi);			
		DWORD exitCode;
		GetExitCodeProcess(pi.hProcess, &exitCode);
		bool TLE;
		clock_t tStart = clock();																			
		while(exitCode==259){
			if((double)(clock()-tStart)/CLOCKS_PER_SEC>k){											
				TerminateProcess(pi.hProcess, uExitCode);													
				TLE=true;
			}
			GetExitCodeProcess(pi.hProcess, &exitCode);													
		}
		if(TLE){
			cout<<"Soluzione Errata utilizza troppo tempo per il TC attuale\n";
			continue;	
		}
		
		//Trascrizione dell'output
		ifstream inSbagliato("output.txt");
		ofstream outSbagliato("outputSbagliato.txt");
		while(!inSbagliato.eof()){
			string next;
			inSbagliato>>next;
			outSbagliato<<next<<" ";
		}
		inSbagliato.close();
		outSbagliato.close();
				
		//Esecuzione del Correttore
		si = {0};
		pi = {0};
		dwProcessoId=0;
		dwThreadId=0;
		CreateProcess("Correttore.exe", NULL, NULL, NULL, false, NULL ,NULL , NULL, &si , &pi );				
		WaitForSingleObject(pi.hProcess, INFINITE);															
		TerminateProcess(pi.hProcess, uExitCode);	
		ifstream esito("esito.txt");
		string res;
		esito>>res;
		cout<<res<<"\n";
		if(res!="Output_Corretto")
			break;
		esito.close();
	}
}
