import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

def init_animation():
    lim = 40
    ax.set_xlim(-lim, lim)
    ax.set_ylim(-lim, lim)
    return sc,

filename = "tabu_1_2_100"

data = pd.read_csv("../output/" + filename + ".csv", names=["y", "x1", "x2"]).reset_index()
x1 = data['x1'].tolist()
x2 = data['x2'].tolist()
y = data['y'].tolist()

fig, ax = plt.subplots()
sc = ax.scatter(x1[0], x2[0])

def update_animation(frame):
    sc.set_offsets([[x1[frame], x2[frame]]])
    return sc,

ani = FuncAnimation(fig, update_animation, frames=len(y), init_func=init_animation, blit=True)
# plt.show()

ani.save(filename + '.gif', writer='Pillow')

