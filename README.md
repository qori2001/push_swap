*This project has been created as part of the 42 curriculum by `otqori`.*

# push_swap

## Description

**push_swap** sorts a list of integers using two stacks (`a` and `b`) and a
limited set of instructions, while trying to use as few instructions as possible.
The program prints the list of instructions to the standard output; nothing is
actually "returned" — a checker program reads those instructions and verifies that
stack `a` ends up sorted in ascending order and stack `b` is empty.

### Allowed instructions

| Instruction | Effect |
|-------------|--------|
| `sa` / `sb` / `ss` | swap the first two elements of `a` / `b` / both |
| `pa` / `pb` | push the top of `b` onto `a` / the top of `a` onto `b` |
| `ra` / `rb` / `rr` | rotate up: first element becomes last (`a` / `b` / both) |
| `rra` / `rrb` / `rrr` | reverse rotate: last element becomes first (`a` / `b` / both) |

### Algorithm

**Parsing.** All arguments are joined and split on spaces, so both
`./push_swap 3 2 1` and `./push_swap "3 2 1"` work. Each token must be an optional
`+`/`-` followed by digits, fit in an `int`, and appear only once. Otherwise the
program prints `Error` on stderr and exits.

**Small stacks (2 to 5 numbers).** Hard-coded strategies: `sort_3` needs at most 2
instructions; for 4 and 5 numbers the smallest values are pushed to `b`, the
remaining 3 are sorted, and the values are pushed back (at most 10 instructions
for 5 numbers).

**Big stacks (6+ numbers) — chunk sort.**
1. Each value is replaced by its rank (`0 … n-1`), so the algorithm works on
   simple indexes instead of arbitrary integers.
2. The ranks are split into chunks (22 per chunk for ≤ 100 numbers, 65 for ≤ 500).
   For each chunk, the element of the chunk closest to the top or bottom of `a`
   is brought up and pushed to `b`. If it belongs to the lower half of the chunk,
   `b` is rotated so small values sink to the bottom (combined with `ra` as `rr`
   when possible). This leaves `b` roughly ordered.
3. Numbers are pushed back to `a` from largest to smallest. If `max - 1` is cheaper
   to reach than `max`, it is pushed first and then fixed with a single `sa`.

### Results (random inputs, tested with `checker_linux`)

| Size | Average | Worst seen | 42 target for full points |
|------|---------|------------|---------------------------|
| 3    | ≤ 2     | 2          | ≤ 3 |
| 5    | ≤ 10    | 10         | ≤ 12 |
| 100  | ~630    | ~690       | < 700 |
| 500  | ~5300   | ~5600      | < 5500 |

## Instructions

### Requirements
- `cc`, `make`
- Your `libft` in a `libft/` folder at the root (needs `ft_split`, `ft_strjoin`,
  `ft_strdup`), with its own Makefile producing `libft/libft.a`.

### Build
```bash
make          # builds push_swap
make bonus    # builds checker (needs bonus/checker.c)
make clean    # removes object files
make fclean   # removes objects and binaries
make re       # full rebuild
```

### Usage
```bash
./push_swap 2 1 3 6 5 8
./push_swap "4 67 3 87 23"

# count instructions
ARG=$(shuf -i 1-10000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# verify with the provided checker
ARG=$(shuf -i 1-10000 -n 500 | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG
```

### Behaviour on special inputs
| Input | Output |
|-------|--------|
| no argument | nothing |
| already sorted / single number | nothing |
| `""`, `"   "`, `1 "" 2` | `Error` |
| non-numeric (`1 2a`, `+`, `-`) | `Error` |
| duplicates (`1 1`, `1 +1`, `0 -0`) | `Error` |
| outside int range (`2147483648`, `-2147483649`, huge numbers) | `Error` |

### Project structure
```
.
├── Makefile
├── push_swap.c              main
├── push_swap.h
├── libft/                   your libft
└── src/
    ├── parsing.c                input validation and conversion
    ├── fonctions_string_utils.c join args, empty-arg check, error exit
    ├── operations_1.c           ra / rb / rra / rrb
    ├── operations_2.c           pa / pb
    ├── operations_3.c           rr / rrr
    ├── operations_4.c           sa / sb / ss + array shifting
    ├── sort_small.c             2 to 5 numbers
    ├── sort_big.c               chunk sort
    ├── founction_sort_utils.c   index/rank helpers
    ├── founction_sort_utils_1.c min / max / rotate-to-top helpers
    └── utils_main.c             stack creation, free, is_sort
```

## Resources

- 42 `push_swap` subject
- [Push_swap: an easy and efficient algorithm – Medium (Jamie Dawson)](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- Visualizer: [o-reo/push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
- Tester: [gemartin99/Push-Swap-Tester](https://github.com/gemartin99/Push-Swap-Tester)

**AI usage:** an AI assistant (Claude) was used to review the code for bugs
(integer overflow in parsing, empty-argument handling, missing malloc checks),
to split files to respect the Norm, to improve the Makefile, and to help write
this README. The algorithm design and the logic were reviewed and understood
before being kept.
