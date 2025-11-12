cpp23 C++ small test project
===============================

# Project layout
```
├── CMakeLists.txt
├── README.md
├── include      # Header files
│   └── cpp23.h
├── src          # Source files
│   └── cpp23.cpp
├── tests        # Various tests
│   ├── integration
│   ├── performance
│   └── unit
├── conanfile.py # Conan package manager file
```

# Due to dependencies are managed by Conan, you need to install it first
```bash
pip install -r requirements.txt
```

# Build
```bash
conan install . -pr debug --build=missing
cmake --preset conan-default
cmake --build --preset conan-debug
```

# Run tests
```bash
ctest --preset conan-debug
```


>📝
> Based on the template https://github.com/edu-one/cpptest
