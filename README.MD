# File Lock

A program to encrypt/decrypt text files implemented in C and python for parsing the arguments.

## Installation

Use git to install it

```bash
git clone https://github.com/Brist0l/file_lock.git
```

Use make for compiling the source code

```bash
make
```

## Usage

This example over here encrypts a file called "test.txt" and the encrypted file is stored as "test.txt_":

```bash
./bin/main test.txt -c
```

This example over here encrypts a file called "test.txt" and overwrites it with the encrypted data:

```bash
./bin/main test.txt -c -x
```

This example over here encrypts a file called "test.txt" and overwrites it with the encrypted data and hides the file:

```bash
./bin/main test.txt -c -x -s
```

This example over here decrypts a file called "test.txt" and writes the decrypted data in "test.txt_":

```bash
./bin/main test.txt -d 
```

For help:

```bash
./bin/main --help 
```
## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[GNU GPL v3](https://choosealicense.com/licenses/gpl-3.0/)
