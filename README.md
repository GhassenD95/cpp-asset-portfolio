# Asset Portfolio

CLI portfolio manager for CS 401 Assignment 2. Holds stocks, bonds,
options, and crypto in one polymorphic collection, with per-type value
and risk models.

## Architecture

```
              Asset  (abstract, pure virtual)
             /    |      \        \
        Stock  Bond    Option    Crypto

  Portfolio ──owns──> std::vector<std::unique_ptr<Asset>>
```

`Asset` is a pure interface: no state, all `= 0`. Each derived class owns
its members and implements everything with `override`. `Portfolio` holds
`unique_ptr<Asset>` — no `new`, no `delete`, no slicing, no leaks.

## Build

```bash
cmake --build build
./build/asset_portfolio
```

or, per the spec:

```bash
g++ -std=c++17 -Wall -Wextra -Werror -pedantic -o portfolio \
    main.cpp Stock.cpp Bond.cpp Option.cpp Crypto.cpp Portfolio.cpp
```

## Usage

```
1. Add Stock       5. Remove Asset       9. Sort by Value
2. Add Bond        6. Display All        10. Find Asset
3. Add Option      7. Display by Type    11. Exit
4. Add Crypto      8. Summary
```

## Testing

All spec tests pass:

```
STOCK: 1500   BOND: 9025   OPTION: 25   CRYPTO: 15000
```

Analytics: total 10550, avg risk 41.67, riskiest AAPL150C, safest US10Y.
Valgrind: 0 errors, all blocks freed.

## What I learned

- **Virtual destructor matters.** Say you `delete` an `Asset*` that's
  really pointing at a Stock.

  Without `virtual ~Asset()`:
  ```
  delete Asset*  →  only Asset's destructor runs
                    Stock's cleanup is skipped (leaks)
  ```
  With it:
  ```
  delete Asset*  →  Stock's destructor runs, then Asset's
                    everything cleaned up
  ```

  Basically: the base class can't forget what type its child is.

