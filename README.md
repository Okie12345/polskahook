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


The polskahook folder should be created and contain all source files.

### Compiling from Source

Once you have a copy of the polskahook source, the next step is to open it in your chosen IDE.

Change all -march=native -mtune=native arguments in [CMakeLists.txt](https://github.com/explowz/cathook/blob/master/CMakeLists.txt) to -march=<your cpu-type> -mtune=<your cpu-type>. This should result in more efficient code optimized for your CPU. You can find a list of valid options [here](https://gcc.gnu.org/onlinedocs/gcc/x86-Options.html).

And simply run this command when you are in the source code folder:

    ./update

If everything goes well, you should receive the binary libcathook.so.

### Loading / Injecting into the Game Process

Run the following command when you are in the source code folder:

    sudo ./attach

This will inject libcathook.so into the hl2_linux process.

Once injected, the INSERT key opens the menu.

## FAQ

### How can I open the menu?
Press the <kbd>INSERT</kbd> key.

### Where is the config file located?
Configuration files are located in the `cathook` folder, which is in the `opt` directory (/opt/cathook/data). The cfg file is human-readable and can be edited in the text editor of your choice.
