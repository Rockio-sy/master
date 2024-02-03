#!/usr/bin/python3

import sys
import scipy.sparse as sp
import os.path
from itertools import count

if len(sys.argv) == 4:
    nrows = int(sys.argv[1])
    ncols = int(sys.argv[2])
    density = float(sys.argv[3])
else:
    buf = input("Введите количество строк, столбцов и плотность (до 1): ").strip().split()
    nrows, ncols, density = int(buf[0]), int(buf[1]), float(buf[2])
    
sparse_matrix = sp.random(nrows, ncols, density, dtype=int)

density_percents = int(density * 100) if (density * 100).is_integer() else density * 100

for i in count(1):
    if not os.path.isfile(f"data/{nrows}x{ncols}_{density_percents}_{i}.txt"):
        file = open(f"data/{nrows}x{ncols}_{density_percents}_{i}.txt", "w")
        break

file.write(f"{nrows} {ncols} {sparse_matrix.count_nonzero()}\n")

for elem, row, col in zip(sparse_matrix.data, sparse_matrix.row, sparse_matrix.col):
    file.write(f"{row} {col} {elem % 100000}\n")

file.close()
