# ParallelProcessingProject
Project for "Parallel and distriuted processing" (pol. Programowanie równoległe i rozproszone) course at Warsaw University of Technology

# Build and run
You can build binaries in project by going to the src folder

```
cd src
```

There you can go build project using command:

```
make build
```

After compiling, to run sequential version type
```
../build/main <algorithm> <function-no> <dimensions> <max-iteration> <save-to-file>
```
where:
* `<algorithm>` - is "random" or "tabu" for rando search and tabu search
* `<function-no>` - is a number of function to optimize; must be `1` or `2`
* `<dimensions>` - is a number of dimension of x; must be positive integer
* `<save-to-file>` - when `T` saves calculation logs to appropriate file in ./output direcotry, otherwise does not

To run OpenMP version, run `build/mainOpenMp` executable with the same arguments as sequential. 

You can specify number of threads by running:

```
export OMP_NUM_THREADS=N
```

Where N is deired number of threads.
