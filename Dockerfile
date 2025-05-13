# Dockerfile
FROM ubuntu:22.04

# Install base dependencies
RUN apt-get update && apt-get install -y \
    software-properties-common \
    x11-apps \
    mesa-utils \
    libgl1-mesa-glx \
    gcc \
    make \
    git \
    # Add any other dependencies you need
    && rm -rf /var/lib/apt/lists/*

# Create a non-root user
RUN useradd -m developer && \
    echo "developer ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

USER developer
WORKDIR /home/developer
ENV DISPLAY=host.docker.internal:0

