import matplotlib.pyplot as plt
import matplotlib.patches as patches

def plot_rectangles(x1, y1, x2, y2, x3, y3, x4, y4):
    fig, ax = plt.subplots()

    # Plot Rectangle 1
    rect1 = patches.Rectangle((x1, y1), x2 - x1, y2 - y1, linewidth=1, edgecolor='r', facecolor='red')
    ax.add_patch(rect1)

    # Plot Rectangle 2
    rect2 = patches.Rectangle((x3, y3), x4 - x3, y4 - y3, linewidth=1, edgecolor='b', facecolor='blue')
    ax.add_patch(rect2)

    # Set axis limits
    ax.set_xlim(min(x1, x3) - 1000, max(x2, x4) + 1000)
    ax.set_ylim(min(y1, y3) - 1000, max(y2, y4) + 1000)

    plt.gca().set_aspect('equal', adjustable='box')  # Equal aspect ratio for x and y axes
    plt.show()
 
# Example usage with the reordered points
x1, y1, x2, y2 = 569, 8249, -1828, -2051 
x3, y3, x4, y4 = 3265, 7028, 7715, -775 

# Reorder the points if needed
if x1 > x2:
    x1, x2 = x2, x1
if y1 > y2:
    y1, y2 = y2, y1

if x3 > x4:
    x3, x4 = x4, x3
if y3 > y4:
    y3, y4 = y4, y3

# Example usage with the reordered points
plot_rectangles(x1, y1, x2, y2, x3, y3, x4, y4)
