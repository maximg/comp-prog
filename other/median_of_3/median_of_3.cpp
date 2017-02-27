


a b c

a < b
b < c
a < c

(a < b) + (a > c) = 2
(a > b) + (a < c) = 2


  int ab = v[0] < v[1];
  int bc = v[1] < v[2];
  int ac = v[0] < v[2];

  int bc1 = ab ^ bc;
  int ac1 = ab ^ ac;

  int idx = (1 + bc1 + ac1) % 3;