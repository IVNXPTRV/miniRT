# Dockerfile
FROM ubuntu:22.04

# Install base dependencies
RUN apt-get update && apt-get install -y \
    software-properties-common \
    x11-apps \
    mesa-utils \
    libgl1-mesa-glx \
    gcc \
    g++ \
    make \
    cmake \
    git \
    gdb \
    nano \
    sudo \
    less \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    freeglut3-dev \
    libglfw3-dev \
    libgl1-mesa-dri \
    libglu1-mesa \
    libx11-dev \
    # Add any other dependencies you need
    && rm -rf /var/lib/apt/lists/*

# Create a non-root user
RUN useradd -m -s /bin/bash developer && \
    echo 'developer:1234' | chpasswd && \
    usermod -aG sudo developer

USER developer

CMD ["bash"]
