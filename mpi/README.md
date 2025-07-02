# MPI

## Install MPI

Use homebrew to install `mpich` or `openmpi` on MacOS:

```bash
brew install mpich
```

## Install mpi4py

```bash
python -m pip install -r mpi/requirements.txt
```

## Run MPI

```bash
mpirun -n 4 python mpi/hello.py

mpiexec -n 4 python mpi/hello.py
```
