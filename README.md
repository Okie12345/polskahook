# Polskahook
[![C++](https://img.shields.io/badge/language-C%2B%2B-%23f34b7d.svg?style=flat-square)](https://en.wikipedia.org/wiki/C%2B%2B)
[![TF2](https://img.shields.io/badge/game-TF2-orange.svg?style=flat-square)](https://store.steampowered.com/app/440/Team_Fortress_2/)
[![GNU/Linux](https://img.shields.io/badge/platform-GNU%2FLinux-ff69b4?style=flat-square)](https://www.gnu.org/gnu/linux-and-gnu.en.html)
[![x86](https://img.shields.io/badge/arch-x86-red.svg?style=flat-square)](https://en.wikipedia.org/wiki/X86)
[![License](https://img.shields.io/github/license/MasterCatPL/polskahook.svg?style=flat-square)](LICENSE)
[![Issues](https://img.shields.io/github/issues/MasterCatPL/polskahook.svg?style=flat-square)](https://github.com/MasterCatPL/polskahook/issues)

A free, open-source cheating program for GNU/Linux for the game **Team Fortress 2**. Designed as an internal cheat - [Shared Library](https://en.wikipedia.org/wiki/Library_(computing)#Shared_libraries) (SO) loaded into the game process. Compatible with the Steam version of the game.

## Table of Contents

- [Table of Contents](#table-of-contents)
- [Getting Started](#getting-started)
    - [Dependencies](#dependencies)
    - [Downloading](#downloading)
    - [Compiling from Source](#compiling-from-source)
    - [Loading / Injecting into the Game Process](#loading--injecting-into-the-game-process)
- [FAQ](#faq)
    - [How can I open the menu?](#how-can-i-open-the-menu)
    - [Where is my cfg file located?](#where-is-my-cfg-file-located)
    - [Loading / Injecting into the Game Process](#loading--injecting-into-the-game-process)

## Getting Started

### Dependencies

The `dialog` package is not mandatory but recommended.

Dependencies are checked automatically by [dependencycheck](https://github.com/explowz/cathook/blob/master/scripts/dependencycheck).

### Downloading

Open a terminal window and enter the following command:

    bash <(wget -qO- https://raw.githubusercontent.com/MasterCatPL/One-in-all-polskahook-install/master/install-all)


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
Naciśnij klawisz <kbd>INSERT</kbd>

### Gdzie jest zlokalizowany mój plik cfg?
Pliki konfiguracyjne są zlokalizowane w folderze `cathook` który jest zlokalizowany w folderze `opt` (`/opt/cathook/data`). Plik cfg jest czytelny dla człowieka i może być edytowany w edytorze tekstu twojego wyboru.
