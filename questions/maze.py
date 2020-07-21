maze = list()
m, n = map(int, input().split())
move_x = [1, 0, -1, 0]
move_y = [0, 1, 0, -1]
dir_num = 0
history = list()
for i in range(m):
    maze.append(list(input()))
ent_x, ent_y = map(int, input().split())
ext_x, ext_y = map(int, input().split())
x = ent_x
y = ent_y
maze[x][y] = '+'
while x != ext_x and y != ext_y:
    if dir_num < 4:
        x_temp = x + move_x[dir_num]
        y_temp = y + move_y[dir_num]
        if 0 <= x_temp < n and 0 <= y_temp < m and maze[x_temp][y_temp] == ' ':
            history.append([x, y, dir_num])
            x = x_temp
            y = y_temp
            maze[x][y] = '+'
            dir_num = 0
        else:
            dir_num += 1
    else:
        if len(history) == 0:
            print('error')
            break
        last = history.pop()
        x = last[0]
        y = last[1]
        dir_num = last[2] + 1
for i in history:
    print(f"({i[0]} , {i[1]}) -> ", end='')
print(f"({ext_x} , {ext_y})")

# '#' means wall, ' ' means rode, '+' means footstep
'''
8 8
# ######
#  ## ##
## ## ##
## ## ##
#     ##
##### ##
#      #
###### #
0 1
7 6
'''
