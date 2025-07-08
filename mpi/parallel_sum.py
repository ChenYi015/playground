#!/usr/bin/env python3

from mpi4py import MPI
import numpy as np

if __name__ == "__main__":
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()

    if rank == 0:
        data = np.arange(100)
        print("Data:", data)
    else:
        data = None

    # Broadcast the data to all processes.
    data = comm.bcast(data, root=0)

    # Compute the local sum.
    local_sum = np.sum(data[rank::size])
    print("Local sum:", local_sum, "rank:", rank, "size:", size)

    # Reduce the local sums to the root process.
    total_sum = comm.reduce(local_sum, op=MPI.SUM, root=0)
    if rank == 0:
        print("Total sum:", total_sum)
