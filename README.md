# Control Board     {#mainpage}

Someday i will create control board for transceiver with LCD+encoder+...

## Compile prerequisites:

On Debian (and may be on Ubuntu):

```
apt-get update
apt-get install make gcc-arm-none-eabi libnewlib-dev doxygen cppcheck vera++ stlink-tools
```

## Compilation and related:

  * `make clean` - clean up sources from compile-time artifacts
  * `make` - simply make `main.elf` binary
  * `make test` - run tests on some functions (not all)
  * `make check` - run `cppcheck` and `vera++` on `*.c` and `*.h` with some configs
  * `make bin` - make `main.bin` firmware
  * `make main.o` - make `main.o` object file from `main.c` sources, if you need it separately. You may make `*.o` from any `*.c`.
  * `make flash` - run `st-flash` to program microcontroller via st-link

config for `cppcheck` - `mk/cppcheck.includes`
config for `vera++` - `mk/vera++.excl`

