# Computer Game 7

## Disclaimer

Ich werde meine Lösung Schritt-für-Schritt live programmieren.  
Deswegen müsst ihr diese nicht selber lösen, ihr könnt es aber gerne probieren.

## Exercise 1

Die Hindernisse sollen jetzt an zufälligen Positionen init. werden.  
Ebenfalls können sich die Hindernisse jetzt zu einem Nachbarfeld bewegen.  
Dies geschieht immer, wenn der Spieler sich auch bewegt hat.  
Das heißt wir brauchen jetzt eine Zufallsfunktion für die Koordinaten der Hindernisse.  
Ein Nachbarfeld ist +1/-1 in vertikaler und horizontaler Reichtung von der aktuellen Position entfernt.  

So würde die Entwicklung des Spielfelds von einem zum anderen Spielzug aussehen:

![Alt text](../media/Game7_1.png)

Wie man sieht hat sich eins der Hindernisse nach rechts bewegt.  
Dementsprechend gibt es auch eine Wahrscheinlichkeit dafür, dass sich ein Hindernis *nicht* bewegt.
