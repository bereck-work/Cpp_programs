## Welcome
This repository contains some c++ programs I wrote for fun.


## Installation
There are currently two ways to install:

Use [pip package manager](https://pip.pypa.io/en/stable/) to install the libraries from ``requirements.txt`` file.

```bash
pip install -r requirements.txt
```

If you have [Poetry package manager](https://python-poetry.org/) installed, you can install the dependencies using 
the following command.
```
poetry install
```

You will also need ``g++`` compiler to compile the cpp programs.

## Running the programs
The C++ programs are located in the `cpp` directory, and you can run them by executing the following command.

```bash
   python3 launcher.py
```

This command opens an user interface, which will ask you want c++ file you want to execute, and then it will run the c++ file for you.

## Why did I make a python program to run cpp programs?
I was lazy to call and run `g++` every time I wanted to compile a c++ program, so I made a python program to automate that with a cool command line interface.
You can run the c++ files using `g++` directly, if you want to.
