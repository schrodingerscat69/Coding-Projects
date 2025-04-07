from ucimlrepo import fetch_ucirepo
import matplotlib.pyplot as plt
import seaborn as sns
from scipy import stats
import numpy as np
import pandas as pd

# fetch dataset
data = fetch_ucirepo(id=144)
df = data.data.features

age = df["Attribute13"]

plt.figure(figsize=(10,5))
sns.histplot(age, kde=False, stat='density', bins=20, color='skyblue', edgecolor='black')
mu, std = age.mean(), age.std()
xmin, xmax = age.min(), age.max()
x_vals = np.linspace(xmin, xmax, 100)
plt.plot(x_vals, stats.norm.pdf(x_vals, mu, std), 'r--', label=f'N({mu:.2f}, {std:.2f}^2')

shape_ln, loc_ln, scale_ln = stats.lognorm.fit(age)
pdf_ln = stats.lognorm.pdf(x_vals, shape_ln, loc=loc_ln, scale=scale_ln)
plt.plot(x_vals, pdf_ln, 'g--', label='log-Normal')

alpha_g, loc_g, scale_g = stats.gamma.fit(age)
pdf_gamma = stats.gamma.pdf(x_vals, a=alpha_g, loc=loc_g, scale=scale_g)
plt.plot(x_vals, pdf_gamma, 'b--', label='Gamma')

loc_exp, scale_exp = stats.expon.fit(age)
pdf_exp = stats.expon.pdf(x_vals, loc=loc_exp, scale=scale_exp)
plt.plot(x_vals, pdf_exp, 'm:', label='Exponential')

plt.title("Age Distribution")
plt.xlabel("Age")
plt.ylabel("Density")
plt.legend()
plt.grid(True)
plt.show()

stats.probplot(age, dist="norm", plot=plt)
plt.title("Q-Q plot for Age")
plt.grid(True)
plt.show()
