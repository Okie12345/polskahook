# Polskahook
[![C++](https://img.shields.io/badge/language-C%2B%2B-%23f34b7d.svg?style=flat-square)](https://en.wikipedia.org/wiki/C%2B%2B)
[![TF2](https://img.shields.io/badge/game-TF2-orange.svg?style=flat-square)](https://store.steampowered.com/app/440/Team_Fortress_2/)
[![GNU/Linux](https://img.shields.io/badge/platform-GNU%2FLinux-ff69b4?style=flat-square)](https://www.gnu.org/gnu/linux-and-gnu.en.html)
[![x86](https://img.shields.io/badge/arch-x86-red.svg?style=flat-square)](https://en.wikipedia.org/wiki/X86)
[![Licencja](https://img.shields.io/github/license/explowz/cathook.svg?style=flat-square)](LICENSE)
[![Problemy](https://img.shields.io/github/issues/explowz/cathook.svg?style=flat-square)](https://github.com/explowz/cathook/issues)

Darmowy program do ćwiczenia o otwartym źródle na GNU/Linux do gry **Team Fortress 2**. Zaprojektowany jako internal cheat - [Wspólna Biblioteka](https://en.wikipedia.org/wiki/Library_(computing)#Shared_libraries) (SO) ładowany do procesu gry. Kompatybilny ze Steamową wersją gry.

## Spis Treści

- [Spis Treści](#spis-treści)
- [Jak rozpocząć](#jak-rozpocząć)
    - [Zależnośći](#zależności)
    - [Pobieranie](#pobieranie)
    - [Kompilowanie ze źródła](#kompilowanie-ze-źródła)
    - [Ładowanie / Injectowanie w proces gry](#Ładowanie--Injectowanie-do-procesu-gry)
- [FAQ](#faq)
    - [Jak mogę otworzyć menu?](#jak-mogę-otworzyć-menu)
    - [Gdzie jest zlokalizowany mój plik cfg?](#gdzie-jest-zlokalizowany-mój-plik-cfg)
    - [Ładowanie / Injectowanie do procesu](#Ładowanie--Injectowanie-do-procesu-gry)

## Jak rozpocząć

### Zależności

Paczka `dialog` nie jest obowiązkowa, ale rekomendowana.

Zależnośći są sprawdzane automatycznie przez [dependencycheck](https://github.com/explowz/cathook/blob/master/scripts/dependencycheck).

### Pobieranie

Otwórz okno terminala i wpisz następującą komendę:

    bash <(wget -qO- https://raw.githubusercontent.com/explowz/One-in-all-cathook-install/master/install-all)

Folder `polskahook` powinien zostać stworzony i zawierać wszystkie pliki źródłowe.

### Kompilowanie ze źródła

Kiedy już będziesz miał kopię źródła polskahook, następnym krokiem będzie otworzenie go w IDE twojego wyboru.

Zmień wszystkie `-march=native -mtune=native` argumenty w [CMakeLists.txt](https://github.com/explowz/cathook/blob/master/CMakeLists.txt) do `-march=<your cpu-type> -mtune=<your cpu-type>`. Powinno to skutkować bardziej wydajnym kodem, zoptymalizowanym pod twoje CPU. Listę prawidłowych opcji można znaleźć [tutaj](https://gcc.gnu.org/onlinedocs/gcc/x86-Options.html).

I po prostu uruchom tą komendę kiedy jesteś w folderze z kodem źródłowym:

    ./update

Jeżeli wszytsko poszło dobrze, powinieneś otrzymać następującą binarkę `libcathook.so`.

### Ładowanie / Injectowanie do procesu gry

Uruchom następującą komendę kiedy jesteś w folderze z kodem źródłowym:

    sudo ./attach

To zinjectuje `libcathook.so` do procesu `hl2_linux`.

Kiedy zainjectowany, klawisz `INSERT` uruchamia menu.

## FAQ

### Jak mogę otworzyć menu?
Naciśnij klawisz <kbd>INSERT</kbd> kiedy w oknie TF2.

### Gdzie jest zlokalizowany mój plik cfg?
Pliki konfiguracyjne są zlokalizowane w folderze `cathook` który jest zlokalizowany w folderze `opt` (`/opt/cathook/data`). Plik cfg jest czytelny dla człowieka i może być edytowany w edytorze tekstu twojego wyboru.
