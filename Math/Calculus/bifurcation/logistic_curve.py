import numpy as np
import matplotlib.pyplot as plt

# Logistic map function
def logistic_map(r, x):
    return r * x * (1 - x)

# Parameters
iterations = 100  # Number of iterations
x0 = 0.5  # Initial value
r_values = np.linspace(2.5, 4.0, 400)  # Range of r values

# Set up the plot
plt.figure(figsize=(10, 7))

# Iterate over different values of r
for r in r_values:
    x = x0
    for i in range(iterations):
        x = logistic_map(r, x)
        if i >= iterations // 2:  # Plot after some iterations to stabilize the values
            plt.plot(r, x, ',k', alpha=0.25)  # Plot the points

plt.title("Logistic Map Bifurcation Diagram")
plt.xlabel("r")
plt.ylabel("$x_n$")
plt.show()


