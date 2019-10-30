# Debugger-Windows
Strumento per effettuare lo stess test di soluzioni C++ su Windows.

Questo strumento funziona solamentre per trovare corner-cases in cui la soluzione produce un output sbagliato oppre sfora il tempo limite. Per utilizzare lo strumento serve avere (ovviamente) la soluzione che bisogna debuggare, una soluzione che produce un output corretto (anche se lenta), un codice che letti i 2 output, prodotti dalla soluzione corretta e da quella sbagliata, dice se l'output della soluzione è corretto, un generatore. Tutti questi file devono essere scritti in C++.

Il suo utilizzo primario è utilizzare lo strees test ed una soluzione lenta per trovare gli errori in una soluzione veloce.

* correctSolution.cpp contiene la soluzione che produce gli output corretti.
* wrongSolution.cpp contine la soluzione che dovete correggere.
* Correttore.cpp devide se l'output prodotto è coinforme a quello corretto.
* Debugger.cpp è il principale che effettua effettivamente lo stress test.
* Generatore.cpp è il file in cui dovrete scrivere il vostro generatore.

Per utilizzare lo strumento scrivere nei file descritti precedentemente quello richiesto, compliate tutti i cpp e poi eseguite Debugegr.cpp, potete modificare i parametri tc per cambiare quanti test verranno eseguiti e k che indica il numero di secondi per i quali potrà rimanere in esecuzione il codice sbagliato.

L'esecuzione termina quando , o finiscono i testcases, oppure wrongSolution.cpp non sfora il tempo limite o produce un output differente da quello corretto: in entrambi i casi troverete in input.txt il test-case che cercavate. 
