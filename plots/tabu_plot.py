import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

lim = 40
def init_animation():
    ax.set_xlim(-lim, lim)
    ax.set_ylim(-lim, lim)
    return sc,

filename = "tabu_1_2_15.csv"

data = pd.read_csv("../output/" + filename, names=["y", "x1", "x2", "checked_points"])
y = data['y'].tolist()
x1 = data['x1'].tolist()
x2 = data['x2'].tolist()
string_list = data['checked_points'].tolist()

# extract points from the end of each row, points are separated by ";"
checked_points = []
for string in string_list:
    num_strings = string.split(";")
    nums = [float(x) for x in num_strings]
    points = []
    for i in range(0, int(len(nums)/2)):
        points.append([nums[2*i], nums[2*i + 1]])
    checked_points.append(points)

#wykres
fig, ax = plt.subplots()
sc = ax.scatter(x1[0], x2[0], color='blue', s=3)

def update_animation(frame):
    ax.clear()
    ax.scatter(x1[frame], x2[frame], color='blue', s=3, label='znalezione minimum')
    x = []
    y = []
    for point in checked_points[frame]:
        x.append(point[0])
        y.append(point[1])
    ax.scatter(x, y, color='#ffd359', s=0.1, label='rozpatrywane punkty')

    ax.set_xlim(-lim, lim)
    ax.set_ylim(-lim, lim)
    plt.legend(loc='upper right')
    plt.title('Tabu search dla funkcji 1')
    text = ax.text(0.4, -0.11, f'iteracja {frame}', transform=ax.transAxes, fontsize=12)
    ax.set_aspect('equal', adjustable='box')
    plt.grid(True)
    return sc,

ani = FuncAnimation(fig, update_animation, frames=len(y), init_func=init_animation, blit=True, interval = 200)
ani.save('../output/tabu.gif')

