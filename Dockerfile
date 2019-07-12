FROM ubuntu:20.04

RUN apt-get -y update && apt-get install -y g++ cmake vim && mkdir /app