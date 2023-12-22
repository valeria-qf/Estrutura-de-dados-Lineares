import timeit
from karatsuba import karatsuba_algorithm
from direct_mult import direct_multiply

x = 1234
y = 9876

karatsuba_time = timeit.timeit(stmt=lambda: karatsuba_algorithm(x, y), globals=globals(), number=1000)
direct_multiply_time = timeit.timeit(stmt=lambda: direct_multiply(x, y), globals=globals(), number=1000)

print(f'Tempo de execução (Karatsuba): {karatsuba_time:.6f} segundos')
print(f'Tempo de execução (Multiplicação direta): {direct_multiply_time:.6f} segundos')