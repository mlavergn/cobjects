# cobjects

CObjects - Object-like constructs for POC (plain old C)

## IMPORTANT

This is a very old project of mine with missing portions, but the base files were still available
so I uploaded it to GitHub in case it's useful to anyone attempting the same concept.

## Description

CObjects is a toolkit for std C with an API based very loosely on GNUStep and OpenStep. 
C doesn't have "classes", but this toolkit provides a basic approximation of objects. 

For example:

NSString* string = [NSString stringWithFormat:@"Hello %@", @"world"];

is implemented as:

CKString* string = CKString_stringWithFormat("Hello %s", "world");

## Usage

```bash
make
./cobj
```
