# NetLib

NetLib is a cross-platform C++ library designed as a simple wrapper for "sys/socket.h" and "Winsock2.h". It provides a unified interface for network programming across different operating systems.

## Usage

1. **Include Headers**: Include "tcp_socket.h" in your C++ source files.
2. **Linking**: Link the generated NetLib binary (NetLib.lib, .a, .so, or .dll) into your output executable.
3. **Examples**: Refer to the "example" folder in the repository for implementation demonstrations.

## Build Instructions

This library uses CMake for cross-platform support.

1. Navigate to the build folder:
```bash
cd build
```

2. Generate the build files (this example uses Ninja):
```bash
cmake .. -G Ninja

```


3. Build the library:
```bash
ninja

```



## Current State and Future Vision

### Current Features

* TCP socket support via the TcpSocket class.
* Cross-platform abstraction for Windows and POSIX systems.

### Roadmap

* UDP Protocol support.
* SSL/TLS implementation for secure communication.