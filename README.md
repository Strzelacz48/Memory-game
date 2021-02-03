# Projekt w języku C
## Tematem projektu jest gra w memory.
Program został napisany w języku C z użyciem narzędzia GTK+3.0 do GUI.
Testowany na linuxsie.
## Zasady gry
Celem gry jest zapełnienie całej planszy parami cyfr od 0 do 17 włącznie.
Aby to osiągnąć trzeba wybierać parami dwa guziki z ukrytymi pod nimi liczbami. Na planszy znajduje się 18 par różnych losowo ułożonych liczb. 

## Instalacja
Aby zainstalować program należy zainstalować biblioteki potrzebne do uruchamiania programów napisanych za pomocą GTK+3.0.
#### Linux
- git >= 2.25.0
- gcc >= 9.0.0
- gtk >= 3.0

ponieważ przy użyciu tych wersji projekt był tworzony.
Żeby je pobrać wystarczy otworzyć terminal i wpisać:
```
sudo apt install git gcc libgtk-3-dev -y
```
na Ubuntu i pochodnych oraz:
```
sudo pacman -S git gcc gtk3
```
na Archu i pochodnych

#### Windows
- git >= 2.25.0
- gtk >= 3.0

Gita można pobrać z <https://git-scm.com/download/win>

A GTK z <https://www.gtk.org/docs/installations/windows/>

Następnie pobrać pliki wejść do folderu zawierającego a następnie wywołać polecenia:
````````
Make
````````
````````
./MemoryGame
````````
## Użytkowanie
Użytkownik może korzystać z matrycy guzików reprezentujących pole gry, a także z guzika "Mieszaj" który resetuje stan rozgrywki i losuje nowy układ planszy. Dolny guzik służy do wysyłania użytkownikowi wiadomości i nie jest interaktywny.
Kiedy użytkownik wybierze dwa guziki i nie są one takie same pozostaną one widoczne do czasu wybrania nowego guzika.

![](https://i.imgur.com/fmALOWF.png)
