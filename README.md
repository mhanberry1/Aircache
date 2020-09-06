# Aircache

## Description

This will allow two or more users to share files directly between one another without the use of a server to host the data.

## Versions

Currently, there are two implementations of the aircache server:

- [Node.js](./node_implementation): This is the proof-of-concept implementation. It was written in node so that features could be implemented quickly. This version will see features first.
- [C](./c_implementation): This is the production implementation of the server. It is designed to be compiled to an extremely lightweight binary and run without the need for shared libraries.
