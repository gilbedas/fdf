x;
y;
z;

OX;
OY;


p1x = zoom * (OX + (10 * x * cos(angle)) - (10 * y * sin(angle)));
p1y = zoom * (OY - (6 * x * sin(angle)) - (6 * y * cos(angle)) - (8 * grid[y][x]));

p2x = zoom * (OX + (10 * (x + 1) * cos(angle)) - (10 * y * sin(angle)));
p2y = zoom * (OY - (6 * (x + 1) * sin(angle)) - (6 * y * cos(angle)) - (8 * grid[y][x + 1]));

p3x = zoom * (OX + (10 * x * cos(angle)) - (10 * (y + 1) * sin(angle)));
p3y = zoom * (OY - (6 * x * sin(angle)) - (6 * (y + 1) * cos(angle)) - (8 * grid[y + 1][x]));

draw_line(p1, p2);
draw_line(p1, p3);
