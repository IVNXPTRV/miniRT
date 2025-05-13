import random

N = 42
for i in range(N):
	pos = ",".join([str(random.random() * 10) for _ in range(3)])
	normal = ",".join([str(random.random() * 2 - 1) for _ in range(3)])
	diameter = random.random() * 4 + 0.1
	height = random.random() * 4 + 0.1
	color = ",".join([str(int(random.random() * 255.99)) for _ in range(3)])
	
	# print(f"sp {pos} {diameter} {color}")
	# print(f"pl {pos} {normal} {color}")
	print(f"cy {pos} {normal} {diameter} {height} {color}")
