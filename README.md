# GameOfLife
Cellular automaton - game of life (John Horton Conway) implementation with configuration file in JSON format.

![Demo](https://raw.githubusercontent.com/jzyra/GameOfLife/master/demo.gif)

#Build
For build this tool, you must install sdl and json library.

    sudo apt-get install libsdl1.2-dev libjson0 libjson0-dev
    
And run :

    make
    
#Usage

For run this tool, you must make configuration file and run tool with configuration file in parameter.

#Configuration file

Configuration file is in JSON format.

For edit a configuration file. You can use this parameters :
- width : Window's size in pixels for width.
- height : Window's size in pixels for height.
- number_cellulars_x : Number of cellulars in x axis.
- number_cellulars_y : Number of cellulars in y axis.
- title : Window's title.
- cellulars : Contain cellulars for init cellular automaton.
