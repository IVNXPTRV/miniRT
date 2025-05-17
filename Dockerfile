FROM ubuntu:25.10

ENV DEBIAN_FRONTEND=noninteractive TZ=Etc/UTC

RUN apt-get update && \
    apt-get install -y tzdata && \
    ln -fs /usr/share/zoneinfo/Etc/UTC /etc/localtime && \
    dpkg-reconfigure -f noninteractive tzdata

# Install base dependencies
RUN apt-get update && apt-get install -y \
    software-properties-common \
    gcc \
    g++ \
    make \
    cmake \
    git \
    gdb \
    nano \
    sudo \
    less \
    mesa-utils \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    freeglut3-dev \
    libglfw3-dev \
    libgl1-mesa-dri \
    libglu1-mesa \
    libx11-dev \
	x11vnc \
	xvfb \
	x11-utils \
	x11-apps \
	openbox \
	supervisor \
	menu \
    # Add any other dependencies you need
    && rm -rf /var/lib/apt/lists/*

# Create a non-root user
RUN useradd -m -s /bin/bash developer && \
    echo 'developer:1234' | chpasswd && \
    usermod -aG sudo developer

# Copy supervisord config
COPY supervisord.conf /etc/supervisor/conf.d/supervisord.conf

CMD ["/usr/bin/supervisord", "-c", "/etc/supervisor/conf.d/supervisord.conf"]
# CMD ["bash"]

