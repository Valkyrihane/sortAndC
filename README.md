# SortAndC
Implementation of a few sorting algorithms in C



### Installation

```bash
git clone https://github.com/Valkyrihane/sortAndC.git
cd sortAndC/
make
```



### Usage

```bash
./sortAndC --help

./sortAndC bubble examples/simple_both
```



* **Algorithm**: sorting method displayed in the `--help` command
* **File**: File containing numbers separated by a line break



### How it works

sortAndC reads from a file a list of numbers separated by a line break (second argument) and uses the algorithm specified (first argument) in order to sort the numbers and display them on the standard output.



The computation time is started once the sorting begins (after reading from the file) and stops once the sorting ends.