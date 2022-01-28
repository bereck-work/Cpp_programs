## Welcome
This is repository that contains some cpp programs I wrote.


## Installation
There are currently two ways to install:

There are currently two ways to install:

Use [pip package manager](https://pip.pypa.io/en/stable/) to install the libraries from ``requirements.txt`` file.

```bash
pip install -r requirements.txt
```

If you have [Poetry package manager](https://python-poetry.org/) installed, you can install the dependencies using 
the following command.

You will also need g++ compiler to compile the cpp programs.

## Running the programs
C++ programs are located in the cpp directory, and you can run them by executing the following command.

```bash
    python3 launcher.py
```

It will open a simple CLI that will ask which file to execute, and it will execute it.

## Why did I make a python program to run cpp programs?
I was lazy to call and run g++ every time I wanted to compile a cpp program, so I made a python program to do that.