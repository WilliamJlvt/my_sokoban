# Unix System Programming - My Sokoban
Warehouse keeper (sokoban) game in computer terminal, project for semester 1 of the Epitech Unix System Programming module (B-PSU-100).

## Introduction
This project involves implementing a terminal version of the classic Sokoban game. The game is played on a map, and the player must move boxes onto storage locations. The player can only push one box at a time, and the boxes can only be pushed, not pulled. The game concludes when all the boxes have been moved onto storage locations, at which point the result is displayed.

The full description of the project can be found in [subject.pdf](pdf/B-PSU-100_my_sokoban.pdf).

## Prerequisites
 - [Make](https://www.gnu.org/software/make/)
 - [GCC](https://gcc.gnu.org/)
 - [LibC](https://www.gnu.org/software/libc/)
 - [NCurses](https://www.gnu.org/software/ncurses/)

## Installation
```
B-PSU-100> git clone git@github.com:WilliamJlvt/my_sokoban.git
...
B-PSU-100> make
...
```

## Usage
```
B-PSU-100> ./my_sokoban -h
USAGE
    ./my_sokoban map
DESCRIPTION
    map  file representing the warehouse map, containing ‘#’ for walls,
         ‘P’ for the player, ‘X’ for boxes and ‘O’ for storage locations.

```

## Results
| test                                            | passed | results |
|-------------------------------------------------|--------|---------|
| 01 - usage and input checks                     | 4/4    | 100%    |
| 02 - basic moves                                | 4/4    | 100%    |
| 03 - basic collisions and box on targets        | 4/4    | 100%    |
| 04 - intermediate moves and collisions          | 6/6    | 100%    |
| 05 - intermediate maps tests                    | 4/4    | 100%    |
| 06 - intermediate winning and losing conditions | 2/2    | 100%    |
| 07 - final moves and collisions                 | 6/6    | 100%    |
| 08 - final maps tests                           | 4/4    | 100%    |
| 09 - final winning and losing conditions        | 2/2    | 100%    |
| total                                           | 36/36  | 100%    |
Final mark: 20

## Coding style
All the source code has been written according to the [Epitech C Coding Style](https://williamjlvt.github.io/assets/coding_style/epitech_c_coding_style.pdf).
#### errors
| Fatal | Major  | Minor | Info |
|-------|--------|-------|------|
| 0     | 0      | 0     | 0    |

## Unit tests
Unit tests are written using the [Criterion](https://github.com/Snaipe/Criterion) framework.
You can find the tests in the [bonus](bonus) directory. Just run `make` to build the tests and `./my_sokoban_tests` to run them.

## Authors
* **William JOLIVET** ([GitHub](https://github.com/WilliamJlvt) / [LinkedIn](https://www.linkedin.com/in/william-jolivet-64951a24b/))

## License
This project is licensed under the GNU Public License version 3.0 - see the [LICENSE](LICENSE) file for details.
