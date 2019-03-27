# G4UIcmdWithADoubleAndUnit: loss of numeric precision when setting a default unit

File [`test.cpp`](test.cpp) provides a minimalist example illustrating the
problem. Both commands are `G4UIcmdWithADoubleAndUnit`. The first one
(`/test/setAngle0` defines a default unit as `deg`. The second
(`/test/setAngle1`) doesn't. When a default unit is set, the numeric precision
is truncated.

The example can be compiled and run as following:

```bash
source /usr/local/geant4/bin/geant4.sh
make
./test test.macro
```

Or using the [Dockerfile](Dockerfile), E.g. as:

```bash
docker build --build-arg DOCKER_TAG=10.04.p03 -t niess/geant4 .
```

It prints the following result:

```bash
setAngle0 : 45.1235 deg
setAngle1 : 45.123456789 deg
```

The problem was tested to occur with Geant4 9.6.p04 and 10.4.p03. It probably
occurs for versions in between as well?
