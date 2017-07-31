## Introduction
This is a simple physics simulating system that calculate the state of several balls, inspired by the game Orbit, written in pure C++.

## Features
- add force field manually
- change the smallest time atom to control the compute speed and result.

## Details

### Hit

When handling the hit event, i applyed an ideal model to compute the result.

As is defined,
$$
e = \frac{v'_2 - v'_1}{v_1 - v_2}
$$
Here, i assume that $e=1$, or, $v'_2 - v'_1 = v_1 - v_2$

And we know that:
$$
m_1 v_1 + m_2 v_2 = m_1 v'_1 + m_2 v'_2
$$
and,
$$
\frac{1}{2} m_1 v_1^2 + \frac {1}{2} m_2 v_2^2 = \frac{1}{2} m_1 v_1^{,2} + \frac {1}{2} m_2 v_2^{,2}
$$
Then we can get the solution:
$$
v'_1 = \frac{(m_1 - m_2) v_1 + 2 m_2 v_2}{m_1 + m_2}
$$

$$
v'_2 = \frac{(m_2 - m_1) v_2 + 2 m_1 v_1}{m_1 + m_2}
$$

> Notes:
>
> When it comes to some complex hit problem, we can split the vector into two directions, and solve it.
>
> If several balls hit together, we can solve each simple problem respectively, and add up offset vectors. 







## About
Author: Linyxus

Blog:   http://blog.linyxus.xyz/
