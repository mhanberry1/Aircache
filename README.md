# Aircache

## Description

This will allow two or more users to share files directly between one another without the use of a server to host the data.

## Server Versions

Currently, there are two implementations of the aircache server:

- [Node.js](./node_implementation): This is the proof-of-concept implementation. It was written in node so that features could be implemented quickly. This version will see features first.
- [C](./c_implementation): This is the production implementation of the server. It is designed to be compiled to an extremely lightweight binary and run without the need for shared libraries.

## Compiling the C Implementation

- Navigate to the `c_implementation` directory
- Run `make all`

## Deploying

### Server

#### Node.js Implementation

- Navigate to the `node_implementation` directory
- Run `npm start`

#### C Implementation

- Navigate to the `c_implementation` directory
- Execute `./server`

### Frontend Interface

- Upload the contents of the `frontend` directory to a web server

**or**

- Open `frontend/index.html` in a web browser
