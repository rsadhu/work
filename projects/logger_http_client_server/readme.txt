The Project shows client server interaction over http protocol.

Use case here is logger utility.

E.g anywhere in code one can use Logger and Logger encapsulates http_client which sends data of logger to the http_server.



Server can do anything with data , that can be left for futuristic usage.


# how to build
1.conan install . --build=missing --output=build
2.cmake ../ -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release