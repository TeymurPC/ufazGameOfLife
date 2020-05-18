# ufazGameOfLife
Project of UFAZ Development Techniques course - Game of Life written in C.

## How to install
First clone the project:
`git clone https://github.com/ufazGameOfLife/ufazGameOfLife.git`
Then make sure you have make, cmake, sdl and cunit installed in your system then:
```bash
cd ufazGameOfLife
cmake .
make
```

## How to run the project
Usage:
```
./ufazGameOfLife [-w width] [-h height] [options]
```
Options:
- -s&emsp;&emsp;Print to SDL instead of standart output
- -c&emsp;&emsp;Make board type Circular instead of Clipped
- -d&emsp;&emsp;Debug mode on for standart input