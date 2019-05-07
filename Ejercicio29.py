from mpl_toolkits.mplot3d import Axes3D  # noqa: F401 unused import

import matplotlib.pyplot as plt
import numpy as np
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter


fig = plt.figure(figsize=(14,5))
ax = fig.add_subplot(1, 2, 1, projection='3d')
data= np.loadtxt("Solucion.dat")
x=np.arange(0,101,1)
y=np.arange(0,301,1)
x1=np.arange(0,101,1)/100
y1=np.arange(0,301,1)*6/300
def f(x,y):
    return data[x,y]

X , Y = np.meshgrid(x,y)
X1 , Y1 = np.meshgrid(x1,y1)
surf = ax.plot_surface(Y1,X1,f(Y,X),cmap=cm.coolwarm,linewidth=0, antialiased=True)

ax.set_xlabel("Time [seconds]")
ax.set_ylabel("Position [meters]")


fig.colorbar(label="Desplazamiento [metros]", ticks=[-0.75,-0.5,-0.25,0,0.25,0.5,0.75])

ax1 = fig.add_subplot(1, 2, 2)
ax1.plot(x1,data[0], label="tiempo inicial")
ax1.plot(x1,data[-1], label="tiempo final")
ax1.legend()
ax1.set_xlabel("Posicion [metros]")
plt.show()
plt.savefig("onda.png")