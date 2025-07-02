#!/usr/bin/env python

from mpi4py import MPI

# Get the MPI communicator.
comm = MPI.COMM_WORLD

# Get the rank of the process.
rank = comm.Get_rank()

# Get the number of processes.
size = comm.Get_size()

# Print a hello message.
print(f"Hello from rank {rank} of {size}.")
