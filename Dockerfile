FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential cmake libpqxx-dev libpq-dev git \
    libgtest-dev curl

# Build gtest libraries
RUN cd /usr/src/gtest && cmake . && make && ls lib && cp lib/*.a /usr/lib/



WORKDIR /app
COPY . /app

RUN mkdir build
WORKDIR /app/build
RUN cmake .. && make

CMD ["./parking_lot"]
