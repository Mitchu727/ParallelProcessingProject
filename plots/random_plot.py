import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

lim = 40
def init_animation():
    ax.set_xlim(-lim, lim)
    ax.set_ylim(-lim, lim)
    return sc,

filename = "random_1_2_50.csv"

data = pd.read_csv("../output/" + filename, names=["y", "xmin1", "xmin2", "x1", "x2"])
y = data['y'].tolist()
xmin1 = data['xmin1'].tolist()
xmin2 = data['xmin2'].tolist()
x1 = data['x1'].tolist()
x2 = data['x2'].tolist()

# wykres
fig, ax = plt.subplots()
sc = ax.scatter(xmin1[0], xmin2[0], color='blue', label='x min')
sc = ax.scatter(x1[0], x2[0], color='orange', label='aktualnie rozpatrywany punkt')
plt.legend()


def update_animation(frame):
    ax.clear()
    ax.scatter(xmin1[frame], xmin2[frame], color='blue', label='dotychczas znalezione minimum')
    ax.scatter(x1[frame], x2[frame], color='orange', label='aktualnie rozpatrywany punkt')
    ax.set_xlim(-lim, lim)
    ax.set_ylim(-lim, lim)
    plt.legend(loc='upper right')
    plt.title('Poszukiwanie losowe dla funkcji 1')
    plt.grid(True)
    text = ax.text(0.4, -0.11, f'iteracja {frame}', transform=ax.transAxes, fontsize=12)
    return sc,

ani = FuncAnimation(fig, update_animation, frames=len(y), init_func=init_animation, blit=True, interval = 300)
ani.save('../output/random.gif')

