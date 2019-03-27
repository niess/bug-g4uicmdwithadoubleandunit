ARG DOCKER_TAG=9.6.p04

from niess/geant4:$DOCKER_TAG

WORKDIR /tmp/test
COPY . .
RUN cd /usr/local/geant4/bin && . ./geant4.sh && cd -                       && \
    g++ -o test $(geant4-config --cflags) test.cpp $(geant4-config --libs)  && \
    ./test
