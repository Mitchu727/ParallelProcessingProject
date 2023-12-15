import pandas as pd


filename = "time_series_tabu_100"

times = pd.read_csv("../output/" + filename + ".csv", names=["t"]).reset_index()
times["acc"] = times['t'][0] / times['t']
print(times["acc"])
ax = times.plot(kind='scatter', x='index', y='acc', color=['blue'], s=15)
ax.set_xticks(times['index'], [f"$2^{{ {x} }}$" for x in times['index']])
ax.set_xlabel("Liczba wątków")
ax.set_ylabel("Przyspieszenie")
ax.set_ylim(bottom=0)
ax.figure.savefig("../output/" + filename + ".png")

