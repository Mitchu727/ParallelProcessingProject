import pandas as pd

if __name__ == "__main__":
    filename = "random_2_2_10000"
    dataToPlot = pd.read_csv("../output/" + filename + ".csv", names=["y_min", "y"]).reset_index()
    ax = dataToPlot.plot(kind='scatter', x='index', y='y', color=['orange'], s=1.5)
    ax = dataToPlot.plot(ax=ax, x='index', y='y_min', legend=False)
    # ax.figure.show()
    ax.figure.savefig(filename + ".png")