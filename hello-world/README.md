To build module:

```bash
$ make
```

To cleanup build files:

```bash
$ make clean
```

To insert module:

```bash
$ sudo insmod hello.ko
```

To check module logs:

```bash
$ sudo dmesg
```

To list loaded modules:

```bash
$ lsmod
```

or

```bash
$ lsmod | grep hello
```

To remove module:

```bash
$ sudo rmmod hello
```

