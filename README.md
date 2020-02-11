<p align="center">
  <img width="260" height="190" src="https://github.com/soleni/PassKeeper/blob/master/logo.png">
</p>

<h3 align="center">Application for secure password storage</h3>

# Build
You must have [libsodium](https://github.com/jedisct1/libsodium) installed before compiling!

To build app simply do:
```bash
$ make
```
To run tests:
```bash
$ make test
```

# Usage
Generate randow strong password (it must have at least one uppercase, lowercase letter, digit and special character):
```bash
$ ./passkeeper generate <size>
```

Read file with passwords:
```bash
$ ./passkeeper read
```

Save your password to file:
```bash
$ ./passkeeper save
```

# Dependencies
* [libsodium](https://github.com/jedisct1/libsodium) - Crypto library.
* [chainsaw](https://github.com/eug-vs/chainsaw) - Utilities library.
