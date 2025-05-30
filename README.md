# Boolean Algebra

Boolean algebra is a branch of algebra that deals with only two values where `true` and `false` which are represented by `1` and `0` respectively. It is used in computer science and digital logic.

## Operators

Operators in boolean algebra take two inputs and return a single output

| **Operator** | **Symbol** | **Use Case** | **Precedence** | **Description** |
|---|---|---|---|---|
| NOT | `¬` | `¬A` | First | Inverts the value of A |
| AND | `•` | `A • B` | Second | Returns true only if both A and B are true |
| OR | `+` | `A + B` | Third | Returns true if either A or B is true |

I will not be using these exact symbols for my project, but they will follow the same rules.

For example:
```
AB̅C̅D̅+AB̅C̅D+AB̅CD̅+AB̅CD+ABC̅D̅+ABC̅D+ABCD̅+ABCD
```
is the same as:
```
A • ¬B • ¬C • ¬D + A • ¬B • ¬C • D + A • ¬B • C • ¬D + A • ¬B • C • D + A • B • ¬C • ¬D + A • B • ¬C • D + A • B • C • ¬D + A • B • C • D
```
just shortened to look more appealing.

There are more operators used in boolean algebra, but I will only be using these three as they make the most sense in terms of regular algebra. Here are the other operators, just in case you are curious:

| **Operator** | **Description** |
|---|---|
| XOR | Returns true if either A or B is true, but not both |
| NAND | Returns true if at least one of A or B is false |
| NOR | Returns true if both A and B are false |
| XNOR | Returns true if A and B are the same value |

## Truth Tables

Truth tables are a way to represent the output of boolean expressions based on all possible combinations of inputs. Below are the truth tables for the basic operations: NOT, AND, and OR.

### NOT
| **Input** | **Output** |
|---|---|
| `0` | `1` |
| `1` | `0` |

### AND
| **Input1** | **Input2** | **Output** |
|---|---|---|
| `0` | `0` | `0` |
| `0` | `1` | `0` |
| `1` | `0` | `0` |
| `1` | `1` | `1` |

### OR
| **Input1** | **Input2** | **Output** |
|---|---|---|
| `0` | `0` | `0` |
| `0` | `1` | `1` |
| `1` | `0` | `1` |
| `1` | `1` | `1` |

## Laws

Just like regular algebra, boolean algebra has laws that govern how expressions can be simplified or manipulated. Below are some of the fundamental laws of boolean algebra, along with their OR and AND forms.

| **Law** | **OR Form** | **AND Form** |
|---|---|---|
| Identity Law | `P + 0 = P` | `P • 1 = P` |
| Idempotent Law | `P + P = P` | `P • P = P` |
| Commutative Law | `P + Q = Q + P` | `P • Q = Q • P` |
| Associative Law | `P + (Q + R) = (P + Q) + R` | `P • (Q • R) = (P • Q) • R` |
| Distributive Law | `P + (Q • R) = (P + Q) • (P + R)` | `P • (Q + R) = (P • Q) + (P • R)` |
| Inversion Law | `¬(¬A) = A` | `¬(¬A) = A` |
| De Morgan's Law | `¬(P + Q) = ¬P • ¬Q` | `¬(P • Q) = ¬P + ¬Q` |
| Complement Law | `P + ¬P = 1` | `P • ¬P = 0` |
| Domination Law | `P + 1 = 1` | `P • 0 = 0` |
| Double Negation Law | `¬(¬A) = A` | `¬(¬A) = A` |
| Absorption Law | `P + (P • Q) = P` | `P • (P + Q) = P` |

---

Thanks to [GeeksforGeeks](https://www.geeksforgeeks.org/boolean-algebra/) for providing the information required for this project.